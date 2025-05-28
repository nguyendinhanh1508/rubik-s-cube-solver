#include <iostream>
#include "include/cube.h"
#include "helper/moves.cpp"
#include "helper/checking.cpp"
#include "search.cpp"
#include <vector>
#include "io.cpp"

int main() {
    Cube scrambled = input();
    std::vector<Notation> phase_one_moves, phase_two_moves;
    if (idastar_phase_one(scrambled, phase_one_moves)) {
        Cube G1 = scrambled;
        for (auto it : phase_one_moves) {
            apply_move(G1, it);
        }
        if (idastar_phase_two(G1, phase_two_moves)) {
            std::vector<Notation> solution = phase_one_moves;
            solution.insert(solution.end(), phase_two_moves.begin(), phase_two_moves.end());
            std::cout << "Solution(" << solution.size() << " moves):\n";
            output(solution);
        }
    }
}