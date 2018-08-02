%{
  #include "grammar.lexer.h"
  #include "BaseVisitor.h"
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
%token <op_val>  OP      "op"
%token <lbr>     LBR     "("
%token <rbr>     RBR     ")"


%%


input:
    %empty
  | expr
  ;

expr:
    INTEGER      { visitNumber($1); }
  | expr OP expr { visitOperator($2); }
  | LBR expr RBR
  ;


%%
