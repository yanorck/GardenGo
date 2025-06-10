%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// O que é específico para as AÇÕES do parser fica aqui
#include "ast.h"

void yyerror(struct AST_Node** ast_root, const char* s);

extern int yylex();
extern int yylineno;
%}

%code requires {
    #include "types.h"
}

%parse-param { struct AST_Node** ast_root }

%union {
    int number;
    char *identifier;
    char* str;
    int op;
    struct duration duration;
    struct coord coord;
    struct value_type value_type;
    struct AST_Node* node;
}

// Tokens
%token <number> NUMBER
%token <identifier> IDENTIFIER
%token <duration> DURATION
%token ZONE PLANT WATER HARVEST FERTILIZE PRUNE WAIT LOOP TIMES IF ELSE AT IN FOR FROM
%token <identifier> MOISTURE_SENSOR TEMPERATURE_SENSOR HUMIDITY_SENSOR
%token <identifier> TEMPERATURE HUMIDITY RAIN
%token SOIL_MOISTURE WEATHER
%token <op> EQ LT GT LE GE
%token PERCENT NEWLINE DOT
%token '(' ')' '{' '}' ',' '-' '='

// Tipos de retorno das regras
%type <coord> COORD AT_CLAUSE_COORD
%type <identifier> PLANT_TYPE FERTILIZER_TYPE SENSOR_TYPE WEATHER_FIELD IN_OPTION FROM_OPTION
%type <value_type> VALUE
%type <op> COMP
%type <number> PERCENT_OPT
%type <node> program statements statement block
%type <node> zone_decl plant_stmt water_stmt harvest_stmt fertilize_stmt prune_stmt wait_stmt loop_stmt if_stmt
%type <node> IF_CLAUSE condition SOIL_COND WEATHER_COND SENSOR_COND

%nonassoc IF_THEN_ELSE
%nonassoc ELSE

%start program

%%

program: statements
         {
             *ast_root = $1;
         }
         ;

statements: /* empty */            { $$ = NULL; }
          | statements statement  { if ($2 != NULL) { $$ = ast_create_sequence_node($1, $2); } else { $$ = $1; } }
          ;
statement: zone_decl NEWLINE      { $$ = $1; }
         | plant_stmt NEWLINE     { $$ = $1; }
         | water_stmt NEWLINE     { $$ = $1; }
         | harvest_stmt NEWLINE   { $$ = $1; }
         | fertilize_stmt NEWLINE { $$ = $1; }
         | prune_stmt NEWLINE     { $$ = $1; }
         | wait_stmt NEWLINE      { $$ = $1; }
         | loop_stmt NEWLINE      { $$ = $1; }
         | if_stmt NEWLINE        { $$ = $1; }
         | NEWLINE                { $$ = NULL; }
         ;
zone_decl: ZONE IDENTIFIER '=' '(' COORD '-' COORD ')' { $$ = ast_create_zone_decl_node($2, $5, $7); };

COORD: NUMBER ',' NUMBER { $$.x = $1; $$.y = $3; };

plant_stmt: PLANT PLANT_TYPE AT '(' COORD ')' IN_OPTION { $$ = ast_create_plant_node($2, $5, $7); };

PLANT_TYPE: IDENTIFIER { $$ = $1; };

IN_OPTION: /* empty */ { $$ = NULL; } | IN IDENTIFIER { $$ = $2; };

water_stmt: WATER '(' COORD ')' FOR DURATION IF_CLAUSE { $$ = ast_create_water_node($3, $6, $7); };

IF_CLAUSE: /* empty */ { $$ = NULL; } | IF condition { $$ = $2; };

condition: SOIL_COND { $$ = $1; } | WEATHER_COND { $$ = $1; } | SENSOR_COND { $$ = $1; };

SOIL_COND: SOIL_MOISTURE COMP VALUE AT_CLAUSE_COORD { $$ = ast_create_soil_cond_node($2, $3, $4); };

WEATHER_COND: WEATHER DOT WEATHER_FIELD COMP VALUE { $$ = ast_create_weather_cond_node($3, $4, $5); };

SENSOR_COND: SENSOR_TYPE COMP VALUE AT_CLAUSE_COORD { $$ = ast_create_sensor_cond_node($1, $2, $3, $4); };

SENSOR_TYPE: MOISTURE_SENSOR { $$ = $1; } | TEMPERATURE_SENSOR { $$ = $1; } | HUMIDITY_SENSOR { $$ = $1; };

WEATHER_FIELD: TEMPERATURE { $$ = $1; } | HUMIDITY { $$ = $1; } | RAIN { $$ = $1; };

COMP: LT { $$ = OP_LT; } | GT { $$ = OP_GT; } | EQ { $$ = OP_EQ; } | LE { $$ = OP_LE; } | GE { $$ = OP_GE; } ;

VALUE: NUMBER PERCENT_OPT { $$.value = $1; $$.is_percent = ($2 != 0); };

PERCENT_OPT: /* empty */ { $$ = 0; } | PERCENT { $$ = 1; };

AT_CLAUSE_COORD: /* empty */ { $$.x = -1; $$.y = -1; } | AT '(' COORD ')' { $$ = $3; };

harvest_stmt: HARVEST PLANT_TYPE FROM_OPTION { $$ = ast_create_harvest_node($2, $3); };

FROM_OPTION: /* empty */ { $$ = NULL; } | FROM IDENTIFIER { $$ = $2; };

fertilize_stmt: FERTILIZE FERTILIZER_TYPE AT '(' COORD ')' FOR DURATION { $$ = ast_create_fertilize_node($2, $5, $8); };

FERTILIZER_TYPE: IDENTIFIER { $$ = $1; };

prune_stmt: PRUNE PLANT_TYPE AT '(' COORD ')' { $$ = ast_create_prune_node($2, $5); };

wait_stmt: WAIT DURATION { $$ = ast_create_wait_node($2.val, $2.unit); };

loop_stmt: LOOP NUMBER TIMES block { $$ = ast_create_loop_node($2, $4); };

block: '{' statements '}' { $$ = $2; };

if_stmt: IF condition block            %prec IF_THEN_ELSE { $$ = ast_create_if_node($2, $3, NULL); }
       | IF condition block ELSE block { $$ = ast_create_if_node($2, $3, $5); }
       ;

%%

void yyerror(struct AST_Node** ast_root, const char* s) {
    // A linha (void)ast_root; evita um aviso de "parâmetro não utilizado".
    // Estamos dizendo ao compilador que sabemos que não estamos usando, e tudo bem.
    (void)ast_root;
    fprintf(stderr, "Erro de sintaxe na linha %d: %s\n", yylineno, s);
}