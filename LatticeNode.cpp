#include "LatticeNode.h"

const double c[9][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
const double w[9] = {4.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0, 1.0 / 36.0, 1.0 / 36.0, 1.0 / 36.0, 1.0 / 36.0};

LatticeNode::LatticeNode() : rho(0.0), ux(0.0), uy(0.0) {
    for (int i = 0; i < 9; ++i) f[i] = 0.0;
}

void LatticeNode::calculateFeq() {
    for(int i = 0; i < 9; ++i) {
        double ciDotU = c[i][0] * ux + c[i][1] * uy;
        feq[i] = w[i] * rho * (1 + 3 * ciDotU + 4.5 * ciDotU * ciDotU - 1.5 * (ux * ux + uy * uy));
    }
}
