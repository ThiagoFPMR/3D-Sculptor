#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>

#include "../include/Voxel.h"
#include "../include/Sculptor.h"

// Parameterized Constructor
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
   /* This class stores all the values of the 3-dimensional
    * matrix in a single 1D vector, then uses axuliary vectors
    * to point to it for ease of accessibility */
   // Checks the validity of the arguments passed
   if (_nx <= 0 || _ny <= 0 || _nz <= 0)
      throw std::invalid_argument("Constructor parameters must be greater than zero.");
   // Storing the dimensions given as object attributes
   nx = _nx;
   ny = _ny;
   nz = _nz;
   // Dynamically allocating main and auxiliary arrays
   v = new Voxel **[_nx];
   v[0] = new Voxel *[_nx * _ny];
   v[0][0] = new Voxel[_nx * _ny * _nz];
   // Making the auxiliary vetors point ot the elements vector
   for (int i = 1; i < _nx; i++)
      v[i] = v[i - 1] + _ny;
   for (int i = 1; i < _nx * _ny; i++)
      v[0][i] = v[0][i - 1] + _nz;
   // Defining the default drawing color as 'invisible black'
   r = 0;
   g = 0;
   b = 0;
   a = 0;
}

// Destructor
Sculptor::~Sculptor()
{
   // Freeing the dynamically allocated memory
   delete[] v[0][0];
   delete[] v[0];
   delete[] v;
}

// Sets the current drawing color
void Sculptor::setColor(float r, float g, float b, float alpha)
{
   // Defines the current drawing color values as the ones given
   r = r;
   g = g;
   b = b;
   a = alpha;
}

// Activates the voxel in the (x, y, z) coordinate
void Sculptor::putVoxel(int x, int y, int z)
{
   // Checking whether the position given is valid
   if (x >= nx || y >= ny || z >= nz)
      throw std::invalid_argument("Sculptor::putVoxel(): arguments must be smaller than the respective matrix dimensions.");
   // Activating the voxel
   v[x][y][z].isOn = true;
   // Setting the color of the voxel
   v[x][y][z].r = r;
   v[x][y][z].g = g;
   v[x][y][z].b = b;
   v[x][y][z].a = a;
}

// Deativates the voxel in the (x, y, z) coordinate
void Sculptor::cutVoxel(int x, int y, int z)
{
   // Checking whether the position given is valid
   if (x >= nx || y >= ny || z >= nz)
      throw std::invalid_argument("Sculptor::cutVoxel(): arguments must be smaller than the respective matrix dimensions.");
   // Deactivating the voxel
   v[x][y][z].isOn = false;
}

// Draws a box shape within the given (x, y, z) coordinates
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
   // Checking if the parameters are valid
   if (x0 >= nx || x1 >= nx || y0 >= ny || y1 >= ny || z0 >= nz || z1 >= nz)
      throw std::invalid_argument("Sculptor::putBox(): arguments must be smaller than the respective matrix dimensions.");
   if (x0 > x1 || y0 > y1 || z0 > z1)
      throw std::invalid_argument("Sculptor::putBox(): x1, y1 and z1 must be equal or greater than x0, y0 and z0 respectivelly.");
   /* Activating and settings the color for every voxel
    * in the box defined by the parameter values */
   for (int i = x0; i <= x1; i++)
      for (int j = y0; j <= y1; j++)
         for (int k = z0; k <= z1; k++)
         {
            // Activating the voxel
            v[i][j][k].isOn = true;
            // Setting the color of the voxel
            v[i][j][k].r = r;
            v[i][j][k].g = g;
            v[i][j][k].b = b;
            v[i][j][k].a = a;
         }
}

// Deletes a box shape within the given (x, y, z) coordinates
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
   // Checking if the parameters are valid
   if (x0 >= nx || x1 >= nx || y0 >= ny || y1 >= ny || z0 >= nz || z1 >= nz)
      throw std::invalid_argument("Sculptor::putBox(): arguments must be smaller than the respective matrix dimensions.");
   if (x0 > x1 || y0 > y1 || z0 > z1)
      throw std::invalid_argument("Sculptor::putBox(): x1, y1 and z1 must be equal or greater than x0, y0 and z0 respectivelly.");
   // Deactivating every voxel in the box defined by the parameter values
   for (int i = x0; i <= x1; i++)
      for (int j = y0; j <= y1; j++)
         for (int k = z0; k <= z1; k++)
         {
            // Deactivating the voxel
            v[i][j][k].isOn = false;
         }
}

// Draws a sphere shape from the given parameters
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
   /* For each voxel in the Sculptor object matrix, this method
    * checks whether they fit the equation of a sphere based
    * on their (i, j, k) coordinates and the parameters given */
   int r2;
   // Checking if the parameters are valid
   if (xcenter >= nx || ycenter >= ny || zcenter >= nz)
      throw std::invalid_argument("Sculptor::putSphere(): arguments must be smaller than the respective matrix dimensions.");
   /* Activating and settings the color for every voxel
    * in the sphere defined by the parameter values */
   for (int i = 0; i < nx; i++)
      for (int j = 0; j < ny; j++)
         for (int k = 0; k < nz; k++)
         {
            // Defining the left side of the equation
            r2 = pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
            // Checking whether the equation is valid for the chosen voxel
            if (r2 == pow(radius, 2))
            {
               // Activating the voxel
               v[i][j][k].isOn = true;
               // Setting the color of the voxel
               v[i][j][k].r = r;
               v[i][j][k].g = g;
               v[i][j][k].b = b;
               v[i][j][k].a = a;
            }
         }
}

// Deletes a sphere shape from the given parameters
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
   /* For each voxel in the Sculptor object matrix, this method
    * checks whether they fit the equation of a sphere based
    * on their (i, j, k) coordinates and the parameters given */
   int r2;
   // Checking if the parameters are valid
   if (xcenter >= nx || ycenter >= ny || zcenter >= nz)
      throw std::invalid_argument("Sculptor::cutSphere(): arguments must be smaller than the respective matrix dimensions.");
   // Deactivating every voxel in the sphere defined by the parameter values
   for (int i = 0; i < nx; i++)
      for (int j = 0; j < ny; j++)
         for (int k = 0; k < nz; k++)
         {
            // Defining the left side of the equation
            r2 = pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
            // Checking whether the equation is valid for the chosen voxel
            if (r2 == pow(radius, 2))
            {
               // Deactivating the voxel
               v[i][j][k].isOn = false;
            }
         }
}

// Draws an elipsoid shape from the given parameters
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
   /* For each voxel in the Sculptor object matrix, this method
    * checks whether they fit the equation of an ellipsoid based
    * on their (i, j, k) coordinates and the parameters given */
   float leftEq = 0;
   // Checking if the parameters are valid
   if (xcenter >= nx || ycenter >= ny || zcenter >= nz)
      throw std::invalid_argument("Sculptor::putEllipsoid(): arguments must be smaller than the respective matrix dimensions.");
   /* Activating and settings the color for every voxel
    * in the ellipsoid defined by the parameter values */
   for (int i = 0; i < nx; i++)
      for (int j = 0; j < ny; j++)
         for (int k = 0; k < nz; k++)
         {
            // Defining the left side of the equation
            leftEq += (float)pow(i - xcenter, 2) / (float)pow(rx, 2);
            leftEq += (float)pow(j - ycenter, 2) / (float)pow(ry, 2);
            leftEq += (float)pow(k - zcenter, 2) / (float)pow(rz, 2);
            // Checking whether the equation is valid for the chosen voxel
            if (leftEq == 1)
            {
               // Activating the voxel
               v[i][j][k].isOn = true;
               // Setting the color of the voxel
               v[i][j][k].r = r;
               v[i][j][k].g = g;
               v[i][j][k].b = b;
               v[i][j][k].a = a;
            }
         }
}

// Draws an elipsoid shape from the given parameters
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
   /* For each voxel in the Sculptor object matrix, this method
    * checks whether they fit the equation of an ellipsoid based
    * on their (i, j, k) coordinates and the parameters given */
   float leftEq = 0;
   // Checking if the parameters are valid
   if (xcenter >= nx || ycenter >= ny || zcenter >= nz)
      throw std::invalid_argument("Sculptor::cutEllipsoid(): arguments must be smaller than the respective matrix dimensions.");
   // Deactivating every voxel in the sphere defined by the parameter values
   for (int i = 0; i < nx; i++)
      for (int j = 0; j < ny; j++)
         for (int k = 0; k < nz; k++)
         {
            // Defining the left side of the equation
            leftEq += (float)pow(i - xcenter, 2) / (float)pow(rx, 2);
            leftEq += (float)pow(j - ycenter, 2) / (float)pow(ry, 2);
            leftEq += (float)pow(k - zcenter, 2) / (float)pow(rz, 2);
            // Checking whether the equation is valid for the chosen voxel
            if (leftEq == 1)
            {
               // Deactivating the voxel
               v[i][j][k].isOn = false;
            }
         }
}

// Write .OFF File
void Sculptor::writeOFF(const char *filename)
{
   /* TO-DO: Rewrite method from scratch (coords and faces have to repeat)
    * just keep track of what the ID for each coord is with a counter var and
    * loop for each voxel without keeping memory and we'll be fine */

   /* TO USE LATER:
    * file.seekg(std::ios::beg);
    * file.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); */
}
