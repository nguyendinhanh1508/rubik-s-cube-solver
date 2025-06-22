#ifndef IO_H
#define IO_H
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "cube.h"
#include "moves.h"

void output(std::vector<Notation> solution);
std::vector<Notation> scramble_gen(int length);
Cube input();
#endif