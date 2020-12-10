/*-----------------------------------------------------------
 * An example program to draw a sphere and a cube
 *   Users can turn on/off the light
 *   Author: S.K. Ueng
 *   Date:  12/4/2001
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
float  normals[6][3]={{0.0,0.0,-1.0}, {0.0,-1.0,0.0}, {1.0,0.0,0.0},
                     {0.0,0.0,1.0}, {0.0,1.0,0.0}, {-1.0,0.0,0.0}};
/* indices of the box faces */
int    cube[6] = {0, 1, 2, 3, 4, 5};

/*-Declare GLU quadric objects, sphere, cylinder, and disk --*/
GLUquadricObj  *sphere=NULL;


/*-----Define window size----*/
int width=512, height=512;

float   lt_pos[]={20.0, 20.0, 5.0, 1.0};
float   lt_diffuse[]={0.9, 0.9, 0.9, 1.0};
float   lt_specular[]={0.9, 0.9, 0.9, 1.0};
float   global_ambient[]={0.2, 0.2, 0.2, 1.0};

float   mat_specular[] ={0.9, 0.9, 0.9, 1.0};
/*------------------------------------------------
 * Procedure to set up light0
 */
void setup_light()
{
  
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, lt_pos);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lt_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lt_specular);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
}

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
 //   gluQuadricNormals(sphere, GLU_FLAT);
    gluQuadricNormals(sphere, GLU_SMOOTH);  /* Generate normals */
  }
  /*---Create a light source----*/
  glEnable(GL_LIGHTING);
  setup_light();
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  /*---Enable normalization of normals----*/
  glEnable(GL_NORMALIZE);
}


/*--------------------------------------------------------
 * Procedure to draw a 1x1x1 cube. The cube is within
 * (-0.5,-0.5,-0.5) ~ (0.5,0.5,0.5)
 */
void draw_cube()
{
  float  cube_color[]={0.9, 0.0, 0.0, 1.0};
  float  white[]={0.95, 0.95, 0.95, 1.0};
  int    i;

  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_SPECULAR);
  glColor3fv(white);
  glMaterialf(GL_FRONT, GL_SHININESS, 6.0);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glColor3fv(cube_color);
  for(i=0;i<6;i++){
    glNormal3fv(normals[i]);
    glBegin(GL_POLYGON);  /* Draw the face */
      glVertex3fv(points[face[i][0]]);
      glVertex3fv(points[face[i][1]]);
      glVertex3fv(points[face[i][2]]);
      glVertex3fv(points[face[i][3]]);
    glEnd();
  }
  glDisable(GL_COLOR_MATERIAL);
}


/*---------------------------------------------------------
 * Procedure to draw the floor.
 */
void draw_floor()
{
  float  flr_color[]={0.0, 0.0, 0.9, 1.0};
  int  i, j;

  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glColor3fv(flr_color);
  glNormal3f(0.0, 1.0, 0.0);
  for(i=0;i<10;i++)
    for(j=0;j<10;j++){
      glBegin(GL_POLYGON);
        glVertex3f((i-5.0)*10.0, -2.2, (j-5.0)*10.0);
        glVertex3f((i-5.0)*10.0, -2.2, (j-4.0)*10.0);
        glVertex3f((i-4.0)*10.0, -2.2, (j-4.0)*10.0);
        glVertex3f((i-4.0)*10.0, -2.2, (j-5.0)*10.0);
      glEnd();
    }
  glDisable(GL_COLOR_MATERIAL);
}

/*-------------------------------------------------------
 * Display callback func. This func. draws three
 * cubes at proper places to simulate a solar system.
 */
void display(void)
{
  float green[]={0.0, 0.9, 0.0, 1.0};

  /*Clear previous frame and the depth buffer */
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

  /*----Define the current eye position and the eye-coordinate system---*/
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(5.0, 9.0, 15.0, 5.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  draw_floor();

  /*-------Draw a cube----*/
  glPushMatrix();              /* Save M1 coord. sys */
  glTranslatef(5.0, 2.5, 5.0); 
  glRotatef(30.0, 0.0, 1.0, 0.0);
  glScalef(5.0, 5.0, 5.0);    /* Scale up the axes */
  draw_cube();
  glPopMatrix();               /* Get M1 back */

  /*-------Draw a sphere-----*/
  glTranslatef(12.0, 2.5, 0.0);
  glMaterialf(GL_FRONT, GL_SHININESS, 8);
  glMaterialfv(GL_FRONT, GL_SPECULAR, green);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glColor3fv(green);
  gluSphere(sphere, 2.5, 32, 32);

  glTranslatef(-13.0, 0.0, 4.0);
  glMaterialf(GL_FRONT, GL_SHININESS, 64);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glColor3f(0.9, 0.9, 0.9);
  gluSphere(sphere, 2.5, 32, 32);
  glutSwapBuffers();
  return;
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

  gluPerspective(90.0, w/h, 0.5, 50.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}


/*--------------------------------------------------
 * Keyboard callback func. When a 'q' key is pressed,
 * the program is aborted.
 */
void my_quit(unsigned char key, int x, int y)
{
  if(key=='Q'||key=='q') exit(0);
  if(key=='1'){
	  glEnable(GL_LIGHTING);
	  glShadeModel(GL_SMOOTH);
  } else if(key=='2') glDisable(GL_LIGHTING);
   else if(key=='3'){
	  glEnable(GL_LIGHTING);
	  glShadeModel(GL_FLAT);
   }
  else if(key=='r'){
    lt_diffuse[0]= 0.95; lt_diffuse[1]= 0.05; lt_diffuse[2]= 0.05; 
    setup_light();
  }else if(key=='g'){
    lt_diffuse[0]= 0.05; lt_diffuse[1]= 0.95; lt_diffuse[2]= 0.05; 
    setup_light();
  }else if(key=='b'){
    lt_diffuse[0]= 0.05; lt_diffuse[1]= 0.05; lt_diffuse[2]= 0.95; 
    setup_light();
  }else if(key=='w'){
    lt_diffuse[0]= 0.95; lt_diffuse[1]= 0.95; lt_diffuse[2]= 0.95; 
    setup_light();
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
  glutCreateWindow("shading");

  myinit();      /*---Initialize other state varibales----*/
  
  /*----Associate callback func's whith events------*/
  glutDisplayFunc(display);
  glutReshapeFunc(my_reshape);
  glutKeyboardFunc(my_quit);

  glutMainLoop();
}

