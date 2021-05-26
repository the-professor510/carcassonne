#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

enum class Special : int8_t {
    None,
    Monastery,
    Shield,
    Village,
};

enum class Edge : int8_t {
    Farm,
    Road,
    City,
};

auto string_to_feature(const std::string& string) {
    if (string.compare("none") == 0) {
        return Special::None;
    } else if (string.compare("monastery") == 0) {
        return Special::Monastery;
    } else if (string.compare("village") == 0) {
        return Special::Village;
    } else {
        return Special::Shield;
    }
}

auto string_to_edge(const std::string& string) {
    if (string.compare("farm") == 0) {
        return Edge::Farm;
    } else if (string.compare("road") == 0) {
        return Edge::Road;
    } else {
        return Edge::City;
    }
}

auto feature_to_string(Special f) -> std::string {
    switch (f) {
        case Special::None:
            return "none";
        case Special::Monastery:
            return "monastery";
        case Special::Village:
            return "village";
        case Special::Shield:
            return "shield";
    }
}

auto edge_to_string(Edge e) -> std::string {
    switch (e) {
        case Edge::Farm:
            return "farm";
        case Edge::Road:
            return "road";
        case Edge::City:
            return "city";
    }
}

class Tile {
   private:
    Special special_feature;
    Edge l_feature, r_feature, u_feature, d_feature;
    bool divides_farm;

   public:
    Tile *l, *r, *u, *d;

    Tile(Special special_feature, Edge l_feature, Edge r_feature, Edge u_feature, Edge d_feature) {
        this->special_feature = special_feature;
        this->l_feature = l_feature;
        this->r_feature = r_feature;
        this->u_feature = u_feature;
        this->d_feature = d_feature;
    }

    auto repr() {
        return feature_to_string(special_feature) + " | left: " +
               edge_to_string(l_feature) + " | right: " +
               edge_to_string(r_feature) + " | up: " +
               edge_to_string(u_feature) + " | down: " +
               edge_to_string(d_feature);
    }
};

auto get_tiles() {
    std::vector<Tile> bag;

    // Create an input filestream
    std::ifstream tileset("tileset.csv");

    // Make sure the file is open
    if (!tileset.is_open()) throw std::runtime_error("Could not open file");

    std::string line;

    // discard line 1
    std::getline(tileset, line);
    // Read data, line by line
    while (std::getline(tileset, line)) {
        std::stringstream ss(line);
        std::vector<std::string> result;
        while (ss.good()) {
            std::string substr;
            std::getline(ss, substr, ',');
            result.push_back(substr);
        }

        auto left = string_to_edge(result[0]);
        auto right = string_to_edge(result[1]);
        auto top = string_to_edge(result[2]);
        auto bottom = string_to_edge(result[3]);
        auto feature = string_to_feature(result[4]);
        // auto passthrough = string_to_passthrough(result[5]);
        auto tile_count = std::stoi(result[6]);

        for (auto i = 0; i < tile_count; i++) {
            bag.emplace_back(feature, left, right, top, bottom);
        }
    }

    // by this point, we have a filled bag of tiles.
    return bag;
}