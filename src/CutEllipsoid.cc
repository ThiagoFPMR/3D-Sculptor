#include "../include/Sculptor.h"
#include "../include/GeometricFigure.h"
#include "../include/CutEllipsoid.h"

// Defines the necessary variables to implement the draw method
CutEllipsoid::CutEllipsoid(int _xc, int _yc, int _zc, int _rx, int _ry, int _rz)
{
    // Setting the class' coordinates
    xc = _xc;
    rx = _rx;
    yc = _yc;
    ry = _ry;
    zc = _zc;
    rz = _rz;
}
// Overwrites the draw method
void CutEllipsoid::draw(Sculptor &t)
{
    // Cuts the Ellipsoid in the given coordinates
    t.cutEllipsoid(xc, yc, zc, rx, ry, rz);
}