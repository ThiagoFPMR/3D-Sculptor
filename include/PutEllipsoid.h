#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "Sculptor.h"
#include "GeometricFigure.h"

/**
 * The PutEllipsoid class is a subclass that works towards
 * implementing polimorfism for its parent class, GeometricFigure.
 *
 * Effecitevly, it provides the same functionality as the
 * putEllipsoid() method from the Sculptor class. It stores the paramteres
 * as attributes and draws on any given Sculptor object through
 * its draw() method.
 */
class PutEllipsoid : public GeometricFigure
{
private:
    int xc, yc, zc, rx, ry, rz;
    float r, g, b, a;

public:
    PutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz, float _r, float _g, float _b, float alpha);
    void draw(Sculptor &t);
};

#endif