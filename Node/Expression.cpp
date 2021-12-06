#include "Expression.h"
#include "Types/MyType.h"
#include "CallingFunction.h"
#include "Brackets.h"
#include "Automaton/TokenAutomaton.h"
#include "Variable.h"
#include "Types/MyInt.h"
#include "Types/MyString.h"
#include "Types/MyArray.h"
#include "Types/MyNullType.h"

using std::vector;

const int Expression::return_from_array = -5;
const int Expression::calling_function = -6;
const int Expression::new_variable = -7;

Expression::Expression(const vector<token>& tokens, const vector<int>& link, int l, int r) : Node(tokens, link, l, r) {
  while (r >= l && tokens[r].s == ";") --r;
  while (tokens[l].s == "(" && link[l] == r) {
    ++l;
    --r;
  }
  Node::l = l;
  Node::r = r;
  if (l > r) return;

  int L = -1;
  int R = -1;
  int prio = -1;
  for (int i = l; i <= r; ++i) {
    if (TokenAutomaton::isOpenBracket(tokens[i].type)) {
      i = link[i];
      continue;
    }
    int cur_prio = TokenAutomaton::getPriopity(tokens[i].type);
    if (cur_prio == -1) continue;
    if (prio == -1 || cur_prio < prio) {
      L = i, R = i;
      prio = cur_prio;
    } else if (cur_prio == prio) {
      R = i;
    }
  }
  if (prio != -1) {
    if (prio == 0) {
      mid = R;
    } else {
      mid = L;
    }
    if (l <= mid - 1) left = std::make_shared<Expression>(tokens, link, l, mid - 1);
    if (mid + 1 <= r) right = std::make_shared<Expression>(tokens, link, mid + 1, r);
  } else {
    if (l == r) {
      if (TokenAutomaton::isNumberLiteral(tokens[l].type)) return;
      if (TokenAutomaton::isStringLiteral(tokens[l].type)) return;
      if (TokenAutomaton::isVariable(tokens[l].type)) return;
      throw std::logic_error("expected literal of variable, found " + tokens[l].s);
    } else {
      if (tokens[r].s == ")") {
        /// function calling
        mid = calling_function;
        right = std::make_shared<CallingFunction>(tokens, link, l, r);
      } else if (tokens[r].s == "]") {
        /// return from array
        if (tokens[l+1].s != "[") {
          throw std::logic_error("expected [] after array, found " + tokens[l+1].s + tokens[r].s);
        }
        mid = return_from_array;
        right = std::make_shared<Expression>(tokens, link, l+2, r-1);
      } else {
        /// creating new variable
        mid = new_variable;
        getTypeByTokens(tokens, l, r-1); // for checking, that [l, r-1] is a type
      }
    }
  }
}

std::pair<bool, std::shared_ptr<MyType>> Expression::run(vector<vector<std::shared_ptr<Node>>>& vars) {
  if (empty() || r < l) return {false, std::make_shared<MyNullType>()};
  if (l == r) {
    if (TokenAutomaton::isNumberLiteral(tokens[l].type)) {
      return {false, std::make_shared<MyInt>(atoi(tokens[l].s.c_str()))};
    } else if (TokenAutomaton::isStringLiteral(tokens[l].type)) {
      return {false, std::make_shared<MyString>(tokens[l].s.substr(1, tokens[l].s.size()-2))};
    } else if (TokenAutomaton::isVariable(tokens[l].type)) {
      return {false, std::dynamic_pointer_cast<Variable>(vars[tokens[l].type].back())->ptr};
    }
  }

  if (mid == calling_function) {
    return right->run(vars);
  } else if (mid == return_from_array) {
    std::shared_ptr<MyType> ptr = std::dynamic_pointer_cast<Variable>(vars[tokens[l].type].back())->ptr;
    if (ptr->id.first == MyType::int_id) {
      return {false,
              std::dynamic_pointer_cast<MyArray<MyInt>>(ptr)->get(std::dynamic_pointer_cast<MyInt>(right->run(vars).second)->value)};
    } else if (ptr->id.first == MyType::string_id) {
      return std::make_pair(false,
              std::dynamic_pointer_cast<MyArray<MyString>>(ptr)->get(std::dynamic_pointer_cast<MyInt>(right->run(vars).second)->value));
    }
  } else if (mid == new_variable) {
    std::shared_ptr<MyType> ptr = getTypeByTokens(tokens, l, r-1);
    vars[tokens[r].type].emplace_back(new Variable(tokens, link, tokens[r].type, ptr));
    return {false, ptr};
  }

  if (tokens[mid].s == "=") {
    return {false, *left->run(vars).second = right->run(vars).second};
  } else if (tokens[mid].s == "+=") {
    return {false, *left->run(vars).second += right->run(vars).second};
  } else if (tokens[mid].s == "-=") {
    return {false, *left->run(vars).second -= right->run(vars).second};
  } else if (tokens[mid].s == "*=") {
    return {false, *left->run(vars).second *= right->run(vars).second};
  } else if (tokens[mid].s == "/=") {
    return {false, *left->run(vars).second /= right->run(vars).second};
  } else if (tokens[mid].s == "%=") {
    return {false, *left->run(vars).second %= right->run(vars).second};
  } else if (tokens[mid].s == "|") {
    return {false, *left->run(vars).second | right->run(vars).second};
  } else if (tokens[mid].s == "&") {
    return {false, *left->run(vars).second & right->run(vars).second};
  } else if (tokens[mid].s == "==") {
    return {false, *left->run(vars).second == right->run(vars).second};
  } else if (tokens[mid].s == "!=") {
    return {false, *left->run(vars).second != right->run(vars).second};
  } else if (tokens[mid].s == "<") {
    return {false, *left->run(vars).second < right->run(vars).second};
  } else if (tokens[mid].s == ">") {
    return {false, *left->run(vars).second > right->run(vars).second};
  } else if (tokens[mid].s == "<=") {
    return {false, *left->run(vars).second <= right->run(vars).second};
  } else if (tokens[mid].s == ">=") {
    return {false, *left->run(vars).second >= right->run(vars).second};
  } else if (tokens[mid].s == "+") {
    return {false, *left->run(vars).second + right->run(vars).second};
  } else if (tokens[mid].s == "*") {
    return {false, *left->run(vars).second * right->run(vars).second};
  } else if (tokens[mid].s == "/") {
    return {false, *left->run(vars).second / right->run(vars).second};
  } else if (tokens[mid].s == "%") {
    return {false, *left->run(vars).second % right->run(vars).second};
  }

  if (tokens[mid].s == "-") {
    if (!left) {
      return {false, -*right->run(vars).second};
    } else {
      return {false, *left->run(vars).second - right->run(vars).second};
    }
  } else if (tokens[mid].s == "!") {
    if (left) {
      throw std::logic_error("binary operator !");
    }
    return {false, !*right->run(vars).second};
  } else {
     throw std::logic_error("unexpected operator " + tokens[mid].s);
  }
}

std::pair<bool, std::shared_ptr<MyType>> Expression::add(vector<vector<std::shared_ptr<Node>>>& vars) {
  return run(vars);
}
