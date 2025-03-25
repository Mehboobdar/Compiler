#include <iostream>
#include <unordered_set>

using namespace std;

// Function to check if a string is a C++ keyword
bool isKeyword(const string& word) {
    // Set of all C++ keywords
    unordered_set<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long",
        "register", "return", "short", "signed", "sizeof", "static", "struct", "switch",
        "typedef", "union", "unsigned", "void", "volatile", "while", "class", "namespace",
        "public", "private", "protected", "template", "typename", "using", "virtual",
        "delete", "new", "this", "throw", "try", "catch", "explicit", "friend", "mutable",
        "operator", "static_cast", "dynamic_cast", "const_cast", "reinterpret_cast",
        "typeid", "wchar_t", "bool", "false", "true", "export", "asm", "final", "override",
        "constexpr", "thread_local", "nullptr"
    };

    return keywords.find(word) != keywords.end();
}

int main() {
    string input;
    cout << "Enter a word: ";
    cin >> input;

    if (isKeyword(input))
        cout << input << " is a valid C++ keyword.\n";
    else
        cout << input << " is NOT a C++ keyword.\n";

    return 0;
}
