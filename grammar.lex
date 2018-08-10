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

"^" {
  yylval.op_val = *yytext;
  return POWER;
}

[a-z][a-z0-9]{0,3} {
  strncpy(yylval.func_name, yytext, 4);
  yylval.func_name[4] = 0;
  return FUNCTION;
}

. {
  lexingError(*yytext);
  return 1;
}


%%


int yywrap() { return 1; }
