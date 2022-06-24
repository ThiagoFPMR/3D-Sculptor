#ifndef PUTBOX_H
#define PUTBOX_H

#include "Sculptor.h"
#include "GeometricFigure.h"

/**
 * The PutBox class is a subclass that works towards
 * implementing polimorfism for its parent class, GeometricFigure.
 *
 * Effecitevly, it provides the same functionality as the
 * putBox() method from the Sculptor class. It stores the paramteres
 * as attributes and draws on any given Sculptor object through
 * its draw() method.
 */
class PutBox : public GeometricFigure
{
private:
    int x0, x1, y0, y1, z0, z1;
    float r, g, b, a;

public:
    PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float alpha);
    void draw(Sculptor &t);
};

#endif