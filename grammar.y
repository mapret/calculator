%{
  #include "grammar.lexer.h"
  #include "BaseVisitor.h"
  void yyerror(const char* a) { parsingError(a); }
%}

%union
{
  float number_val;
  char  op_val;
  char  func_name[5];
}

%left LINOP
%left MULOP
%left POWER

%start input
/*%glr-parser*/

%token <number_val> NUMBER   "number"
%token <op_val>     MULOP    "mulop"
%token <op_val>     LINOP    "linop"
%token <op_val>     POWER    "power"
%token <func_name>  FUNCTION "function"
%token <lbr>        LBR      "("
%token <rbr>        RBR      ")"


%%


input:
  expr
  ;

expr:
    NUMBER                { visitNumber($1); }
  | expr LINOP expr       { visitOperator($2); }
  | expr MULOP expr       { visitOperator($2); }
  | expr POWER expr       { visitOperator($2); }
  | LINOP expr            { visitUnaryOperator($1); }
  | FUNCTION LBR expr RBR { visitFunction($1); }
  | LBR expr RBR
  ;


%%
