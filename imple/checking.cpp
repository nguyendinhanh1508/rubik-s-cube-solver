#include "../include/checking.h"

bool in_G1(const Cube& cube) {
    for (auto it : cube.edge_orient) {
        if (it != 0) return false;
    }
    for (auto it : cube.corner_orient) {
        if (it != 0) return false;
    }
    for (int i = 4; i <= 7; i++) {
        if (cube.edges[i] < 4 || cube.edges[i] > 7)  return false;
    }
    return true;
}

int heuristic_phase_one(const Cube& cube) {
    int cost = 0;
    for (auto it : cube.edge_orient) {
        cost += it;
    }
    for (auto it : cube.corner_orient) {
        cost += (it == 0);
    }
    for (int i = 4; i <= 7; i++){
        if (cube.edges[i] < 4 || cube.edges[i] > 7) cost++;
    }
    return cost;
}

int heuristic_phase_two(const Cube& cube) {
    int misplaced_edges = 0;
    int misplaced_corners = 0;
    for (int i = 0; i < 12; i++) {
        if (cube.edges[i] != i) misplaced_edges++;
    }
    for (int i = 0; i < 8; i++) {
        if (cube.corners[i] != i) misplaced_corners++;
    }
    return std::max(misplaced_edges, misplaced_corners) / 4;
}

bool is_solved(const Cube& cube) {
    for (int i = 0; i < 12; i++) {
        if (cube.edges[i] != i) return false;
    }
    for (int i = 0; i < 8; i++) {
        if (cube.corners[i] != i) return false;
    }
    return true;
}