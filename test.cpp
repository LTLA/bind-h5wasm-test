#include <emscripten/bind.h>
#include "tatami/ext/HDF5DenseMatrix.hpp"
#include "tatami/stats/sums.hpp"
#include <algorithm>

int dimprod(std::string file, std::string name) {
    tatami::HDF5DenseMatrix<double, int> mat(file, name);
    auto sums = tatami::column_sums(&mat);
    return std::accumulate(sums.begin(), sums.end(), 0);
}

EMSCRIPTEN_BINDINGS(dimprod) {
    emscripten::function("dimprod", &dimprod);
}
