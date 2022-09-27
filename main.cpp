#include <iostream>
#include <span>
#include <unordered_set>
#include <vector>

namespace {
    bool is_unique1(const std::span<const char>& s) {
        std::unordered_set<char> set;
        for(auto c : s) {
            if(set.contains(c)) {
                return false;
            }
            set.emplace(c);
        }
    }

    bool is_unique2(const std::span<const char>& s) {
        std::vector<char> v(s.begin(), s.end());
        std::sort(v.begin(), v.end());
        return std::unique(v.begin(), v.end()) == v.end();
    }
}

int main() {
    {
        const char str[] = "abcdfef";
        std::clog << std::boolalpha << is_unique1(str) << '\n';
    }

    {
        const char str[] = "abcdfe";
        std::clog << std::boolalpha << is_unique1(str) << '\n';
    }

    {
        const char str[] = "abcdfef";
        std::clog << std::boolalpha << is_unique2(str) << '\n';
    }

    {
        const char str[] = "abcdfe";
        std::clog << std::boolalpha << is_unique2(str) << '\n';
    }
    return 0;
}
