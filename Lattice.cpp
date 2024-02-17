#include "Lattice.h"
#include <iostream>

Lattice::Lattice(int w, int h) : width(w), height(h), nodes(w * h) {}

LatticeNode& Lattice::operator()(int x, int y) {
    return nodes[y * width + x];
}

const LatticeNode& Lattice::operator()(int x, int y) const {
    return nodes[y * width + x];
}

void Lattice::printNode(int x, int y) {
    // Implementation of printNode...
}

void Lattice::countFeqs() {
    // Implementation of countFeqs...
}

void Lattice::initializeToEquilibrium(double initialDensity) {
    // Implementation of initializeToEquilibrium...
}
