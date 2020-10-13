#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<vector>
#include<time.h>
#include<math.h>
#include<list>
typedef int MenuObject;
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

#define DOT 10
#define LINE 20
#define TRIANGLE 30
#define RECTANGLE 40
#define CIRCLE 50
#define AIRBRUSH 60

#define BIG 100
#define MEDIUM 200
#define SMALL 300

#define REDO 1000
#define UNDO 2000

#define CLEAR 400
#define QUIT 888

#define FILL 111
#define NO_FILL 222

#define CUSTOM 123
/* all the function prototypes */
void init_function();
void display_function();
void reshape_function(int,int);
void keyboard_function(unsigned char,int,int);
void mouse_function(int,int,int,int);
void motion_function(int,int);
void color_function(int);
void type_function(int);
void eraser_function(int);
void control_function(int);
void menu_function(int);
void clear_function();
void fillmode_function(int);
void backgroundcolor_function(int);
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
        int getX(){
            return xPos;
        }
        int getY(){
            return yPos;
        }
        float getR(){
            return red;
        }
        float getG(){
            return green;
        }
        float getB(){
            return blue;
        }
        void setPos(int x,int y){
            xPos = x;
            yPos = y;
        }
        void setColor(float r,float g,float b){
            red=r;
            green=g;
            blue=b;
        }
};

/* intial global variables */
int windowWidth=512;
int windowHeight=512;
float red=0.0,green=0.0,blue=0.0;
float bckColor[3]={1.0,1.0,1.0};
MenuObject color_menu,type_menu,file_menu,eraser_menu,control_menu,fillmode_menu,backgroundcolor_menu;
std::vector<Point>currentPoints;
std::list<int> undoHistory;
std::list<int> redoHistory;
std::vector<Point> redoPoints;
bool fillMode=false,isEraser=false;
/*----------------------------------------------------------------
    Main function , sets up attributes and menu for the window.
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
    glutAddMenuEntry("White", WHITE);
    glutAddMenuEntry("Black", BLACK);
    glutAddMenuEntry("Red", RED);
    glutAddMenuEntry("Green", GREEN);
    glutAddMenuEntry("Yellow", YELLOW);
    glutAddMenuEntry("Blue", BLUE);
    glutAddMenuEntry("Purple", PURPLE);
    glutAddMenuEntry("Cyan",CYAN);
    glutAddMenuEntry("Random",RANDOM);
    glutAddMenuEntry("Custom",CUSTOM);

    type_menu = glutCreateMenu(type_function);
    glutAddMenuEntry("Dot",DOT);
    glutAddMenuEntry("Line",LINE);
    glutAddMenuEntry("Triangle",TRIANGLE);
    glutAddMenuEntry("Rectangle",RECTANGLE);
    glutAddMenuEntry("Circle",CIRCLE);
    glutAddMenuEntry("Airbrush",AIRBRUSH);

    eraser_menu=glutCreateMenu(eraser_function);
    glutAddMenuEntry("Big",BIG);
    glutAddMenuEntry("Medium",MEDIUM);
    glutAddMenuEntry("Small",SMALL);

    control_menu=glutCreateMenu(control_function);
    glutAddMenuEntry("redo",REDO);
    glutAddMenuEntry("undo",UNDO);

    fillmode_menu = glutCreateMenu(fillmode_function);
    glutAddMenuEntry("fill",FILL);
    glutAddMenuEntry("no fill",NO_FILL);

    backgroundcolor_menu=glutCreateMenu(backgroundcolor_function);
    glutAddMenuEntry("black",BLACK);
    glutAddMenuEntry("white",WHITE);
    glutAddMenuEntry("Custom",CUSTOM);

    MenuObject main_menu= glutCreateMenu(menu_function);
    glutAddSubMenu("Color",color_menu);
    glutAddSubMenu("Background color",backgroundcolor_menu);
    glutAddSubMenu("Type",type_menu);
    glutAddSubMenu("Fill mode",fillmode_menu);
    glutAddSubMenu("Eraser",eraser_menu);
    glutAddSubMenu("Control",control_menu);
    glutAddMenuEntry("Clear",CLEAR);
    glutAddMenuEntry("Quit",QUIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
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
void reshape_function(int newWidth,int newHeight){
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
    glClearColor(bckColor[0],bckColor[1],bckColor[2],1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2);
    glBegin(GL_POINTS);
    for(unsigned int i=0;i<currentPoints.size();i++){
        glColor3f(currentPoints[i].getR(),currentPoints[i].getG(),currentPoints[i].getB());
        glVertex2i(currentPoints[i].getX(),currentPoints[i].getY());
    }
    glEnd();
    glutSwapBuffers();
}
void menu_function(int value){
    switch(value){
        case QUIT:
            printf("Thanks for using!\n");
            exit(0);
            break;
        case CLEAR:
            clear_function();
            break;
    }
}
void keyboard_function(unsigned char key,int x,int y){};
void mouse_function(int x1,int y1,int x2,int y2){};
void motion_function(int x,int y){};
void type_function(int value){};
void eraser_function(int value){};
void control_function(int value){
    switch(value){
        case UNDO:
            undo_function();
            break;
        case REDO:
            redo_function();
            break;
    }
}
void clear_function(){
    currentPoints.clear();
    undoHistory.clear();
    redoHistory.clear();
    redoPoints.clear();
    glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
    printf("Everything successfully cleared.");
    display_function();
};
void fillmode_function(int value){
    fillMode=value==FILL?true:false;
};
void backgroundcolor_function(int value){
    switch(value){
        case WHITE:
            bckColor[0]=bckColor[1]=bckColor[2]=1.0;
            break;
        case BLACK:
            bckColor[0]=bckColor[1]=bckColor[2]=0.0;
        case CUSTOM:
            printf("Please enter 3 decimals betwwen 1 and 0(space it with space):");
            scanf("%f %f %f",bckColor[0],bckColor[1],bckColor[2]);
    }
    display_function();
};
void undo_function(){
    if(undoHistory.size()>0){
        if(undoHistory.back()!=currentPoints.size()&&redoHistory.back()!=currentPoints.size())redoHistory.push_back(currentPoints.size());
        int numSteps = currentPoints.size()-undoHistory.back();
        for(int i=0;i<numSteps;i++){
            redoPoints.push_back(currentPoints.back());
            currentPoints.pop_back();
        }
        redoHistory.push_back(undoHistory.back());
        undoHistory.pop_back();
    }
    else printf("You don't have any records left.");
}
void redo_function(){
    if(redoHistory.size()>1){
        undoHistory.push_back(redoHistory.back());
        redoHistory.pop_back();
        int numRemove = redoHistory.back() - currentPoints.size();
        for(int i=0;i<numRemove;i++){
            currentPoints.push_back(redoPoints.back());
            redoPoints.pop_back();
        }
    }
    else printf("Can't redo. You haven't done anything further.");
}
void drawPoint(int xPos,int yPos){
    if(isEraser) currentPoints.push_back(Point(xPos,windowHeight-yPos,bckColor[0],bckColor[1],bckColor[2]));
    else currentPoints.push_back(Point(xPos,windowHeight-yPos,red,green,blue));
}
