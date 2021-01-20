/***********************************************************************
 * Sample Program for Homework Number 4.
 *   Rendering a cube on the floor
 */
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>

/*--- Define coordinates of vertices. */
float  points[][3] = {{-1.0, 0.0, -1.0}, {1.0, 0.0, -1.0}, 
                      {1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0}, 
                      {-1.0, 0.0, 1.0}, {1.0, 0.0, 1.0},
                      {1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}};

/*----Define faces, these num. are indices of vertices---*/
int    face[][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {1, 2, 6, 5}, 
                    {4, 5, 6, 7}, {2, 3, 7, 6}, {0, 4, 7, 3}};
/*----Define a cube by using face indices ----*/
int    cube[6] = {0, 1, 2, 3, 4, 5};

/*----Define normals of faces ----*/
float  normal[][4] = {{0.0, 0.0, -1.0}, {0.0, -1.0, 0.0}, {1.0, 0.0, 0.0},
		      {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {-1.0, 0.0, 0.0}};

/*----Define material properties for cube -----*/
float  mat_ambient[] = {0.1, 0.3, 0.1, 1.0};
float  mat_diffuse[] = {0.1, 0.9, 0.1, 1.0};
float  mat_specular[] = {0.4, 0.4, 0.4, 1.0};
float  mat_shininess = 64.0;
float  flr_diffuse[] = {0.60, 0.60, 0.60, 1.0};
float  flr_ambient[]={0.3, 0.3, 0.3, 1.0};
float  flr_specular[] = {0.0, 0.0, 0.0, 1.0};

/*----Define light source properties -------*/
float  lit_position[] = {10.0, 14.0, 0.0, 1.0};
float  lit_direction[] = {-1.0, -1.0, 1.0, 0.0};
float  lit_diffuse[] = {0.8, 0.4, 0.4, 1.0};
float  lit_specular[] = {0.7, 0.7, 0.7, 1.0};
float  lit_cutoff=60.0;
float  lit_exponent=8.0;

float  lit1_position[] = {-0.5, 1.0, -2.0, 1.0};
float  lit1_diffuse[] = {0.7, 0.7, 0.0, 1.0};

float  global_ambient[]={0.2, 0.2, 0.2, 1.0};

/*----Some global variables for transformation------*/
float  lit_angle=0.0;
float  cube_angle=0.0;
float  head=0.0, roll=0.0, Epitch=0.0, Wpitch=0.0;
float  up = 0.0, right = 0.0, zoom= 0.0;
/*----------------------------------------------------------
 * Procedure to initialize the working environment.
 */
void  myinit()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);      /*set the background color BLACK */
                   /*Clear the Depth & Color Buffers */
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);  /*Enable depth buffer for shading computing */
  glEnable(GL_NORMALIZE);   /*Enable mornalization  */

  glEnable(GL_LIGHTING);    /*Enable lighting effects */
  glEnable(GL_LIGHT0);      /*Turn on light0 */
  glEnable(GL_LIGHT1);      /*Turn on light1 */
  /*-----Define light0 ---------*/
  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, lit_cutoff);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lit_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lit_specular);
  glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, lit_exponent);

  /*-----Define light1 ---------*/
  glLightfv(GL_LIGHT1, GL_DIFFUSE, lit1_diffuse);
  glLightfv(GL_LIGHT1, GL_SPECULAR, lit_specular);
  
 
  /*-----Define some global lighting status -----*/
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); /* local viewer */
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient); /*global ambient*/

  /*-----Enable face culling -----*/
  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);
}
/*--------------------------------------------------------
 * Procedure to draw the cube, whose vertices and faces
 * are defined above.
 */
void draw_cube()
{
  int    i;
  float  range;

 /*-----Define some material properties shared by every one ---*/
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

  for(i=0;i<6;i++){     /* draw the six faces one by one */
    range = 1.0;
    glNormal3fv(normal[i]);
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
  int   i, j;

  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

  /*----Define the current eye position and the eye-coordinate system---*/
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glRotatef(head, 0.0, 1.0, 0.0);    /*--Transformation in Eye coord. sys--*/
  glRotatef(roll, 0.0, .0, 1.0);
  glRotatef(Epitch, 1.0, 0.0, 0.0);
  glTranslatef(0.0, up, 0.0);
  glTranslatef(-right, 0.0, 0.0);
  glTranslatef(0.0, 0.0, -zoom);

  glPushMatrix();
  glLoadIdentity();
  /*----position light1 (fixed) in eye coord sys ---*/
  glLightfv(GL_LIGHT1, GL_POSITION, lit1_position);  /*fixed position in eye space---*/
  /*---draw the light source ---*/
  glTranslatef(lit1_position[0], lit1_position[1], lit1_position[2]);
  glDisable(GL_LIGHTING);
  glDisable(GL_CULL_FACE);
  glColor3f(0.80, 0.80, 0.0);
  glutSolidSphere(0.3, 12, 12);
  glPopMatrix();
  glEnable(GL_CULL_FACE);
  /*----Define Viewing Matrix-----*/
  gluLookAt(8.0, 8.0, 20.0, 8.0, 4.0, 4.0, 0.0, 1.0, 0.0);
  
  /*-------Rotate light position----*/
  glPushMatrix();
  glTranslatef(8.0, 0.0, 8.0);          /* Move to [8, 0, 8] */
  glRotatef(lit_angle, 0.0, 1.0, 0.0);  /* Rotate about y-axis */
  /*-------Draw light source as a red cube----*/
  glPushMatrix();
  glTranslatef(lit_position[0],lit_position[1],lit_position[2]);
  glColor3f(1.0, 0.0, 0.0);
  glutWireSphere(0.5, 8, 8);
  glPopMatrix();

  glEnable(GL_LIGHTING);      /* Turn on lighting */
  /*----Redefine position and direction of light0-----*/
  glLightfv(GL_LIGHT0, GL_POSITION, lit_position);
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lit_direction);
  glPopMatrix();

  /*-------Draw the floor ----*/
  glMaterialfv(GL_FRONT, GL_DIFFUSE, flr_diffuse);  /*diffuse color */
  glMaterialfv(GL_FRONT, GL_SPECULAR, flr_specular);
  glMaterialfv(GL_FRONT, GL_AMBIENT, flr_ambient);
  glNormal3f(0.0, 1.0, 0.0);  
  for(i=-6;i<=16;i++){
    for(j=-6;j<=16;j++){
      glBegin(GL_POLYGON);
      glVertex3f(i*2.0+0.0, 0.0, j*2.0+0.0);
      glVertex3f(i*2.0+0.0, 0.0, j*2.0+2.0);
      glVertex3f(i*2.0+2.0, 0.0, j*2.0+2.0);
      glVertex3f(i*2.0+2.0, 0.0, j*2.0+0.0);
      glEnd();
    }
  }
  /*-------Draw the cube ----*/
  glPushMatrix();
  glTranslatef(4.0, 0.0, 4.0);
  glRotatef(cube_angle, 0.0, 1.0, 0.0);
  glScalef(5.0, 4.0, 5.0); /*set the metrics=5x4x5*/
  draw_cube();
  glPopMatrix();

  /*-----Draw another cube ---*/
  glPushMatrix();
  glTranslatef(12, 0.0, 12.0);
  glRotatef(cube_angle/2.0, 0.0, 1.0, 0.0);
  glScalef(3.0, 6.0, 3.0);
  draw_cube();
  glPopMatrix();
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
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if(w>h)
    gluPerspective(90.0, (double)h/(double)w, 2.0, 30.0);
  else
    gluPerspective(90.0, (double)w/(double)h, 2.0, 30.0);
}
/*--------------------------------------------------
 * Keyboard callback func. When a 'q' key is pressed, exit.
 */
void key_func(unsigned char key, int x, int y)
{
  if(key=='Q'||key=='q') exit(0);
  if(key==','||key=='<') cube_angle -= 10.0;
  else if(key=='.'||key=='>') cube_angle +=10.0;
  if(cube_angle>36.0) cube_angle -= 360.0;
  else if(cube_angle<(-360.0)) cube_angle += 360.0;
  if(key=='l'||key=='L') right += 0.5;
  else if(key=='r'||key=='R') right -= 0.5;
  if(key=='u'||key=='U') up += 0.5;
  else if(key=='d'||key=='D') up -= 0.5;
  if(key=='n'||key=='N') zoom -=0.5;
  else if(key=='f'||key=='F') zoom += 0.5;
  if(key=='x') Epitch += 10.0;
  else if(key=='X') Wpitch += 10.0;
  if(key=='y') head +=10.0;
  else if(key=='Y') head -=10.0;
  if(key=='z') roll += 10.0;
  else if(key=='Z') roll -= 10.0;
  else if(key=='1') glEnable(GL_LIGHT0);
  else if(key=='0') glDisable(GL_LIGHT0);
  /*---Rotate light position by SPACE key ----*/
  if(key==' ') lit_angle += 5.0;

  display();
}
/*---------------------------------------------------
 * Main procedure which defines the graphics environment,
 */
void main(int argc, char **argv)
{
  /*-----Initialize the GLUT environment-------*/
  glutInit(&argc, argv);
  /*-----Depth buffer is used, be careful !!!----*/
  glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB| GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutCreateWindow("cube");
  myinit();      /*---Initialize other state varibales----*/
  
  /*----Associate callback func's whith events------*/
  glutDisplayFunc(display);
  glutReshapeFunc(my_reshape);
  glutKeyboardFunc(key_func);
  glutMainLoop();
}
