#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "../include/Voxel.h"
#include "../include/Sculptor.h"
#include "../include/GeometricFigure.h"
#include "../include/PutVoxel.h"
#include "../include/CutVoxel.h"
#include "../include/PutBox.h"
#include "../include/CutBox.h"
#include "../include/PutSphere.h"
#include "../include/CutSphere.h"
#include "../include/PutEllipsoid.h"
#include "../include/CutEllipsoid.h"

/* TO-DO: Implement copy constructors so there's no need to
 * dynamically allocate everything. Also make the Sculptor
 * storage less of a point of failure (it could lead to too much
 * garbage being generated as of right now).*/

int main()
{
    Sculptor *canvas = nullptr; // Initializes pointer to avoid segmentation fault
    std::vector<GeometricFigure *> cmds;

    std::ifstream fin;
    std::string s;
    std::stringstream sstream;
    fin.open("/home/thiago/Workspace/Uni/DCA1202/3D-Sculptor/tests/test.txt");
    if (!fin.is_open())
        exit(1);

    /* Loops while there is still text to read,
     * reading a line on each iteration */
    while (std::getline(fin, s))
    {
        // Stores the line as a string stream object
        sstream.clear();
        sstream.str(s);
        // Reads out the term determining the line's command
        sstream >> s;
        if (s.compare("dim") == 0)
        {
            // Stores the dimensions of the Sculptor object
            int nx, ny, nz;
            sstream >> nx;
            sstream >> ny;
            sstream >> nz;
            /* Creates the Sculptor object with the given parameters
             * and releases any previously stored values. */
            Sculptor *tmp = canvas;
            canvas = new Sculptor(nx, ny, nz);
            delete tmp;
        }
        if (s.compare("putvoxel") == 0)
        {
            // Store the parameters of the PutVoxel constructor
            int x0, y0, z0;
            float r, g, b, a;
            sstream >> x0;
            sstream >> y0;
            sstream >> z0;
            sstream >> r;
            sstream >> g;
            sstream >> b;
            sstream >> a;
            // Creates a PutVoxel object and adds it to the commands vector
            cmds.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
        }
        if (s.compare("cutvoxel") == 0)
        {
            // Store the parameters of the CutVoxel constructor
            int x0, y0, z0;
            sstream >> x0;
            sstream >> y0;
            sstream >> z0;
            // Creates a CutVoxel object and adds it to the commands vector
            cmds.push_back(new CutVoxel(x0, y0, z0));
        }
        if (s.compare("putbox") == 0)
        {
            // Store the parameters of the PutBox constructor
            int x0, x1, y0, y1, z0, z1;
            float r, g, b, a;
            sstream >> x0;
            sstream >> x1;
            sstream >> y0;
            sstream >> y1;
            sstream >> z0;
            sstream >> z1;
            sstream >> r;
            sstream >> g;
            sstream >> b;
            sstream >> a;
            // Creates a PutBox object and adds it to the commands vector
            cmds.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        if (s.compare("cutbox") == 0)
        {
            // Store the parameters of the CutBox constructor
            int x0, x1, y0, y1, z0, z1;
            sstream >> x0;
            sstream >> x1;
            sstream >> y0;
            sstream >> y1;
            sstream >> z0;
            sstream >> z1;
            // Creates a CutBox object and adds it to the commands vector
            cmds.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        }
        if (s.compare("putsphere") == 0)
        {
            // Store the parameters of the PutSphere constructor
            int x0, y0, z0, radius;
            float r, g, b, a;
            sstream >> x0;
            sstream >> y0;
            sstream >> z0;
            sstream >> radius;
            sstream >> r;
            sstream >> g;
            sstream >> b;
            sstream >> a;
            // Creates a PutSphere object and adds it to the commands vector
            cmds.push_back(new PutSphere(x0, y0, z0, radius, r, g, b, a));
        }
        if (s.compare("cutsphere") == 0)
        {
            // Store the parameters of the CutSphere constructor
            int x0, y0, z0, radius;
            sstream >> x0;
            sstream >> y0;
            sstream >> z0;
            sstream >> radius;
            // Creates a CutSphere object and adds it to the commands vector
            cmds.push_back(new CutSphere(x0, y0, z0, radius));
        }
        if (s.compare("putellipsoid") == 0)
        {
            // Store the parameters of the PutEllipsoid constructor
            int x0, y0, z0, rx, ry, rz;
            float r, g, b, a;
            sstream >> x0;
            sstream >> y0;
            sstream >> z0;
            sstream >> rx;
            sstream >> ry;
            sstream >> rz;
            sstream >> r;
            sstream >> g;
            sstream >> b;
            sstream >> a;
            // Creates a PutEllipsoid object and adds it to the commands vector
            cmds.push_back(new PutEllipsoid(x0, y0, z0, rx, ry, rz, r, g, b, a));
        }
        if (s.compare("cutellipsoid") == 0)
        {
            // Store the parameters of the CutEllipsoid constructor
            int x0, y0, z0, rx, ry, rz;
            sstream >> x0;
            sstream >> y0;
            sstream >> z0;
            sstream >> rx;
            sstream >> ry;
            sstream >> rz;
            // Creates a CutEllipsoid object and adds it to the commands vector
            cmds.push_back(new CutEllipsoid(x0, y0, z0, rx, ry, rz));
        }
    }
    for (int i = 0; i < cmds.size(); i++)
    {
        cmds[i]->draw(*canvas);
    }

    canvas->writeOFF("exit.off");

    // Deletes the dynamically allocated objects
    for (int i = 0; i < cmds.size(); i++)
        delete cmds[i];
    delete canvas;
    return 0;
}