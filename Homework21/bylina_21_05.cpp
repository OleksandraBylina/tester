//
// Created by bylin on 01.12.2024.
//

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main() {
    string input = "example text";
    transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {
        return toupper(c);
    });

    cout << input << endl;
    return 0;
}