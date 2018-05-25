#include "animation.h"
#include <GL/gl.h>
#include <GL/glut.h>

float DEPTH;
float ARM_ROTATION;
float LEG_ROTATION;
int IS_WALKING;

int ARM_ROTATION_FACTOR;
int ARM_ROTATION_LIMIT;
int LEG_ROTATION_FACTOR;
int LEG_ROTATION_LIMIT;

void
moveCharacter ()
{
    if (ARM_ROTATION >= ARM_ROTATION_LIMIT)
        ARM_ROTATION_FACTOR = -1;
    else if (ARM_ROTATION <= -ARM_ROTATION_LIMIT)
        ARM_ROTATION_FACTOR = 1;

    if (LEG_ROTATION >= LEG_ROTATION_LIMIT)
        LEG_ROTATION_FACTOR = -1;
    else if (LEG_ROTATION <= -LEG_ROTATION_LIMIT)
        LEG_ROTATION_FACTOR = 1;

    DEPTH += 0.1;
    ARM_ROTATION += 1.0 * ARM_ROTATION_FACTOR;
    LEG_ROTATION += 1.5 * LEG_ROTATION_FACTOR;
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
    DEPTH = -15.0;
    ARM_ROTATION = 0.0;
    LEG_ROTATION = 0.0;
    IS_WALKING = 0;

    ARM_ROTATION_FACTOR = 1;
    ARM_ROTATION_LIMIT = 10;
    LEG_ROTATION_FACTOR = 1;
    LEG_ROTATION_LIMIT = 15;

    glutIdleFunc (NULL);
}
