#include "body.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>

void
drawEye()
{
    printf ("Draw eye\n");
}

void
drawFace()
{
    printf ("Draw face\n");

    drawEye ();
    drawEye ();
}

void
drawHead()
{
    printf ("Draw head\n");

    drawFace ();
}

void
drawRightArm()
{
    printf ("Draw right arm\n");
}

void
drawLeftArm()
{
    printf ("Draw left arm\n");
}

void
drawArms()
{
    printf ("Draw arms\n");

    drawLeftArm ();
    drawRightArm ();
}

void
drawRightLeg()
{
    printf ("Draw right leg\n");
}

void
drawLeftLeg()
{
    printf ("Draw left leg\n");
}

void
drawLegs()
{
    printf ("Draw legs\n");

    drawLeftLeg ();
    drawRightLeg ();
}

void
drawRightFoot()
{
    printf ("Draw right foot\n");
}

void
drawLeftFoot()
{
    printf ("Draw left foot\n");
}

void
drawFeet()
{
    printf ("Draw feet\n");

    drawRightFoot ();
    drawLeftFoot ();
}

void
drawBody()
{
    printf ("Draw body\n");
}

void
drawCharacter()
{
    printf ("Draw character\n");

    drawBody ();
    drawHead ();
    drawLegs ();
    drawFeet ();
    drawArms ();
}
