#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "Voxel.h"

/**
 * The Sculptor class allows for the creation o voxel-based meshes.
 *
 * Details.
 *
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * Sculptor trono(_nx,_ny,_nz); // Declaration
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 */
class Sculptor
{
protected:
    Voxel ***v;       // 3D matrix
    int nx, ny, nz;   // Dimensions
    float r, g, b, a; // Current drawing color
public:
    /**
     * This is the Sculptor class' constructor method.
     *
     * This constructor method dynamically allocates a 3D matrix defined by
     * the given parameters, which the class' methods utilize to draw on. It
     * also saves the dimensions of the matrix and sets the drawing color as
     * (r=0, g=0, b=0, a=0).
     *
     * @param _nx The x dimension size.
     * @param _ny The y dimension size.
     * @param _nz The z dimension size.
     * @see Sculptor, setColor()
     */
    Sculptor(int _nx, int _ny, int _nz);
    ~Sculptor();
    /**
     * Brief.
     *
     * Details.
     *
     */
    void setColor(float r, float g, float b, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void writeOFF(const char *filename);
};

#endif