#include <iostream>
#include "include/cube.h"
#include <vector>

Cube input() {

}

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