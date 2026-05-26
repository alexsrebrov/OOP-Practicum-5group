#include <iostream>
#include "Vector.hpp"
#include "Map.hpp"
#include "Array.hpp"

int main() {
    Vector<int> nums;
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(8);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(9);
    nums.push_back(5);
    nums.push_back(7);

    Map<char, int> result = nums
        .stream()
        .filter([](const int& x) { return x > 2; })
        .sort([](const int& lhs, const int& rhs) {return lhs > rhs;})
        .limit(4)
        .map<char>([](const int& x) {return 'a' + x;})
        .toMap<int>([](const char c) {return c - 'a'; });

    for (auto num : result) {
        std::cout << num.key << " " << num.value << '\n';
    }

    Array<int> arr(4);
    arr.setAt(0, 8);
    arr.setAt(1, -9);
    arr.setAt(2, 1);
    arr.setAt(3, 7);

    Vector<double> res = arr.stream()
        .filter([](int num) {return num >= 0;})
        .map<double>([](int num) {return num * 1.5;})
        .toVector();
    
    for (auto num : res) {
        std::cout << num << ' ';
    }
}