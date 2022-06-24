#include "../include/Sculptor.h"
#include "../include/GeometricFigure.h"
#include "../include/PutVoxel.h"

// Defines the necessary variables to implement the draw method
PutVoxel::PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float alpha)
{
    // Setting the class' coordinates
    x = _x;
    y = _y;
    z = _z;
    // Setting the class' coordinates
    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

// Overwrites the draw method
void PutVoxel::draw(Sculptor &t)
{
    /* Sets the drawing color used by the given Sculptor
     * object and draws a single Voxel in the given coordinates */
    t.setColor(r, g, b, a);
    t.putVoxel(x, y, z);
}