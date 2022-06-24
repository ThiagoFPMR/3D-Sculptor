#include "../include/Sculptor.h"
#include "../include/GeometricFigure.h"
#include "../include/PutSphere.h"

// Defines the necessary variables to implement the draw method
PutSphere::PutSphere(int _xc, int _yc, int _zc, int _radius, float _r, float _g, float _b, float alpha)
{
    // Setting the class' coordinates
    xc = _xc;
    yc = _yc;
    zc = _zc;
    radius = _radius;
    // Setting the class' colors
    r = _r;
    b = _b;
    g = _g;
    a = alpha;
}
// Overwrites the draw method
void PutSphere::draw(Sculptor &t)
{
    /* Sets the drawing color used by the given Sculptor
     * object and draws a Sphere in the given coordinates */
    t.setColor(r, g, b, a);
    t.putSphere(xc, yc, zc, radius);
}