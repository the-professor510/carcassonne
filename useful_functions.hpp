#include <sstream>
#include <string>
#include <vector>

auto string_split(const std::string& string, const char sep) {
    // consider switching to a search-and-allocate method if push_back becomes a performace bottleneck.
    std::vector<std::string> result;

    std::stringstream ss(string);
    while (ss.good()) {
        std::string substr;
        std::getline(ss, substr, sep);
        result.push_back(substr);
    }

    return result;
}