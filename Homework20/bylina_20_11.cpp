//
// Created by bylin on 28.11.2024.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    string name = "output.txt";
    vector<int> V = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> firstHalf(V.begin(), V.begin() + V.size() / 2);
    vector<int> secondHalf(V.begin() + V.size() / 2, V.end());
    sort(firstHalf.begin(), firstHalf.end());
    sort(secondHalf.begin(), secondHalf.end());
    vector<int> result;
    set_difference(secondHalf.begin(), secondHalf.end(),
                   firstHalf.begin(), firstHalf.end(),
                   back_inserter(result));
    ofstream outputFile(name);
    for (int num : result) {
        outputFile << num << "\n";
    }
    return 0;
}
