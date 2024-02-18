#include <iostream>
#include <vector>
#include "Lattice.h"
#include <ctime>

using namespace std;


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
    printLattice(lattice);
    
    lattice.initializeToEquilibrium(1);
    printLattice(lattice);

    lattice.initializeRandomly(); 
    printLattice(lattice);

    lattice.countFeqs();
    printLattice(lattice);
    
    lattice.collision(1.0, 1.0);
    printLattice(lattice);

    lattice.stream();
    printLattice(lattice);

    return 0;
}
