#include "../include/Sculptor.h"
#include "../include/GeometricFigure.h"
#include "../include/CutVoxel.h"

// Defines the necessary variables to implement the draw method
CutVoxel::CutVoxel(int _x, int _y, int _z)
{
    x = _x;
    y = _y;
    z = _z;
}
// Overwrites the draw method
void CutVoxel::draw(Sculptor &t)
{
    // Cuts the Voxel in the given coordinates
    t.cutVoxel(x, y, z);
}