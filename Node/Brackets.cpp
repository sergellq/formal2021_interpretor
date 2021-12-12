#include "Brackets.h"

#include "Def.h"
#include "For.h"
#include "If.h"
#include "While.h"
#include "jump_function.h"
#include "stdexcept"
#include "Types/MyNullType.h"
using std::vector;

Brackets::Brackets(const vector<token>& tokens, const vector<int>& link, int l, int r) :
    Node(tokens, link, l, r) {
  if (tokens[l].s == "{" && tokens[r].s == "}") {
    int L = l + 1;
    while (L < r) {
      int R = L;
      if (tokens[L].s == "def") {
        R = jump(link, R, 2, 3);
        next.emplace_back(new Def(tokens, link, L, link[R], R));
      } else if (tokens[L].s == "while" || tokens[L].s == "for") {
        R = jump(link, R, 1, 1);
        if (tokens[L].s == "while") {
          next.push_back(std::make_shared<While>(tokens, link, L, link[R], R));
        } else {
          next.emplace_back(std::make_shared<For>(tokens, link, L, link[R], R));
        }
      } else if (tokens[L].s == "if") {
        R = jump(link, R, 1, 1);
        if (tokens[R + 1].s == "else") {
          int W = jump(link, R, 2);
          next.emplace_back(std::make_shared<If>(tokens, link, L, link[R], R, link[W], W));
        } else {
          next.emplace_back(std::make_shared<If>(tokens, link, L, link[R], R));
        }
      } else if (tokens[L].s == "{") {
        R = link[R];
        next.emplace_back(std::make_shared<Brackets>(tokens, link, L, R));
      } else {
        while (tokens[R].s != ";") {
          ++R;
        }
        next.emplace_back(std::make_shared<Expression>(tokens, link, L, R));
        L = R + 1;
        continue;
      }

      if (tokens[R].s != "}") {
        throw std::logic_error("wrong node parsing");
      }
      L = R + 1;
    }
  }
}

std::pair<bool, std::shared_ptr<MyType>> Brackets::run(vector<vector<std::shared_ptr<Node>>>& vars) {
  if (empty()) return {false, std::make_shared<MyNullType>()};
  for (auto i : next) {
    auto ret = i->add(vars);
    if (ret.first) {
      return ret;
    }
  }
  return {false, std::make_shared<MyNullType>()};
}

std::pair<bool, std::shared_ptr<MyType>> Brackets::add(vector<vector<std::shared_ptr<Node>>>& vars) {
  return run(vars);
}
