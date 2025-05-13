%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>

extern int yylineno;
void yyerror(const char *s);
%}

%option noyywrap nodefault

%%

"ZONE"          { return ZONE; }
"PLANT"         { return PLANT; }
"WATER"         { return WATER; }
"HARVEST"       { return HARVEST; }
"FERTILIZE"     { return FERTILIZE; }
"PRUNE"         { return PRUNE; }
"WAIT"          { return WAIT; }
"LOOP"          { return LOOP; }
"TIMES"         { return TIMES; }
"IF"            { return IF; }
"ELSE"          { return ELSE; }
"AT"            { return AT; }
"IN"            { return IN; }
"FOR"           { return FOR; }
"FROM"          { return FROM; }
"MOISTURE_SENSOR" { yylval.identifier = strdup(yytext); return MOISTURE_SENSOR; }
"TEMPERATURE_SENSOR" { yylval.identifier = strdup(yytext); return TEMPERATURE_SENSOR; }
"HUMIDITY_SENSOR" { yylval.identifier = strdup(yytext); return HUMIDITY_SENSOR; }
"SOIL_MOISTURE" { return SOIL_MOISTURE; }
"WEATHER"       { return WEATHER; }
"TEMPERATURE"   { yylval.identifier = strdup(yytext); return TEMPERATURE; }
"HUMIDITY"      { yylval.identifier = strdup(yytext); return HUMIDITY; }
"RAIN"          { yylval.identifier = strdup(yytext); return RAIN; }
"=="            { return EQ; }
"<="            { return LE; }
">="            { return GE; }
"<"             { return LT; }
">"             { return GT; }
"{"             { return '{'; }
"}"             { return '}'; }
"("             { return '('; }
")"             { return ')'; }
","             { return ','; }
"-"             { return '-'; }
"="             { return '='; }
<<EOF>>         { return 0; }
\n              { yylineno++; return NEWLINE; }
\r\n            { yylineno++; return NEWLINE; }
[ \t]+        { /* Ignorar espaços, tabs e returns */ }
"//".*          { /* Ignorar comentários */ }
[0-9]+[smh]     { 
    yylval.duration.val = atoi(yytext);
    yylval.duration.unit = yytext[strlen(yytext)-1];
    return DURATION; 
}
[0-9]+          { yylval.number = atoi(yytext); return NUMBER; }
[A-Za-z_][a-zA-Z0-9_]*\.[a-zA-Z_][a-zA-Z0-9_]*   { yylval.str = strdup(yytext); return VARCOMP; }
[A-Za-z_][A-Za-z0-9_]* { yylval.identifier = strdup(yytext); return IDENTIFIER; }
"%"             { return PERCENT; }
.               { 
    fprintf(stderr, "Erro léxico: Caractere inválido '%c' (0x%02X)\n", *yytext, *yytext); 
    return *yytext; 
}

%%