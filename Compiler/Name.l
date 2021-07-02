%{
#define YYSTYPE double
#include "Name.tab.h"
#include <stdlib.h>
%}


%%

[ \t]+ { }
[0-9]+ { yylval=atof(yytext); 
 return NUMBER;
}

"+" return PLUS;
"-" return MINUS;
"*" return TIMES;
"/" return DIVIDE;
"^" return POWER;
"(" return LEFT;
")" return RIGHT;
"\n" return END;

%%