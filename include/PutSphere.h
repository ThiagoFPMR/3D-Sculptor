#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "Sculptor.h"
#include "GeometricFigure.h"

/**
 * The PutSphere class is a subclass that works towards
 * implementing polimorfism for its parent class, GeometricFigure.
 *
 * Effecitevly, it provides the same functionality as the
 * putSphere() method from the Sculptor class. It stores the paramteres
 * as attributes and draws on any given Sculptor object through
 * its draw() method.
 */
class PutSphere : public GeometricFigure
{
private:
    int xc, yc, zc, radius;
    float r, g, b, a;

public:
    PutSphere(int _xc, int _yc, int _zc, int _radius, float _r, float _g, float _b, float alpha);
    void draw(Sculptor &t);
};

#endif