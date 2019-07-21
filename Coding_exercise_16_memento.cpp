#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct Token
{
  int value;

  Token(int value) : value(value) {}
};

struct Memento
{
  vector<shared_ptr<Token>> tokens;
};

struct TokenMachine
{
  vector<shared_ptr<Token>> tokens;

  Memento add_token(int value)
  {
    return add_token(make_shared<Token>(value));
  }

  // adds the token to the set of tokens and returns the
  // snapshot of the entire system
  Memento add_token(const shared_ptr<Token>& token)
  {
    // todo
    tokens.push_back(token);
    Memento res;
    res.tokens.reserve(tokens.size());
    for (size_t i = 0; i < tokens.size(); ++i)
        res.tokens.push_back(make_shared<Token>(tokens[i]->value));
    return res;
  }

  // reverts the system to a state represented by the token
  void revert(const Memento& m)
  {
      // todo
      tokens.clear();
      tokens.reserve(m.tokens.size());
      for (size_t i = 0; i < m.tokens.size(); ++i)
        tokens.push_back(make_shared<Token>(m.tokens[i]->value));
  }
};
