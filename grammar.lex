%{
  #include "grammar.parser.h"
%}


%%


[0-9]+ {
    yylval.int_val = atoi(yytext);
    return INTEGER;
}

"(" {
  return LBR;
}

")" {
  return RBR;
}

"+"|"-"|"*"|"/" {
    yylval.op_val = *yytext;
    return OP;
}

. {
  fprintf(stderr, "Lexeing error: %s\n", yytext);
  return 1;
}


%%


int yywrap() { return 1; }
