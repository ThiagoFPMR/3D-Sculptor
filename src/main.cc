#include <iostream>

#include "../include/Voxel.h"
#include "../include/Sculptor.h"


int main() {
    // cria um escultor cuja matriz tem 10x10x10 voxels
    Sculptor trono(21,21,21);
    // para mudar a cor do voxel
    trono.setColor(0,0,1.0,1.0); // azul
    // ativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
    trono.putEllipsoid(10,10,10,3, 3, 3);
    // desativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
    // trono.cutBox(1,8,1,9,1,9);
    // grava a escultura digital no arquivo "trono.off"
    trono.writeOFF("elipse.off");
    return 0;
}