#include "../include/Sculptor.h"
#include "../include/GeometricFigure.h"
#include "../include/PutEllipsoid.h"

// Defines the necessary variables to implement the draw method
PutEllipsoid::PutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz, float _r, float _g, float _b, float alpha)
{
    // Setting the class' coordinates
    xc = _xc;
    rx = _rx;
    yc = _yc;
    ry = _ry;
    zc = _zc;
    rz = _rz;
    // Setting the class' colors
    r = _r;
    b = _b;
    g = _g;
    a = alpha;
}
// Overwrites the draw method
void PutEllipsoid::draw(Sculptor &t)
{
    /* Sets the drawing color used by the given Sculptor
     * object and draws an Ellipsoid in the given coordinates */
    t.setColor(r, g, b, a);
    t.putEllipsoid(xc, yc, zc, rx, ry, rz);
}