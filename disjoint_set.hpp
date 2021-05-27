#pragma once

#include <numeric>
#include <vector>

// TODO: convert find() to iterative instead of recursive.
// TODO: convert std::vector -> std::array templated on an int.

// adapted from code found here https://www.geeksforgeeks.org/disjoint-set-data-structures/
class DisjointSet {
    int n;
    std::vector<int> rank, parent;

   public:
    // Constructor to create and
    // initialize sets of n items
    DisjointSet(int n) {
        rank = std::vector<int>(n);
        parent = std::vector<int>(n);
        this->n = n;
        make_set();
    }

    // Creates n single item sets
    void make_set() {
        // fills parent with the numbers from 0 -> n - 1.
        std::iota(parent.begin(), parent.end(), 0);
    }

    // Finds the "set id" of given item x
    // which is the ID of a select member
    // of x's set.
    auto find(int x) -> int {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {
            // if x is not the parent of itself
            // Then x is not the representative of
            // its set,
            parent[x] = find(parent[x]);

            // so we recursively call find() on its parent
            // and move i's node directly under the
            // representative of this set
        }
        return parent[x];
    }

    // unify the set that contains x and the set that contains y.
    void unify(int x, int y) {
        // Find current sets of x and y
        auto xset = find(x);
        auto yset = find(y);

        // If they are already in same set
        if (xset == yset)
            return;

        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            // If ranks are same, then increment
            // rank.
            parent[yset] = xset;
            rank[xset]++;
        }
    }

    auto are_same_set(int x, int y) -> bool {
        return find(x) == find(y);
    }
};