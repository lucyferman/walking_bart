#include "body.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>

float rSkin = 255.0 / 255.0;
float gSkin = 217.0 / 255.0;
float bSkin = 15.0 / 255.0;

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
drawHair()
{
    printf ("Draw hair\n");
}

void
drawHead()
{
    printf ("Draw head\n");

    /**
    Drawing a sphere that represent the bottom part of the head
    **/
    glPushMatrix ();
    glTranslatef (0, 1.0, -6.0);
    glScalef (0.7, 0.7, 0.7);
    glColor3f (rSkin, gSkin, bSkin);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();

    /**
    Drawing a cylinder that represent the top part of the head
    **/
    glPushMatrix ();
    glTranslatef (0, 2.0, -6.0);
    glScalef (0.7, 1.0, 0.7);
    glRotatef (90, 1.0, 0.0, 0.0);
    gluCylinder (gluNewQuadric (), 1, 1, 1.0, 100, 100);
    glPopMatrix ();

    drawHair ();
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
