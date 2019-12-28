#include <windows.h>
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void init();

void lineSegment();

int main(int argc, char **argv) {
    // initialize GLUT
    glutInit(&argc, argv);
    // set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // set top-left display-window position
    glutInitWindowPosition(50, 100);
    // set display-window width and height
    glutInitWindowSize(400, 300);

    glutCreateWindow("An Example OpenGL Program");

    // execute initialization procedure.
    init();
    // send graphics to display window.
    glutDisplayFunc(lineSegment);
    // display everything and wait.
    glutMainLoop();
    return 0;
}

void init() {
    // set display-window color to white
    glClearColor(1.0, 1.0, 1.0, 0.0);
    // set projection parameters.
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void lineSegment() {
    // clear display window
    glClear(GL_COLOR_BUFFER_BIT);
    // set line segment color to green.
    glColor3f(0.0, 0.4, 0.2);

    glBegin(GL_LINES);
    // specify line-segment geometry
    glVertex2i(180, 15);
    glVertex2i(10, 145);

    glEnd();
    // process all OpenGL routines as quickly as possible.
    glFlush();

}
