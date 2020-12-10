/***********************************************************************
 * Sample Program for Homework Number 4.
 * Complete this program please.
 */
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>


#define   TSIZE  64   /* define texture dimension */
#define   ON      1
#define   OFF     0
/*-------Define a cube------*/
float  points[][3] = {{-1.0, 0.0, -1.0}, {1.0, 0.0, -1.0}, 
                      {1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0}, 
                      {-1.0, 0.0, 1.0}, {1.0, 0.0, 1.0},
                      {1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}};

int    face[][4] = {{0, 3, 2, 1}, {0, 1, 5, 4}, {1, 2, 6, 5}, 
                    {4, 5, 6, 7}, {2, 3, 7, 6}, {0, 4, 7, 3}};

int    cube[6] = {0, 1, 2, 3, 4, 5};
float  normal[][4] = {{0.0, 0.0, -1.0}, {0.0, -1.0, 0.0}, {1.0, 0.0, 0.0},
		      {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {-1.0, 0.0, 0.0}};

/*-------Material properties ------*/
float  mat_ambient[] = {0.8, 0.8, 0.8, 1.0};
float  mat_diffuse[] = {0.8, 0.8, 0.8, 1.0};
float  flr_diffuse[] = {0.1, 0.1, 0.7, 1.0};
float  mat_specular[] = {0.8, 0.8, 0.8, 1.0};
float  mat_shininess = 16.0;

float  lit_position[] = {8.0, 15.0, -2.0, 1.0};
float  lit_direction[] = {-1.0, -1.0, 1.0, 0.0};
float  lit_ambient[] = {0.3, 0.3, 0.3, 1.0};
float  lit_diffuse[] = {0.8, 0.8, 0.8, 1.0};
float  lit_specular[] = {0.9, 0.9, 0.9, 1.0};
float  lit_angle=0.0;
float  lit_cutoff=45.0;

float  cube_angle=0.0;
float  head=0.0, roll=0.0, Epitch=0.0, Wpitch=0.0;
float  up = 0.0, right = 0.0, zoom= 0.0;

/*-----Create image space for textures -----*/
unsigned char  checkboard[TSIZE][TSIZE][4];   /* checkboard textures */
unsigned char  brick[TSIZE][TSIZE][4];        /* brick wall textures */
unsigned int   textName[2];                   /* declare two texture maps*/

float    ds=0.0, dt=0.0;
//Texture mapping status
int status=ON;

/*----------------------------------------------------------
 * Procedure to make a checkboard texture.
 */
void make_check()
{
  int   i, j, c;

  for(i=0;i<TSIZE;i++)
    for(j=0;j<TSIZE;j++){
      c = (((i&0x8)==0)^((j&0x8)==0))*255;
      checkboard[i][j][0] = c;
      checkboard[i][j][1] = c;
      checkboard[i][j][2] = c;
      checkboard[i][j][3] = 255;
    }
}


/*----------------------------------------------------------
 * Procedure to maKe a brick wall texture map
 */
void brick_pattern()
{
  int  y, x, i;


  for(y=0;y<12;y++){    /*----Create the first row of bricks----*/
    for(x=0;x<2;x++){
      brick[y][x][0] = 140;
      brick[y][x][1] = 140;
      brick[y][x][2] = 140;
      brick[y][x][3] = 255;
    }

    for(x=2;x<30;x++){
      brick[y][x][0] = 200;
      brick[y][x][1] = 0;
      brick[y][x][2] = 0;
      brick[y][x][3] = 255;
    }

    for(x=30;x<34;x++){
      brick[y][x][0] = 140;
      brick[y][x][1] = 140;
      brick[y][x][2] = 140;
      brick[y][x][3] = 255;
    }

    for(x=34;x<62;x++){
      brick[y][x][0] = 200;
      brick[y][x][1] = 0;
      brick[y][x][2] = 0;
      brick[y][x][3] = 255;
    }

    for(x=62;x<64;x++){
      brick[y][x][0] = 140;
      brick[y][x][1] = 140;
      brick[y][x][2] = 140;
      brick[y][x][3] = 255;
    }
  }

  for(y=12;y<16;y++)     /*--Create the cement between two breick layers */
    for(x=0;x<64;x++){
      brick[y][x][0] = 140;
      brick[y][x][1] = 140;
      brick[y][x][2] = 140;
      brick[y][x][3] = 255;
    }

  for(y=16;y<28;y++){    /*--Create the 2nd layer of bricks---*/
    for(x=0;x<14;x++){
      brick[y][x][0] = 200;
      brick[y][x][1] = 0;
      brick[y][x][2] = 0;
      brick[y][x][3] = 255;
    }

    for(x=14;x<18;x++){
      brick[y][x][0] = 140;
      brick[y][x][1] = 140;
      brick[y][x][2] = 140;
      brick[y][x][3] = 255;
    }

    for(x=18;x<46;x++){
      brick[y][x][0] = 200;
      brick[y][x][1] = 0;
      brick[y][x][2] = 0;
      brick[y][x][3] = 255;
    }

    for(x=46;x<50;x++){
      brick[y][x][0] = 140;
      brick[y][x][1] = 140;
      brick[y][x][2] = 140;
      brick[y][x][3] = 255;
    }

    for(x=50;x<64;x++){      
      brick[y][x][0] = 200;
      brick[y][x][1] = 0;
      brick[y][x][2] = 0;
      brick[y][x][3] = 255;
    }
  }

  for(y=28;y<32;y++) /*---Add another layer of cement----*/
    for(x=0;x<64;x++){
      brick[y][x][0] = 140;
      brick[y][x][1] = 140;
      brick[y][x][2] = 140;
      brick[y][x][3] = 255;
    }
  
  for(y=32;y<64;y++)
    for(x=0;x<64;x++)
      for(i=0;i<4;i++) brick[y][x][i] = brick[y-32][x][i];
}


/*--------------------------------------------------------------------------------
 * Procedure to copy frambauffer image and load into a texture.
 */
void copy_framebuffer_texture(int texID, int xsize, int ysize)
{
	glReadBuffer(GL_FRONT);
	glBindTexture(GL_TEXTURE_2D, texID);
	glCopyTexImage2D(GL_TEXTURE_2D,
		                            0,
									GL_RGBA,
									50, 50,
									TSIZE, TSIZE,
									0);
}


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
  glEnable(GL_NORMALIZE);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, lit_position);
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lit_direction);
  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, lit_cutoff);
  glLightfv(GL_LIGHT0, GL_AMBIENT, lit_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lit_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lit_specular);

  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lit_ambient);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  glViewport(0, 0, 499, 499);

  /*-----Create Texture -----*/
  make_check();
  glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
  glGenTextures(2, textName);
  glBindTexture(GL_TEXTURE_2D, textName[0]);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TSIZE, TSIZE, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, checkboard);

  /*-----Create another texture ----*/
  brick_pattern();
  glBindTexture(GL_TEXTURE_2D, textName[1]);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, TSIZE, TSIZE, 0, GL_RGBA,
		GL_UNSIGNED_BYTE, brick);
  
}


/*--------------------------------------------------------
 * Procedure to draw the cube, whose vertices and faces
 * are defined above.
 */
void draw_cube()
{
  int    i;
  float  range;

  glMatrixMode(GL_TEXTURE);
  glLoadIdentity();
  glTranslatef(ds, dt, 0.0);
  glMatrixMode(GL_MODELVIEW);

  for(i=0;i<6;i++){     /* draw the six faces one by one */
    range = 1.0;
    glNormal3fv(normal[i]);
    glBegin(GL_POLYGON);  /* Draw the face */
      glTexCoord2f(0.0, 0.0); glVertex3fv(points[face[i][0]]);
      glTexCoord2f(0.0, range); glVertex3fv(points[face[i][1]]);
      glTexCoord2f(range, range); glVertex3fv(points[face[i][2]]);
      glTexCoord2f(range, 0.0); glVertex3fv(points[face[i][3]]);
    glEnd();
  }
}


/*-----------------------------------------------------
 * Draw a sphere
 */
void draw_cylinder()
{
  static GLUquadricObj  *cylind=NULL;

  if(cylind==NULL){
    cylind = gluNewQuadric();
    gluQuadricDrawStyle(cylind, GLU_FILL);
    gluQuadricNormals(cylind, GLU_SMOOTH);
  }

  gluQuadricTexture(cylind, GL_TRUE);  
  glPushMatrix();
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  gluCylinder(cylind, 1.0, 1.0, 8.0, 12, 3);
  glPopMatrix();
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
  gluLookAt(8.0, 8.0, 16.0, 8.0, 6.0, 2.0, 0.0, 1.0, 0.0);
  
  /*-------Rotate light position----*/
  glPushMatrix();
  glTranslatef(8.0, 0.0, 8.0);
  glRotatef(lit_angle, 0.0, 1.0, 0.0);

  glPushMatrix();
  glTranslatef(lit_position[0],lit_position[1],lit_position[2]);
  glScalef(0.5, 0.5, 0.5);
  glDisable(GL_LIGHTING);
  glColor3f(0.9, 0.9, 0.0);
  draw_cube();
  glPopMatrix();

  glEnable(GL_LIGHTING);
  glLightfv(GL_LIGHT0, GL_POSITION, lit_position);
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lit_direction);
  glPopMatrix();

  /*-------Draw the floor ----*/
  /*---Define material properties---*/
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, flr_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
  
  glDisable(GL_TEXTURE_2D);
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      glNormal3f(0.0, 1.0, 0.0);
      glBegin(GL_POLYGON);
      glVertex3f(i*4.0+0.0, 0.0, j*4.0+0.0);
      glVertex3f(i*4.0+0.0, 0.0, j*4.0+4.0);
      glVertex3f(i*4.0+4.0, 0.0, j*4.0+4.0);
      glVertex3f(i*4.0+4.0, 0.0, j*4.0+0.0);
      glEnd();
    }
  }

  //checking status to enable or disable texture mapping
 if(status==ON) glEnable(GL_TEXTURE_2D);
  else glDisable(GL_TEXTURE_2D);

  /*-------Draw the cube ----*/
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glBindTexture(GL_TEXTURE_2D, textName[0]);

  glPushMatrix();
  glTranslatef(4.0, 0.0, 4.0);
  glRotatef(cube_angle, 0.0, 1.0, 0.0);
  glScalef(3.0, 6.0, 3.0); /*set the metrics=6x6x6*/
  draw_cube();
  glPopMatrix();
 

  /*-----Draw a cylinder with brick texture ---*/
 
  glBindTexture(GL_TEXTURE_2D, textName[1]);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
  glPushMatrix();
  glTranslatef(10.0, 0.0, 8.0);
  glRotatef(cube_angle, 0.0, 1.0, 0.0);
  draw_cylinder();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);

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
    gluPerspective(80.0, (double)h/(double)w, 2.0, 30.0);
  else
    gluPerspective(80.0, (double)w/(double)h, 2.0, 30.0);
}

/*--------------------------------------------------
 * Keyboard callback func. When a 'q' key is pressed,
 * the program is aborted.
 */
void key_func(unsigned char key, int x, int y)
{
  if(key=='Q'||key=='q') exit(0);

  /* Do something here */
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

  if(key==' ') lit_angle += 10.0;

  if(key=='s'){
    ds += 0.1;
    if(ds>1.0) ds = ds - 1.0;
  }else if(key=='S'){
    ds -= 0.1;
    while(ds<0.0) ds += 1.0;
  }

  if(key=='t'){
    dt += 0.1;
    if(dt>1.0) dt = dt - 1.0;
  }else if(key=='T'){
    dt -= 0.1;
    while(dt<0.0) dt += 1.0;
  }
  if(key=='0'){
	 status = OFF;
  }else if(key=='1'){
	  status = ON;
  }
  if(key=='c'){
    copy_framebuffer_texture(textName[0], TSIZE, TSIZE);
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

