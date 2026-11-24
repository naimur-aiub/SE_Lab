
#include <GL/glut.h>

float _move = 0.0f;

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0f, 2f, 0.0f);

    glBegin(GL_QUADS);
        glVertex2f(100, 100);
        glVertex2f(100, 150);
        glVertex2f(150, 150);
        glVertex2f(150, 100);
    glEnd();

    glutSwapBuffers();
}

void update(int value)
{
    _move += 10;

    if (_move > 500)
        _move = 0;

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutCreateWindow("Transformation");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

    glutDisplayFunc(drawScene);
    glutTimerFunc(20, update, 0);

    glutMainLoop();

    return 0;
}
