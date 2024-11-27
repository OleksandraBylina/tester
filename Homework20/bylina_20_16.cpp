//
// Created by bylin on 28.11.2024.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    vector<int> V = {15, 26, 37, 48, 59, 20, 31, 42};
    map<int, vector<int>> M;
    for (int num : V) {
        int key = num % 10;
        M[key].push_back(num);
    }
    for (const auto &pair : M) {
        cout << pair.first << ": ";
        for (size_t i = 0; i < pair.second.size(); ++i) {
            cout << pair.second[i];
            if (i < pair.second.size() - 1) {
                cout << ", ";
            }
        }
        cout << "\n";
    }
    return 0;
}
