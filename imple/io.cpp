#include "../include/io.h"

void output(std::vector<Notation> solution) {
    std::string res = "";
    for (auto it : solution) {
        std::string cur;
        switch (it) {
            case U:
                cur = "U ";
                break;
            case U2:
                cur = "U2 ";
                break;
            case U_PRIME:
                cur = "U' ";
                break;
            case D:
                cur = "D ";
                break;
            case D2:
                cur = "D2 ";
                break;
            case D_PRIME:
                cur = "D' ";
                break;
            case R:
                cur = "R ";
                break;
            case R2:
                cur = "R2 ";
                break;
            case R_PRIME:
                cur = "R' ";
                break;
            case L:
                cur = "L ";
                break;
            case L2:
                cur = "L2 ";
                break;
            case L_PRIME:
                cur = "L' ";
                break;
            case F:
                cur = "F ";
                break;
            case F2:
                cur = "F2 ";
                break;
            case F_PRIME:
                cur = "F' ";
                break;
            case B:
                cur = "B ";
                break;
            case B2:
                cur = "B2 ";
                break;
            case B_PRIME:
                cur = "B' ";
                break;
        }
        res.insert(res.end(), cur.begin(), cur.end());
    }
    std::cout << res;
}

#include <chrono>
#include <random>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int rnd() {
    return rng() % 18;
}
std::vector<Notation> scramble_gen(int length = 20) {
    std::vector<Notation> all_moves = { 
        U, U2, U_PRIME, 
        D, D2, D_PRIME, 
        R, R2, R_PRIME, 
        L, L2, L_PRIME, 
        F, F2, F_PRIME, 
        B, B2, B_PRIME
    };

    std::vector<Notation> scramble;
    scramble.reserve(length);
    Notation last_move = static_cast<Notation>(-1);
    for (int i = 0; i < length; i++) {
        Notation move;
        do {
            move = all_moves[rnd()];
        } while (move / 3 == last_move / 3);
        scramble.push_back(move);
        last_move = move;
    }
    return scramble;
}

Cube input() { //no input yet so just scramble and give solution
    Cube cube;
    for (int i = 0; i < 12; i++) {
        cube.edges[i] = i;
        cube.edge_orient[i] = 0;
    }
    for (int i = 0; i < 8; i++) {
        cube.corners[i] = i;
        cube.corner_orient[i] = 0;
    }
    auto scramble = scramble_gen();
    for (auto it : scramble) {
        apply_move(cube, it);
    }
    std::cout << "Generated scramble (" << scramble.size() << " moves):\n";
    output(scramble);
    std::cout << '\n';
    return cube;
}