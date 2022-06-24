#include "../include/Sculptor.h"
#include "../include/GeometricFigure.h"
#include "../include/CutSphere.h"

// Defines the necessary variables to implement the draw method
CutSphere::CutSphere(int _xc, int _yc, int _zc, int _radius)
{
    // Setting the class' coordinates
    xc = _xc;
    yc = _yc;
    zc = _zc;
    radius = _radius;
}
// Overwrites the draw method
void CutSphere::draw(Sculptor &t)
{
    // Cuts the Sphere in the given coordinates
    t.cutSphere(xc, yc, zc, radius);
}