#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "Sculptor.h"
#include "GeometricFigure.h"

/**
 * The CutSphere class is a subclass that works towards
 * implementing polimorfism for its parent class, GeometricFigure.
 *
 * Effecitevly, it provides the same functionality as the
 * cutSphere() method from the Sculptor class. It stores the paramteres
 * as attributes and draws on any given Sculptor object through
 * its draw() method.
 */
class CutSphere : public GeometricFigure
{
private:
    int xc, yc, zc, radius;

public:
    CutSphere(int _xc, int _yc, int _zc, int _radius);
    void draw(Sculptor &t);
};

#endif