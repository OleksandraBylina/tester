//
// Created by bylin on 01.12.2024.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

struct Date {
    int year, month, day;

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

int monthToNumber(const string& month) {
    static map<string, int> months = {
        {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
        {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
        {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };
    if (isdigit(month[0])) return stoi(month);
    return months[month];
}

int main() {
    ifstream inputFile("dates.txt");
    set<Date> uniqueDates;

    if (!inputFile) {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int day, year;
        string month;

        while (ss >> day >> month >> year) {
            int monthNum = monthToNumber(month);
            uniqueDates.insert({year, monthNum, day});
        }
    }

    inputFile.close();

    for (const auto& date : uniqueDates) {
        cout << date.year << "/" << date.month << "/" << date.day << ", ";
    }

    cout << endl;
    return 0;
}

