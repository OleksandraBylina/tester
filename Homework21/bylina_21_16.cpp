//
// Created by bylin on 01.12.2024.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

template <typename InputIt, typename OutputIt, typename UnaryOperation, typename UnaryPredicate>
OutputIt transform_if(InputIt first, InputIt last, OutputIt result, UnaryOperation op, UnaryPredicate pred) {
    while (first != last) {
        if (pred(*first)) {
            *result++ = op(*first);
        }
        ++first;
    }
    return result;
}

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7};
    vector<int> output;

    auto is_even = [](int x) { return x % 2 == 0; };
    auto square = [](int x) { return x * x; };

    transform_if(input.begin(), input.end(), back_inserter(output), square, is_even);

    for (int x : output) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
