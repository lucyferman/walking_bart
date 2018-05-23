#ifndef BODY_UTILS_H
#define BODY_UTILS_H

typedef struct VertexCoordinates
{
    float x, z;
} VertexCoordinates ;

VertexCoordinates
getSpikeCoordinates (float x_center,
                     float z_center,
                     float radiux,
                     int n,
                     int i);

#endif
