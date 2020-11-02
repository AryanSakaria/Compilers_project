grammar Expr;

/** The start rule; begin parsing here. */
prog:   stat+ ; 

stat:   expr NEWLINE          #statExpr      
    |   ID '=' expr NEWLINE   #statAssignExpr
    |   NEWLINE               #statNewLine
    ;

expr:   expr op=('*'|'/') expr   #exprMulDiv
    |   expr op=('+'|'-') expr   #exprAddSub
    |   INT                   #exprINT
    |   ID                    #exprID
    |   '(' expr ')'          #exprParenthesis
    ;

ID  :   [a-zA-Z]+ ;      // match identifiers <label id="code.tour.expr.3"/>
INT :   [0-9]+ ;         // match integers
NEWLINE:'\r'? '\n' ;     // return newlines to parser (is end-statement signal)
WS  :   [ \t]+ -> skip ; // toss out whitespace
