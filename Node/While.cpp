#include "While.h"
#include "stdexcept"
#include "Brackets.h"
#include "Types/MyInt.h"
#include "Types/MyNullType.h"

using std::vector;

While::While(const vector<token>& tokens, const vector<int>& link, int start, int l, int r):
    Node(tokens, link, l, r),
    body(tokens, link, l, r),
    logic(tokens, link, start+2, l-2) {
  if (tokens[start].s != "while") {
    throw std::logic_error("while is ont while");
  }
  if (tokens[start+1].s != "(" || tokens[l-1].s != ")") {
    throw std::logic_error("expected () after while, find " + tokens[start+1].s + tokens[l-1].s);
  }
}

std::pair<bool, MyType*> While::run(vector<std::vector<Node*>>& vars) {
  while (dynamic_cast<MyInt*>(logic.run(vars).second)->value) {
    auto ret = body.run(vars);
    if (ret.first) {
      return ret;
    }
  }
  return {false, new MyNullType()};
}

std::pair<bool, MyType*> While::add(vector<std::vector<Node*>>& vars) {
  return run(vars);
}
