#include "../include/moves.h"

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

void apply_move(Cube &cube, Notation move){
    switch(move) {
        case U:
            rotate(cube.edges[0], cube.edges[1], cube.edges[2], cube.edges[3]);
            rotate(cube.edge_orient[0], cube.edge_orient[1], cube.edge_orient[2], cube.edge_orient[3]);
            rotate(cube.corners[0], cube.corners[1], cube.corners[2], cube.corners[3]);
            rotate(cube.corner_orient[0], cube.corner_orient[1], cube.corner_orient[2], cube.corner_orient[3]);
            break;
        case U2:
            rotate(cube.edges[0], cube.edges[1], cube.edges[2], cube.edges[3]);
            rotate(cube.edge_orient[0], cube.edge_orient[1], cube.edge_orient[2], cube.edge_orient[3]);
            rotate(cube.corners[0], cube.corners[1], cube.corners[2], cube.corners[3]);
            rotate(cube.corner_orient[0], cube.corner_orient[1], cube.corner_orient[2], cube.corner_orient[3]);
            rotate(cube.edges[0], cube.edges[1], cube.edges[2], cube.edges[3]);
            rotate(cube.edge_orient[0], cube.edge_orient[1], cube.edge_orient[2], cube.edge_orient[3]);
            rotate(cube.corners[0], cube.corners[1], cube.corners[2], cube.corners[3]);
            rotate(cube.corner_orient[0], cube.corner_orient[1], cube.corner_orient[2], cube.corner_orient[3]);
            break;
        case U_PRIME:
            rotate(cube.edges[0], cube.edges[1], cube.edges[2], cube.edges[3], true);
            rotate(cube.edge_orient[0], cube.edge_orient[1], cube.edge_orient[2], cube.edge_orient[3], true);
            rotate(cube.corners[0], cube.corners[1], cube.corners[2], cube.corners[3], true);
            rotate(cube.corner_orient[0], cube.corner_orient[1], cube.corner_orient[2], cube.corner_orient[3], true);
            break;
        case D:
            rotate(cube.edges[8], cube.edges[9], cube.edges[10], cube.edges[11], true);
            rotate(cube.edge_orient[8], cube.edge_orient[9], cube.edge_orient[10], cube.edge_orient[11], true);
            rotate(cube.corners[4], cube.corners[5], cube.corners[6], cube.corners[7], true);
            rotate(cube.corner_orient[4], cube.corner_orient[5], cube.corner_orient[6], cube.corner_orient[7], true);
            break;
        case D2:
            rotate(cube.edges[8], cube.edges[9], cube.edges[10], cube.edges[11], true);
            rotate(cube.edge_orient[8], cube.edge_orient[9], cube.edge_orient[10], cube.edge_orient[11], true);
            rotate(cube.corners[4], cube.corners[5], cube.corners[6], cube.corners[7], true);
            rotate(cube.corner_orient[4], cube.corner_orient[5], cube.corner_orient[6], cube.corner_orient[7], true);
            rotate(cube.edges[8], cube.edges[9], cube.edges[10], cube.edges[11], true);
            rotate(cube.edge_orient[8], cube.edge_orient[9], cube.edge_orient[10], cube.edge_orient[11], true);
            rotate(cube.corners[4], cube.corners[5], cube.corners[6], cube.corners[7], true);
            rotate(cube.corner_orient[4], cube.corner_orient[5], cube.corner_orient[6], cube.corner_orient[7], true);
            break;
        case D_PRIME:
            rotate(cube.edges[8], cube.edges[9], cube.edges[10], cube.edges[11]);
            rotate(cube.edge_orient[8], cube.edge_orient[9], cube.edge_orient[10], cube.edge_orient[11]);
            rotate(cube.corners[4], cube.corners[5], cube.corners[6], cube.corners[7]);
            rotate(cube.corner_orient[4], cube.corner_orient[5], cube.corner_orient[6], cube.corner_orient[7]);
            break;
        case L:
            rotate(cube.edges[1], cube.edges[4], cube.edges[9], cube.edges[5], true);
            rotate(cube.edge_orient[1], cube.edge_orient[4], cube.edge_orient[9], cube.edge_orient[5], true);
            rotate(cube.corners[1], cube.corners[0], cube.corners[4], cube.corners[5], true);
            cube.corner_orient[1] = (cube.corner_orient[1] + 1) % 3;
            cube.corner_orient[0] = (cube.corner_orient[0] + 1) % 3;
            cube.corner_orient[4] = (cube.corner_orient[4] + 2) % 3;
            cube.corner_orient[5] = (cube.corner_orient[5] + 2) % 3;
            break;
        case L2:
            rotate(cube.edges[1], cube.edges[4], cube.edges[9], cube.edges[5], true);
            rotate(cube.edge_orient[1], cube.edge_orient[4], cube.edge_orient[9], cube.edge_orient[5], true);
            rotate(cube.corners[1], cube.corners[0], cube.corners[4], cube.corners[5], true);
            cube.corner_orient[1] = (cube.corner_orient[1] + 1) % 3;
            cube.corner_orient[0] = (cube.corner_orient[0] + 1) % 3;
            cube.corner_orient[4] = (cube.corner_orient[4] + 2) % 3;
            cube.corner_orient[5] = (cube.corner_orient[5] + 2) % 3;
            rotate(cube.edges[1], cube.edges[4], cube.edges[9], cube.edges[5], true);
            rotate(cube.edge_orient[1], cube.edge_orient[4], cube.edge_orient[9], cube.edge_orient[5], true);
            rotate(cube.corners[1], cube.corners[0], cube.corners[4], cube.corners[5], true);
            cube.corner_orient[1] = (cube.corner_orient[1] + 1) % 3;
            cube.corner_orient[0] = (cube.corner_orient[0] + 1) % 3;
            cube.corner_orient[4] = (cube.corner_orient[4] + 2) % 3;
            cube.corner_orient[5] = (cube.corner_orient[5] + 2) % 3;
            break;
        case L_PRIME:
            rotate(cube.edges[1], cube.edges[4], cube.edges[9], cube.edges[5]);
            rotate(cube.edge_orient[1], cube.edge_orient[4], cube.edge_orient[9], cube.edge_orient[5]);
            rotate(cube.corners[1], cube.corners[0], cube.corners[4], cube.corners[5]);
            cube.corner_orient[1] = (cube.corner_orient[1] + 2) % 3;
            cube.corner_orient[0] = (cube.corner_orient[0] + 2) % 3;
            cube.corner_orient[4] = (cube.corner_orient[4] + 1) % 3;
            cube.corner_orient[5] = (cube.corner_orient[5] + 1) % 3;
            break;
        case R:
            rotate(cube.edges[3], cube.edges[7], cube.edges[11], cube.edges[6], true);
            rotate(cube.edge_orient[3], cube.edge_orient[7], cube.edge_orient[11], cube.edge_orient[6], true);
            rotate(cube.corners[2], cube.corners[3], cube.corners[7], cube.corners[6], true);
            cube.corner_orient[2] = (cube.corner_orient[2] + 1) % 3;
            cube.corner_orient[3] = (cube.corner_orient[3] + 1) % 3;
            cube.corner_orient[6] = (cube.corner_orient[6] + 2) % 3;
            cube.corner_orient[7] = (cube.corner_orient[7] + 2) % 3;
            break;
        case R2:
            rotate(cube.edges[3], cube.edges[7], cube.edges[11], cube.edges[6], true);
            rotate(cube.edge_orient[3], cube.edge_orient[7], cube.edge_orient[11], cube.edge_orient[6], true);
            rotate(cube.corners[2], cube.corners[3], cube.corners[7], cube.corners[6], true);
            cube.corner_orient[2] = (cube.corner_orient[2] + 1) % 3;
            cube.corner_orient[3] = (cube.corner_orient[3] + 1) % 3;
            cube.corner_orient[6] = (cube.corner_orient[6] + 2) % 3;
            cube.corner_orient[7] = (cube.corner_orient[7] + 2) % 3;
            rotate(cube.edges[3], cube.edges[7], cube.edges[11], cube.edges[6], true);
            rotate(cube.edge_orient[3], cube.edge_orient[7], cube.edge_orient[11], cube.edge_orient[6], true);
            rotate(cube.corners[2], cube.corners[3], cube.corners[7], cube.corners[6], true);
            cube.corner_orient[2] = (cube.corner_orient[2] + 1) % 3;
            cube.corner_orient[3] = (cube.corner_orient[3] + 1) % 3;
            cube.corner_orient[6] = (cube.corner_orient[6] + 2) % 3;
            cube.corner_orient[7] = (cube.corner_orient[7] + 2) % 3;
            break;
        case R_PRIME:
            rotate(cube.edges[3], cube.edges[7], cube.edges[11], cube.edges[6]);
            rotate(cube.edge_orient[3], cube.edge_orient[7], cube.edge_orient[11], cube.edge_orient[6]);
            rotate(cube.corners[2], cube.corners[3], cube.corners[7], cube.corners[6]);
            cube.corner_orient[2] = (cube.corner_orient[2] + 2) % 3;
            cube.corner_orient[3] = (cube.corner_orient[3] + 2) % 3;
            cube.corner_orient[6] = (cube.corner_orient[6] + 1) % 3;
            cube.corner_orient[7] = (cube.corner_orient[7] + 1) % 3;
            break;
        case F:
            rotate(cube.edges[0], cube.edges[4], cube.edges[8], cube.edges[7], true);
            cube.edge_orient[0] ^= 1;
            cube.edge_orient[4] ^= 1;
            cube.edge_orient[8] ^= 1;
            cube.edge_orient[7] ^= 1;
            rotate(cube.corners[0], cube.corners[3], cube.corners[7], cube.corners[4], true);
            cube.corner_orient[0] = (cube.corner_orient[0] + 1) % 3;
            cube.corner_orient[3] = (cube.corner_orient[3] + 2) % 3;
            cube.corner_orient[7] = (cube.corner_orient[7] + 1) % 3;
            cube.corner_orient[4] = (cube.corner_orient[4] + 2) % 3;
            break;
        case F2:
            rotate(cube.edges[0], cube.edges[4], cube.edges[8], cube.edges[7], true);
            cube.edge_orient[0] ^= 1;
            cube.edge_orient[4] ^= 1;
            cube.edge_orient[8] ^= 1;
            cube.edge_orient[7] ^= 1;
            rotate(cube.corners[0], cube.corners[3], cube.corners[7], cube.corners[4], true);
            cube.corner_orient[0] = (cube.corner_orient[0] + 1) % 3;
            cube.corner_orient[3] = (cube.corner_orient[3] + 2) % 3;
            cube.corner_orient[7] = (cube.corner_orient[7] + 1) % 3;
            cube.corner_orient[4] = (cube.corner_orient[4] + 2) % 3;
            rotate(cube.edges[0], cube.edges[4], cube.edges[8], cube.edges[7], true);
            cube.edge_orient[0] ^= 1;
            cube.edge_orient[4] ^= 1;
            cube.edge_orient[8] ^= 1;
            cube.edge_orient[7] ^= 1;
            rotate(cube.corners[0], cube.corners[3], cube.corners[7], cube.corners[4], true);
            cube.corner_orient[0] = (cube.corner_orient[0] + 1) % 3;
            cube.corner_orient[3] = (cube.corner_orient[3] + 2) % 3;
            cube.corner_orient[7] = (cube.corner_orient[7] + 1) % 3;
            cube.corner_orient[4] = (cube.corner_orient[4] + 2) % 3;
            break;
        case F_PRIME:
            rotate(cube.edges[0], cube.edges[4], cube.edges[8], cube.edges[7]);
            cube.edge_orient[0] ^= 1;
            cube.edge_orient[4] ^= 1;
            cube.edge_orient[8] ^= 1;
            cube.edge_orient[7] ^= 1;
            rotate(cube.corners[0], cube.corners[3], cube.corners[7], cube.corners[4]);
            cube.corner_orient[0] = (cube.corner_orient[0] + 2) % 3;
            cube.corner_orient[3] = (cube.corner_orient[3] + 1) % 3;
            cube.corner_orient[7] = (cube.corner_orient[7] + 2) % 3;
            cube.corner_orient[4] = (cube.corner_orient[4] + 1) % 3;
            break;
        case B:
            rotate(cube.edges[2], cube.edges[5], cube.edges[10], cube.edges[6], true);
            cube.edge_orient[2] ^= 1;
            cube.edge_orient[5] ^= 1;
            cube.edge_orient[10] ^= 1;
            cube.edge_orient[6] ^= 1;
            rotate(cube.corners[1], cube.corners[2], cube.corners[6], cube.corners[5], true);
            cube.corner_orient[1] = (cube.corner_orient[1] + 2) % 3;
            cube.corner_orient[2] = (cube.corner_orient[2] + 1) % 3;
            cube.corner_orient[6] = (cube.corner_orient[6] + 1) % 3;
            cube.corner_orient[5] = (cube.corner_orient[5] + 2) % 3;
            break;
        case B2:
            rotate(cube.edges[2], cube.edges[5], cube.edges[10], cube.edges[6], true);
            cube.edge_orient[2] ^= 1;
            cube.edge_orient[5] ^= 1;
            cube.edge_orient[10] ^= 1;
            cube.edge_orient[6] ^= 1;
            rotate(cube.corners[1], cube.corners[2], cube.corners[6], cube.corners[5], true);
            cube.corner_orient[1] = (cube.corner_orient[1] + 2) % 3;
            cube.corner_orient[2] = (cube.corner_orient[2] + 1) % 3;
            cube.corner_orient[6] = (cube.corner_orient[6] + 1) % 3;
            cube.corner_orient[5] = (cube.corner_orient[5] + 2) % 3;
            rotate(cube.edges[2], cube.edges[5], cube.edges[10], cube.edges[6], true);
            cube.edge_orient[2] ^= 1;
            cube.edge_orient[5] ^= 1;
            cube.edge_orient[10] ^= 1;
            cube.edge_orient[6] ^= 1;
            rotate(cube.corners[1], cube.corners[2], cube.corners[6], cube.corners[5], true);
            cube.corner_orient[1] = (cube.corner_orient[1] + 2) % 3;
            cube.corner_orient[2] = (cube.corner_orient[2] + 1) % 3;
            cube.corner_orient[6] = (cube.corner_orient[6] + 1) % 3;
            cube.corner_orient[5] = (cube.corner_orient[5] + 2) % 3;
            break;
        case B_PRIME:
            rotate(cube.edges[2], cube.edges[5], cube.edges[10], cube.edges[6]);
            cube.edge_orient[2] ^= 1;
            cube.edge_orient[5] ^= 1;
            cube.edge_orient[10] ^= 1;
            cube.edge_orient[6] ^= 1;
            rotate(cube.corners[1], cube.corners[2], cube.corners[6], cube.corners[5]);
            cube.corner_orient[1] = (cube.corner_orient[1] + 1) % 3;
            cube.corner_orient[2] = (cube.corner_orient[2] + 2) % 3;
            cube.corner_orient[6] = (cube.corner_orient[6] + 2) % 3;
            cube.corner_orient[5] = (cube.corner_orient[5] + 1) % 3;
            break;
    }
}