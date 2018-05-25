#ifndef ANIMATION_H_
#define ANIMATION_H_

extern float DEPTH;
extern float ARM_ROTATION;
extern float LEG_ROTATION;
extern int IS_WALKING;

void
moveCharacter ();

void
walk (unsigned char key, int x, int y);

void
initialize ();

#endif
