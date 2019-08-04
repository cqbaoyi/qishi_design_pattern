#include <string>
#include <sstream>
using namespace std;

struct Expression;

struct ExpressionVisitor
{
  // accept methods here :)
  virtual void accept(Expression& obj) = 0;
  ostringstream oss;
};

struct Expression
{
  virtual void visit(ExpressionVisitor& ev) = 0;
};

struct Value : Expression
{
  int value;

  Value(int value) : value(value) {}
  
  void visit(ExpressionVisitor& ev)
  {
      ev.oss << value;
  }
};

struct AdditionExpression : Expression
{
  Expression &lhs, &rhs;

  AdditionExpression(Expression &lhs, Expression &rhs) : lhs(lhs), rhs(rhs) {}
  
  void visit(ExpressionVisitor& ev)
  {
      ev.oss << "(";
      lhs.visit(ev);
      ev.oss << "+";
      rhs.visit(ev);
      ev.oss << ")";
  }
};

struct MultiplicationExpression : Expression
{
  Expression &lhs, &rhs;

  MultiplicationExpression(Expression &lhs, Expression &rhs)
    : lhs(lhs), rhs(rhs) {}
    
    void visit(ExpressionVisitor& ev)
    {
        lhs.visit(ev);
        ev.oss << "*";
        rhs.visit(ev);
    }
};

struct ExpressionPrinter : ExpressionVisitor
{
    // accept methods here :)
    void accept(Expression& obj)
    {
        obj.visit(*this);
    }

  string str() const 
  { /* todo */ 
      return oss.str();
  }
};
