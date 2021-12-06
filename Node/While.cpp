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

std::pair<bool, std::shared_ptr<MyType>> While::run(vector<vector<std::shared_ptr<Node>>>& vars) {
  while (std::dynamic_pointer_cast<MyInt>(logic.run(vars).second)->value) {
    auto ret = body.run(vars);
    if (ret.first) {
      return ret;
    }
  }
  return {false, std::make_shared<MyNullType>()};
}

std::pair<bool, std::shared_ptr<MyType>> While::add(vector<vector<std::shared_ptr<Node>>>& vars) {
  return run(vars);
}
