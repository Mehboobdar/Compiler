#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

// Set of C++ keywords for identification
unordered_set<string> keywords = {
    "int", "float", "double", "char", "return", "if", "else", "while", "for", "do",
    "switch", "case", "break", "continue", "void", "class", "struct", "public", "private",
    "protected", "static", "virtual", "try", "catch", "throw"
};

// Set of operators
unordered_set<string> operators = {
    "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||"
};

// Set of symbols
unordered_set<char> symbols = {';', ',', '(', ')', '{', '}', '[', ']'};

// Function to check if a token is a number
bool isNumber(const string& token) {
    for (char ch : token) {
        if (!isdigit(ch) && ch != '.') return false;
    }
    return true;
}

// Function to tokenize a given string
void tokenize(const string& str) {
    vector<string> tokens;
    stringstream ss(str);
    string word;

    while (ss >> word) {
        string token = "";
        for (char ch : word) {
            if (symbols.count(ch)) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token = "";
                }
                tokens.push_back(string(1, ch)); // Store symbol separately
            } else if (isspace(ch)) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token = "";
                }
            } else {
                token += ch;
            }
        }
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    // Classify tokens
    for (const string& t : tokens) {
        if (keywords.count(t))
            cout << "Keyword: " << t << endl;
        else if (operators.count(t))
            cout << "Operator: " << t << endl;
        else if (symbols.count(t[0]))
            cout << "Symbol: " << t << endl;
        else if (isNumber(t))
            cout << "Number: " << t << endl;
        else
            cout << "Identifier: " << t << endl;
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    cout << "\nTokens:\n";
    tokenize(input);

    return 0;
}
