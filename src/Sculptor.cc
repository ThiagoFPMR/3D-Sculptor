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
   /* NOTE: This method uses a 'this' pointer instead of just giving the parameters
    * better names because modifying the function parameters is not allowed.*/
   // Defines the current drawing color values as the ones given
   this->r = r;
   this->g = g;
   this->b = b;
   this->a = alpha;
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
      throw std::invalid_argument("Sculptor::cutBox(): arguments must be smaller than the respective matrix dimensions.");
   if (x0 > x1 || y0 > y1 || z0 > z1)
      throw std::invalid_argument("Sculptor::cutBox(): x1, y1 and z1 must be equal or greater than x0, y0 and z0 respectivelly.");
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
            if (r2 < pow(radius, 2))
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
            if (r2 < pow(radius, 2))
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
   float leftEq;
   // Checking if the parameters are valid
   if (xcenter >= nx || ycenter >= ny || zcenter >= nz)
      throw std::invalid_argument("Sculptor::putEllipsoid(): arguments must be smaller than the respective matrix dimensions.");
   /* Activating and settings the color for every voxel
    * in the ellipsoid defined by the parameter values */
   for (int i = 0; i < nx; i++)
      for (int j = 0; j < ny; j++)
         for (int k = 0; k < nz; k++)
         {
            leftEq = 0;
            // Defining the left side of the equation
            leftEq += (float)pow(i - xcenter, 2) / (float)pow(rx, 2);
            leftEq += (float)pow(j - ycenter, 2) / (float)pow(ry, 2);
            leftEq += (float)pow(k - zcenter, 2) / (float)pow(rz, 2);
            // Checking whether the equation is valid for the chosen voxel
            if (leftEq < 1)
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
   float leftEq;
   // Checking if the parameters are valid
   if (xcenter >= nx || ycenter >= ny || zcenter >= nz)
      throw std::invalid_argument("Sculptor::cutEllipsoid(): arguments must be smaller than the respective matrix dimensions.");
   // Deactivating every voxel in the sphere defined by the parameter values
   for (int i = 0; i < nx; i++)
      for (int j = 0; j < ny; j++)
         for (int k = 0; k < nz; k++)
         {
            leftEq = 0;
            // Defining the left side of the equation
            leftEq += (float)pow(i - xcenter, 2) / (float)pow(rx, 2);
            leftEq += (float)pow(j - ycenter, 2) / (float)pow(ry, 2);
            leftEq += (float)pow(k - zcenter, 2) / (float)pow(rz, 2);
            // Checking whether the equation is valid for the chosen voxel
            if (leftEq < 1)
            {
               // Deactivating the voxel
               v[i][j][k].isOn = false;
            }
         }
}

// Write .OFF File
void Sculptor::writeOFF(const char *filename)
{
   // Defines variables that will be used in this method
   int nVertices = 0, nFaces = 0, nActiveVoxels = 0, **activeVoxelCoords;
   activeVoxelCoords = new int *[nx * ny * nz];
   activeVoxelCoords[0] = new int[3 * nx * ny * nz];
   for (int i = 1; i < nx * ny * nz; i++)
      activeVoxelCoords[i] = activeVoxelCoords[i - 1] + 3;
   /* The loop below iterates through every voxel, checks whether it's active,
    * and updates the count variables based on it. It also stores the active
    * voxels' coords in arrays for further use.*/
   for (int i = 0; i < nx; i++)
      for (int j = 0; j < ny; j++)
         for (int k = 0; k < nz; k++)
         {
            if (v[i][j][k].isOn)
            {
               activeVoxelCoords[nActiveVoxels][0] = i;
               activeVoxelCoords[nActiveVoxels][1] = j;
               activeVoxelCoords[nActiveVoxels][2] = k;
               nActiveVoxels++;
               nVertices += 8;
               nFaces += 6;
            }
         }
   // Opens the .OFF file to write on
   std::ofstream fout;
   fout.open(filename);
   if (!fout.is_open())
      exit(1);
   // Writes the opening lines of the file
   fout << "OFF\n";
   fout << nVertices << " " << nFaces << " 0\n";
   /* The loop below loops through every voxel and writes their corner
    * coordinates to the .OFF file.*/
   for (int i = 0; i < nActiveVoxels; i++)
   {
      /* For this code implementation, the top-left-front corner of every voxel
       * is (i, j, k) while the bottom-right-back corner is (i+1, j+1, k+1). The
       * coordinates for the other corners are based around them.*/
      int corners[8][3] = {{activeVoxelCoords[i][0], activeVoxelCoords[i][1], activeVoxelCoords[i][2]},
                           {activeVoxelCoords[i][0], activeVoxelCoords[i][1], activeVoxelCoords[i][2] + 1},
                           {activeVoxelCoords[i][0], activeVoxelCoords[i][1] + 1, activeVoxelCoords[i][2]},
                           {activeVoxelCoords[i][0] + 1, activeVoxelCoords[i][1], activeVoxelCoords[i][2]},
                           {activeVoxelCoords[i][0] + 1, activeVoxelCoords[i][1] + 1, activeVoxelCoords[i][2]},
                           {activeVoxelCoords[i][0], activeVoxelCoords[i][1] + 1, activeVoxelCoords[i][2] + 1},
                           {activeVoxelCoords[i][0] + 1, activeVoxelCoords[i][1], activeVoxelCoords[i][2] + 1},
                           {activeVoxelCoords[i][0] + 1, activeVoxelCoords[i][1] + 1, activeVoxelCoords[i][2] + 1}};
      // Writing to the .OFF file
      for (int j = 0; j < 8; j++)
      {
         fout << corners[j][0] << " ";
         fout << corners[j][1] << " ";
         fout << corners[j][2] << "\n";
      }
   }
   /* The loop below loops through every face of every voxel and writes
    * their corners and the color used to paint them to the .OFF file.*/
   for (int i = 0; i < nActiveVoxels; i++)
   {
      // Gets the colors for the voxel
      double red = v[activeVoxelCoords[i][0]][activeVoxelCoords[i][1]][activeVoxelCoords[i][2]].r;
      double green = v[activeVoxelCoords[i][0]][activeVoxelCoords[i][1]][activeVoxelCoords[i][2]].g;
      double blue = v[activeVoxelCoords[i][0]][activeVoxelCoords[i][1]][activeVoxelCoords[i][2]].b;
      double alpha = v[activeVoxelCoords[i][0]][activeVoxelCoords[i][1]][activeVoxelCoords[i][2]].a;

      double faces[6][9] = {{4, 8. * i, 8. * i + 3., 8. * i + 6., 8. * i + 1., red, green, blue, alpha},
                            {4, 8. * i, 8. * i + 1, 8. * i + 5., 8. * i + 2., red, green, blue, alpha},
                            {4, 8. * i, 8. * i + 2., 8. * i + 4., 8. * i + 3., red, green, blue, alpha},
                            {4, 8. * i + 2., 8. * i + 5., 8. * i + 7., 8. * i + 4., red, green, blue, alpha},
                            {4, 8. * i + 3., 8. * i + 4., 8. * i + 7., 8. * i + 6., red, green, blue, alpha},
                            {4, 8. * i + 1., 8. * i + 6., 8. * i + 7., 8. * i + 5., red, green, blue, alpha}};

      // Writing to the .OFF file
      for (int j = 0; j < 6; j++)
      {
         fout << (int)faces[j][0] << " ";
         fout << (int)faces[j][1] << " ";
         fout << (int)faces[j][2] << " ";
         fout << (int)faces[j][3] << " ";
         fout << (int)faces[j][4] << " ";
         fout << faces[j][5] << " ";
         fout << faces[j][6] << " ";
         fout << faces[j][7] << " ";
         fout << faces[j][8] << "\n";
      }
   }

   fout.close();
   delete[] activeVoxelCoords[0];
   delete[] activeVoxelCoords;
}
