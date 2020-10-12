#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<vector>
#include<time.h>
#include<math.h>
using namespace std;
typedef int menu_object;
/* define some overly used variables with names*/
#define WHITE 0
#define BLACK 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define YELLOW 5
#define PURPLE 6
#define CYAN 7
#define RANDOM 8

#define CIRCLE 10
#define RECTANGLE 20
#define SQUARE 30
/* all the function prototypes */
void init_function();
void display_function();
void reshape_function(int,int);
void keyboard_function(unsigned char,int,int);
void mouse_function(int,int,int,int);
void motion_function(int,int);
void color_function(int);
void type_function(int);
/* intial global variables */
int windowWidth=512;
int windowHeight=512;
float red=0.0,green=0.0,blue=0.0;
menu_object color_menu,type_menu,file_menu;
/* A class for a dot to store picture easily*/
class Point{
    private:
        int xPos;
        int yPos;
        float red,green,blue;
    public:
        Point(int x,int y,float r,float g,float b){
            xPos=x;
            yPos=y;
            red=r;
            green=g;
            blue=b;
        }
        int Point::getX(){
            return xPos;
        }
        int Point::getY(){
            return yPos;
        }
        float Point::getR(){
            return red;
        }
        float Point::getG(){
            return green;
        }
        float Point::getB(){
            return blue;
        }
        void Point::setPos(int x,int y){
            xPos = x;
            yPos = y;
        }
        void Point::setColor(float r,float g,float b){
            red=r;
            green=g;
            blue=b;
        }
};

/*----------------------------------------------------------------
    Main function , sets up attributes for the window.
------------------------------------------------------------------*/
int main(int argc, char **argv){
    glutInit(&argc, argv); // make connection with server
    glutInitWindowPosition(200,200); // intitialize window position
    glutInitWindowSize(windowWidth,windowHeight); // initialize window size
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE); // initialize display mode
    init_function();
    glutCreateWindow("Paint(knock off)");
    glutDisplayFunc(display_function);
    glutReshapeFunc(reshape_function);
    glutKeyboardFunc(keyboard_function);
    glutMouseFunc(mouse_function);
    glutMotionFunc(motion_function);

    color_menu = glutCreateMenu(color_function);
    glutAddMenuEntry("white", WHITE);
    glutAddMenuEntry("black", BLACK);
    glutAddMenuEntry("red", RED);
    glutAddMenuEntry("green", GREEN);
    glutAddMenuEntry("yellow", YELLOW);
    glutAddMenuEntry("blue", BLUE);
    glutAddMenuEntry("purple", PURPLE);
    glutAddMenuEntry("cyan",CYAN);
    glutAddMenuEntry("random",RANDOM);

    type_menu = glutCreateMenu(type_function);
    glutAddMenuEntry("Circle",CIRCLE);
    glutAddMenuEntry("Rectangle",RECTANGLE);
    glutAddMenuEntry("Square",SQUARE);


}
/*----------------------------------------------------------------
initalize data alighment and others
------------------------------------------------------------------ */
void init_function(){
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(red,green,blue);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,windowWidth,0.0,windowHeight);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
/*----------------------------------------------------------------
color section function
---------------------------------------------------------------- */
void color_function(int value){
    switch(value){
        case WHITE:
            red=green=blue=0.0;
            break;
        case BLACK:
            red=green=blue=1.0;
            break;
        case RED:
            red=1.0;
            green=blue=0.0;
            break;
        case GREEN:
            green=1.0;
            red=blue=0.0;
            break;
        case YELLOW:
            green=red=1.0;
            blue=0.0;
            break;
        case BLUE:
            green=red=0.0;
            blue=1.0;
            break;
        case PURPLE:
            red=blue=1.0;
            green=0;
            break;
        case CYAN:
            blue=green=1.0;
            red=0.0;
            break;
        case RANDOM:
            srand(time(NULL));
            red=float(rand())/float(RAND_MAX);
            green=float(rand())/float(RAND_MAX);
            blue=float(rand())/float(RAND_MAX);
            break;
    }
} 
void reshape_fuction(int newWidth,int newHeight){
    windowWidth=newWidth;
    windowHeight=newHeight;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,newWidth,0,newHeight);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,newWidth,newHeight);
    glutPostRedisplay();
}
void display_function(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2);
    glBegin(GL_POINTS);
}