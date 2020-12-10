/*-----------------------------------------------------------
 * An example program to draw a car
 *   Divide the window into four parts, each part shows an image
 *   resulting from a projection method.
 *   Author: S.K. Ueng
 *   Date:  11/4/2001
 */
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>

#define  PI   3.141592653

#define Step  0.5

/*-----Define a unit box--------*/
/* Vertices of the box */
float  points[][3] = {{-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}, 
                      {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5}, 
                      {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5},
                      {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5}};
/* face of box, each face composing of 4 vertices */
int    face[][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {1, 2, 6, 5}, 
                    {4, 5, 6, 7}, {2, 3, 7, 6}, {0, 4, 7, 3}};
float  colors[6][3]={{0.5,0.5,0.5}, {0.7,0.7,0.7}, {0.7,0.5,0.5},
                     {0.5,0.5,0.5}, {0.5,0.7,0.5}, {0.5,0.5,0.7}};
/* indices of the box faces */
int    cube[6] = {0, 1, 2, 3, 4, 5};

/*-Declare GLU quadric objects, sphere, cylinder, and disk --*/
GLUquadricObj  *sphere=NULL, *cylind=NULL, *disk;


/*-Declare car position, orientation--*/
float  self_ang=-90.0, glob_ang=0.0;
float  position[3]={8.0, 0.0, 0.0};

/*-----Define window size----*/
int width=600, height=600;


/*-----Translation and rotations of eye coordinate system---*/
float   eyeDx=0.0, eyeDy=0.0, eyeDz=0.0;
float   eyeAngx=0.0, eyeAngy=0.0, eyeAngz=0.0;
double  Eye[3]={0.0, 0.0, 30.0}, Focus[3]={0.0, 0.0, 0.0}, 
        Vup[3]={0.0, 1.0, 0.0};

float   u[3][3]={{1.0,0.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0}};
float   eye[3];
float   cv, sv; /* cos(5.0) and sin(5.0) */

/*-----Drawing stye
 0:4-windows, 1:x direction, 2:y direction, 3:z-dirtection, 4:perspective
 */
int style=0;

void draw_scene(void);
float norm2(float v[]);

/*----------------------------------------------------------
 * Procedure to initialize the working environment.
 */
void  myinit()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);      /*set the background color BLACK */
                   /*Clear the Depth & Color Buffers */
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

  glEnable(GL_DEPTH_TEST);
  /*---Create quadratic objects---*/
  if(sphere==NULL){
    sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluQuadricNormals(sphere, GLU_SMOOTH);
  }
  if(cylind==NULL){
    cylind = gluNewQuadric();
    gluQuadricDrawStyle(cylind, GLU_FILL);
    gluQuadricNormals(cylind, GLU_SMOOTH);
  }
  if(disk==NULL){
    disk = gluNewQuadric();
    gluQuadricDrawStyle(disk, GLU_FILL);
    gluQuadricNormals(disk, GLU_SMOOTH);
  }

  /*---- Compute cos(5.0) and sin(5.0) ----*/
  cv = cos(5.0*PI/180.0);
  sv = sin(5.0*PI/180.0);
  /*---- Copy eye position ---*/
  eye[0] = Eye[0];
  eye[1] = Eye[1];
  eye[2] = Eye[2];
}


/*--------------------------------------------------------
 * Procedure to draw a 1x1x1 cube. The cube is within
 * (-0.5,-0.5,-0.5) ~ (0.5,0.5,0.5)
 */
void draw_cube()
{
  int    i;

  for(i=0;i<6;i++){
    glColor3fv(colors[i]);  /* Set color */
    glBegin(GL_POLYGON);  /* Draw the face */
      glVertex3fv(points[face[i][0]]);
      glVertex3fv(points[face[i][1]]);
      glVertex3fv(points[face[i][2]]);
      glVertex3fv(points[face[i][3]]);
    glEnd();
  }
}


/*---------------------------------------------------------
 * Procedure to draw the floor.
 */
void draw_floor()
{
  int  i, j;

  for(i=0;i<10;i++)
    for(j=0;j<10;j++){
      if((i+j)%2==0) glColor3f(0.8, 0.8, 0.8);
      else glColor3f(0.2, 0.2, 0.4);
      glBegin(GL_POLYGON);
        glVertex3f((i-5.0)*10.0, -2.2, (j-5.0)*10.0);
        glVertex3f((i-5.0)*10.0, -2.2, (j-4.0)*10.0);
        glVertex3f((i-4.0)*10.0, -2.2, (j-4.0)*10.0);
        glVertex3f((i-4.0)*10.0, -2.2, (j-5.0)*10.0);
      glEnd();
    }
}

/*-------------------------------------------------------
 * Procedure to draw three axes and the orign
 */
void draw_axes()
{

  /*----Draw a white sphere to represent the original-----*/
  glColor3f(0.9, 0.9, 0.9);

  gluSphere(sphere, 2.0,   /* radius=2.0 */
	    12,            /* composing of 12 slices*/
	    12);           /* composing of 8 stacks */

  /*----Draw three axes in colors, yellow, meginta, and cyan--*/
  /* Draw Z axis  */
  glColor3f(0.0, 0.95, 0.95);
  gluCylinder(cylind, 0.5, 0.5, /* radius of top and bottom circle */
	      10.0,              /* height of the cylinder */
              12,               /* use 12-side polygon approximating circle*/
	      3);               /* Divide it into 3 sections */
  
  /* Draw Y axis */
  glPushMatrix();
  glRotatef(-90.0, 1.0, 0.0, 0.0);  /*Rotate about x by -90', z becomes y */
  glColor3f(0.95, 0.0, 0.95);
  gluCylinder(cylind, 0.5, 0.5, /* radius of top and bottom circle */
	      10.0,             /* height of the cylinder */
              12,               /* use 12-side polygon approximating circle*/
	      3);               /* Divide it into 3 sections */
  glPopMatrix();

  /* Draw X axis */
  glColor3f(0.95, 0.95, 0.0);
  glPushMatrix();
  glRotatef(90.0, 0.0, 1.0, 0.0);  /*Rotate about y  by 90', x becomes z */
  gluCylinder(cylind, 0.5, 0.5,   /* radius of top and bottom circle */
	      10.0,             /* height of the cylinder */
              12,               /* use 12-side polygon approximating circle*/
	      3);               /* Divide it into 3 sections */
  glPopMatrix();
  /*-- Restore the original modelview matrix --*/
  glPopMatrix();
}

/*-------------------------------------------------------
 * Make viewing matrix
 */
void make_view(int x)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  switch(x){
  case 4:       /* Perspective */

    /* In this sample program, eye position and Xe, Ye, Ze are computed
       by ourselves. Therefore, use them directly; no trabsform is
       applied upon eye coordinate system
       */
    gluLookAt(eye[0], eye[1], eye[2], 
	      eye[0]-u[2][0], eye[1]-u[2][1], eye[2]-u[2][2],
	      u[1][0], u[1][1], u[1][2]);
    break;

  case 1:       /* X direction parallel viewing */
    gluLookAt(30.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    break;
  case 2:       /* Y direction parallel viewing */
    gluLookAt(0.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    break;
  case 3:
    gluLookAt(0.0, 0.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    break;
  }
}

/*------------------------------------------------------
 * Procedure to make projection matrix
 */
void make_projection(int x)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if(x==4){
    gluPerspective(90.0, (double) width/ (double) height, 1.5, 50.0);
  }else{
      if(width>height)
	glOrtho(-40.0, 40.0, -40.0*(float)height/(float)width, 
		40.0*(float)height/(float)width, 
		-0.0, 100.0);
      else
	glOrtho(-40.0*(float)width/(float)height, 
		40.0*(float)width/(float)height, -40.0, 40.0, 
		-0.0, 100.0);
  }
  glMatrixMode(GL_MODELVIEW);
}


/*---------------------------------------------------------
 * Procedure to draw view volume, eye position, focus ,...
 * for perspective projection
 */
void draw_view()
{
  int    i;

  glMatrixMode(GL_MODELVIEW);

  /*----Draw Eye position-----*/
  glPushMatrix();
  glTranslatef(eye[0], eye[1], eye[2]);
  glColor3f(0.0, 1.0, 0.0);
  glutWireSphere(1.0, 10, 10);
  glPopMatrix();

  /*----Draw eye coord. axes -----*/
  glColor3f(1.0, 1.0, 0.0);           /* Draw Xe */
  glBegin(GL_LINES);
    glVertex3f(eye[0], eye[1], eye[2]);
    glVertex3f(eye[0]+20.0*u[0][0], eye[1]+20.0*u[0][1], eye[2]+20.0*u[0][2]);
  glEnd();

  glColor3f(1.0, 0.0, 1.0);          /* Draw Ye */
  glBegin(GL_LINES);
    glVertex3f(eye[0], eye[1], eye[2]);
    glVertex3f(eye[0]+20.0*u[1][0], eye[1]+20.0*u[1][1], eye[2]+20.0*u[1][2]);
  glEnd();

  glColor3f(0.0, 1.0, 1.0);          /* Draw Ze */
  glBegin(GL_LINES);
    glVertex3f(eye[0], eye[1], eye[2]);
    glVertex3f(eye[0]+20.0*u[2][0], eye[1]+20.0*u[2][1], eye[2]+20.0*u[2][2]);
  glEnd();
}


/*--------------------------------------------------------
 * Display callback procedure to draw the scene
 */
void display()
{
  /*Clear previous frame and the depth buffer */
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
  switch(style){
  case 0:
    make_view(4);
    make_projection(4);
    glViewport(width/2, 0, width/2, height/2);
    draw_scene();

    make_view(1);
    make_projection(1);
    glViewport(0, height/2, width/2, height/2);
    draw_scene();
    make_view(1);
    draw_view();

    make_view(2);
    glViewport(width/2, height/2, width/2, height/2);
    draw_scene();
    make_view(2);
    draw_view();

    make_view(3);
    glViewport(0, 0, width/2, height/2);
    draw_scene();
    make_view(3);
    draw_view();
    break;

  case 4:
    glViewport(0, 0, width, height);
    make_view(4);
    make_projection(4);
    draw_scene();
    break;
  }
  /*-------Swap the back buffer to the front --------*/
  glutSwapBuffers();
  return;

}

/*-------------------------------------------------------
 * This procedure draw the car
 */
void draw_scene()
{

  draw_floor();

  draw_axes();
  /*-------Draw the car body which is a cube----*/
  glTranslatef(position[0], 0.0, position[2]); 
  glRotatef(self_ang, 0.0, 1.0, 0.0);

  glPushMatrix();              /* Save M1 coord. sys */
  glScalef(17.0, 3.0, 6.0);    /* Scale up the axes */
  draw_cube();
  glPopMatrix();               /* Get M1 back */

  /*-------Draw the front wheels -----*/
  glColor3f(.80, 0.40, 0.0);
  glPushMatrix();              /* Save M1 coord. sys */
  glTranslatef(-6.0, 0.0, 4.0); /* Go to left wheel position */
  glutSolidTorus(1.0,  /* inner radius */
                 2.0,  /* outer radius */
                 24,   /* divided into 18 segments */
                 12);  /* 12 rings */
  glPopMatrix();

  glPushMatrix();              /* Save M1 coord. sys */
  glTranslatef(-6.0, 0.0, -4.0);/* Go to right wheel position */
  glutSolidTorus(1.0,  /* inner radius */
                 2.0,  /* outer radius */
                 24,   /* divided into 18 segments */
                 12);  /* 12 rings */
  glPopMatrix();

  /*------Draw back wheels ----*/
  glColor3f(1.0, 0.4, 0.0);
  glPushMatrix();              /* Save M1 coord. sys */
  glTranslatef(6.0, 0.0, 4.0); /* Go to left wheel position */
  glutSolidTorus(1.0,  /* inner radius */
                 2.0,  /* outer radius */
                 24,   /* divided into 18 segments */
                 12);  /* 12 rings */
  glPopMatrix();

  glPushMatrix();              /* Save M1 coord. sys */
  glTranslatef(6.0, 0.0, -4.0);/* Go to right wheel position */
  glutSolidTorus(1.0,  /* inner radius */
                 2.0,  /* outer radius */
                 24,   /* divided into 18 segments */
                 12);  /* 12 rings */
  glPopMatrix();

}


/*--------------------------------------------------
 * Reshape callback function which defines the size
 * of the main window when a reshape event occurrs.
 */
void my_reshape(int w, int h)
{

  width = w;
  height = h;

  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90.0, (double) w/ (double) h, 1.5, 50.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}


/*--------------------------------------------------
 * Keyboard callback func. When a 'q' key is pressed,
 * the program is aborted.
 */
void my_quit(unsigned char key, int ix, int iy)
{
  int    i;
  float  x[3], y[3], z[3];

  /*--- Control the car. ----*/
  if(key=='Q'||key=='q') exit(0);
  if(key==' '){                              /* move car ahead, SPACE key */
    position[0] += Step*cos(self_ang*PI/180.0);
    position[2] -= Step*sin(self_ang*PI/180.0);
  }else if(key=='b'){                        /* move car back b-key */
    position[0] -= Step*cos(self_ang*PI/180.0);
    position[2] += Step*sin(self_ang*PI/180.0);
  }else if(key=='T'){                        /* make a left turn */
    self_ang += 10.0;
    if(self_ang > 360.0) self_ang -= 360.0;
  }else if(key=='t'){                        /* make a right turn */
    self_ang += -10.0;
    if(self_ang < 0.0) self_ang += 360.0;

/*------transform the EYE coordinate system ------*/
  }else if(key=='u'){
    eyeDy += 0.5;       /* move up */
    for(i=0;i<3;i++) eye[i] -= 0.5*u[1][i];
  }else if(key=='d'){
    eyeDy += -0.5;       /* move down */
    for(i=0;i<3;i++) eye[i] += 0.5*u[1][i];
  }else if(key=='w'){
    eyeDx += -0.5;       /* move left */
    for(i=0;i<3;i++) eye[i] += 0.5*u[0][i];
  }else if(key=='e'){
    eyeDx += 0.5;        /* move right */
    for(i=0;i<3;i++) eye[i] -= 0.5*u[0][i];
  }else if(key=='n'){
    eyeDz += 0.5;        /* zoom in */
    for(i=0;i<3;i++) eye[i] -= 0.5*u[2][i];
  }else if(key=='f'){
    eyeDz += -0.5;       /* zoom out */
    for(i=0;i<3;i++) eye[i] += 0.5*u[2][i];
  }else if(key=='p'){             /* pitching */
    eyeAngx += 5.0;
    if(eyeAngx > 360.0) eyeAngx -= 360.0;
    y[0] = u[1][0]*cv - u[2][0]*sv;
    y[1] = u[1][1]*cv - u[2][1]*sv;
    y[2] = u[1][2]*cv - u[2][2]*sv;

    z[0] = u[2][0]*cv + u[1][0]*sv;
    z[1] = u[2][1]*cv + u[1][1]*sv;
    z[2] = u[2][2]*cv + u[1][2]*sv;

    for(i=0;i<3;i++){
      u[1][i] = y[i];
      u[2][i] = z[i];
    }
  }else if(key=='P'){          
    eyeAngx += -5.0;
    if(eyeAngx<0.0) eyeAngx += 360.0;
    y[0] = u[1][0]*cv + u[2][0]*sv;
    y[1] = u[1][1]*cv + u[2][1]*sv;
    y[2] = u[1][2]*cv + u[2][2]*sv;

    z[0] = u[2][0]*cv - u[1][0]*sv;
    z[1] = u[2][1]*cv - u[1][1]*sv;
    z[2] = u[2][2]*cv - u[1][2]*sv;

    for(i=0;i<3;i++){
      u[1][i] = y[i];
      u[2][i] = z[i];
    }
  }else if(key=='h'){            /* heading */
    eyeAngy += 5.0;
    if(eyeAngy>360.0) eyeAngy -= 360.0;
    for(i=0;i<3;i++){
      x[i] = cv*u[0][i] - sv*u[2][i];
      z[i] = sv*u[0][i] + cv*u[2][i];
    }
    for(i=0;i<3;i++){
      u[0][i] = x[i];
      u[2][i] = z[i];
    }
  }else if(key=='H'){
    eyeAngy += -5.0;
    if(eyeAngy<0.0) eyeAngy += 360.0;
    for(i=0;i<3;i++){
      x[i] = cv*u[0][i] + sv*u[2][i];
      z[i] = -sv*u[0][i] + cv*u[2][i];
    }
    for(i=0;i<3;i++){
      u[0][i] = x[i];
      u[2][i] = z[i];
    }
  }else if(key=='r'){            /* rolling */
    eyeAngz += 5.0;
    if(eyeAngz>360.0) eyeAngz -= 360.0;
    for(i=0;i<3;i++){
      x[i] = cv*u[0][i] - sv*u[1][i];
      y[i] = sv*u[0][i] + cv*u[1][i];
    }
    for(i=0;i<3;i++){
      u[0][i] = x[i];
      u[1][i] = y[i];
    }
  }else if(key=='R'){
    eyeAngz += -5.0;
    if(eyeAngz<0.0) eyeAngz += 360.0;
    for(i=0;i<3;i++){
      x[i] = cv*u[0][i] + sv*u[1][i];
      y[i] = -sv*u[0][i] + cv*u[1][i];
    }
    for(i=0;i<3;i++){
      u[0][i] = x[i];
      u[1][i] = y[i];
    }
  }else if(key=='0'){
	  style = 0;
  }else if(key=='4'){
	  style = 4;
  }
  display();
}



/*---------------------------------------------------
 * Main procedure which defines the graphics environment,
 * the operation style, and the callback func's.
 */
void main(int argc, char **argv)
{
  /*-----Initialize the GLUT environment-------*/
  glutInit(&argc, argv);

  /*-----Depth buffer is used, be careful !!!----*/
  glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB| GLUT_DEPTH);

  glutInitWindowSize(width, height);
  glutCreateWindow("windmill");

  myinit();      /*---Initialize other state varibales----*/
  
  /*----Associate callback func's whith events------*/
  glutDisplayFunc(display);
  /*  glutIdleFunc(display); */
  glutReshapeFunc(my_reshape);
  glutKeyboardFunc(my_quit);

  glutMainLoop();
}


/*------------------------------------------
 * Procedure to compute norm of vector v[]
 */
float norm2(float v[])
{
  double  sum;
  float   temp;

  sum = v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
  temp = (float) sqrt(sum);
  return temp;
}
