/***********************************************************************
 * Sample Program for aliasing phenomena in texture mapping.
 */
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>


#define   TSIZE  256   /* define texture dimension */


/*-----Create image space for textures -----*/
unsigned char  checkboard[TSIZE][TSIZE][4];   /* checkboard textures */
unsigned char  texture[TSIZE][TSIZE][4];   /* checkboard textures */
unsigned int   textName[2];                   /* declare two texture maps*/

float    ds=0.0, dt=0.0;
float     head=0.0, up=0.0, roll=0.0, zoom=0.0,
          Epitch=0.0, right=0.0, left=0.0, Wpitch=0.0;
/*----------------------------------------------------------
 * Procedure to make a checkboard texture.
 */
void make_check()
{
  int   i, j, c;

  for(i=0;i<TSIZE;i++)
    for(j=0;j<TSIZE;j++){
      c = (((i&0x10)==0)^((j&0x10)==0))*255;
      checkboard[i][j][0] = c;
      checkboard[i][j][1] = c;
      checkboard[i][j][2] = c;
      checkboard[i][j][3] = 255;
    }
}

/*----------------------------------------------------------
 * Procedure to make a checkboard texture.
 */
void make_texture()
{
  int   i, j, c;

  for(i=0;i<TSIZE;i++)
    for(j=0;j<TSIZE;j++){
      c = (((i&0x4)==0)^((j&0x4)==0))*255;
      texture[i][j][0] = c;
      texture[i][j][1] = c;
      texture[i][j][2] = c;
      texture[i][j][3] = 255;
    }
}




/*----------------------------------------------------------
 * Procedure to initialize the working environment.
 */
void  myinit()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);      /*set the background color BLACK */
                   /*Clear the Depth & Color Buffers */
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

  glEnable(GL_DEPTH_TEST);  /*Enable depth buffer for shading computing */


  glViewport(0, 0, 499, 499);

  /*-----Create Texture, lower frequency, better filter. -----*/
  make_check();

  glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
  glGenTextures(2, textName);
  glBindTexture(GL_TEXTURE_2D, textName[0]);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TSIZE, TSIZE, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, checkboard);

  /*-----Create another texture, higher frequency with bad filter. ----*/
  make_texture();
  glBindTexture(GL_TEXTURE_2D, textName[1]);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TSIZE, TSIZE, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texture);

  /*---- Bind the check board texture.-----*/
  /*
  glEnable(GL_TEXTURE_2D);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  
  */
}


/*-------------------------------------------------------
 * Display and Idle callback func. This func. draws three
 * cubes at proper places to simulate a solar system.
 */
void display()
{
  int   i, j;

  /*Clear previous frame and the depth buffer */
  glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

  /*----Define the current eye position and the eye-coordinate system---*/
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glRotatef(head, 0.0, 1.0, 0.0);
  glRotatef(roll, 0.0, .0, 1.0);
  glRotatef(Epitch, 1.0, 0.0, 0.0);
  glTranslatef(0.0, up, 0.0);
  glTranslatef(-right, 0.0, 0.0);
  glTranslatef(0.0, 0.0, -zoom);
  /*----Define Viewing Matrix-----*/
  gluLookAt(0.0, 8.0, -50.0, 0.0, 0.0, 2.0, 0.0, 1.0, 0.0);
  
  /*-------Draw the floor ----*/
  glColor3f(.90, .90, .90);
  glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(-30, 0.0, -60);
      glTexCoord2f(1.0, 0.0); glVertex3f(30, 0.0, -60);
      glTexCoord2f(1.0, 1.0); glVertex3f(30, 0.0, 60);
      glTexCoord2f(0.0, 1.0); glVertex3f(-30, 0.0, 60.0);
  glEnd();

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
    gluPerspective(80, (double)h/(double)w, 1.0, 300.0);
  else
    gluPerspective(80, (double)w/(double)h, 1.0, 300.0);
}

/*--------------------------------------------------
 * Keyboard callback func. When a 'q' key is pressed,
 * the program is aborted.
 */
void key_func(unsigned char key, int x, int y)
{
  if(key=='Q'||key=='q') exit(0);

  /* Do something here */
  
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

  if(key=='1'){
    glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, textName[0]);
  }else if(key=='2'){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textName[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  }else if(key=='3'){
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textName[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
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

  glutInitWindowSize(500, 500);
  glutCreateWindow("cube");

  myinit();      /*---Initialize other state varibales----*/
  
  /*----Associate callback func's whith events------*/
  glutDisplayFunc(display);
  glutReshapeFunc(my_reshape);
  glutKeyboardFunc(key_func);

  glutMainLoop();
}

