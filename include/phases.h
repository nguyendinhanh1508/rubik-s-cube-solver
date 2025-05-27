#ifndef PHASES_H
#define PHASES_H
#include "cube.h"
#include <vector>

std::vector<Notation> phase_one = {
    U, U2, U_PRIME, 
    D, D2, D_PRIME, 
    R, R2, R_PRIME, 
    L, L2, L_PRIME, 
    F, F2, F_PRIME, 
    B, B2, B_PRIME
};

std::vector<Notation> phase_two = {
    U, U2, U_PRIME,
    D, D2, D_PRIME,
    F2, B2, R2, L2
};
#endif