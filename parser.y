%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

extern int yylex();
extern FILE *yyin;
extern int yylineno;
%}

%union {
    int number;
    char *identifier;
    char* str;
    struct {
        int val;
        char unit;
    } duration;
    struct {
        int x;
        int y;
    } coord;
}

%token <number> NUMBER
%token <identifier> IDENTIFIER
%token <duration> DURATION
%token ZONE PLANT WATER HARVEST FERTILIZE PRUNE WAIT LOOP TIMES IF ELSE AT IN FOR FROM
%token <identifier> MOISTURE_SENSOR TEMPERATURE_SENSOR HUMIDITY_SENSOR
%token <identifier> TEMPERATURE HUMIDITY RAIN
%token SOIL_MOISTURE WEATHER
%token EQ LT GT LE GE PERCENT NEWLINE
%token '(' ')' '{' '}' ',' '-' '='
%token <str> VARCOMP

%type <coord> COORD
%type <identifier> PLANT_TYPE FERTILIZER_TYPE
%type <identifier> SENSOR_TYPE WEATHER_FIELD

%start program

%%

program: statements
       ;

statements: /* empty */
          | statements statement
          ;

statement: zone_decl NEWLINE
         | plant_stmt NEWLINE
         | water_stmt NEWLINE
         | harvest_stmt NEWLINE
         | fertilize_stmt NEWLINE
         | prune_stmt NEWLINE
         | wait_stmt NEWLINE
         | loop_stmt NEWLINE
         | if_stmt NEWLINE
         | NEWLINE
         ;

zone_decl: ZONE IDENTIFIER '=' '(' COORD '-' COORD ')'
                { 
                    printf("Zone declaration: %s from (%d,%d) to (%d,%d)\n", 
                           $2, $5.x, $5.y, $7.x, $7.y); 
                    free($2);
                }
          ;

COORD: NUMBER ',' NUMBER
                { 
                    $$.x = $1; 
                    $$.y = $3; 
                    printf("Coord: (%d,%d)\n", $$.x, $$.y);
                }
      ;

plant_stmt: PLANT PLANT_TYPE AT '(' COORD ')' IN_OPTION
                { printf("Plant command\n"); free($2); }
          ;

PLANT_TYPE: IDENTIFIER ;

IN_OPTION: /* empty */
         | IN IDENTIFIER { free($2); }
         ;

water_stmt: WATER '(' COORD ')' FOR DURATION IF_CLAUSE
                { printf("Water command\n"); }
          ;

IF_CLAUSE: /* empty */
         | IF SENSOR_COND
         ;

SENSOR_COND: SENSOR_TYPE COMP VALUE AT_CLAUSE
                { printf("Sensor condition\n"); free($1); }
           ;

SENSOR_TYPE: MOISTURE_SENSOR { $$ = $1; }
           | TEMPERATURE_SENSOR { $$ = $1; }
           | HUMIDITY_SENSOR { $$ = $1; }
           ;

COMP: LT | GT | EQ | LE | GE ;

VALUE: NUMBER PERCENT_OPT
                { /* Handle value */ }
      ;

PERCENT_OPT: /* empty */
           | PERCENT
           ;

AT_CLAUSE: /* empty */
          | AT '(' COORD ')'
          ;

harvest_stmt: HARVEST PLANT_TYPE FROM_OPTION
                { printf("Harvest command\n"); free($2); }
         ;

FROM_OPTION: /* empty */
           | FROM IDENTIFIER { free($2); }
           ;

fertilize_stmt: FERTILIZE FERTILIZER_TYPE AT '(' COORD ')' FOR DURATION
                { printf("Fertilize command\n"); free($2); }
          ;

FERTILIZER_TYPE: IDENTIFIER ;

prune_stmt: PRUNE PLANT_TYPE AT '(' COORD ')'
                { printf("Prune command\n"); free($2); }
      ;

wait_stmt: WAIT DURATION
          {
              printf("Wait command: %d%c\n", $2.val, $2.unit);
          }
          ;

loop_stmt: LOOP NUMBER TIMES block
                { printf("Loop %d times\n", $2); }
     ;

block: '{' statements '}'
                { printf("Block\n"); }
     ;

if_stmt: IF condition block else_clause
                { printf("If statement\n"); }
   ;

condition: SOIL_COND | WEATHER_COND | SENSOR_COND | VARCOMP COMP NUMBER PERCENT_OPT { printf("Sensor condition\n"); } ;

SOIL_COND: SOIL_MOISTURE COMP VALUE AT_CLAUSE ;

WEATHER_COND: WEATHER '.' WEATHER_FIELD COMP VALUE
                { free($3); }
             ;

WEATHER_FIELD: TEMPERATURE { $$ = $1; }
             | HUMIDITY { $$ = $1; }
             | RAIN { $$ = $1; }
             ;

else_clause: /* empty */
           | ELSE block
           ;

%%

int main(int argc, char *argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("Error opening file");
            return 1;
        }
    }
    
    yyparse();
    
    if (argc > 1) {
        fclose(yyin);
    }
    
    return 0;
}