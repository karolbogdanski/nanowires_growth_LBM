#ifndef LATTICE_H
#define LATTICE_H

#include <vector>
#include "LatticeNode.h"

class Lattice {
public:
    int width, height;
    std::vector<LatticeNode> nodes;

    Lattice(int w, int h);

    LatticeNode& operator()(int x, int y);
    const LatticeNode& operator()(int x, int y) const;

    void printNode(int x, int y);
    void countFeqs();
    void initializeToEquilibrium(double initialDensity);
    void collision(double t, double tau);
    void stream();
    void initializeRandomly();

private:
    //TODO: This is declared both here and in LatticeNode. Refactor later
    // Assuming c is defined here as the array of discrete velocities
    const int c[9][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
};

#endif // LATTICE_H
