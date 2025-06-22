#ifndef CHECKING_H
#define CHECKING_H
#include <iostream>
#include "cube.h"

bool in_G1(const Cube& cube);

int heuristic_phase_one(const Cube& cube);

int heuristic_phase_two(const Cube& cube);

bool is_solved(const Cube& cube);
#endif