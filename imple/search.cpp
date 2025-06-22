#include "../include/search.h"

bool dfs_phase_one(Cube& cube, int depth, int threshold, std::vector<Notation>& path, Notation prev) {
    int estimate = depth + heuristic_phase_one(cube);
    if (estimate > threshold) return false;
    if (in_G1(cube)) return true;
    for (Notation move : phase_one) {
        if (prev != -1 && move / 3 == prev / 3) continue;
        Cube next = cube;
        apply_move(next, move);
        path.push_back(move);
        if (dfs_phase_one(next, depth + 1, threshold, path, move)) return true;
        path.pop_back();
    }
    return false;
}

bool idastar_phase_one(Cube start, std::vector<Notation>& solution) {
    int threshold = heuristic_phase_one(start);
    while (threshold <= 20) {
        std::vector<Notation> path;
        if (dfs_phase_one(start, 0, threshold, path, static_cast<Notation>(-1))) {
            solution = path;
            return true;
        }
        threshold++;
    }
    return false;
}

bool dfs_phase_two(Cube& cube, int depth, int threshold, std::vector<Notation>& path, Notation last_move) {
    int estimate = depth + heuristic_phase_two(cube);
    if (estimate > threshold) return false;
    if (is_solved(cube)) return true;
    for (Notation move : phase_two) {
        if (last_move != -1 && move / 3 == last_move / 3) continue;
        Cube next = cube;
        apply_move(next, move);
        path.push_back(move);
        if (dfs_phase_two(next, depth + 1, threshold, path, move)) return true;
        path.pop_back();
    }
    return false;
}

bool idastar_phase_two(Cube& cube, std::vector<Notation>& solution) {
    int threshold = heuristic_phase_two(cube);
    while (threshold <= 20) {
        std::vector<Notation> path;
        if (dfs_phase_two(cube, 0, threshold, path, static_cast<Notation>(-1))) {
            solution = path;
            return true;
        }
        threshold++;
    }
    return false;
}