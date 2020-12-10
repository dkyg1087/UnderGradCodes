/***************************************************
 * Example program: Draw a moving cube
 *   Author: S. K. Ueng
 *   National Taiwan Ocean Univ. Comp. Sci. Dept.
 */
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>


#define   PI   3.1415927

float  points[][3] = {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, 
                      {1.0, 0.0, 1.0}, {0.0, 0.0, 1.0},
                      {0.0, 1.0, 0.0}, {1.0, 1.0, 0.0},
{1.0, 1.0, 1.0}, {0.0, 1.0, 1.0}};

int    face[][4] = {{0, 1, 2, 3}, {7, 6, 5, 4}, {0, 4, 5, 1}, 
                    {1, 5, 6, 2}, {3, 2, 6, 7}, {0, 3, 7, 4}};

int    cube[6] = {0, 1, 2, 3, 4, 5};

float  color[][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};


int    width=500, height=500;    /* window shape */

float  pos[3] = {4.0, 0.0, 4.0};
float  angle = 0.0;

/* Declare rotation angle of eye coord. system */
float  roll_ang=0.0, yaw_ang=0.0, pitch_ang=0.0;

/* Declare translation distance in eye coord. system */
float  dx, dy, dz;

/* Declare perspective projection flag */
int perspective=0;

/* Declare three Quadrics objects */
GLUquadricObj *sphere=NULL, *cylinder=NULL, *circle=NULL;
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
  glOrtho(-8.0, 8.0 , -8.0, 8.0, 0.0, 20.0);
  
  glEnable(GL_DEPTH_TEST);  /*Enable depth buffer for shading computing */
   
  /*---- Initialize the quadric objects ----*/
  sphere = gluNewQuadric();
  cylinder = gluNewQuadric();
  circle = gluNewQuadric();

  gluQuadricDrawStyle(sphere, GLU_FILL);
  gluQuadricDrawStyle(cylinder, GLU_FILL);
  gluQuadricDrawStyle(circle, GLU_FILL);
}


/*--------------------------------------------------------
 * Procedure to draw the cube. The geometrical data of the cube
 * are defined above.
 */
void draw_cube()
{
  int    i;


  for(i=0;i<6;i++){     /* draw the six faces one by one */
    glColor3fv(color[i%3]);  /* Set the current color */

    glBegin(GL_POLYGON);  /* Draw the face */
      glVertex3fv(points[face[i][0]]);
      glVertex3fv(points[face[i][1]]);
      glVertex3fv(points[face[i][2]]);
      glVertex3fv(points[face[i][3]]);
    glEnd();
  }
}


/*-------------------------------------------------------
 * Procedure to draw coordinate system
 */
void draw_coord_sys()
{
   /*--Draw the origin ---*/
	glColor3f(0.8, 0.8, 0.1);
	gluSphere(sphere, 0.4, 8, 8);

	/*--Draw the z-axis  */
	glColor3f(0.0, 0.0, 1.0);
	gluCylinder(cylinder, 0.2,  0.2, /* radius */
		        3.0,                 /* length */
				6, 6);               /* slices & stacks*/
	/*--Draw the x-axis */
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	gluCylinder(cylinder, 0.2,  0.2, /* radius */
		        3.0,                 /* length */
				6, 6);               /* slices & stacks*/
	glPopMatrix();
	/*--Draw the y-axis */
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(cylinder, 0.2,  0.2, /* radius */
		        3.0,                 /* length */
				6, 6);               /* slices & stacks*/
	glPopMatrix();
}


/*------------------------------------------------------------
 * Procedure to draw a floor of black-and-white tiles.
 */
void draw_floor()
{
	int   i,  j;

	for(i=0;i<10;i++)
		for(j=0;j<10;j++){
			if((i+j)%2==0) glColor3f(0.8, 0.8, 0.8);
			else glColor3f(0.3, 0.3, 0.3);
			glBegin(GL_POLYGON);
			glVertex3f(i, 0.0, j);
			glVertex3f(i, 0.0, j+1);
			glVertex3f(i+1, 0.0, j+1);
			glVertex3f(i+1, 0.0, j);
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
  glLoadIdentity();

  glRotatef(roll_ang, 0, 0, -1);
  glRotatef(yaw_ang, 0.0, 1.0, 0.0);
  glRotatef(pitch_ang, 1,0,0);
  glTranslatef(dx, dy, dz);
  gluLookAt(6.0, 6.0, 6.0, 3.0, 0.0, 3.0, 0.0, 1.0, 0.0);

  /*-------Draw the floor ----*/
  
  draw_floor();

  /*-------Draw the coordinate system ---*/
  draw_coord_sys();

  /*-------Draw the cube ----*/
  glTranslatef(pos[0],pos[1], pos[2]);

  glPushMatrix();
  glScalef(1.0, 4.0, 1.0);
  draw_cube();
  glPopMatrix();

  /*-------Draw another cube---*/
  glPushMatrix();
  glTranslatef(0.0, 0.0, 3.0);
 
  
  glTranslatef(0.5, 0.50, 2.0);
  glRotatef(angle, 0.0, 1.0, 0.0);
  glTranslatef(-0.5, -0.50, -2.0);
 glScalef(1.0, 1.0, 4.0);
  draw_cube();
  glPopMatrix();
  /*-------Draw the third cube ---*/
 
  glTranslatef(3.0, 0.0, 0.0);
  glScalef(4.0, 1.0, 1.0);
  glTranslatef(0.5, 0.5, 0.5);
  glRotatef(angle, 1.0, 0.0, 0.0);
  glTranslatef(-0.5, -0.5, -0.5);
  draw_cube();


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
  if(perspective==1)
	  gluPerspective(90.0, (double) w/h, 1.0, 40.0);
  else
      if(w>h)
         glOrtho(-10.0, 10.0, -10.0*(float)h/(float)w, 10.0*(float)h/(float)w, 
             0.50, 30.0);
      else
         glOrtho(-10.0*(float)w/(float)h, 10.0*(float)w/(float)h, -10.0, 10.0, 
            0.50, 30.0);
  width = w; height = h;
  glutPostRedisplay();
}


/*--------------------------------------------------
 * Keyboard callback func. When a 'q' key is pressed,
 * the program is aborted.
 */
void my_quit(unsigned char key, int x, int y)
{
  if(key=='Q'||key=='q') exit(0);
  if(key=='Z') pos[2] += 0.5;
  else if(key=='z') pos[2] -= 0.5;
  if(key=='x') pos[0] -= 0.5;  
  else if(key=='X') pos[0] += 0.5;
   else if(key=='R'||key=='r') angle += 3.0;
  else if(key=='L'||key=='l') angle -= 3.0;
  if(angle >= 360.0) angle -= 360.0;
  else if(angle < 0.0) angle += 360.0;
 
  if(key=='>'||key=='.'){
	  roll_ang += 3.0;
	  if(roll_ang>360.0) roll_ang -= 360.0;
  }else if(key=='<'||key==','){
	  roll_ang -= 3.0;
	  if(roll_ang<0.0) roll_ang += 360.0;
  }else if(key=='p'){
	  pitch_ang += 3.0;
	  if(pitch_ang>360.0) pitch_ang -= 360.0;
  }else if(key=='P'){
	  pitch_ang -= 3.0;
	  if(pitch_ang<0.0) pitch_ang += 360.0;
  }else if(key=='y'){
	  yaw_ang += 3.0;
	  if(yaw_ang>360.0) yaw_ang -= 360.0;
  }else if(key=='Y'){
	  yaw_ang -= 3.0;
      if(yaw_ang<0.0) yaw_ang += 360.0;
  }else if(key=='f') dz += 0.2;
  else if(key=='b') dz -= 0.2;
  else if(key=='4') dx -= 0.2;
  else if(key=='6') dx += 0.2;
  else if(key=='8') dy += 0.2;
  else if(key=='2') dy -= 0.2;
  
  display();
}


/*------------------------------------------------------
 * Menu callback function
 */
void menu_func(int value)
{
	perspective = value;
	
	my_reshape(width, height);
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

  glutInitWindowSize(500, 500);
  glutCreateWindow("cube");

  myinit();      /*---Initialize other state varibales----*/
  
  /*----Associate callback func's whith events------*/
  glutCreateMenu(menu_func);
  glutAddMenuEntry("Parallel", 0);
  glutAddMenuEntry("Perspective", 1);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutDisplayFunc(display);

  glutReshapeFunc(my_reshape);
  glutKeyboardFunc(my_quit);

  glutMainLoop();
}

