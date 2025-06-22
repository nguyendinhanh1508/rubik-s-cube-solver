# 3x3 Rubik's Cube Solver
# Overview
This project implements a two-phase IDA* solver for the 3x3 Rubik's Cube. The solver uses:<br>
Phase 1: Solves to a subgroup G1 (edges oriented, corners oriented, middle edges in middle slice)<br>
Phase 2: Completes the solve to a fully solved cube
# Components
1. ```cube.h```:
- Defines the cube representation.
2. ```moves.h```/```moves.cpp```:
- Implements all 18 basic cube notations.
3. ```search.h```/```search.cpp```:
- Search algo
- Implements IDA* with two phases.
4. ```checking.h```/```checking.cpp```:
- **G1** group membership checking.
- Heuristic for both phases.
- Solved state verification.
# Algorithm Details
## Phase 1(G1 Group)
### Goal:
- All edge orientations are correct.
- All corner orientations are correct.
- Middle edges (FL, BL, BR, FR) are in middle slice.
### Allowed moves:
All 18 basic moves
### Heuristic:
- Sum of edge orientation.
- Sum of corner orientation.
- Sum of middle edges not in middle slice.
## Phase 2(Solved state)
### Goal:
Fully Solved cube
### Allowed moves:
- U, U', U2
- D, D', D2
- F2, B2, R2, L2
### Heuristic:
- Maximum of edge and corner permutation distances divided by 4
# How to use
Please use the command in ```compilecmd.txt``` to compile your code.<br>
Then just run main.exe and enjoy!<br>