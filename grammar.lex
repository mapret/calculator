%{
  #include "grammar.parser.h"
  #include "BaseVisitor.h"
%}


%%


[0-9]+(\.[0-9]*)? {
    yylval.number_val = atof(yytext);
    return NUMBER;
}

"(" {
  return LBR;
}

")" {
  return RBR;
}

"*"|"/" {
  yylval.op_val = *yytext;
  return MULOP;
}

"+"|"-" {
  yylval.op_val = *yytext;
  return LINOP;
}

. {
  lexingError(*yytext);
  return 1;
}


%%


int yywrap() { return 1; }
