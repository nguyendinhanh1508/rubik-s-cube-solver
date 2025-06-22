#ifndef MOVES_H
#define MOVES_H
#include <iostream>
#include "../include/cube.h"

void rotate(int& a, int& b, int& c, int& d, bool ccw);
void apply_move(Cube &cube, Notation move);
#endif