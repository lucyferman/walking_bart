#include "animation.h"
#include <GL/gl.h>
#include <GL/glut.h>

float DEPTH = 0.0;
int IS_WALKING = 0;

void
moveCharacter ()
{
    DEPTH += 0.1;
    glutPostRedisplay ();
}

void
walk (unsigned char key, int x, int y)
{
    switch (key) {
        case 'w':
        if (!IS_WALKING)
        {
            glutIdleFunc (moveCharacter);
            IS_WALKING = 1;
        }
        break;
        case 's':
        if (IS_WALKING)
            initialize ();
        break;
        case 'r':
        {
            initialize ();
        }
        break;
    }
}

void
initialize ()
{
    DEPTH = -10.0;
    IS_WALKING = 0;
    glutIdleFunc (NULL);
}
