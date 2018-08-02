%{
  #include "grammar.lexer.h"
  void yyerror(const char* a) { fprintf(stderr, "Parsing error: %s\n", a); }
%}

%union
{
  int  int_val;
  char op_val;
}

%left OP

%start input
/*%glr-parser*/

%token <int_val> INTEGER "integer"
%token <op>      OP      "op"
%token <lbr>     LBR     "("
%token <rbr>     RBR     ")"


%%


input:
    %empty
  | expr
  ;

expr:
    INTEGER
  | expr OP expr
  | LBR expr RBR;


%%
