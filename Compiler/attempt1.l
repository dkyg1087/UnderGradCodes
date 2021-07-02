%{
#include "attempt1.tab.h"
#include <stdlib.h>
%}


%%
"+"   	{return ADD;}
"-"   	{return SUB;}
"*"   	{return MUL;}
"/"   	{return DIV;}
"^"   	{return POW;}
[a-zA-Z] {yylval.name = yytext;return VAR;}
"diff"  {return DIFF;}
"("     {return LEFT;}
")"     {return RIGHT;}
[0-9]+ 	{yylval.num =atof(yytext);return NUMBER;}
\n  	{return END;}
[ \t] 	{/*空白忽略*/}
. 	{printf("Illegal syntax %c\n",*yytext);}

%%