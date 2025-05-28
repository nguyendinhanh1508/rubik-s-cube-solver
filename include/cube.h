#ifndef CUBE_H
#define CUBE_H

/*
the edges are in clockwise order
it starts from the top layer of the cube, and the one closest to us will be 0, then it will go in a clockwise pattern
  UB           2
UL  UR       1   3
  UF           0
second layer:
BL  BR       5   6

FL  FR       4   7
last layer:
  DB          10
DL  DR       9  11
  DF           8
the corners are also in clockwise order
top layer:
U1  U2       1   2
U0  U3       0   3
bottom layer:
D1  D2       5   6
D0  D3       4   7
*/


/* legend
edge positions:
UF = 0, UL = 1, UB = 2, UR = 3
FL = 4, BL = 5, BR = 6, FR = 7
DF = 8, DL = 9, DB = 10, DR = 11
corner positions:
U0 = 0, U1 = 1, U2 = 2, U3 = 3
D0 = 4, D1 =  5, D2 = 6, D3 = 7
*/
enum Notation { 
    U, U2, U_PRIME, 
    D, D2, D_PRIME, 
    R, R2, R_PRIME, 
    L, L2, L_PRIME, 
    F, F2, F_PRIME, 
    B, B2, B_PRIME
};

struct Cube {
    int edges[12];
    int corners[8];
    int edge_orient[12];
    int corner_orient[8];
};
#endif