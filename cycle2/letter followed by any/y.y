%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s);
%}

%token LETTER DIGIT

%% 

variable:
    LETTER rest { printf("Valid variable\n"); }
    ;

rest:
    | rest LETTER
    | rest DIGIT
    ;

%% 

int main() {
    printf("Enter a variable: ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("");
}
    
