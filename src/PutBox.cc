#include "../include/Sculptor.h"
#include "../include/GeometricFigure.h"
#include "../include/PutBox.h"

// Defines the necessary variables to implement the draw method
PutBox::PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float alpha)
{
    // Setting the class' coordinates
    x0 = _x0;
    x1 = _x1;
    y0 = _y0;
    y1 = _y1;
    z0 = _z0;
    z1 = _z1;
    // Setting the class' colors
    r = _r;
    b = _b;
    g = _g;
    a = alpha;
}
// Overwrites the draw method
void PutBox::draw(Sculptor &t)
{
    /* Sets the drawing color used by the given Sculptor
     * object and draws a Box in the given coordinates */
    t.setColor(r, g, b, a);
    t.putBox(x0, x1, y0, y1, z0, z1);
}