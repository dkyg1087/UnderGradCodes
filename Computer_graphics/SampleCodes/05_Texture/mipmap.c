/***********************************************************************
 * Sample Program formip-map texture mapping.
 */
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>


#define   SIZE0 256/* define texture dimension */
#define   SIZE1 128
#define   SIZE2   64
#define   SIZE3   32
#define   SIZE4   16
#define   SIZE5     8
#define   SIZE6     4
#define   SIZE7     2
#define   SIZE8     1


/*-----Create image space for textures -----*/
unsigned char  checkboard[SIZE0*SIZE0*4];   /* checkboard textures */
unsigned char  texture0[SIZE0*SIZE0*4];   /* checkboard textures */
unsigned char  texture1[SIZE1*SIZE1*4];   /* checkboard textures */
unsigned char  texture2[SIZE2*SIZE2*4];   /* checkboard textures */
unsigned char  texture3[SIZE3*SIZE3*4];   /* checkboard textures */
unsigned char  texture4[SIZE4*SIZE4*4];   /* checkboard textures */
unsigned char  texture5[SIZE5*SIZE5*4];   /* checkboard textures */
unsigned char  texture6[SIZE6*SIZE6*4];   /* checkboard textures */
unsigned char  texture7[SIZE7*SIZE7*4];   /* checkboard textures */
unsigned char  texture8[SIZE8*SIZE8*4];   /* checkboard textures */

unsigned int   textName[3];                   /* declare two texture maps*/

float    ds=0.0, dt=0.0;
float     head=0.0, up=0.0, roll=0.0, zoom=0.0,
          Epitch=0.0, right=0.0, left=0.0, Wpitch=0.0;
/*----------------------------------------------------------
 * Procedure to make a checkboard texture.
 */
void make_check(unsigned char check[], int size)
{
  int   i, j, c;

  for(i=0;i<size;i++)
    for(j=0;j<size;j++){
      if(size>127){
        c = (((i&0x10)==0)^((j&0x10)==0))*255;
      
      check[i*size*4 + j*4 + 0] = c;
      check[i*size*4 + j*4 + 1] = c;
      check[i*size*4 + j*4 + 2] = c;
      check[i*size*4 + j*4 + 3] = 255;
    }else{
      c =255;
      
      check[i*size*4 + j*4 + 0] = c;
      check[i*size*4 + j*4 + 1] = c;
      check[i*size*4 + j*4 + 2] = c;
      check[i*size*4 + j*4 + 3] = 255;
   }
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
  make_check(checkboard, SIZE0);
  //another texture
  make_check(texture0, SIZE0);
  make_check(texture1, SIZE1);
  make_check(texture2, SIZE2);
  make_check(texture3, SIZE3);
  make_check(texture4, SIZE4);
  make_check(texture5, SIZE5);
make_check(texture6, SIZE6);
make_check(texture7, SIZE7);
make_check(texture8, SIZE8);
  /*---- Bind the check board texture.-----*/
  glEnable(GL_TEXTURE_2D);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glGenTextures(2, textName);

//The ordinal texture map
  glBindTexture(GL_TEXTURE_2D, textName[0]);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//assign image data
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, SIZE0, SIZE0, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, checkboard);

  /*-----Create another texture, mipmap texture. ----*/
  glBindTexture(GL_TEXTURE_2D, textName[1]);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  // build our texture mipmaps
/*
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, SIZE0, SIZE0,
                       GL_RGBA, GL_UNSIGNED_BYTE, texture0 );
*/
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, SIZE0, SIZE0, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texture0);
  glTexImage2D(GL_TEXTURE_2D, 1, GL_RGBA, SIZE1, SIZE1, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texture1);
  glTexImage2D(GL_TEXTURE_2D, 2, GL_RGBA, SIZE2, SIZE2, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texture2);
  glTexImage2D(GL_TEXTURE_2D, 3, GL_RGBA, SIZE3, SIZE3, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texture3);
  glTexImage2D(GL_TEXTURE_2D, 4, GL_RGBA, SIZE4, SIZE4, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texture4);
  glTexImage2D(GL_TEXTURE_2D, 5, GL_RGBA, SIZE5, SIZE5, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texture5);
  glTexImage2D(GL_TEXTURE_2D, 6, GL_RGBA, SIZE6, SIZE6, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texture6);
  glTexImage2D(GL_TEXTURE_2D, 7, GL_RGBA, SIZE7, SIZE7, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texture7);
  glTexImage2D(GL_TEXTURE_2D, 8, GL_RGBA, SIZE8, SIZE8, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, texture8);
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
  gluLookAt(-10.0, 40.0, -100.0, -10.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  
  /*-------Draw the 1st floor ----*/
  glColor3f(.90, .90, .90);
  glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(-30, 0.0, -60);
      glTexCoord2f(3.0, 0.0); glVertex3f(30, 0.0, -60);
      glTexCoord2f(3.0, 3.0); glVertex3f(30, 0.0, 60);
      glTexCoord2f(0.0, 3.0); glVertex3f(-30, 0.0, 60.0);
  glEnd();
 /*-------Draw the 2nd floor ----*/
 glTranslatef(60.0, 0.0, 0.0);
  glColor3f(.90, 0, .90);
  glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(-30, 0.0, -60);
      glTexCoord2f(3.0, 0.0); glVertex3f(30, 0.0, -60);
      glTexCoord2f(3.0, 3.0); glVertex3f(30, 0.0, 60);
      glTexCoord2f(0.0, 3.0); glVertex3f(-30, 0.0, 60.0);
  glEnd();
 /*-------Draw the 3rd floor ----*/
glTranslatef(0.0, 0.0, 70.0);
 glColor3f(.90, .90, 0.0);
  glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(-30, 0.0, -60);
      glTexCoord2f(3.0, 0.0); glVertex3f(30, 0.0, -60);
      glTexCoord2f(3.0, 3.0); glVertex3f(30, 0.0, 60);
      glTexCoord2f(0.0, 3.0); glVertex3f(-30, 0.0, 60.0);
  glEnd();
 /*-------Draw the 4th floor ----*/
glTranslatef(-60.0, 0.0, 70.0);
  glColor3f(0.0, .90, .90);
  glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(-30, 0.0, -60);
      glTexCoord2f(3.0, 0.0); glVertex3f(30, 0.0, -60);
      glTexCoord2f(3.0, 3.0); glVertex3f(30, 0.0, 60);
      glTexCoord2f(0.0, 3.0); glVertex3f(-30, 0.0, 60.0);
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

 
  }else if(key=='3'){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textName[1]);
  }else if(key=='0'){
     glDisable(GL_TEXTURE_2D);
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

