/*---------------------------------------------------------------------------------
 * This file contains a program, drawing & animating a wind-mill.
 * This program is used to teach LCS and scene graph concepts.
 *
 * by S. K. Ueng, Nov.  2006
 */
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>


/*-----Define a unit box--------*/
/* Vertices of the box */
float  points[][3] = {{-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}, 
                      {0.5, 0.5, -0.5}, {-0.5, 0.5, -0.5}, 
                      {-0.5, -0.5, 0.5}, {0.5, -0.5, 0.5},
                      {0.5, 0.5, 0.5}, {-0.5, 0.5, 0.5}};
/* face of box, each face composing of 4 vertices */
int    face[][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {1, 2, 6, 5}, 
                    {4, 5, 6, 7}, {2, 3, 7, 6}, {0, 4, 7, 3}};
/* indices of the box faces */
int    cube[6] = {0, 1, 2, 3, 4, 5};

/*-----Define GLU quadric objects, a sphere and a cylinder----*/
GLUquadricObj  *sphere=NULL, *cylind=NULL;

/*-----Define window size----*/
int width=512, height=512;

//Global variables recording rotation angles of H-arm and blades.
float  arm_ang=45.0, bld_ang=10.0;

/*----------------------------------------------------------
 * Procedure to initialize the working environment.
 */
void  myinit()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);      /*set the background color BLACK */
                   /*Clear the Depth & Color Buffers */
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

  glViewport(0, 0, 499, 499);

  /*-----Set a parallel projection mode-----*/
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-15.0, 15.0 , -15.0, 15.0, -10.5, 30.0);
  
  glEnable(GL_DEPTH_TEST);  /*Enable depth buffer for shading computing */

  glFlush();/*Enforce window system display the results*/
}


/*-------------------------------------------------------
 * Procedure to draw a polygon as a blade of the windmill
 */
void draw_blade()
{
  glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 8.0, 0.0);
    glVertex3f(-1.0, 8.0, 0.0);
    glVertex3f(-1.0, 4.0, 0.0);
  glEnd();
}

/*--------------------------------------------------------
 * Procedure to draw a cube. The geometrical data of the cube
 * are defined above.
 */
void draw_cube()
{
  int    i;

  glColor3f(0.20, 0.75, 0.0);  /* Set the current color */
  for(i=0;i<6;i++){
    glBegin(GL_POLYGON);  /* Draw the face */
      glVertex3fv(points[face[i][0]]);
      glVertex3fv(points[face[i][1]]);
      glVertex3fv(points[face[i][2]]);
      glVertex3fv(points[face[i][3]]);
    glEnd();
  }
}



/*-------------------------------------------------------
 * Display and Idle callback func. This func. draws three
 * cubes at proper places to simulate a solar system.
 */
void display()
{
  /*Clear previous frame and the depth buffer */
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

  /*----Define the current eye position and the eye-coordinate system---*/
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();           /* Initialize modelview matrix */
  gluLookAt(10.0, 5.0, 15.0, 10.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  /*-------Draw the base of the windmill which is a cube----*/
  glTranslatef(10.0, 0.0, 6.0);

  glPushMatrix();              /* Save M1 coord. sys */
  glRotatef(30.0, 0.0, 1.0, 0.0);  /* rotate about y-axis by 30' */
  glScalef(6.0, 6.0, 6.0);     /* Scale up the axes by 6 times */
  draw_cube();                 /* Draw a unit cube in the new coord. sys. */
  glPopMatrix();               /* Get M1 back */

  glTranslatef(0.0, 3.0, 0.0); /* Go up by 2 units, move to M2 coord. sys */

  /*-------Draw the cylinder, arm of the windmill------*/
  glColor3f(0.68, 0.68, 0.68);    /* Gray colored */

  if(cylind==NULL){               /* allocate a quadric object, if necessary */
    cylind = gluNewQuadric();
    gluQuadricDrawStyle(cylind, GLU_FILL);
    gluQuadricNormals(cylind, GLU_SMOOTH);
  }

  glPushMatrix();              /* Save M2 system */
  glRotatef(-90.0, 1.0, 0.0, 0.0);  /* Roate about x axis, z become y,
                                       and y become -z */
  /*--- Draw a cylinder ---*/
  gluCylinder(cylind, 1.0, 1.0, /* radius of top and bottom circle */
	      7.0,              /* height of the cylinder */
          12,               /* use 12-side polygon approximating circle*/
	      3);               /* Divide it into 3 sections */
  glPopMatrix();         /* Get M2 back */

  glTranslatef(0.0, 8.0, 0.0); /* Go up 8 units, become M3 coord. sys*/

  /*----- Draw a unit sphere ---*/
  if(sphere==NULL){
    sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_FILL);
  }
  glColor3f(0.95, 0.2, 0.2);
  gluSphere(sphere, 2.0,   /* radius=2.0 */
	    12,            /* composing of 12 slices*/
	    12);           /* composing of 12 stacks */

  /*---- Draw forearm of the windmill ---*/
  glRotatef(arm_ang, 0.0, 1.0, 0.0);

  glColor3f(0.68, 0.68, 0.68);
  gluCylinder(cylind, 1.0, 1.0, 4.0, 12, 3);

  glTranslatef(0.0, 0.0, 5.0); /* goto end of forearm, M4 coord. sys. */
  glColor3f(0.2, 0.2, 0.95);
  gluSphere(sphere, 1.5,   /* radius=1.5 */
	    12,            /* composing of 12 slices*/
	    12);           /* composing of 12 stacks */

  /*------Draw three blades ---*/
  glColor3f(1.0, 1.0, 1.0);
  
  glRotatef(bld_ang, 0.0, 0.0, 1.0);  /* Rotate about x axis, M5 coord. sys. */
  draw_blade();/* draw the first blade */
 
  glRotatef(120.0, 0.0, 0.0, 1.0);    /* rotate by 120 degree, M6 coord. sys */
  draw_blade();/* draw 2nd blade */
  
  glRotatef(120.0, 0.0, 0.0, 1.0);    /* rotate by 120 degree,M7 coord. sys */
  draw_blade();/* draw 3rd blade */
 
  /*-------Swap the back buffer to the front --------*/
  glutSwapBuffers();
  glFlush(); /*--Display the results----*/
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
  if(w>h)
    glOrtho(-15.0, 15.0, -15.0*(float)h/(float)w, 15.0*(float)h/(float)w, 
            -10.5, 30.0);
  else
    glOrtho(-15.0*(float)w/(float)h, 15.0*(float)w/(float)h, -15.0, 15.0, 
            -10.5, 30.0);
}


/*--------------------------------------------------
 * Keyboard callback func. When a 'q' key is pressed,
 * the program is aborted.
 */
void my_keyboard(unsigned char key, int x, int y)
{
  if(key=='Q'||key=='q') exit(0);
  if(key=='r'){
    arm_ang += 5.0;
    if(arm_ang>360.0) arm_ang -= 360.0;
  }else if(key=='c'){
    bld_ang += 5.0;
    if(bld_ang>360.0) bld_ang -=360.0;
  }
  display();
}


/*---------------------------------------------
 * Idle event callback function, increase blade and arm
 * rotation angles.
 */
void idle_func()
{
  bld_ang += 5.0;
  if(bld_ang>360.0){
    bld_ang -= 360.0;
    arm_ang += 3.0;
    if(arm_ang>360.0) arm_ang -= 360.0;
  }
  display(); /* show the scene again */
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
  glutIdleFunc(idle_func);    /* Add idle event */
  glutReshapeFunc(my_reshape);
  glutKeyboardFunc(my_keyboard);

  glutMainLoop();
}
