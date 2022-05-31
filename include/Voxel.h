#ifndef VOXEL_H
#define VOXEL_H

// The voxel is the base for the sculptor
struct Voxel {
    float r,g,b; // Colors
    float a;
    // Transparency
    bool isOn; // Included or not
};

#endif