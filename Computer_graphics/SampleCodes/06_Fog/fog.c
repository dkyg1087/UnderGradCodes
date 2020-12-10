/*-----------------------------------------------------
 * Sample program for fog-fading effect.
 * Should have this effect in hw4.
 * Copy Right: S.K. Ueng, CS Dept, National Taiwan Ocean Univ.
 */
#include <stdio.h>
#include <GL/glut.h>

float  points[][3] = {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, 
                      {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, 
                      {0.0, 0.0, 1.0}, {1.0, 0.0, 1.0},
                      {1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}};

int    face[][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {1, 2, 6, 5}, 
                    {4, 5, 6, 7}, {2, 3, 7, 6}, {0, 4, 7, 3}};

int    cube[6] = {0, 1, 2, 3, 4, 5};
float  normal[][4] = {{0.0, 0.0, -1.0}, {0.0, -1.0, 0.0}, {1.0, 0.0, 0.0},
		      {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {-1.0, 0.0, 0.0}};

/*---Define material properties---*/
float  mat_ambient[] = {0.1, 0.8, 0.1, 1.0};
float  mat_diffuse[] = {0.1, 0.8, 0.1, 1.0};
float  flr_diffuse[] = {0.8, 0.8, 0.8, 1.0};
float  flr_ambient[] = {0.4, 0.4, 0.4, 1.0};
float  mat_specular[] = {0.8, 0.8, 0.8, 1.0};
float  mat_shininess = 16.0;

/*---Define light properties ----*/
float  lit_position[] = {0.0, 6.0, 0.0, 1.0};
float  lit_ambient[] = {0.2, 0.2, 0.2, 1.0};
float  lit_diffuse[] = {0.8, 0.8, 0.8, 1.0};
float  lit_specular[] = {0.9, 0.9, 0.9, 1.0};

/*---Define fog color----*/
float fog_color[]={0.15, 0.20, 0.20, 0.50};

/*--- Translates of eye position ---*/
float dx=0.0, dy=0.0, dz=0.0;

/*----------------------------------------------
 * Procedure to initialize the environment.
 */
void myinit()
{ /*---Clear the background to the fog color---*/
  glClearColor(fog_color[0], fog_color[1], fog_color[2], fog_color[3]);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  glShadeModel(GL_SMOOTH);

  glEnable(GL_DEPTH_TEST); /*depth test is crucial, add it*/
  glEnable(GL_NORMALIZE);  /* Since glScalef() is used, normals are enlarged
                            * we have to scale them down.*/

  /*----Set up lighting conditions -----*/
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, lit_position);
  glLightfv(GL_LIGHT0, GL_AMBIENT, lit_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lit_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lit_specular);

  /*----Set up fog conditions ---*/
  glEnable(GL_FOG);                /*enable fog fade */
  glFogi(GL_FOG_MODE, GL_LINEAR);  /*fog factor=GL_LINEAR,GL_EXP,or GL_EXP2*/
  glFogf(GL_FOG_DENSITY, 0.15);    /*fog opacity(density)= 0.25*/
  glFogf(GL_FOG_START, 1.0);       /*Setup two ends for GL_LINEAR*/
  glFogf(GL_FOG_END, 36.0);
  glFogfv(GL_FOG_COLOR, fog_color);/*set the fog color */

  glViewport(0, 0, 499, 499);
  glFlush();
}

/*----------------------------------------------------------
 * procedure to draw cube
 */
void draw_cube()
{
  int    i;

  for(i=0;i<6;i++){
    glNormal3fv(normal[i]);
    glBegin(GL_POLYGON);
      glVertex3fv(points[face[i][0]]);
      glVertex3fv(points[face[i][1]]);
      glVertex3fv(points[face[i][2]]);
      glVertex3fv(points[face[i][3]]);
    glEnd();
  }
}


/*------------------------------------------------------
 * Procedure to draw the whole scene.
 */
void display()
{
  int    i,  j;

  /*---Clear window to the fog color---*/
  /*---Depth bufer has to be clear, otherwise the rendering is wrong */
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  /*---Define the eye coordinate transf. matrix. */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(dx, dy, dz);
  gluLookAt(8.0, 3.5, 16.0, 8.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  /*-----Draw the floor, 8x8 square------*/
  glMaterialfv(GL_FRONT, GL_AMBIENT, flr_ambient);/*set material properties*/
  glMaterialfv(GL_FRONT, GL_DIFFUSE, flr_diffuse);/*for the floor*/
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialf(GL_FRONT, GL_SHININESS, 0.0);

  glNormal3f(0.0, 1.0, 0.0);  /*-define normal-*/
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      glPushMatrix();
      glTranslatef(i*2.0, 0.0, j*2.0);
      glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 2.0);
	glVertex3f(2.0, 0.0, 2.0);
	glVertex3f(2.0, 0.0, 0.0);
      glEnd();
      glPopMatrix();
    }
  }

  /*----Define material properties for cubes and draw them ---*/
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      if(i%2==j%2){
	glPushMatrix();
	glTranslatef(i*2.0+0.5, 0.0, j*2.0+0.5);
	glScalef(1.0, 2.0, 1.0);/*be careful, this instruction may make*/
	draw_cube();            /*the surface normals inconsistant*/
	glPopMatrix();          /*Our normals are OK, they are x, y, z axes*/
      }
    }
  }

  glutSwapBuffers();
  glFlush();
}


/*--------------------------------------------------
 * Keyboard callback func. When a 'q' key is pressed,
 * the program is aborted.
 */
void key_func(unsigned char key, int x, int y)
{
  if(key=='Q'||key=='q') exit(0);
  if(key=='f') glEnable(GL_FOG);
  else if(key=='g') glDisable(GL_FOG);  
     /*fog factor=GL_LINEAR,GL_EXP,or GL_EXP2*/
  else if(key=='l')   glFogi(GL_FOG_MODE, GL_LINEAR);
  else if(key=='e')   glFogi(GL_FOG_MODE,GL_EXP);
  else if(key=='x')   glFogi(GL_FOG_MODE, GL_EXP2);
  else if(key=='f') dz += 1.0;
  else if(key=='n') dz -= 1.0;
  else if(key=='l') dx += 1.0;
  else if(key=='r') dx -= 1.0;
  glutPostRedisplay();
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
    gluPerspective(90.0, (double)h/(double)w, 1.0, 50.0);
  else
    gluPerspective(90.0, (double)w/(double)h, 1.0, 50.0);
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
  glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGBA| GLUT_DEPTH);

  glutInitWindowSize(500, 500);
  glutCreateWindow("fog");

  myinit();      /*---Initialize other state varibales----*/
  
  /*----Associate callback func's whith events------*/
  glutDisplayFunc(display);
  glutReshapeFunc(my_reshape);
  glutKeyboardFunc(key_func);
  glutMainLoop();
}
