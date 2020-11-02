
// Generated from Expr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExprParser.
 */
class  ExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExprParser.
   */
    virtual antlrcpp::Any visitProg(ExprParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitStatExpr(ExprParser::StatExprContext *context) = 0;

    virtual antlrcpp::Any visitStatAssignExpr(ExprParser::StatAssignExprContext *context) = 0;

    virtual antlrcpp::Any visitStatNewLine(ExprParser::StatNewLineContext *context) = 0;

    virtual antlrcpp::Any visitExprINT(ExprParser::ExprINTContext *context) = 0;

    virtual antlrcpp::Any visitExprAddSub(ExprParser::ExprAddSubContext *context) = 0;

    virtual antlrcpp::Any visitExprID(ExprParser::ExprIDContext *context) = 0;

    virtual antlrcpp::Any visitExprParenthesis(ExprParser::ExprParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitExprMulDiv(ExprParser::ExprMulDivContext *context) = 0;


};

