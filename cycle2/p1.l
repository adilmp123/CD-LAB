%{
#include <stdio.h>
%}

%% 
.*adil.*   { /* do nothing */ }
.|\n      { printf("%s\n", yytext); }
%%

int main(int argc, char **argv) {
    yylex();
    return 0;
}
