#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define  PI   3.141592653
typedef enum {false, true} bool;
GLUquadricObj  *sphere=NULL, *cylind=NULL, *disk=NULL;
float cubePoint[][3]={{-0.5,0,-0.5},{-0.5,0,0.5},{0.5,0,0.5},{0.5,0,-0.5},{-0.5,1,-0.5},{-0.5,1,0.5},{0.5,1,0.5},{0.5,1,-0.5}};
float seaPoint[][3]={{-80,-80,-80},{-80,-80,80},{80,-80,80},{80,-80,-80},{-80,80,-80},{-80,80,80},{80,80,80},{80,80,-80}};
float bodyPoint[][3]={{-5.1,-6,-16},{-5.1,-6,0},{5.1,-6,0},{5.1,-6,-16},{-7.2,0,-18},{-7.2,0,0},{7.2,0,0},{7.2,0,-18}};
int cubeFace[][4]={{0,1,2,3},{5,1,2,6},{4,5,6,7},{6,2,3,7},{7,3,0,4},{4,0,1,5}};
float  colors[6][3]={{0.5,0.5,0.5}, {0.7,0.7,0.7}, {0.7,0.5,0.5},
                     {0.5,0.5,0.5}, {0.5,0.7,0.5}, {0.5,0.5,0.7}};
float crabPoint[5][2]={};
float grassPoint[30][3]={};
float armVerAngle=30.0,armHorAngle=0.0,leftBladeAngle=0.0,rightBladeAngle=0.0;
bool armControl = false; 
void drawSea(void);
void drawBody(void);
void drawCube(void);
void drawPropeller(char c);
void drawBlade(void);
void addAngle(int);
void draw_axes();
bool boundCheck();
void drawCrab(float,float);
float position[3]={0.0,-20.0,0.0},currentStep=0.5,self_ang=0.0;
int width=800, height=800;
float camVerAngle=230.0,camHorAngle=30.0;
float cpos[3]={12.0,10.0,12.0};
void displayFunction(){
    glClearColor(0.1,0.3,0.57,1.0);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(position[0]+1.0*cos(camHorAngle*PI/180)*sin(camVerAngle*PI/180),position[1]+1.0*sin(camHorAngle*PI/180),position[2]+1.0*cos(camHorAngle*PI/180)*cos(camVerAngle*PI/180),position[0],position[1],position[2], 0.0, 1.0, 0.0);
    drawCrab(0.0,0.0);
    
    for(int i=0;i<30;i++){
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(grassPoint[i][0],-80,grassPoint[i][2]);
        glRotatef(-90.0,1.0,0.0,0.0);
        gluCylinder(cylind,1.0,1.0,grassPoint[i][1],24,3);
        glPopMatrix();
    }
    glPushMatrix();
    for(int i=0;i<5;i++){
        drawCrab(crabPoint[i][0],crabPoint[i][1]);
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-80,-80,-80);
    draw_axes();
    glPopMatrix();
    drawSea();
    glTranslatef(position[0], position[1], position[2]); 
    glRotatef(self_ang, 0.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(-90.0,1.0,0.0,0.0);
    glScalef(6.0,6.0,6.0);
    glTranslatef(0,0,0.01);
    glColor3f(1.0,0.0,1.0);
    gluCylinder(cylind,0.85,1.2,0.97,24,3);
    glColor3f(1.0,1.0,0.0);
    gluDisk(disk,0.0,0.85,24,3);
    glTranslatef(0.0,0.0,0.97);
    glColor3f(1.0,1.0,0.0);
    gluDisk(disk,0.0,1.2,24,3);
    glPopMatrix();
    //body
    glPushMatrix();
    glTranslatef(0.0,6.0,0.0);
    drawBody();
    glTranslatef(0,0,3.6);
    glRotatef(-90.0,1.0,0.0,0.0);
    glColor3f(0.75,0.75,0.75);
    gluCylinder(cylind,1.0,0.5,1.0,24,3);
    glRotatef(90,1.0,0.0,0.0);
    glTranslatef(0.0,2.0,-1.8);
    glColor3f(0.25,0.25,0.25);
    gluCylinder(cylind,1.0,1.0,3.6,24,3);
    glPopMatrix();
    
    //arm
    glPushMatrix();
    glColor3f(0,1.0,1.0);
    gluSphere(sphere,1.5,12,12);
    glColor3f(0.5,0.5,0.5);
    glRotatef(armHorAngle,0.0,1.0,0.0);
    glRotatef(armVerAngle,1.0,0.0,0.0);
    glTranslatef(0.0,0.0,1.5);
    gluCylinder(cylind,0.7,0.7,4.0,24,3);
    glColor3f(0.75,0.5,0.5);
    glTranslatef(0,0,4.0);
    gluCylinder(cylind,0.7,1.6,1.0,24,3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,6.0,-16.0);
    glRotatef(-120.0,1.0,0.0,0.0);
    glScalef(5.0,0.2,4.0);
    drawCube();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0,6.0,-16.0);
    glRotatef(-90.0,1.0,0.0,0.0);
    glTranslatef(0.0,cos(30.0)*2.0,2.0);
    glScalef(20.0,2.0,0.3);
    drawCube();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(3.6,3,-17);
    glRotatef(180.0,0.0,1.0,0.0);
    glScalef(0.4,0.4,0.4);
    drawPropeller('l');
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.6,3,-17);
    glRotatef(180.0,0.0,1.0,0.0);
    glScalef(0.4,0.4,0.4);
    drawPropeller('r');
    glPopMatrix();
    /*TODO the main thing.*/
    glutSwapBuffers();
    glFlush();
    return;
}
void drawCrab(float x,float z){
    srand(time(NULL));
    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(x,-80,z);
    glScalef(4.0,1.0,4.0);
    drawCube();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(x,-80,z);
    glTranslatef(2,0.5,-2);
    glScalef(3.0,0.3,0.5);
    drawCube();
    glTranslatef(0.0,0.0,2);
    drawCube();
    glTranslatef(0.0,0.0,2);
    drawCube();
    glTranslatef(0.0,0.0,2);
    drawCube();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(x,-80,z);
    glTranslatef(-2,0.5,-2);
    glScalef(3.0,0.3,0.5);
    drawCube();
    glTranslatef(0.0,0.0,2);
    drawCube();
    glTranslatef(0.0,0.0,2);
    drawCube();
    glTranslatef(0.0,0.0,2);
    drawCube();
    glPopMatrix();
}
void mouseFunction(int button,int state,int x,int y){
    if(state==GLUT_DOWN){
        if(button==GLUT_RIGHT_BUTTON)armControl=!armControl;
    }
}
void keyboardFunction(unsigned char key, int x, int y){
    if(key==27)exit(0);
    else if(key=='i'){
            camHorAngle+=1.0;
            if(camHorAngle >=360)camHorAngle-=360;
        }
        else if(key=='k'){
            camHorAngle-=1.0;
            if(camHorAngle<0)camHorAngle+=360;
        }
        else if(key=='l'){
            camVerAngle+=1.0;
            if(camVerAngle >=360)camVerAngle-=360;
        }
        else if(key=='j'){
            camVerAngle-=1.0;
            if(camVerAngle<0)camVerAngle+=360;
        }
        else if(key=='t'){
            currentStep+=1.0;
            if(currentStep>=10.0){
                currentStep-=1.0;
            }
        }
        else if(key=='g'){
            currentStep-=1.0;
            if(currentStep<0.0){
                currentStep+=1.0;
            }
        }
    if(armControl){
        if(key=='w'){
            if(armVerAngle!=30.0)armVerAngle-=5.0;
        }
        else if(key=='s'){
            if(armVerAngle!=150.0)armVerAngle+=5.0;
        }
        else if(key=='a'){
            if(armHorAngle==0.0)armHorAngle=360.0;
            armHorAngle-=5.0;
        }
        else if(key=='d'){
            if(armHorAngle==360.0)armHorAngle=0.0;
            armHorAngle+=5.0;
        }
    }
    else{
        if(key=='a'){
            position[0] += currentStep*cos(self_ang*PI/180.0);
            position[2] -= currentStep*sin(self_ang*PI/180.0);
            if(!boundCheck()){
                position[0] += currentStep*cos(self_ang*PI/180.0);
                position[2] -= currentStep*sin(self_ang*PI/180.0);
            }
        }
        else if(key=='d'){
            position[0] -= currentStep*cos(self_ang*PI/180.0);
            position[2] += currentStep*sin(self_ang*PI/180.0);
            if(!boundCheck()){
                position[0] -= currentStep*cos(self_ang*PI/180.0);
                position[2] += currentStep*sin(self_ang*PI/180.0);
            }
        }
        else if(key=='s'){
            addAngle(90);
            position[0] += currentStep*cos(self_ang*PI/180.0);
            position[2] -= currentStep*sin(self_ang*PI/180.0);
            if(!boundCheck()){
                position[0] -= currentStep*cos(self_ang*PI/180.0);
                position[2] += currentStep*sin(self_ang*PI/180.0);
            }
            addAngle(-90);
        }
        else if(key=='w'){
            addAngle(90);
            position[0] -= currentStep*cos(self_ang*PI/180.0);
            position[2] += currentStep*sin(self_ang*PI/180.0);
            if(!boundCheck()){
                position[0] += currentStep*cos(self_ang*PI/180.0);
                position[2] -= currentStep*sin(self_ang*PI/180.0);
            }
            addAngle(-90);
            leftBladeAngle+=30.0;
            if(leftBladeAngle>=360.0)leftBladeAngle-=360.0;
            rightBladeAngle+=30.0;
            if(rightBladeAngle>=360.0)rightBladeAngle-=360.0;
        }
        else if(key=='q'){
            addAngle(3);
            rightBladeAngle+=30.0;
            if(rightBladeAngle>=360.0)rightBladeAngle-=360.0;
        }
        else if(key=='e'){
            addAngle(-3);
            leftBladeAngle+=30.0;
            if(leftBladeAngle>=360.0)leftBladeAngle-=360.0;
        }
        else if(key=='r'){
            position[1]+=1.0;
            if(position[1]>10.0)position[1]=10.0;
            
        }
        else if(key=='f'){
            position[1]-=1.0;
            if(position[1]<-70.0)position[1]=-70.0;
        }
    }
    displayFunction();
    return;
}
void addAngle(int amount){
    self_ang+=amount;
    if(self_ang>=360.0){
        self_ang-=360.0;
    }
    else if(self_ang<0.0){
        self_ang+=360.0;
    }
}
void drawBlade()
{
  glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 4.0, 0.0);
    glVertex3f(1.0, 8.0, 0.0);
    glVertex3f(-1.0, 8.0, 0.0);
    glVertex3f(-1.0, 4.0, 0.0);
  glEnd();
}
void drawPropeller(char c){
    glPushMatrix();
    glColor3f(0.68, 0.68, 0.68);
    gluCylinder(cylind,1.0,1.0,3.5,12,3);
    glTranslatef(0,0,4.0);
    glColor3f(0.2, 0.2, 0.95);
    gluSphere(sphere,1.5,12,12);
    glColor3f(1.0,1.0,1.0);
    glRotatef(c=='l'?leftBladeAngle:rightBladeAngle,0.0,0.0,1.0);
    drawBlade();
    glRotatef(120.0, 0.0, 0.0, 1.0);
    drawBlade();
    glRotatef(120.0, 0.0, 0.0, 1.0); 
    drawBlade();
    glPopMatrix();
}
void drawCube(){
    for(int i=0;i<6;i++){
        glColor3fv(colors[i]);
        glBegin(GL_POLYGON);
            glVertex3fv(cubePoint[cubeFace[i][0]]);
            glVertex3fv(cubePoint[cubeFace[i][1]]);
            glVertex3fv(cubePoint[cubeFace[i][2]]);
            glVertex3fv(cubePoint[cubeFace[i][3]]);
        glEnd();
    }
}
void drawBody(){
    for(int i=0;i<6;i++){
        glColor3fv(colors[i]);
        glBegin(GL_POLYGON);
            glVertex3fv(bodyPoint[cubeFace[i][0]]);
            glVertex3fv(bodyPoint[cubeFace[i][1]]);
            glVertex3fv(bodyPoint[cubeFace[i][2]]);
            glVertex3fv(bodyPoint[cubeFace[i][3]]);
        glEnd();
    }
}
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
	      160.0,              /* height of the cylinder */
              12,               /* use 12-side polygon approximating circle*/
	      3);               /* Divide it into 3 sections */
  
  /* Draw Y axis */
  glPushMatrix();
  glRotatef(-90.0, 1.0, 0.0, 0.0);  /*Rotate about x by -90', z becomes y */
  glColor3f(0.95, 0.0, 0.95);
  gluCylinder(cylind, 0.5, 0.5, /* radius of top and bottom circle */
	      160.0,             /* height of the cylinder */
              12,               /* use 12-side polygon approximating circle*/
	      3);               /* Divide it into 3 sections */
  glPopMatrix();

  /* Draw X axis */
  glColor3f(0.95, 0.95, 0.0);
  glPushMatrix();
  glRotatef(90.0, 0.0, 1.0, 0.0);  /*Rotate about y  by 90', x becomes z */
  gluCylinder(cylind, 0.5, 0.5,   /* radius of top and bottom circle */
	      160.0,             /* height of the cylinder */
              12,               /* use 12-side polygon approximating circle*/
	      3);               /* Divide it into 3 sections */
  glPopMatrix();
  /*-- Restore the original modelview matrix --*/
  glPopMatrix();
}
void drawSea(){
    for(int i=0;i<1;i++){
        glColor3f(0.25,0.41,0.88);
        glBegin(GL_POLYGON);
            glVertex3fv(seaPoint[cubeFace[i][0]]);
            glVertex3fv(seaPoint[cubeFace[i][1]]);
            glVertex3fv(seaPoint[cubeFace[i][2]]);
            glVertex3fv(seaPoint[cubeFace[i][3]]);
        glEnd();
    }
    glColor3f(1.0,1.0,0.0);
    for(int i=-80;i<=80;i+=10){
        glBegin(GL_LINES);
            glVertex3f(i,-79.9,80);
            glVertex3f(i,-79.9,-80);
        glEnd();
    }
    for(int i=-80;i<=80;i+=10){
        glBegin(GL_LINES);
            glVertex3f(80,-79.9,i);
            glVertex3f(-80,-79.9,i);
        glEnd();
    }
}
bool boundCheck(){
    if(position[0]<=-80)return false;
    if(position[0]>=80)return false;
    if(position[2]<=-80)return false;
    if(position[2]>=80)return false;
}
void reshapeFunction(int w,int h){
    width = w;
    height = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w>h)
        glOrtho(-40.0, 40.0, -40.0*(float)h/(float)w, 40.0*(float)h/(float)w, 
             -100.0, 100.0);
    else
        glOrtho(-40.0*(float)w/(float)h, 40.0*(float)w/(float)h, -40.0, 40.0, 
            -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void initFunction(){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
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
}
void idleFunction(){
    leftBladeAngle+=0.3;
    if(leftBladeAngle>=360.0)leftBladeAngle-=360.0;
    rightBladeAngle+=0.3;
    if(rightBladeAngle>=360.0)rightBladeAngle-=360.0;
    displayFunction();
}
void main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(width,height);
    glutCreateWindow("ROV");
    initFunction();
    glutDisplayFunc(displayFunction);
    glutReshapeFunc(reshapeFunction);
    glutKeyboardFunc(keyboardFunction);
    glutMouseFunc(mouseFunction);
    glutIdleFunc(idleFunction);
    srand(time(NULL));
    for(int i=0;i<5;i++){
        crabPoint[i][0]=(rand()%150)-75;
        crabPoint[i][1]=(rand()%150)-75;
    }
    for(int i=0;i<30;i++){
        grassPoint[i][0]=(rand()%150)-75;
        grassPoint[i][1]=rand()%50;
        grassPoint[i][2]=(rand()%150)-75;
    }
    glutMainLoop();
}