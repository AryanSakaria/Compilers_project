#include <string>
#include <vector>

using namespace std;

class ASTProg;

class ASTStatExpr;
class ASTStatAssignExpr;

class ASTExpr;
class ASTExprBinary;
class ASTExprTernary;
class ASTExprID;
class ASTExprINT;

class ASTvisitor
{
public:
    virtual void visit(ASTProg &node) = 0;
    virtual void visit(ASTStatExpr &node) = 0;
    virtual void visit(ASTStatAssignExpr &node) = 0;

    virtual void visit(ASTExprBinary &node) = 0;
    virtual void visit(ASTExprTernary &node) = 0;
    virtual void visit(ASTExprID &node) = 0;
    virtual void visit(ASTExprINT &node) = 0;
    virtual void visit(ASTExpr &node) = 0;
};

class ASTnode
{
public:
    virtual ~ASTnode()
    {
    }

    //  virtual void printPostFix() const = 0;

    virtual void accept(ASTvisitor &V) = 0;
};

class ASTStat : public ASTnode
{
public:
    virtual ~ASTStat()
    {
    }

    //  virtual void printPostFix() const = 0;

    virtual void accept(ASTvisitor &V) = 0;
};

class ASTProg : public ASTnode
{
public:
    std::vector<ASTStat *> statementList;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExpr : public ASTnode
{
public:
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatExpr : public ASTStat
{
public:
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTStatAssignExpr : public ASTStat
{
public:
    string id;
    ASTExpr *expr;
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprBinary : public ASTExpr
{
    std::string bin_operator;

    // lhs and rhs can be of any type.
    // So we need to use BaseAST
    ASTExpr *left;
    ASTExpr *right;

public:
    // Constructor to initialize binary operator,
    // lhs and rhs of the binary expression.
    ASTExprBinary(std::string op, ASTExpr *_left, ASTExpr *_right) : bin_operator(op), left(_left), right(_right) {}

    /*  virtual void printPostFix() const 
     {
     	lhs->printPostFix();
     	rhs->printPostFix();
     	std::cout << bin_operator << " "; 
     } */

    ASTExpr *getLeft()
    {
        return left;
    }

    ASTExpr *getRight()
    {
        return right;
    }

    std::string getBin_operator()
    {
        return bin_operator;
    }
    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprTernary : public ASTExpr
{

    ASTExpr *first;
    ASTExpr *second;
    ASTExpr *third;

public:
    ASTExprTernary(ASTExpr *first, ASTExpr *second, ASTExpr *third) : first(first), second(second), third(third) {}

    /*   virtual void printPostFix() const
     {
     	first->printPostFix();
     	second->printPostFix();
     	third->printPostFix();
     	std::cout << "? " << std::endl; 
     }  */

    ASTExpr *getFirst()
    {
        return first;
    }

    ASTExpr *getSecond()
    {
        return second;
    }

    ASTExpr *getThird()
    {
        return third;
    }

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }
};

class ASTExprINT : public ASTExpr
{

    int intlit;

public:
    ASTExprINT(int intlit) : intlit(intlit) {}

    int getIntLit()
    {
        return intlit;
    }

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }

    /* virtual void printPostFix() const
	{
		std::cout << intlit << " " ;
	} */
};

class ASTExprID : public ASTExpr
{

    string id;

public:
    ASTExprID(string id) : id(id) {}

    string getID()
    {
        return id;
    }

    virtual void accept(ASTvisitor &v)
    {
        v.visit(*this);
    }

    /* virtual void printPostFix() const
	{
		std::cout << intlit << " " ;
	} */
};

class ASTContext
{
public:
    ASTnode *root;

    ~ASTContext()
    {
        clearAST();
    }

    /// free all saved expression trees
    void clearAST()
    {
        delete root;
    }
};
