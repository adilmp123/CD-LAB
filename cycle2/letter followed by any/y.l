%{
#include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]*  { return LETTER; }
[0-9]+                { return DIGIT; }
[ \t]                 ; 
\n                    { return '\n'; }
.                     { return yytext[0]; } 
%%

int yywrap() {
    return 1;
}

