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
};

#endif // LATTICE_H
