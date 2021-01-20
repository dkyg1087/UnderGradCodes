#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define  PI   3.141592653
typedef enum {false, true} bool;
GLUquadricObj  *sphere=NULL, *cylind=NULL, *disk=NULL;
float cubePoint[][3]={{-0.5, 0.0, -0.5}, {0.5, 0.0, -0.5}, 
                      {0.5, 1.0, -0.5}, {-0.5, 1.0, -0.5}, 
                      {-0.5, 0.0, 0.5}, {0.5, 0.0, 0.5},
                      {0.5, 1.0, 0.5}, {-0.5, 1.0, 0.5}};
float seaPoint[][3]={{-60,-60,-60},{-60,-60,60},{60,-60,60},{60,-60,-60},{-60,60,-60},{-60,60,60},{60,60,60},{60,60,-60}};
float bodyPoint[][3]={{-5.1,-6,-16},{5.1,-6,-16},
                      {7.2,0,-18},{-7.2,0,-18},
                      {-5.1,-6,0},{5.1,-6,0},
                      {7.2,0,0},{-7.2,0,0}};
int cubeFace[][4]={{0, 3, 2, 1}, {0, 1, 5, 4}, {1, 2, 6, 5}, 
                    {4, 5, 6, 7}, {2, 3, 7, 6}, {0, 4, 7, 3}};
float  colors[6][3]={{0.5,0.5,0.5}, {0.7,0.7,0.7}, {0.7,0.5,0.5},
                     {0.5,0.5,0.5}, {0.5,0.7,0.5}, {0.5,0.5,0.7}};
float crabPoint[5][2]={};
float grassPoint[30][3]={};
float perPoint[8][3]={};
float frustumVar[6]={-18,18,-18,18,30,60};
float armVerAngle=30.0,armHorAngle=0.0,leftBladeAngle=0.0,rightBladeAngle=0.0;
bool armControl = false,showLife = false; 
void drawSea(void);
void drawBody(void);
void drawCube(void);
void drawPropeller(char c);
void drawBlade(void);
void addAngle(int);
void draw_axes();
void drawRov();
void drawLife();
bool boundCheck();
void drawCrab(float,float);
void drawEverything();
void setPerspective(float);
void drawViewVol();
void drawLights();
void drawPlastic();
float viewSize=0;
float position[3]={0.0,-30.0,0.0},currentStep=0.5,self_ang=0.0;
int width=800, height=800;
float camVerAngle=230.0,camHorAngle=30.0,tempX=0,tempZ=0,eyeX,eyeZ;
float cpos[3]={12.0,10.0,12.0};
float eye[3]={};
int viewMode=1;
float zoomSize=0;
int testA=5,testB=100;
/*NEW START */
float  global_ambient[]={0.2, 0.2, 0.2, 1.0};
float  mat_ambient[] = {0.1, 0.3, 0.1, 1.0};
float  mat_diffuse[] = {0.3, 0.3, 0.3, 1.0};
float  mat_specular[] = {0.4, 0.4, 0.4, 0.3};
float  mat_shininess = 64.0;
float  normal[][4] = {{0.0, 0.0, -1.0}, {0.0, -1.0, 0.0}, {1.0, 0.0, 0.0},
		      {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {-1.0, 0.0, 0.0}};
float  flr_diffuse[] = {0.25, 0.41, 0.88, 1.0};
float  flr_ambient[]={0.3, 0.3, 0.3, 1.0};
float  flr_specular[] = {0.0, 0.0, 0.0, 0.0};
float  lit_position[] = {10.0, 14.0, 0.0, 1.0};
float  lit_direction[] = {-1.0, -1.0, 1.0, 0.0};
float  lit_diffuse[] = {1.0, 1.0, 1.0, 1.0};
float  lit_specular[] = {0.7, 0.7, 0.7, 1.0};
float  lit_cutoff=60.0;
float  lit_exponent=0.0;

float  lit1_position[] = {-0.5, 1.0, -2.0, 1.0};
float  lit1_diffuse[] = {1.0, 1.0, 1.0, 1.0};
float  light_emission[] = {0.2, 0.2, 0.2,1.0};
float  directional_light_dir[]={0.0,1.0,0.0,0.0};
float  fixed_light_pos[]={-30,-10,-30,1};
float fixed_light_angle=0.0;
float fixed_light_diffuse[]={1.0, 1.0, 1.0, 1.0};
bool  light1=true,light0=true,light2=true;
bool shading=true;
float spotlight_angle=0.0;
/*NEW END */
void displayFunction(){
    glClearColor(0.1,0.3,0.68,1.0);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    switch(viewMode){
        case 1:
            gluLookAt(60,0,0,-60,0,0,0,1,0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-60+zoomSize,60-zoomSize,-60+zoomSize,60-zoomSize,-100,300);
            glMatrixMode(GL_MODELVIEW);
            glViewport(0,0,width,height);
            drawEverything();
            break;
        case 2:
            gluLookAt(0,30,0,0,-60,0,1,0,0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-60+zoomSize,60-zoomSize,-60+zoomSize,60-zoomSize,-100,300);
            glMatrixMode(GL_MODELVIEW);
            glViewport(0,0,width,height);
            drawEverything();
            break;
        case 3:
            gluLookAt(0,0,60,0,0,-60,0,1,0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-60+zoomSize,60-zoomSize,-60+zoomSize,60-zoomSize,-100,300);
            glMatrixMode(GL_MODELVIEW);
            glViewport(0,0,width,height);
            drawEverything();
            break;
        case 4:
            eyeX=5.4*sin(self_ang*PI/180.0);
            eyeZ=5.4*cos(self_ang*PI/180.0);
            tempX=6.4*sin(self_ang*PI/180.0);
            tempZ=6.4*cos(self_ang*PI/180.0);
            gluLookAt(position[0]+eyeX, position[1]+8.0,position[2]+eyeZ,position[0]+tempX,position[1]+8.0,position[2]+tempZ,0,1,0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glFrustum(frustumVar[0],frustumVar[1],frustumVar[2],frustumVar[3],frustumVar[4],frustumVar[5]);
            glMatrixMode(GL_MODELVIEW);
            drawEverything();
            break;
        case 5:
            gluLookAt(60,0,0,-60,0,0,0,1,0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-62,62,-62,62,-100,300);
            glMatrixMode(GL_MODELVIEW);
            glViewport(0, height/2, width/2, height/2);
            drawEverything();

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(0,30,0,0,-60,0,1,0,0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-62,62,-62,62,-100,300);
            glMatrixMode(GL_MODELVIEW);
            glViewport(width/2, 0, width/2, height/2);
            drawEverything();

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(0,0,60,0,0,-60,0,1,0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-62,62,-62,62,-100,300);
            glMatrixMode(GL_MODELVIEW);
            glViewport(width/2, height/2, width/2, height/2);
            drawEverything();

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eyeX=5.4*sin(self_ang*PI/180.0);
            eyeZ=5.4*cos(self_ang*PI/180.0);
            tempX=6.4*sin(self_ang*PI/180.0);
            tempZ=6.4*cos(self_ang*PI/180.0);
            gluLookAt(position[0]+eyeX, position[1]+8.0,position[2]+eyeZ,position[0]+tempX,position[1]+8.0,position[2]+tempZ,0,1,0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glFrustum(frustumVar[0],frustumVar[1],frustumVar[2],frustumVar[3],frustumVar[4],frustumVar[5]);
            glMatrixMode(GL_MODELVIEW);
            glViewport(0, 0, width/2, height/2);
            drawEverything();
            
            break;
        case 6:
            gluLookAt(position[0]+20.0*cos(camHorAngle*PI/180)*sin(camVerAngle*PI/180),position[1]+20.0*sin(camHorAngle*PI/180),position[2]+20.0*cos(camHorAngle*PI/180)*cos(camVerAngle*PI/180),position[0],position[1],position[2], 0.0, 1.0, 0.0);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-60,60,-60,60,-100,300);
            glMatrixMode(GL_MODELVIEW);
            glViewport(0,0,width,height);
            drawEverything();
            break;
    }
    glutSwapBuffers();
    glFlush();
    return;
}
void setPerspective(float x){
    frustumVar[0]+=x;
    frustumVar[1]-=x;
    frustumVar[2]+=x;
    frustumVar[3]-=x;
    perPoint[0][0]=frustumVar[0];
    perPoint[0][1]=frustumVar[3];
    perPoint[1][0]=frustumVar[0];
    perPoint[1][1]=frustumVar[2];
    perPoint[2][0]=frustumVar[1];
    perPoint[2][1]=frustumVar[2];
    perPoint[3][0]=frustumVar[1];
    perPoint[3][1]=frustumVar[3];
    for(int i=0;i<4;i++){
        perPoint[i][2]=frustumVar[4];
    }
    for(int i=4;i<8;i++){
        perPoint[i][0]=perPoint[i-4][0]*frustumVar[5]/frustumVar[4];
        perPoint[i][2]=frustumVar[5];
        perPoint[i][1]=perPoint[i-4][1]*frustumVar[5]/frustumVar[4];
    }
}
void drawEverything(){
    drawPlastic();
    drawLights();
    drawSea();
    drawLife();
    drawRov();
}
void drawPlastic(){
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS,16.0);
    glPushMatrix();
    float temp[]={1.0,0.0,0.0,1.0};
    glTranslatef(-30,-60,-30);
    glScalef(10.0,5.0,15.0);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,temp);
    drawCube();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(10.0,-60.0,-30.0);
    glScalef(10.0,5.0,15.0);
    float temp1[]={0.0,1.0,0.0,1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE,temp1);
    drawCube();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-50.0,-60.0,10.0);
    glScalef(15.0,5.0,15.0);
    float temp2[]={0.0,0.0,1.0,1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE,temp2);
    drawCube();
    glPopMatrix();
    
}
void drawLife(){
    if(showLife){
        for(int i=0;i<30;i++){
        glPushMatrix();
        //glColor3f(0.0,1.0,0.0);
        float grassDiffuse[]={0.2,0.67,0.1,1.0};
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, grassDiffuse);
        glMaterialf(GL_FRONT, GL_SHININESS,7.0);
        glTranslatef(grassPoint[i][0],-60,grassPoint[i][2]);
        glRotatef(-90.0,1.0,0.0,0.0);
        gluCylinder(cylind,1.0,1.0,grassPoint[i][1],24,3);
        glTranslatef(0.0,0.0,grassPoint[i][1]);
        gluDisk(disk,0.0,1.0,24,3);
        glPopMatrix();
        }
        glPushMatrix();
        for(int i=0;i<5;i++){
            drawCrab(crabPoint[i][0],crabPoint[i][1]);
        }
        glPopMatrix();
    }
    return;
}
void drawCrab(float x,float z){
    srand(time(NULL));
    glPushMatrix();
    //glColor3f(1.0,1.0,0.0);
    glTranslatef(x,-60,z);
    glScalef(4.0,1.0,4.0);
    drawCube();
    glPopMatrix();
    
    glPushMatrix();
    //glColor3f(1.0,1.0,0.0);
    glTranslatef(x,-60,z);
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
    //glColor3f(1.0,1.0,0.0);
    glTranslatef(x,-60,z);
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
        if(button==GLUT_LEFT_BUTTON){
            viewMode+=1;
            if(viewMode==7)viewMode=1;
        }
        if(button==3){
            if(viewMode==5||viewMode==4||viewMode==6){
                setPerspective(1.0);
            }
            else{
                zoomSize+=1.0;
            }
        }
        if(button==4){
            if(viewMode==5||viewMode==4||viewMode==6){
                setPerspective(-1.0);
            }
            else{
                zoomSize-=1.0;
            }
        }
    }
}
void keyboardFunction(unsigned char key, int x, int y){
    if(key==27)exit(0);
    else if(key=='0'){
        spotlight_angle+=10.0;
    }
    else if(key==')'){
        spotlight_angle-=10.0;
    }
    else if(key=='='){
        lit_exponent+=0.5;
        if(lit_exponent>5.0)lit_exponent=5.0;
        glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, lit_exponent);
    }
    else if(key=='+'){
        lit_exponent-=0.5;
        if(lit_exponent<-5.0)lit_exponent=-5.0;
        glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, lit_exponent);
    }
    else if(key=='-'){
        lit_cutoff+=5.0;
        if(lit_cutoff>90.0)lit_cutoff=90.0;
        glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, lit_cutoff);
    }
    else if(key=='_'){
        lit_cutoff-=5.0;
        if(lit_cutoff<15.0)lit_cutoff=15.0;
        glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, lit_cutoff);
    }
    else if(key==' '){
        fixed_light_angle+=5.0;
    }
    else if(key ==','){
        if(light0)glDisable(GL_LIGHT0);
        else glEnable(GL_LIGHT0);
        light0=!light0;
    }
    else if(key =='.'){
        if(light1)glDisable(GL_LIGHT1);
        else glEnable(GL_LIGHT1);
        light1=!light1;
    }
    else if(key=='/'){
        if(light2)glDisable(GL_LIGHT2);
        else glEnable(GL_LIGHT2);
        light2=!light2;
    }
    else if(key=='m'){
        if(directional_light_dir[2]==1.0){
            directional_light_dir[2]=0.0;
            directional_light_dir[1]=1.0;
        }
        else if(directional_light_dir[1]==1.0){
            directional_light_dir[1]=0.0;
            directional_light_dir[0]=1.0;
        }
        else if(directional_light_dir[0]==1.0){
            directional_light_dir[0]=0.0;
            directional_light_dir[2]=1.0;
        }
    }
    else if(key=='n'){
        if(fixed_light_diffuse[0]==1.0&&fixed_light_diffuse[1]==1.0){
            fixed_light_diffuse[1]=0.0;
            fixed_light_diffuse[2]=0.0;
        }
        else if(fixed_light_diffuse[0]==1.0){
            fixed_light_diffuse[0]=0.0;
            fixed_light_diffuse[1]=1.0;
        }
        else if(fixed_light_diffuse[1]==1.0){
            fixed_light_diffuse[1]=0.0;
            fixed_light_diffuse[2]=1.0;
        }
        else{
            fixed_light_diffuse[0]=1.0;
            fixed_light_diffuse[1]=1.0;
            fixed_light_diffuse[2]=1.0;
        }
        glLightfv(GL_LIGHT1, GL_DIFFUSE, fixed_light_diffuse);
    }
    else if(key=='x'){
        if(shading){
            glShadeModel(GL_SMOOTH);
        }
        else{
            glShadeModel(GL_FLAT);
        }
        shading=!shading;
    }
    else if(key=='i'&&viewMode==6){
            camHorAngle+=1.0;
            if(camHorAngle >=360)camHorAngle-=360;
        }
        else if(key=='k'&&viewMode==6){
            camHorAngle-=1.0;
            if(camHorAngle<0)camHorAngle+=360;
        }
        else if(key=='l'&&viewMode==6){
            camVerAngle+=1.0;
            if(camVerAngle >=360)camVerAngle-=360;
        }
        else if(key=='j'&&viewMode==6){
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
        else if(key=='z'){
            showLife=!showLife;
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
            if(position[1]<-50.0)position[1]=-50.0;
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
    glPushMatrix();
    for(int i=0;i<6;i++){
        glColor3fv(colors[i]);
        glNormal3fv(normal[i]);
        glBegin(GL_POLYGON);
            glVertex3fv(cubePoint[cubeFace[i][0]]);
            glVertex3fv(cubePoint[cubeFace[i][1]]);
            glVertex3fv(cubePoint[cubeFace[i][2]]);
            glVertex3fv(cubePoint[cubeFace[i][3]]);
        glEnd();
    }
    glPopMatrix();
}
void drawBody(){
    for(int i=0;i<6;i++){
        glNormal3fv(normal[i]);
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
	      120.0,              /* height of the cylinder */
              12,               /* use 12-side polygon approximating circle*/
	      3);               /* Divide it into 3 sections */
  
  /* Draw Y axis */
  glPushMatrix();
  glRotatef(-90.0, 1.0, 0.0, 0.0);  /*Rotate about x by -90', z becomes y */
  glColor3f(0.95, 0.0, 0.95);
  gluCylinder(cylind, 0.5, 0.5, /* radius of top and bottom circle */
	      120.0,             /* height of the cylinder */
              12,               /* use 12-side polygon approximating circle*/
	      3);               /* Divide it into 3 sections */
  glPopMatrix();

  /* Draw X axis */
  glColor3f(0.95, 0.95, 0.0);
  glPushMatrix();
  glRotatef(90.0, 0.0, 1.0, 0.0);  /*Rotate about y  by 90', x becomes z */
  gluCylinder(cylind, 0.5, 0.5,   /* radius of top and bottom circle */
	      120.0,             /* height of the cylinder */
              12,               /* use 12-side polygon approximating circle*/
	      3);               /* Divide it into 3 sections */
  glPopMatrix();
  /*-- Restore the original modelview matrix --*/
  glPopMatrix();
}
void drawSea(){
    glPushMatrix();
    glTranslatef(-60,-60,-60);
    glDisable(GL_LIGHTING);
    draw_axes();
    glEnable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, flr_diffuse);  /*diffuse color */
    glMaterialfv(GL_FRONT, GL_AMBIENT, flr_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, flr_specular);
    glNormal3f(0.0, 1.0, 0.0);
    for(int i=0;i<1;i++){
        glBegin(GL_POLYGON);
            glVertex3fv(seaPoint[cubeFace[i][0]]);
            glVertex3fv(seaPoint[cubeFace[i][1]]);
            glVertex3fv(seaPoint[cubeFace[i][2]]);
            glVertex3fv(seaPoint[cubeFace[i][3]]);
        glEnd();
    }
    float test[]={1.0,1.0,0.0,1.0};
    glMaterialfv(GL_FRONT,GL_DIFFUSE,test);
    for(int i=-60;i<=60;i+=10){
        glBegin(GL_LINES);
            glVertex3f(i,-59.9,60);
            glVertex3f(i,-59.9,-60);
        glEnd();
    }
    for(int i=-60;i<=60;i+=10){
        glBegin(GL_LINES);
            glVertex3f(60,-59.9,i);
            glVertex3f(-60,-59.9,i);
        glEnd();
    }
    glPopMatrix();
}
bool boundCheck(){
    if(position[0]<=-60)return false;
    if(position[0]>=60)return false;
    if(position[2]<=-60)return false;
    if(position[2]>=60)return false;
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
void drawLights(){
    eyeX=3.4*sin(self_ang*PI/180.0);
    eyeZ=3.4*cos(self_ang*PI/180.0);
    float temp[]={position[0]+eyeX,position[1]+10.0,position[2]+eyeZ,1};
    glLightfv(GL_LIGHT0,GL_POSITION,temp);
    float temp2[]={sin((self_ang+spotlight_angle)*PI/180.0),-cos(60.0*PI/180.0),cos((self_ang+spotlight_angle)*PI/180.0)};
    glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,temp2);
    glPushMatrix();
    glDisable(GL_LIGHTING);
    fixed_light_pos[0]=40.0*cos(fixed_light_angle*PI/180.0);
    fixed_light_pos[2]=40.0*sin(fixed_light_angle*PI/180.0);
    glTranslatef(fixed_light_pos[0],fixed_light_pos[1],fixed_light_pos[2]);
    if(light1){
        glColor3f(1,1,1);
    }
    else glColor3f(0,0,0);
    gluSphere(sphere,1,12,12);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    glLightfv(GL_LIGHT1,GL_POSITION,fixed_light_pos);

    glLightfv(GL_LIGHT2,GL_POSITION,directional_light_dir);
}
void initFunction(){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    /* NEW START */
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
      /*-----Define light0 (spotlight)---------*/
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, lit_cutoff);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lit_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lit_specular);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, lit_exponent);

    /*-----Define light1 (fixed point light)---------*/
    glLightfv(GL_LIGHT1, GL_DIFFUSE, fixed_light_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lit_specular);
    
    /*-----Define Light2 (directional Light)---------*/
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lit1_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, lit_specular);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    /* NEW END */
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
    setPerspective(0);
}
void drawLines(){
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3fv(perPoint[0]);
    glVertex3fv(perPoint[1]);
    glVertex3fv(perPoint[2]);
    glVertex3fv(perPoint[3]);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3fv(perPoint[4]);
    glVertex3fv(perPoint[5]);
    glVertex3fv(perPoint[6]);
    glVertex3fv(perPoint[7]);
    glEnd();
    for(int i=4;i<8;i++){
        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3fv(perPoint[i]);
        glEnd();
    }
}
void idleFunction(){
    leftBladeAngle+=0.3;
    if(leftBladeAngle>=360.0)leftBladeAngle-=360.0;
    rightBladeAngle+=0.3;
    if(rightBladeAngle>=360.0)rightBladeAngle-=360.0;
    displayFunction();
}
void drawRov(){
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
    glTranslatef(position[0], position[1], position[2]); 
    
    glRotatef(self_ang, 0.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(-90.0,1.0,0.0,0.0);
    glScalef(6.0,6.0,6.0);
    glTranslatef(0,0,0.01);
    //glColor3f(1.0,0.0,1.0);
    gluCylinder(cylind,0.85,1.2,0.97,24,3);
    glColor3f(1.0,1.0,0.0);
    gluDisk(disk,0.0,0.85,24,3);
    glTranslatef(0.0,0.0,0.97);
    //glColor3f(1.0,1.0,0.0);
    gluDisk(disk,0.0,1.2,24,3);
    glPopMatrix();
    //body
    glPushMatrix();
    glTranslatef(0.0,6.0,0.0);
    drawBody();
    glTranslatef(0,0,3.6);
    glRotatef(-90.0,1.0,0.0,0.0);
    //glColor3f(0.75,0.75,0.75);
    gluCylinder(cylind,1.0,0.5,1.0,24,3);
    glRotatef(90,1.0,0.0,0.0);
    glTranslatef(0.0,2.0,-1.8);
    //glColor3f(0.25,0.25,0.25);
    gluCylinder(cylind,1.0,1.0,3.6,24,3);
    drawViewVol();
    glTranslatef(0.0,2.0,1.8);
    glMaterialfv(GL_FRONT,GL_EMISSION,light_emission);
    gluSphere(sphere,1,12,12);
    float temp[] = {0.0,0.0,0.0,1.0};
    glMaterialfv(GL_FRONT,GL_EMISSION,temp);
    glPopMatrix();
    
    //arm
    glPushMatrix();
    //glColor3f(0,1.0,1.0);
    gluSphere(sphere,1.5,12,12);
    //glColor3f(0.5,0.5,0.5);
    glRotatef(armHorAngle,0.0,1.0,0.0);
    glRotatef(armVerAngle,1.0,0.0,0.0);
    glTranslatef(0.0,0.0,1.5);
    gluCylinder(cylind,0.7,0.7,4.0,24,3);
    //glColor3f(0.75,0.5,0.5);
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
}
void drawViewVol(){
    glPushMatrix();
    glTranslatef(0,0,3.6);
    glDisable(GL_LIGHTING);
    drawLines();
    glEnable(GL_LIGHTING);
    glPopMatrix();
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
        crabPoint[i][0]=(rand()%110)-55;
        crabPoint[i][1]=(rand()%110)-55;
    }
    for(int i=0;i<30;i++){
        grassPoint[i][0]=(rand()%110)-55;
        grassPoint[i][1]=rand()%50;
        grassPoint[i][2]=(rand()%110)-55;
    }
    glutMainLoop();
}