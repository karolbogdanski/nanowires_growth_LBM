#include <iostream>
#include <vector>
#include "Lattice.h"

using namespace std;


// struct LatticeNode {
//     double feq[9]; //Equilibrium function
//     double f[9]; // Assuming a D2Q9 model for simplicity
//     double rho;  // Density
//     double ux, uy; // Velocity components
//     const double c[9][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
//     const double w[9] = {4.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 36.0, 1.0 / 36.0, 1.0 / 36.0, 1.0 / 36.0};
//     //TODO: consider this during optimalization
//     //double uSq = ux * ux + uy * uy;

//     LatticeNode() : rho(0.0), ux(0.0), uy(0.0) {
//         for (int i = 0; i < 9; ++i) f[i] = 0.0;
//     }

//     void calculateFeq() {

//         for(int i = 0; i < 9; ++i) {
//             double ciDotU = c[i][0] * ux + c[i][1] * uy; // e_i . u
//             feq[i] = w[i] * rho * (1 + 3 * ciDotU + 4.5 * ciDotU * ciDotU - 1.5 * (ux * ux + uy * uy));
//         }
//     }
// };

// class Lattice {
// public:
//     int width, height;
//     std::vector<LatticeNode> nodes;

//     Lattice(int w, int h) : width(w), height(h), nodes(w * h) {}

//         // Make sure this operator is not const-qualified if you want to modify the nodes.
//     LatticeNode& operator()(int x, int y) {
//         return nodes[y * width + x];
//     }

//     // Const version used for const objects
//     const LatticeNode& operator()(int x, int y) const {
//         return nodes[y * width + x];
//     }

//     void printNode(int x, int y){
//             std::cout << "Node (" << x << ", " << y << "): ";
//             std::cout << "Density: " << operator()(x, y).rho << ", ";
//             std::cout << "Velocity: (" << operator()(x, y).ux << ", " << operator()(x, y).uy << ")" << endl;
//             std::cout << "Feq: ";
//             for(int k = 0; k < 9; k++) std::cout << operator()(x, y).feq[k] << ", ";
//             std::cout << std::endl;
//             std::cout << "F: ";
//             for(int k = 0; k < 9; k++) std::cout << operator()(x, y).f[k] << ", ";
//             std::cout << std::endl;

//     }

//     void countFeqs() {

//         for (int i = 0; i < width; i++) {
//             for (int j = 0; j< height; j++){
//                 operator()(i, j).calculateFeq();
//             }
//         }
//     }

//     void initializeToEquilibrium(double initialDensity) {
//         for (LatticeNode& node : nodes) {
//             node.rho = initialDensity;
//             node.ux = 0.0;
//             node.uy = 0.0;
//             node.calculateFeq(); // Calculate equilibrium based on initial density and zero velocities

//             // Assign the equilibrium distribution to the distribution functions of the node
//             for (int i = 0; i < 9; ++i) {
//                 node.f[i] = node.feq[i]; // Assuming feq is a member of LatticeNode that holds the equilibrium distribution
//             }
//         }
//     }

//     // void validateNodeCalc(int x, int y) {

//     //     for(int i = 0; i < 9; ++i) {
//     //         double ciDotU = operator()(x, y).c[i][0] * operator()(x, y).ux + operator()(x, y).c[i][1] * operator()(x, y).uy; // e_i . u
//     //         std::cout << "cciDotU= " << ciDotU << std::endl;
//     //         //operator()(x, y).f[i] = operator()(x, y).w[i] * operator()(x, y).rho * (1 + 3 * ciDotU + 4.5 * ciDotU * ciDotU - 1.5 * operator()(x, y).uSq);
//     //     }
//     // }

//};

void printLattice(Lattice& lattice) {
    for (int y = 0; y < lattice.height; ++y) {
        for (int x = 0; x < lattice.width; ++x) {
            lattice.printNode(x, y);
        }
        std::cout << std::endl;
    }
}




int main() {

    cout << "dupa" << endl;
    string dupa = "ass";
    cout << dupa << endl;

    Lattice lattice(5, 5); // Create a 5x5 lattice

    // Example initialization (setting some arbitrary values)

    printLattice(lattice);
    lattice.initializeToEquilibrium(1);
    //printLattice(lattice);
    lattice.printNode(2, 2);

    lattice(2, 2).ux = 0.1;  // Set x velocity at the center
    lattice(2, 2).uy = 0.2;  // Set y velocity at the center
    lattice.countFeqs();
    //lattice.calculateNodeFeq(2, 2);
    //std::cout << (1.0/9) * (1 + 3*(1*0.1 + 0*0.2) + 4.5*(1*0.1 + 0*0.2)*(1*0.1 + 0*0.2) - 1.5*(0.1 *0.1 + 0.2*0.2)) << std::endl;
    lattice.printNode(2, 2);
    return 0;
}
