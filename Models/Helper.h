#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

class Helper {
public:
    static void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    static string toUpperCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
    }

    static bool isNumeric(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
};

#endif
