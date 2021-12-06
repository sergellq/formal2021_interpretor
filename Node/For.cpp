#include "For.h"
#include <stdexcept>
#include "Types/MyInt.h"
#include "Types/MyNullType.h"

using std::vector;

int find_next_semicolon(const vector<token>& tokens, int pos, int r) {
  ++pos;
  while (pos < r && tokens[pos].s != ";") ++pos;
  if (pos == r) {
    throw std::logic_error("expected for (;;), found less, than one ;");
  }
  return pos;
}

For::For(const vector<token>& tokens, const vector<int>& link, int start, int l, int r) :
    Node(tokens, link, start, r),
    body(tokens, link, l, r),
    init(tokens, link, start + 2, find_next_semicolon(tokens, start + 2, l)),
    logic(tokens, link, find_next_semicolon(tokens, start + 2, l) + 1,
                        find_next_semicolon(tokens, find_next_semicolon(tokens, start + 2, l), l)),
    step(tokens, link, find_next_semicolon(tokens, find_next_semicolon(tokens, start + 2, l), l) + 1,
                       l - 2) {
  if (tokens[start].s != "for") {
    throw std::logic_error("for is not for");
  }
  if (tokens[start + 1].s != "(" || tokens[l - 1].s != ")") {
    throw std::logic_error("expected () after for, found " + tokens[start + 1].s + tokens[l - 1].s);
  }
}

std::pair<bool, std::shared_ptr<MyType>> For::run(vector<vector<std::shared_ptr<Node>>>& vars) {
  auto ret = init.run(vars);
  if (ret.first) {
    return ret;
  }
  while (std::dynamic_pointer_cast<MyInt>(logic.run(vars).second)->value) {
    ret = body.run(vars);
    if (ret.first) {
      return ret;
    }
    ret = step.run(vars);
    if (ret.first) {
      return ret;
    }
  }
  /// TODO smth with deleting args from init
  return {false, std::make_shared<MyNullType>()};
}

std::pair<bool, std::shared_ptr<MyType>> For::add(vector<vector<std::shared_ptr<Node>>>& vars) {
  return run(vars);
}
