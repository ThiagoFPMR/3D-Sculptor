#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "Sculptor.h"
#include "GeometricFigure.h"

/**
 * The CutVoxel class is a subclass that works towards
 * implementing polimorfism for its parent class, GeometricFigure.
 *
 * Effecitevly, it provides the same functionality as the
 * cutVoxel() method from the Sculptor class. It stores the paramteres
 * as attributes and draws on any given Sculptor object through
 * its draw() method.
 */
class CutVoxel : public GeometricFigure
{
private:
    int x, y, z;

public:
    CutVoxel(int _x, int _y, int _z);
    void draw(Sculptor &t);
};

#endif