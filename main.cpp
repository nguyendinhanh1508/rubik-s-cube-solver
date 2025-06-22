#include <iostream>
#include <vector>
#include "include/checking.h"
#include "include/cube.h"
#include "include/io.h"
#include "include/moves.h"
#include "include/phases.h"
#include "include/search.h"

int main() {
    Cube scrambled = input();
    std::cout << "Hang on I'm thinking of the solution!\n";
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
        } else {
            std::cout << "Failed phase two";
        }
    } else {
        std::cout << "Failed phase one";
    }
}