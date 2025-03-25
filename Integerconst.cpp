#include <iostream>
#include <cctype> // For isdigit()
using namespace std;

// Function to check if a string is a valid integer constant
bool isValidIntegerConstant(const string& str) {
    if (str.empty()) return false;  // Empty string is not a valid integer

    int start = 0;

    // Check for optional '+' or '-' at the beginning
    if (str[0] == '+' || str[0] == '-') {
        if (str.length() == 1) return false; // Just '+' or '-' alone is invalid
        start = 1;
    }

    // Check if the rest of the characters are all digits
    for (int i = start; i < str.length(); i++) {
        if (!isdigit(str[i])) return false;
    }

    // Leading zero check (valid only if it's exactly "0")
    if (str[start] == '0' && str.length() > start + 1) return false;

    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isValidIntegerConstant(input))
        cout << input << " is a valid integer constant.\n";
    else
        cout << input << " is NOT a valid integer constant.\n";

    return 0;
}
