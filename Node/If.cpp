#include "If.h"
#include <stdexcept>
#include "Types/MyInt.h"
#include "Types/MyNullType.h"

using std::vector;

If::If(const vector<token>& tokens, const vector<int>& link, int start, int l, int r, int L, int R):
    Node(tokens, link, start, r),
    true_logic(tokens, link, l, r),
    false_logic(tokens, link, L, R),
    logic(tokens, link, start+2, l-2) {
  if (tokens[start].s != "if") {
    throw std::logic_error("if is not if");
  }
  if (tokens[start+1].s != "(" || tokens[l-1].s != ")") {
    throw std::logic_error("expected () after if, found " + tokens[start+1].s + tokens[l-1].s);
  }
}

std::pair<bool, std::shared_ptr<MyType>> If::run(vector<vector<std::shared_ptr<Node>>>& vars) {
  if (std::dynamic_pointer_cast<MyInt>(logic.run(vars).second)->value) {
    auto ret = true_logic.run(vars);
    if (ret.first) {
      return ret;
    }
  } else {
    auto ret = false_logic.run(vars);
    if (ret.first) {
      return ret;
    }
  }
  return {false, std::make_shared<MyNullType>()};
}

std::pair<bool, std::shared_ptr<MyType>> If::add(vector<vector<std::shared_ptr<Node>>>& vars) {
  return run(vars);
}
