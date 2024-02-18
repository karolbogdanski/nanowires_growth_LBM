#include "Lattice.h"
#include <iostream>

Lattice::Lattice(int w, int h) : width(w), height(h), nodes(w * h) {}

    LatticeNode& Lattice::operator()(int x, int y) {
        return nodes[y * width + x];
    }

    const LatticeNode& Lattice::operator()(int x, int y) const {
        return nodes[y * width + x];
    }

    void Lattice::countFeqs() {

        for (int i = 0; i < width; i++) {
            for (int j = 0; j< height; j++){
                operator()(i, j).calculateFeq();
            }
        }
    }

    void Lattice::printNode(int x, int y){
            std::cout << "Node (" << x << ", " << y << "): ";
            std::cout << "Density: " << this->operator()(x, y).rho << ", ";
            std::cout << "Velocity: (" << this->operator()(x, y).ux << ", " << this->operator()(x, y).uy << ")" << std::endl;
            std::cout << "Feq: ";
            for(int k = 0; k < 9; k++) std::cout << this->operator()(x, y).feq[k] << ", ";
            std::cout << std::endl;
            std::cout << "F: ";
            for(int k = 0; k < 9; k++) std::cout << this->operator()(x, y).f[k] << ", ";
            std::cout << std::endl;
    }

    void Lattice::initializeToEquilibrium(double initialDensity) {
            for (LatticeNode& node : this->nodes) {
                node.rho = initialDensity;
                node.ux = 0.0;
                node.uy = 0.0;
                node.calculateFeq(); // Calculate equilibrium based on initial density and zero velocities

                // Assign the equilibrium distribution to the distribution functions of the node
                for (int i = 0; i < 9; ++i) {
                    node.f[i] = node.feq[i]; // Assuming feq is a member of LatticeNode that holds the equilibrium distribution
                }
            }
        }

    void Lattice::collision( double t, double tau) {
        for (LatticeNode& node : this->nodes){
            for (int i = 0; i < 9; ++i) {
                // Compute the BGK collision term
                node.f[i] = t*(node.f[i] - (node.f[i] - node.feq[i])) / tau;
            }
        }
    }
       void Lattice::stream() {
        std::vector<LatticeNode> tempNodes = nodes; // Temporary copy for the streaming step

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                // Stream each distribution function to the neighboring nodes
                for (int i = 0; i < 9; ++i) {
                    int newX = (x + c[i][0] + width) % width; // Account for periodic boundary conditions
                    int newY = (y + c[i][1] + height) % height; // Account for periodic boundary conditions

                    nodes[newY * width + newX].f[i] = tempNodes[y * width + x].f[i];
                }
            }
        }
}

    void Lattice::initializeRandomly() {
        for (LatticeNode& node : nodes) {
            node.rho = 1.0;  // Example density
            node.ux = 0.05;  // Example small x-velocity
            node.uy = 0.05;  // Example small y-velocity
            
            // Initialize distribution functions with random values
            for (int i = 0; i < 9; ++i) {
                node.f[i] = static_cast<double>(rand()) / RAND_MAX;
            }
        }
    }
