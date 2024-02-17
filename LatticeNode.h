#ifndef LATTICENODE_H
#define LATTICENODE_H

struct LatticeNode {
    double feq[9]; // Equilibrium function
    double f[9]; // Distribution function
    double rho;  // Density
    double ux, uy; // Velocity components

    LatticeNode();

    void calculateFeq();
};

#endif // LATTICENODE_H
