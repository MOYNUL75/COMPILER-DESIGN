//Read a program from a file and detected all integer and real number
#include <iostream>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

bool isRealNumber(string str) {
    int pointCount = 0;
    int digitCount = 0;
    bool isNegative = false;
    int start = 0;

    if (str[0] == '-') {
        isNegative = true;
        start = 1;
    }

    for (int i = start; i < str.length(); i++) {
        if (str[i] == '.') {
            pointCount++;
        } else if (isdigit(str[i])) {
            digitCount++;
        } else {
            return false;
        }
    }

    if (pointCount > 1 || digitCount == 0) {
        return false;
    }

    return true;
}

bool isIntegerNumber(string str) {
    if (str[0] == '-') {
        str = str.substr(1);
    }

    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream file("Source_code2.txt");
    string str;

    while (file >> str) {
        if (isIntegerNumber(str)) {
            cout << str << " is an integer number." << endl;
        } else if (isRealNumber(str)) {
            cout << str << " is a real number." << endl;
        } else {
            cout << str << " is not a number." << endl;
        }
    }

    file.close();

    return 0;
}
