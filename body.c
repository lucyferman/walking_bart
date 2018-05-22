#include "body.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>

float rSkin = 255.0 / 255.0;
float gSkin = 217.0 / 255.0;
float bSkin = 15.0 / 255.0;

void
drawEye (float xTranslation)
{
    printf ("Draw eye\n");
    int rotation = 1;
    if(xTranslation * 100 < 0)
        rotation = -1;

    glColor3f (0.9, 0.9, 0.9);
    glPushMatrix ();
    glTranslatef (xTranslation, 1.3, -5.4);
    glRotatef (20, 0.0, 0.5 * rotation, 0.0);
    glScalef (0.25, 0.25, 0.1);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();

    glColor3f (0.25, 0.25, 0.25);
    glPushMatrix ();
    glTranslatef (xTranslation, 1.2, -5.0);
    glRotatef (20, 0.0, 0.5 * rotation, 0.0);
    glScalef (0.05, 0.05, 0.01);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();
}

void
drawMouth ()
{
    printf ("Draw mouth\n");

    glColor3f (0.25, 0.25, 0.25);
    glPushMatrix ();
    glTranslatef (0.0, 0.6, -6.0);
    glScalef (0.57, 0.15, 0.57);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();
}

void
drawNose ()
{
    printf ("Draw nose\n");

    // Draw the first part of the nose with a cylinder
    glPushMatrix ();
    glTranslatef (0.0, 0.7, -4.4);
    glScalef (0.1, 0.1, 0.4);
    gluCylinder (gluNewQuadric (), 1, 1, 1.0, 100, 100);
    glPopMatrix ();

    // Draw the last part of the nose with a sphere
    glPushMatrix ();
    glTranslatef (0.0, 0.7, -4.0);
    glScalef (0.1, 0.1, 0.1);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();
}

void
drawFace ()
{
    printf ("Draw face\n");

    drawNose ();
    drawEye (-0.27);
    drawEye (0.27);
    drawMouth ();
}

void
drawHair ()
{
    printf ("Draw hair\n");
}

void
drawNeck ()
{
    printf ("Draw neck\n");

    glColor3f (rSkin, rSkin, bSkin);
    glPushMatrix ();
    glTranslatef (0.0, 0.35, -6.0);
    glScalef (0.2, 0.2, 0.2);
    glRotatef (90, 1.0, 0.0, 0.0);
    gluCylinder (gluNewQuadric (), 1, 1, 1.0, 100, 100);
    glPopMatrix ();
}

void
drawHead ()
{
    printf ("Draw head\n");

    /**
    Drawing a sphere that represent the bottom part of the head
    **/
    glColor3f (rSkin, gSkin, bSkin);
    glPushMatrix ();
    glTranslatef (0.0, 1.0, -6.0);
    glScalef (0.7, 0.7, 0.7);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();

    /**
    Drawing a cylinder that represent the top part of the head
    **/
    glPushMatrix ();
    glTranslatef (0.0, 2.0, -6.0);
    glScalef (0.7, 1.0, 0.7);
    glRotatef (90, 1.0, 0.0, 0.0);
    gluCylinder (gluNewQuadric (), 1, 1, 1.0, 100, 100);
    glPopMatrix ();

    drawNeck ();
    drawHair ();
    drawFace ();
}

void
drawRightArm ()
{
    printf ("Draw right arm\n");
}

void
drawLeftArm ()
{
    printf ("Draw left arm\n");
}

void
drawArms ()
{
    printf ("Draw arms\n");

    drawLeftArm ();
    drawRightArm ();
}

void
drawRightLeg ()
{
    printf ("Draw right leg\n");
}

void
drawLeftLeg ()
{
    printf ("Draw left leg\n");
}

void
drawLegs ()
{
    printf ("Draw legs\n");

    drawLeftLeg ();
    drawRightLeg ();
}

void
drawRightFoot ()
{
    printf ("Draw right foot\n");
}

void
drawLeftFoot ()
{
    printf ("Draw left foot\n");
}

void
drawFeet ()
{
    printf ("Draw feet\n");

    drawRightFoot ();
    drawLeftFoot ();
}

void
drawBody ()
{
    printf ("Draw body\n");
}

void
drawCharacter ()
{
    printf ("Draw character\n");

    drawBody ();
    drawHead ();
    drawLegs ();
    drawFeet ();
    drawArms ();
}
