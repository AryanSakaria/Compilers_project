
// Generated from Expr.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "ExprVisitor.h"


/**
 * This class provides an empty implementation of ExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ExprBaseVisitor : public ExprVisitor {
public:

  virtual antlrcpp::Any visitProg(ExprParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatExpr(ExprParser::StatExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatAssignExpr(ExprParser::StatAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatNewLine(ExprParser::StatNewLineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprINT(ExprParser::ExprINTContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAddSub(ExprParser::ExprAddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprID(ExprParser::ExprIDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprParenthesis(ExprParser::ExprParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprMulDiv(ExprParser::ExprMulDivContext *ctx) override {
    return visitChildren(ctx);
  }


};

