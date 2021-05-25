#pragma once

#include <string>
#include <vector>
#include <fstream>

enum Special : int8_t {
    None,
    Monastery,
    Shield,
    Village,
};

enum Edge : int8_t {
    Farm,
    Road,
    City,
};

class Tile {
   private:
    Special special_feature;
    Edge l_feature, r_feature, u_feature, d_feature;
    bool divides_farm;

   public:
    Tile *l, *r, *u, *d;

    Tile(Special special_feature, Edge l_feature, Edge r_feature, Edge u_feature, Edge d_feature, bool divides_farm) {
        this->special_feature = special_feature;
        this->l_feature = l_feature;
        this->r_feature = r_feature;
        this->u_feature = u_feature;
        this->d_feature = d_feature;
    }
};

auto get_tiles() {
    std::vector<Tile> bag;

    // Create an input filestream
    std::ifstream tileset("tileset.csv");
}