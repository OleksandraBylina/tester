//
// Created by bylin on 23.11.2024.
//
#include <iostream>
#include <list>
#include <cmath>
#include <algorithm>

class NumberStorage {
    std::list<int> numbers;

public:
    void add(int number) {
        numbers.push_back(number);
    }

    void remove(int number) {
        numbers.remove(number);
    }

    int findClosest(int target) const {
        auto it = std::min_element(numbers.begin(), numbers.end(), [target](int a, int b) {
            return std::abs(a - target) < std::abs(b - target);
        });
        return it != numbers.end() ? *it : -1;
    }

    void print() const {
        for (int number : numbers) {
            std::cout << number << ' ';
        }
        std::cout << '\n';
    }
};

int main() {
    NumberStorage storage;
    storage.add(10);
    storage.add(20);
    storage.add(30);
    storage.print();
    storage.remove(20);
    storage.print();
    std::cout << storage.findClosest(25) << '\n';
    return 0;
}
