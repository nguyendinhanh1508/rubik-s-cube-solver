#ifndef SEARCH_H
#define SEARCH_H
#include <iostream>
#include <vector>
#include "phases.h"
#include "checking.h"
#include "moves.h"

bool dfs_phase_one(Cube& cube, int depth, int threshold, std::vector<Notation>& path, Notation prev);
bool idastar_phase_one(Cube start, std::vector<Notation>& solution);
bool dfs_phase_two(Cube& cube, int depth, int threshold, std::vector<Notation>& path, Notation last_move);
bool idastar_phase_two(Cube& cube, std::vector<Notation>& solution);
#endif