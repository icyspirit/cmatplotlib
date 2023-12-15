

#include "cmatplotlib.hpp"

using namespace cmatplotlib;

int main()
{
    std::vector<double> x{1, 2, 3};
    std::vector<double> y{2, 4, 6};
    std::vector<std::vector<double>> z = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};
    print(x, y);
    figure();
    plot(x, y, "hi");
    figure();
    contour(x, y, z);

    /*
    figure();
    axes("3d");
    plot(x, y);
    */

    show();
}
