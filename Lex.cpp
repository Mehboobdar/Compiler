%{
#include <stdio.h>
%}

%%
[ \t\n]+           ;   // Ignore spaces, tabs, and newlines
"int"|"float"|"char"|"double"|"return"   { printf("Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*   { printf("Identifier: %s\n", yytext); }
[0-9]+                 { printf("Number: %s\n", yytext); }
"=="|"<="|">="|"!="|"&&"|"||"   { printf("Operator: %s\n", yytext); }
"(" | ")" | "{" | "}" | ";" | ","  { printf("Symbol: %s\n", yytext); }
.   { printf("Unknown: %s\n", yytext); }

%%

int main() {
    yylex(); // Call the lexical analyzer
    return 0;
}

int yywrap() {
    return 1;
}
