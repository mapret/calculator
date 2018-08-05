%{
  #include "grammar.lexer.h"
  #include "BaseVisitor.h"
  void yyerror(const char* a) { fprintf(stderr, "Parsing error: %s\n", a); }
%}

%union
{
  float number_val;
  char  op_val;
}

%left LINOP
%left MULOP

%start input
/*%glr-parser*/

%token <number_val> NUMBER "number"
%token <op_val>     MULOP  "mulop"
%token <op_val>     LINOP  "linop"
%token <lbr>        LBR    "("
%token <rbr>        RBR    ")"


%%


input:
    %empty
  | expr
  ;

expr:
    NUMBER          { visitNumber($1); }
  | expr LINOP expr { visitOperator($2); }
  | expr MULOP expr { visitOperator($2); }
  | LBR expr RBR
  ;


%%
