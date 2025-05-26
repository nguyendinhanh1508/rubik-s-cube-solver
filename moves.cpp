#include <iostream>
#include "include/cube.h"

void rotate(int& a, int& b, int& c, int& d, bool ccw = false){
    if (ccw) {
        int hold = a;
        a = b;
        b = c;
        c = d;
        d = hold;
    } else {
        int hold = a;
        a = d;
        d = c;
        c = b;
        b = hold;
    }
}

void applymove(Cube &cube, Notation move, bool isprime = false){
    switch(move) {
        case U:
            rotate(cube.edges[0], cube.edges[1], cube.edges[2], cube.edges[3], isprime);
            rotate(cube.edge_orient[0], cube.edge_orient[1], cube.edge_orient[2], cube.edge_orient[3], isprime);
            rotate(cube.corners[0], cube.corners[1], cube.corners[2], cube.corners[3], isprime);
            rotate(cube.corner_orient[0], cube.corner_orient[1], cube.corner_orient[2], cube.corner_orient[3], isprime);
            break;
        case D:
            rotate(cube.edges[8], cube.edges[9], cube.edges[10], cube.edges[11], !isprime);
            rotate(cube.edge_orient[8], cube.edge_orient[9], cube.edge_orient[10], cube.edge_orient[11], !isprime);
            rotate(cube.corners[4], cube.corners[5], cube.corners[6], cube.corners[7], !isprime);
            rotate(cube.corner_orient[4], cube.corner_orient[5], cube.corner_orient[6], cube.corner_orient[7], !isprime);
            break;
        case L:
            rotate(cube.edges[1], cube.edges[4], cube.edges[9], cube.edges[5], !isprime);
            rotate(cube.edge_orient[1], cube.edge_orient[4], cube.edge_orient[9], cube.edge_orient[5], !isprime);
            rotate(cube.corners[1], cube.corners[0], cube.corners[4], cube.corners[5], !isprime);
            if (!isprime) {
                cube.corner_orient[1] = (cube.corner_orient[1] + 1) % 3;
                cube.corner_orient[0] = (cube.corner_orient[0] + 1) % 3;
                cube.corner_orient[4] = (cube.corner_orient[4] + 2) % 3;
                cube.corner_orient[5] = (cube.corner_orient[5] + 2) % 3;
            } else {
                cube.corner_orient[1] = (cube.corner_orient[1] + 2) % 3;
                cube.corner_orient[0] = (cube.corner_orient[0] + 2) % 3;
                cube.corner_orient[4] = (cube.corner_orient[4] + 1) % 3;
                cube.corner_orient[5] = (cube.corner_orient[5] + 1) % 3;
            }
            break;
        case R:
            rotate(cube.edges[3], cube.edges[7], cube.edges[11], cube.edges[6], !isprime);
            rotate(cube.edge_orient[3], cube.edge_orient[7], cube.edge_orient[11], cube.edge_orient[6], !isprime);
            rotate(cube.corners[2], cube.corners[3], cube.corners[7], cube.corners[6], !isprime);
            if (!isprime) {
                cube.corner_orient[2] = (cube.corner_orient[2] + 1) % 3;
                cube.corner_orient[3] = (cube.corner_orient[3] + 1) % 3;
                cube.corner_orient[6] = (cube.corner_orient[6] + 2) % 3;
                cube.corner_orient[7] = (cube.corner_orient[7] + 2) % 3;
            } else {
                cube.corner_orient[2] = (cube.corner_orient[2] + 2) % 3;
                cube.corner_orient[3] = (cube.corner_orient[3] + 2) % 3;
                cube.corner_orient[6] = (cube.corner_orient[6] + 1) % 3;
                cube.corner_orient[7] = (cube.corner_orient[7] + 1) % 3;
            }
            break;
        case F:
            rotate(cube.edges[0], cube.edges[4], cube.edges[8], cube.edges[7], !isprime);
            cube.edge_orient[0] ^= 1;
            cube.edge_orient[4] ^= 1;
            cube.edge_orient[8] ^= 1;
            cube.edge_orient[7] ^= 1;
            rotate(cube.corners[0], cube.corners[3], cube.corners[7], cube.corners[4], !isprime);
            if (!isprime) {
                cube.corner_orient[0] = (cube.corner_orient[0] + 1) % 3;
                cube.corner_orient[3] = (cube.corner_orient[3] + 2) % 3;
                cube.corner_orient[7] = (cube.corner_orient[7] + 1) % 3;
                cube.corner_orient[4] = (cube.corner_orient[4] + 2) % 3;
            } else {
                cube.corner_orient[0] = (cube.corner_orient[0] + 2) % 3;
                cube.corner_orient[3] = (cube.corner_orient[3] + 1) % 3;
                cube.corner_orient[7] = (cube.corner_orient[7] + 2) % 3;
                cube.corner_orient[4] = (cube.corner_orient[4] + 1) % 3;
            }
            break;
        case B:
            rotate(cube.edges[2], cube.edges[5], cube.edges[10], cube.edges[6], !isprime);
            cube.edge_orient[2] ^= 1;
            cube.edge_orient[5] ^= 1;
            cube.edge_orient[10] ^= 1;
            cube.edge_orient[6] ^= 1;
            rotate(cube.corners[1], cube.corners[2], cube.corners[6], cube.corners[5], !isprime);
            if (!isprime) {
                cube.corner_orient[1] = (cube.corner_orient[1] + 2) % 3;
                cube.corner_orient[2] = (cube.corner_orient[2] + 1) % 3;
                cube.corner_orient[6] = (cube.corner_orient[6] + 1) % 3;
                cube.corner_orient[5] = (cube.corner_orient[5] + 2) % 3;
            } else {
                cube.corner_orient[1] = (cube.corner_orient[1] + 1) % 3;
                cube.corner_orient[2] = (cube.corner_orient[2] + 2) % 3;
                cube.corner_orient[6] = (cube.corner_orient[6] + 2) % 3;
                cube.corner_orient[5] = (cube.corner_orient[5] + 1) % 3;
            }
            break;
    }
}