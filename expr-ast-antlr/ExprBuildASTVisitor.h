#include <iostream>
#include "ast.h"
#include <vector>
#include "ExprVisitor.h"

using namespace std;

class ExprBuildASTVisitor : public ExprVisitor
{
public:
    /**
   * Visit parse trees produced by ExprParser.
   */
    virtual antlrcpp::Any visitProg(ExprParser::ProgContext *context)
    {
        cout << "In visitProg" << endl;
        ASTProg *node = new ASTProg();
        ASTStat *statementNode;

        for (auto statement : context->stat())
        {
            statementNode = visit(statement);
            if (statementNode != nullptr)
            {
                node->statementList.push_back(statementNode);
            }
        }
        return (ASTProg *) node;
    }

    virtual antlrcpp::Any visitStatExpr(ExprParser::StatExprContext *context)
    {
        cout << "In visitStatExpr" << endl;
        ASTStatExpr *node = new ASTStatExpr();
        node->expr = visit(context->expr());
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitStatAssignExpr(ExprParser::StatAssignExprContext *context)
    {
        cout << "In visitStatAssignExpr" << endl;
        
        ASTStatAssignExpr *node = new ASTStatAssignExpr();

        node->id = context->ID()->getText();
        node->expr = visit(context->expr());
        return (ASTStat *) node;
    }

    virtual antlrcpp::Any visitStatNewLine(ExprParser::StatNewLineContext *context)
    {
        cout << "In visitStatNewLine" << endl;

        return (ASTStat *) nullptr;
    }

    virtual antlrcpp::Any visitExprINT(ExprParser::ExprINTContext *context)
    {
        cout << "In visitExprINT" << endl;
        //cout << "Integer is " << context->INT()->getText() << endl;
        ASTExprINT *node = new ASTExprINT(stoi(context->INT()->getText()));
        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprAddSub(ExprParser::ExprAddSubContext *context)
    {
        cout << "In visitExprAddSub" << endl;
        ASTExprBinary *node;
        ASTExpr *left, *right;

        left = visit(context->expr(0));
        right = visit(context->expr(1));

        string op = context->op->getText();

        if (op[0] == '+')
            node = new ASTExprBinary("+", left, right);
        else
            node = new ASTExprBinary("-", left, right);

        return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprID(ExprParser::ExprIDContext *context)
    {
        cout << "In visitExprID" << endl;
        // cout << "Identifier is " << context->ID()->getText() << endl;
        string id = context->ID()->getText();

        ASTExprID *node = new ASTExprID(id);

            return (ASTExpr *) node;
    }

    virtual antlrcpp::Any visitExprParenthesis(ExprParser::ExprParenthesisContext *context)
    {
        cout << "In visitExprParenthesis" << endl;
        return visit(context->expr());
    }

    virtual antlrcpp::Any visitExprMulDiv(ExprParser::ExprMulDivContext *context)
    {
        cout << "In visitExprMulDiv" << endl;
        ASTExpr *left;
        ASTExpr *right;
       
        ASTExprBinary *node;

        left = visit(context->expr(0));
        right = visit(context->expr(1));

        string op = context->op->getText();

        if (op[0] == '*')
            node = new ASTExprBinary("*", left, right);
        else
            node = new ASTExprBinary("/", left, right);

        return (ASTExpr *) node;
    }
};