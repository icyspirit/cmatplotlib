
#include "cmatplotlib.hpp"
#include <vector>

int main() {
    std::vector<double> x, y;
    std::vector<std::vector<double>> z;
    for (int i=0; i<10; ++i) {
        x.push_back(i);
    }
    for (int j=0; j<10; ++j) {
        y.push_back(j);
    }
    for (int i=0; i<10; ++i) {
        z.push_back(std::vector<double>());
        for (int j=0; j<10; ++j) {
            z[i].push_back(i*j);
        }
    }
    
    mpl<double> m;
    m.plot(x);
    m.show();
    m.plot(x, y);
    m.show();
    m.contour(z);
    m.show();
    m.contour(x, y, z);
    m.show();
}
