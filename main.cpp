#include <iostream>
#include "state.hpp"
#include "tile.hpp"

int main(int argc, char const *argv[]) {
    auto bag = get_tiles();
    
    for (auto tile : bag) {
        std::cout << tile.repr() << "\n";
    }

    return 0;
}