#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define PI   3.141592653
/* define a unit box */
  // vertices of the box, the order is from 0 to 7
float points[][3] = { {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5},
                      {0.5, 0.5, -0.5},   {-0.5, 0.5, -0.5},
                      {-0.5, -0.5, 0.5},  {0.5, -0.5, 0.5},
                      {0.5, 0.5, 0.5},    {-0.5, 0.5, 0.5} };
  // face of box
int face[][4] = { {0, 3, 2, 1}, {0, 1, 5, 4}, {1, 2, 6, 5},
                  {4, 5, 6, 7}, {2, 3, 7, 6}, {0, 4, 7, 3} };
  // indices of the box faces
int cube[6] = { 0,1,2,3,4,5 };
/* define the color */
float colors[6][3] = { {0.5, 0.5, 0.5}, {0.7, 0.7, 0.7}, {0.7, 0.5, 0.5},
                       {0.5, 0.5, 0.5}, {0.5, 0.7, 0.5}, {0.5, 0.5, 0.7} };
/* declare glu quadric objects, sphere, cylinder, and disk */
GLUquadricObj* sphere = NULL, * cylind = NULL, * disk = NULL;
/* declare position, orientation */
float  self_ang = -90.0, glob_ang = 0.0;
float  position[3] = { 8.0, 0.0, 0.0 };
float  ang_node_1 = 0.0;
float  ang_node_2 = 0.0;
float  ang_blade = 0.0;
float  Step = 0.5;
bool   CameraView = true;
/* define window size */
int width = 512, height = 512;
/* initialize other state varibales */
void  myinit() {
    // set the background color black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // clear the depth & color buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    // create quadratic objects
    if (sphere == NULL) {
        sphere = gluNewQuadric();
        gluQuadricDrawStyle(sphere, GLU_FILL);
        gluQuadricNormals(sphere, GLU_SMOOTH);
    }
    if (cylind == NULL) {
        cylind = gluNewQuadric();
        gluQuadricDrawStyle(cylind, GLU_FILL);
        gluQuadricNormals(cylind, GLU_SMOOTH);
    }
    if (disk == NULL) {
        disk = gluNewQuadric();
        gluQuadricDrawStyle(disk, GLU_FILL);
        gluQuadricNormals(disk, GLU_SMOOTH);
    }
}
/* draw a unit cube */
void draw_cube() {
    int i;
    for (i = 0; i < 6; i++) {
        // set color
        glColor3fv(colors[i]);
        // draw the face
        glBegin(GL_POLYGON);
            glVertex3fv(points[face[i][0]]);
            glVertex3fv(points[face[i][1]]);
            glVertex3fv(points[face[i][2]]);
            glVertex3fv(points[face[i][3]]);
        glEnd();
    }
}
/* draw the floor */
void draw_floor() {
    int i, j;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++) {
            //draw the floor
            glBegin(GL_POLYGON);
                glVertex3f((i - 5.0) * 10.0, -2.5, (j - 5.0) * 10.0);
                glVertex3f((i - 5.0) * 10.0, -2.5, (j - 4.0) * 10.0);
                glVertex3f((i - 4.0) * 10.0, -2.5, (j - 4.0) * 10.0);
                glVertex3f((i - 4.0) * 10.0, -2.5, (j - 5.0) * 10.0);
            glEnd();
        }
}
/* draw the sphere */
void draw_sphere() {
    gluSphere(sphere, 2.0, // radius=1.0
        12,                // composing of 12 slices
        12);               // composing of 8 stacks 
}
/* draw three axes and the orign */
void draw_axes() {
    glTranslatef(-50, 0, -50);
    // draw a sphere to represent the original
    glColor3f(0.95, 0.0, 0.95);
    draw_sphere();
    // draw Z axis
    glColor3f(0.0, 0.0, 1.0);
    gluCylinder(cylind, 0.5, 0.5, // radius of top and bottom circle
        10.0,                     // height of the cylinder
        12,                       // use 12-side polygon approximating circle
        3);                       // divide it into 3 sections
    // draw Y axis
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glRotatef(-90.0, 1.0, 0.0, 0.0); // rotate about x by -90', z becomes y
    gluCylinder(cylind, 0.5, 0.5,
        10.0,
        12,
        3);
    glPopMatrix();
    // draw X axis
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(90.0, 0.0, 1.0, 0.0);  // rotate about y by 90', z becomes x
    gluCylinder(cylind, 0.5, 0.5,
        10.0,
        12,
        3);
    glPopMatrix();
    // restore the original modelview matrix
    glPopMatrix();
}
/* draw the blade */
void draw_blade() {
    glBegin(GL_POLYGON);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(1.0, 4.0, 0.0);
        glVertex3f(1.0, 8.0, 0.0);
        glVertex3f(-1.0, 8.0, 0.0);
        glVertex3f(-1.0, 4.0, 0.0);
    glEnd();
}
/* draw the trees */
void draw_tree() {
    glPushMatrix(); // tree_1
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(40.0, 0.0, 20.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(cylind, 0.5, 0.5,
        10.0,
        12,
        3);
    glPopMatrix();
    glPushMatrix(); // tree_2
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(20.0, 0.0, 40.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(cylind, 0.5, 0.5,
        10.0,
        12,
        3);
    glPopMatrix();
    glPushMatrix(); // tree_3
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(40.0, 0.0, 40.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(cylind, 0.5, 0.5,
        10.0,
        12,
        3);
    glPopMatrix();
    glPushMatrix(); // tree_4
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(60.0, 0.0, 20.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(cylind, 0.5, 0.5,
        10.0,
        12,
        3);
    glPopMatrix();
    glPushMatrix(); // tree_5
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(60.0, 0.0, 40.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(cylind, 0.5, 0.5,
        10.0,
        12,
        3);
    glPopMatrix();
    glPushMatrix(); // tree_6
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(20.0, 0.0, 60.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(cylind, 0.5, 0.5,
        10.0,
        12,
        3);
    glPopMatrix();
    glPushMatrix(); // tree_7
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(40.0, 0.0, 60.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(cylind, 0.5, 0.5,
        10.0,
        12,
        3);
    glPopMatrix();
    glPushMatrix(); // tree_8
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(60.0, 0.0, 60.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(cylind, 0.5, 0.5,
        10.0,
        12,
        3);
    glPopMatrix();
}
/* display function */
void display() {
    // define the angle of self-rotate
    static float ang_self = 0.0;
    static float angle = 0.0;
    // clear previous frame and the depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // define the current eye position and the eye-coordinate system
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // View
    if (CameraView) {
        // look at(-50.0, 0.0, -50.0) from eye(15.0, 15.0, 8.0), and eye-direction(0.0, 1.0, 0.0)
        gluLookAt(15.0, 15.0, 8.0, -50.0, 0.0, -50.0, 0.0, 1.0, 0.0);
    }
    else {
        // look at(-50.0, 0.0, -50.0) from eye(8.0, 15.0, 15.0), and eye-direction(0.0, 1.0, 0.0)
        gluLookAt(8.0, 15.0, 15.0, -50.0, 0.0, -50.0, 0.0, 1.0, 0.0);
    }
    glColor3f(0.95, 0.95, 1.0);
    draw_floor();
    draw_axes();
    // draw the background
    glPushMatrix();
    glColor3f(0.0, 0.95, 0.95);
    glTranslatef(-3.0, 0.0, -3.0);
    glRotatef(45, 0.0, 1.0, 0.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    draw_floor();
    glPopMatrix();
    // draw the tree
    draw_tree();
    // draw the ROV body which is a cube, (8, 0, 0)
    glTranslatef(position[0], 0.0, position[2]);
    glRotatef(self_ang, 0.0, 1.0, 0.0);
    glPushMatrix();
    glScalef(17.0, 3.0, 6.0);
    draw_cube();
    glPopMatrix();
    // draw the windmill_cube
    glPushMatrix();
    glTranslatef(-6.0, 4.0, 0.0);
    glScalef(2.0, 10.0, 2.0);
    draw_cube();
    glPopMatrix();
    // draw the node_3, (2.0, 8.0, 0.0)
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-6.0, 8.0, 0.0);
    draw_sphere();
    // draw the arm_3, (-3.0, 9.0, 0.0)
    glTranslatef(-5, 1.0, 0.0);
    glPushMatrix();
    glRotatef(90, 0.0, 0.0, 1.0);
    glScalef(2.0, 10.0, 2.0);
    draw_cube();
    glPopMatrix();
    // draw the node_4, (-6.0, 9.0, 0.0)
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-3.0, 0.0, 0.0);
    draw_sphere();
    // draw the windmill blades
    glColor3f(0.95, 0.95, 0.0);
    glPushMatrix();
    glRotatef(ang_blade, 1.0, 0.0, 0.0);
    draw_blade();
    glRotatef(120.0, 1.0, 0.0, 0.0);
    draw_blade();
    glRotatef(120.0, 1.0, 0.0, 0.0);
    draw_blade();
    glPopMatrix();
    // go back to the body position(8.0, 0.0, 0.0)
    glTranslatef(6.0, -8.0, 0.0);
    glTranslatef(5.0, -1.0, 0.0);
    glTranslatef(3.0, 0.0, 0.0);
    // draw the node_1, (15, 2, 0)
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(7.0, 2.0, 0.0);
    glRotatef(ang_node_1, 0.0, 0.0, 1.0);
    draw_sphere();
    // draw arm_1, (15, 3, 0)
    glTranslatef(0.0, 1.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 10.0, 2.0);
    draw_cube();
    glPopMatrix();
    // draw the node_2, (15, 8, 0)
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.0, 5.0, 0.0);
    glRotatef(ang_node_2, 0.0, 1.0, 0.0);
    draw_sphere();
    // draw arm_2, (23, 9, 0)
    glTranslatef(8.0, 1.0, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(2.0, 15.0, 2.0);
    draw_cube();
    glPopMatrix();
    // swap the back buffer to the front
    glutSwapBuffers();
    return;
}
/* reshape callback function */
void my_reshape(int w, int h) {
    width = w;
    height = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w > h)
        glOrtho(-40.0, 40.0, -40.0 * (float)h / (float)w, 40.0 * (float)h / (float)w, -100.0, 100.0);
    else
        glOrtho(-40.0 * (float)w / (float)h, 40.0 * (float)w / (float)h, -40.0, 40.0, -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
/* keyboard callback function */
void my_quit(unsigned char key, int x, int y) {
    if (key == 'Q' || key == 'q') 
        exit(0);
    // accelerate and decelerate
    if (key == 'u') {
        if (Step <= 2.0) {
            Step += 0.1;
        }
    }
    else if (key == 'o') {
        if (Step >= 0.5) {
            Step -= 0.1;
        }
    }
    // control ROV
    if (key == 'i') {
        if ((position[0] + Step * cos(self_ang * PI / 180.0) >= 0.0) && (position[2] - Step * sin(self_ang * PI / 180.0) >= 0.0)) {
            position[0] += Step * cos(self_ang * PI / 180.0);
            position[2] -= Step * sin(self_ang * PI / 180.0);
        }
        ang_blade += 50.0;
        if (ang_blade > 360.0) {
            ang_blade -= 360.0;
        }
    }
    else if (key == 'k') {
        if ((position[0] - Step * cos(self_ang * PI / 180.0) >= 0.0) && (position[2] + Step * sin(self_ang * PI / 180.0) >= 0.0)) {
            position[0] -= Step * cos(self_ang * PI / 180.0);
            position[2] += Step * sin(self_ang * PI / 180.0);
        }
        ang_blade -= 50.0;
        if (ang_blade < -360.0) {
            ang_blade += 360.0;
        }
    }
    else if (key == 'j') {
        self_ang += 10.0;
        if (self_ang > 360) {
            self_ang -= 360;
        }
    }
    else if (key == 'l') {
        self_ang -= 10.0;
        if (self_ang < -360) {
            self_ang += 360;
        }
    }
    // control ang_node_1
    if (key == 'w') {
        ang_node_1 += 10.0;
        if (ang_node_1 > 360) {
            ang_node_1 -= 360;
        }
    }
    else if (key == 's') {
        ang_node_1 -= 10.0;
        if (ang_node_1 < -360) {
            ang_node_1 += 360;
        }
    }
    // control ang_node_2
    if (key == 'a') {
        ang_node_2 += 10.0;
        if (ang_node_2 > 360) {
            ang_node_2 -= 360;
        }
    }
    else if (key == 'd') {
        ang_node_2 -= 10.0;
        if (ang_node_2 < -360) {
            ang_node_2 += 360;
        }
    }
    // control camera view
    if (key == 'x') {
        CameraView = false;
    }
    else if (key == 'c') {
        CameraView = true;
    }
    display();
}
/* main function */
int main(int argc, char** argv) {
    // initialize the glut environment
    glutInit(&argc, argv);
    // depth buffer is used, be careful
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("CG_HW2");
    myinit();
    // associate callback func's with events
    glutDisplayFunc(display);
    // glutIdleFunc(display);
    glutReshapeFunc(my_reshape);
    glutKeyboardFunc(my_quit);
    glutMainLoop();
}