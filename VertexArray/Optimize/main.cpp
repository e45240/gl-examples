#include <windows.h>
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

typedef GLfloat vertex3[3];

/**
 *          p8 @ * * * * @ p7
 *           * *       * *
 *      p5 @ * * * * @ p6*
 *         * p4@ * * * * @ p3
 *         * *       * *
 *      p1 @ * * * * @ p2
 *
 */
const vertex3 pt[] = {
        {-1, -1, -1},
        {1,  -1, -1},
        {1,  1,  -1},
        {-1, 1,  -1},
        {-1, -1, 1},
        {1,  -1, 1},
        {1,  1,  1},
        {-1, 1,  1}
};

const vertex3 ps[] = {
        // top
        {-1, -1, 1},
        {1,  -1, 1},
        {1,  1,  1},
        {-1, 1,  1},

        // bottom
        {-1, -1, -1},
        {1,  -1, -1},
        {1,  1,  -1},
        {-1, 1,  -1},

        // front
        {-1, -1, -1},
        {1,  -1, -1},
        {1,  -1, 1},
        {-1, -1, 1},

        // back
        {-1, 1,  -1},
        {1,  1,  -1},
        {1,  1,  1},
        {-1, 1,  1},

        // left
        {-1, 1,  -1},
        {-1, -1, -1},
        {-1, -1, 1},
        {-1, 1,  1},

        // right
        {1,  -1, -1},
        {1,  1,  -1},
        {1,  1,  1},
        {1,  -1, 1}
};

const vertex3 colors[] = {
        {0.0f, 1.0f, 0.0f}, // green
        {0.0f, 1.0f, 0.0f}, // green
        {0.0f, 1.0f, 0.0f}, // green
        {0.0f, 1.0f, 0.0f}, // green

        {1.0f, 0.5f, 0.0f}, // orange
        {1.0f, 0.5f, 0.0f}, // orange
        {1.0f, 0.5f, 0.0f}, // orange
        {1.0f, 0.5f, 0.0f}, // orange

        {1.0f, 0.0f, 0.0f}, // red
        {1.0f, 0.0f, 0.0f}, // red
        {1.0f, 0.0f, 0.0f}, // red
        {1.0f, 0.0f, 0.0f}, // red

        {1.0f, 1.0f, 0.0f}, // yellow
        {1.0f, 1.0f, 0.0f}, // yellow
        {1.0f, 1.0f, 0.0f}, // yellow
        {1.0f, 1.0f, 0.0f}, // yellow

        {0.0f, 0.0f, 1.0f}, // blue
        {0.0f, 0.0f, 1.0f}, // blue
        {0.0f, 0.0f, 1.0f}, // blue
        {0.0f, 0.0f, 1.0f}, // blue

        {1.0f, 0.0f, 1.0f}, // violet
        {1.0f, 0.0f, 1.0f}, // violet
        {1.0f, 0.0f, 1.0f}, // violet
        {1.0f, 0.0f, 1.0f}  // violet
};

GLfloat xRotated, yRotated, zRotated;

void init() {
    glClearColor(0, 0, 0, 0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
}

void DrawCube() {
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.5);
    glRotatef(xRotated, 1.0, 0.0, 0.0);
    // rotation about Y axis
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    // rotation about Z axis
    glRotatef(zRotated, 0.0, 0.0, 1.0);
    glVertexPointer(3, GL_FLOAT, 0, ps);
    glColorPointer(3, GL_FLOAT, 0, colors);
    GLubyte vertexIndex[] = {
            0, 1, 2, 3, // top
            4, 5, 6, 7, // bottom
            8, 9, 10, 11, // front
            12, 13, 14, 15, // back
            16, 17, 18, 19, // left
            20, 21, 22, 23  // right
    };
    glDrawElements(GL_QUADS, sizeof(vertexIndex) / sizeof(GLubyte), GL_UNSIGNED_BYTE, vertexIndex);
    glEnd();            // End Drawing The Cube
    glFlush();
}


void animation() {
    yRotated += 0.01;
    xRotated += 0.02;
    DrawCube();
}


void reshape(int x, int y) {
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(40.0, (GLdouble) x / (GLdouble) y, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);  //Use the whole window for rendering
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    //we initialize the glut. functions
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(DrawCube);
    glutReshapeFunc(reshape);
    //Set the function for the animation.
    glutIdleFunc(animation);
    glutMainLoop();
    return 0;
}
