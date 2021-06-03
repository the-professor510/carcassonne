#include <iostream>

#include "disjoint_set.hpp"

namespace DisjointSetTests {
auto disjoint_set_init_test() {
    constexpr auto disjoint_set_size = 100;
    auto a = DisjointSet<disjoint_set_size>();

    if (a.get_size() != disjoint_set_size) return false;

    for (auto i = 0; i < disjoint_set_size; i++) {
        auto set = a.find(i);
        if (set != i) {
            return false;
        }
    }

    return true;
}

auto disjoint_set_union_test() {
    constexpr auto disjoint_set_size = 100;
    auto a = DisjointSet<disjoint_set_size>();

    if (a.are_same_set(1, 0)) return false;

    a.unify(0, 1);

    if (!a.are_same_set(1, 0)) return false;
    if (a.are_same_set(1, 2)) return false;

    a.unify(1, 2);

    if (!a.are_same_set(1, 2)) return false;
    if (!a.are_same_set(0, 2)) return false;

    a.unify(50, 2);

    if (!a.are_same_set(1, 2)) return false;
    if (!a.are_same_set(0, 2)) return false;
    if (!a.are_same_set(0, 50)) return false;

    return true;
}

auto run() {
    std::cout << "disjoint_set_init_test: " << (disjoint_set_init_test() ? "PASS ✅" : "FAIL ❌") << '\n';
    std::cout << "disjoint_set_union_test: " << (disjoint_set_union_test() ? "PASS ✅" : "FAIL ❌") << '\n';
}
}  // namespace DisjointSetTests

int main() {
    DisjointSetTests::run();
    return 0;
}
