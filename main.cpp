#include <iostream>
#include <vector>
#include <iomanip>
#include "funcstep.h"

int main() {
    std::cout << "Step function test" << std::endl;

    std::vector<double> koefs = {1.0}; // a = 1
    FuncStep step(koefs);

    // по точкам вручную
    std::cout << "Manual mode" << std::endl;
    for (int i = -10; i < 10; ++i) {
        std::cout << "y(" << std::setw(3) << i << ") = " << step.calc(i) << std::endl;
    }

    // по массиву x
    std::cout << "All array mode" << std::endl;
    auto res = step.calcAll(-5.0, 0.5, 5.0);
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << "y(" << std::setw(5) << res[i].first << ") = "
                  << res[i].second << std::endl;
    }

    return 0;
}