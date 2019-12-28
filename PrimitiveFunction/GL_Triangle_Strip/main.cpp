#include <windows.h>
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void init();

void display();

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
    glutDisplayFunc(display);
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

void display() {
    // clear display window
    glClear(GL_COLOR_BUFFER_BIT);
    // set line segment color to green.
    glColor3f(0.0, 0.4, 0.2);

    //   p6 +------------+ p5
    //     -              -
    //    -                -
    //p1 +                  + p4
    //    -                -
    //     -              -
    //   p2 +------------+ P3
    GLint p1 [] = {20, 70};
    GLint p2 [] = {70, 20};
    GLint p3 [] = {120, 20};
    GLint p4 [] = {170, 70};
    GLint p5 [] = {120, 120};
    GLint p6 [] = {70, 120};

    glBegin(GL_TRIANGLE_STRIP);
    // specify line-segment geometry
    // 【p1 p2 p6】 【p2 p6 p3】 【p6 p3 p5】 【p3 p5 p4】four triangles
    glVertex2i(p1[0], p1[1]);
    glVertex2i(p2[0], p2[1]);
    glVertex2i(p6[0], p6[1]);
    glVertex2i(p3[0], p3[1]);
    glVertex2i(p5[0], p5[1]);
    glVertex2i(p4[0], p4[1]);
    glEnd();
    // process all OpenGL routines as quickly as possible.
    glFlush();

}
