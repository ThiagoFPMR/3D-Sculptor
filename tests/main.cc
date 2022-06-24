#include <iostream>
#include <vector>

#include "../include/Voxel.h"
#include "../include/Sculptor.h"

int main()
{
    // cria um escultor cuja matriz tem 10x10x10 voxels
    Sculptor canvas(21, 21, 21);
    // para mudar a cor do voxel
    canvas.setColor(0, 0, 1.0, 1.0); // azul
    // ativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
    canvas.putEllipsoid(10, 10, 10, 9, 5, 7);
    // desativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
    // trono.cutBox(1,8,1,9,1,9);
    // grava a escultura digital no arquivo "trono.off"
    canvas.writeOFF("eeeee.off");
    return 0;
}