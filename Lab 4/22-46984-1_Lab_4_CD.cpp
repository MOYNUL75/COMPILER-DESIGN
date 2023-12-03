/*
 1.	Write a C/C++ program using the following instructions (filename: ID.c/ ID.cpp):
a.	Read a file named “program.cpp” (given below). 
b.	After reading the file you have to identify and count the unique name of the user-defined functions 
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    ifstream inputFile("Program.cpp");
    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    unordered_set<string> functions;
    unordered_map<string, int> operators;
    regex functionDeclaration("([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\([^\\)]*\\)\\s*\\{");

    string line;

    while (getline(inputFile, line)) {
        smatch match;
        if (regex_search(line, match, functionDeclaration)) {
            // Extract function name from the matched group
            string functionName = match[1];
            functions.insert(functionName);
        }

        istringstream iss(line);
        string word;

        while (iss >> word) {
            if (word == "+" || word == "-" || word == "*" || word == "=") {
                // Count operators
                operators[word]++;
            }
        }
    }

    // Output the results
    int functionCount = 0;
    cout << "User Defined Functions:" << endl;
    for (const auto &function : functions) {
        cout << "Function-" << ++functionCount << ": " << function << endl;
    }
    cout << "Total number of user-defined functions: " << functionCount << endl;


    int operatorCount = 0;
    cout << "\nOperators:" << endl;
    for (const auto &op : operators) {
        cout << "Operator-" << ++operatorCount << ": " << op.first << endl;
    }

    cout << "Total number of operators: " << operatorCount << endl;

    inputFile.close();

    return 0;
}
