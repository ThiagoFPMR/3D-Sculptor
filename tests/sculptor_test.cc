#include <iostream>

#include "../include/Voxel.h"
#include "../include/Sculptor.h"

/*
void test() {
    Voxel *** h;
    Voxel a;
    a.a = 0.7;
    Sculptor obj(3, 3, 3);
    std::cout << "ye" << std::endl;
    obj.getMatrix(&h);
    std::cout << "gottem" << std::endl;
    for (int i = 0; i < 3; i++) {
        h[0][0][i] = a;
        std::cout << h[0][0][i].a << std::endl;
    }
}
*/
void color_test() {
    Sculptor obj(-3, 3, 3);
    std::cout << "ye" << std::endl;
    obj.setColor(0.4, 0.5, 0.3, 0.7);
}

int main() {
    std::cout << 0 << std::endl;
    //test();
    color_test();
    std::cout << 1 << std::endl;
    return 0;
}