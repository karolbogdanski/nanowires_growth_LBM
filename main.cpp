#include <iostream>
#include <vector>



struct LatticeNode {
    double f[9]; // Assuming a D2Q9 model for simplicity
    double rho;  // Density
    double ux, uy; // Velocity components
    
    LatticeNode() : rho(0.0), ux(0.0), uy(0.0) {
        for (int i = 0; i < 9; ++i) f[i] = 0.0;
    }

    void calculateFeq() {

        for(int i = 0; i < 9; ++i) {


        }
    }
};

class Lattice {
public:
    int width, height;
    std::vector<LatticeNode> nodes;

    Lattice(int w, int h) : width(w), height(h), nodes(w * h) {}

        // Make sure this operator is not const-qualified if you want to modify the nodes.
    LatticeNode& operator()(int x, int y) {
        return nodes[y * width + x];
    }

    // Const version used for const objects
    const LatticeNode& operator()(int x, int y) const {
        return nodes[y * width + x];
    }

};

void printLattice(Lattice& lattice) {
    for (int y = 0; y < lattice.height; ++y) {
        for (int x = 0; x < lattice.width; ++x) {
            LatticeNode& node = lattice(x, y);
            std::cout << "Node (" << x << ", " << y << "): ";
            std::cout << "Density: " << node.rho << ", ";
            std::cout << "Velocity: (" << node.ux << ", " << node.uy << ")\n";
        }
        std::cout << std::endl;
    }
}

int main() {

    Lattice lattice(5, 5); // Create a 5x5 lattice

    // Example initialization (setting some arbitrary values)
    lattice(2, 2).rho = 1.0; // Set density at the center
    lattice(2, 2).ux = 0.1;  // Set x velocity at the center
    lattice(2, 2).uy = 0.2;  // Set y velocity at the center

    printLattice(lattice);

    return 0;
}
