#include "body.h"
#include "body_utils.h"
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
    if (xTranslation * 100 < 0)
        rotation = -1;

    // Draw the sclera
    glColor3f (0.9, 0.9, 0.9);
    glPushMatrix ();
    glTranslatef (xTranslation, 1.3, -5.4);
    glRotatef (20, 0.0, 0.5 * rotation, 0.0);
    glScalef (0.25, 0.25, 0.1);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();

    // Draw the pupil
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
drawEar(float xTranslation)
{
    printf ("Draw ear\n");
    int rotation = 1;
    if (xTranslation * 100 > 0)
        rotation = -1;

    glPushMatrix ();
    glTranslatef (xTranslation, 1.3, -6);
    glRotatef (30, 0.0, 0.0, 0.5 * rotation);
    glScalef (0.08, 0.12, 0.05);
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
drawHairSpike (float x, float z)
{
    printf ("Draw hair spike\n");
    if (x * 1000 > 0)
        x -= 0.08;
    else if(x * 10 != 0)
        x += 0.08;

    if (z * 1000 > 0)
        z -= 0.08;
    else if(z * 10 != 0)
        z += 0.08;

    glPushMatrix ();
    glTranslatef (x, 2.2, -6.0 + z);
    glScalef (0.1, 0.2, 0.1);
    glRotatef (90, 1.0, 0.0, 0.0);
    gluCylinder (gluNewQuadric (), 0.2, 0.8, 1.0, 100, 100);
    glPopMatrix ();
}

void
drawHair ()
{
    printf ("Draw hair\n");

    VertexCoordinates coordinates;
    int i;
    int j;
    int nAux;
    float radiusAux;
    int radius = 0.7;
    int n = 4;
    int ns[4] = { 13, 10, 5, 1 };
    float radiuses[4] = { 0.7, 0.47, 0.3, 0 };
    for (i = 0; i < n; i++)
    {
        nAux = ns[i];
        radiusAux = radiuses[i];
        for (j = 0; j < nAux; j++)
        {
            coordinates = getSpikeCoordinates (0.0, 0.0, radiusAux, nAux, j);
            drawHairSpike (coordinates.x, coordinates.z);
        }
    }
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


    glColor3f (rSkin, gSkin, bSkin);

    /**
    Drawing a sphere that represent the bottom part of the head
    **/
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

    // Head cover
    glPushMatrix ();
    glTranslatef (0.0, 2.0, -6.0);
    glScalef (0.7, 0.001, 0.7);
    gluSphere (gluNewQuadric (), 1, 100, 100);
    glPopMatrix ();

    drawEar (-0.71);
    drawEar (0.71);
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
