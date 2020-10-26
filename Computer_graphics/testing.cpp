/*----------------------------------------------------------------
    00757143 
------------------------------------------------------------------*/
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
void undo_function();
void redo_function();
void erasePoint(int,int);
void drawPoint(int,int);
void paintBrush(int,int);
void drawLine(int,int,int,int);
void drawRectangle(int,int,int,int);
void drawCircle(int,int,int);
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
int eraserSize=7;
int brushSize=7;
int firstX,firstY;
int currentShape=DOT;
float red=0.0,green=0.0,blue=0.0;
float bckColor[3]={1.0,1.0,1.0};
MenuObject color_menu,type_menu,file_menu,eraser_menu,control_menu,fillmode_menu,backgroundcolor_menu;
std::vector<Point>currentPoints;
std::list<int> undoHistory;
std::list<int> redoHistory;
std::vector<Point> redoPoints;
bool fillMode=false,isEraser=false,isSecond = false;
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
    //glutAddMenuEntry("Custom",CUSTOM);

    type_menu = glutCreateMenu(type_function);
    glutAddMenuEntry("Dot",DOT);
    glutAddMenuEntry("Line",LINE);
    //glutAddMenuEntry("Triangle",TRIANGLE);
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
    //glutAddMenuEntry("Custom",CUSTOM);

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
    printf("OK");
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
    isSecond = false;
	isEraser = false;
    switch(value){
        case WHITE:
            red=green=blue=1.0;
            break;
        case BLACK:
            red=green=blue=0.0;
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
/*----------------------------------------------------------------
    Handles window reshaping.
------------------------------------------------------------------*/
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
/*----------------------------------------------------------------
    Displaying function, from vector to glut buffer.
------------------------------------------------------------------*/
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
/*----------------------------------------------------------------
    controls Quit and Clear
------------------------------------------------------------------*/
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
/*----------------------------------------------------------------
    Quick shortcuts for other functions
------------------------------------------------------------------*/
void keyboard_function(unsigned char key,int x,int y){
    isSecond = false;
    switch(key){
        case 'q':
        case 'Q':
        case 27:
            exit(0);
            break;
        case 'c':
        case 'C':
            clear_function();
            break;
        case 'u':
        case 'U':
            undo_function();
            break;
        case 'r':
        case 'R':
            redo_function();
            break;
    }
}
/*----------------------------------------------------------------
    Controls mouse activity
------------------------------------------------------------------*/
void mouse_function(int button,int state,int x,int y){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(isEraser){
            undoHistory.push_back(currentPoints.size());
            erasePoint(x,y);
        }
        else{
            if(currentShape==DOT){
                undoHistory.push_back(currentPoints.size());
                drawPoint(x,y);
            }
            else if(currentShape==AIRBRUSH){
                undoHistory.push_back(currentPoints.size());
                paintBrush(x, y);
            }
            else{
                if(isSecond){
                    if(undoHistory.back()!=currentPoints.size())undoHistory.push_back(currentPoints.size());
                    if(currentShape==LINE)drawLine(firstX,firstY,x,y);
                    else if(currentShape==RECTANGLE)drawRectangle(firstX,firstY,x,y);
                    else if(currentShape==CIRCLE){
                        int r=(int)sqrt(pow(firstX-x,2)+pow(firstY-y,2));
                        drawCircle(firstX,firstY,r);
                    }
                    isSecond=false;
                }
                else{
                    firstX=x;
                    firstY=y;
                    isSecond=true;
                }
            }
        }
        if(undoHistory.size()>20)undoHistory.pop_front();
    }
}
/*----------------------------------------------------------------
    Mouse motion activity
------------------------------------------------------------------*/
void motion_function(int x,int y){
    if(isEraser)erasePoint(x,y);
    else if(currentShape==DOT)drawPoint(x,y);
    else if(currentShape==AIRBRUSH)paintBrush(x,y);
}
/*----------------------------------------------------------------
    Shapes function
------------------------------------------------------------------*/
void type_function(int value){
    isSecond = false;
    isEraser = false;
    currentShape=value;
}
/*----------------------------------------------------------------
    Choose the size of the eraser
------------------------------------------------------------------*/
void eraser_function(int value){
    isEraser = true;
    switch(value){
        case BIG:
            eraserSize = 12;
            break;
        case MEDIUM:
            eraserSize = 7;
            break;
        case SMALL:
            eraserSize=2;
            break;
    }
}
/*----------------------------------------------------------------
    Redo and Undo function
------------------------------------------------------------------*/
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
/*----------------------------------------------------------------
    clear everything and also redo undo history
------------------------------------------------------------------*/
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
/*----------------------------------------------------------------
    decide whether fill or no fill 
------------------------------------------------------------------*/
void fillmode_function(int value){
    fillMode=value==FILL?true:false;
};
/*----------------------------------------------------------------
    Choose background color (white or black)
------------------------------------------------------------------*/
void backgroundcolor_function(int value){
    switch(value){
        case WHITE:
            bckColor[0]=bckColor[1]=bckColor[2]=1.0;
            break;
        case BLACK:
            bckColor[0]=bckColor[1]=bckColor[2]=0.0;
            break;
    }
    display_function();
};
/*----------------------------------------------------------------
    Actuall undo function. remembers the step of currentPoint to remmeber where to stop undoing. 
------------------------------------------------------------------*/
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
    else printf("You don't have any records left.\n");
    display_function();
}
/*----------------------------------------------------------------
    Actuall redo function. remembers the step of currentPoint to remmeber where to stop redoing. 
------------------------------------------------------------------*/
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
    else printf("Can't redo. You haven't done anything further.\n");
    display_function();
}
/*----------------------------------------------------------------
    Draw a single dot.
------------------------------------------------------------------*/
void drawPoint(int xPos,int yPos){
    if(isEraser) currentPoints.push_back(Point(xPos,windowHeight-yPos,bckColor[0],bckColor[1],bckColor[2]));
    else currentPoints.push_back(Point(xPos,windowHeight-yPos,red,green,blue));
}
/*----------------------------------------------------------------
    erase a part of canvas depends on the size 
------------------------------------------------------------------*/
void erasePoint(int x,int y){
    for(int i=-1*eraserSize;i<=eraserSize;i++)for(int j=-1*eraserSize;j<=eraserSize;j++)drawPoint(x+i,y+j);
}
/*----------------------------------------------------------------
    another type of brush, randomly put dots in a radius 
------------------------------------------------------------------*/
void paintBrush(int x,int y){
    for(int i=0;i<5;i++){
        int tempX = rand() % (brushSize) - brushSize / 2 + x;
		int tempY = rand() % (brushSize) - brushSize / 2 + y;
		drawPoint(tempX, tempY);
    }
}
/*----------------------------------------------------------------
    mid point circle Algorithm from Geeks4Geeks 
------------------------------------------------------------------*/
void drawCircle(int xCenter,int yCenter,int actRadius){
    int radius;
    radius=fillMode?0:actRadius;
    for(int i=radius;i<=actRadius;i++){
        int x=i,y=0;
        drawPoint(x+xCenter,y+yCenter);
        if(i>0){
            drawPoint(x+xCenter,-y+yCenter);
            drawPoint(y+xCenter,x+yCenter);
            drawPoint(-y+xCenter,x+yCenter);
        }
        int P=1-i;
        while(x>y){
            y++;
            //Mid point inside of perim
            if(P<=0)P=P+2*y+1;
            //Mid point out of perim
            else{
                x--;
                P=P+2*y-2*x+1;
            }
            //If all done
            if(x<y)break;
            //Drawing the point and the reflection
            drawPoint(x+xCenter,y+yCenter);
            drawPoint(-x+xCenter,y+yCenter);
            drawPoint(x+xCenter,-y+yCenter);
            drawPoint(-x+xCenter,-y+yCenter);
            //If the point os on the line x=y then
            //the perimeter points have alredy been drawn 
            if(x!=y){
                drawPoint(y+xCenter,x+yCenter);
                drawPoint(-y+xCenter,x+yCenter);
                drawPoint(y+xCenter,-x+yCenter);
                drawPoint(-y+xCenter,-x+yCenter);
            }
        }
    }
}
/*----------------------------------------------------------------
    Basically a lot of drawline. 
------------------------------------------------------------------*/
void drawRectangle(int x1,int y1,int x2,int y2){
    if(fillMode){
        if(y2<y1){
            int temp=y2;
            y2=y1;
            y1=temp;
        }
        for(int i=y2;i>=y1;i--)drawLine(x1,i,x2,i);
    }
    else{
        drawLine(x1, y1, x2, y1);
		drawLine(x2, y1, x2, y2);
		drawLine(x2, y2, x1, y2);
		drawLine(x1, y2, x1, y1);
    }
}
/*----------------------------------------------------------------
    Bresenham's line generation algorithm, also from Geeks4Geeks 
------------------------------------------------------------------*/
void drawLine(int x1,int y1,int x2,int y2){
    bool changed = false;
	// Bresenham's line algorithm is only good when abs(dx) >= abs(dy)
	// So when abs(dx) < abs(dy), change axis x and y
	if (abs(x2 - x1) < abs(y2 - y1)){
		int tmp1 = x1;
		x1 = y1;
		y1 = tmp1;
		int tmp2 = x2;
		x2 = y2;
		y2 = tmp2;
		changed = true;
	}
	int dx = x2 - x1;
	int dy = y2 - y1;
	int yi = 1;
	int xi = 1;
	if (dy < 0){
		yi = -1;
		dy = -dy;
	}
	if (dx < 0){
		xi = -1;
		dx = -dx;
	}
	int d = 2 * dy - dx;
	int incrE = dy * 2;
	int incrNE = 2 * dy - 2 * dx;
	int x = x1, y = y1;
	if (changed)drawPoint(y, x);
	else drawPoint(x, y);
	while (x != x2){
		if (d <= 0)d += incrE;
		else{
			d += incrNE;
			y += yi;
		}
		x += xi;
		if (changed)drawPoint(y, x);
		else drawPoint(x, y);
	}
}