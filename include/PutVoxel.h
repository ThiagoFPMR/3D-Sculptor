#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "Sculptor.h"
#include "GeometricFigure.h"

/**
 * The PutVoxel class is a subclass that works towards
 * implementing polimorfism for its parent class, GeometricFigure.
 *
 * Effecitevly, it provides the same functionality as the
 * putVoxel() method from the Sculptor class. It stores the paramteres
 * as attributes and draws on any given Sculptor object through
 * its draw() method.
 */
class PutVoxel : public GeometricFigure
{
private:
    int x, y, z;
    float r, g, b, a;

public:
    PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float alpha);
    void draw(Sculptor &t);
};

#endif