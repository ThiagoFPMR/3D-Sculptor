#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "Sculptor.h"
#include "GeometricFigure.h"

/**
 * The CutEllpsoid class is a subclass that works towards
 * implementing polimorfism for its parent class, GeometricFigure.
 *
 * Effecitevly, it provides the same functionality as the
 * cutEllipsoid() method from the Sculptor class. It stores the paramteres
 * as attributes and draws on any given Sculptor object through
 * its draw() method.
 */
class CutEllipsoid : public GeometricFigure
{
private:
    int xc, yc, zc, rx, ry, rz;

public:
    CutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz);
    void draw(Sculptor &t);
};

#endif