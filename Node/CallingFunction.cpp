#include "CallingFunction.h"
#include "Def.h"
#include "Automaton/TokenAutomaton.h"
#include "stdexcept"
#include <iostream>
#include "Types/MyNullType.h"

using std::vector;

CallingFunction::CallingFunction(const vector<token>& tokens, const vector<int>& link, int l, int r) :
    Node(tokens, link, l, r),
    name(tokens[l].type) {
  int L = l+2;
  while (L < r) {
    int R = L;
    while (R < r && tokens[R].s != ",") ++R;
    next.emplace_back(new Expression(tokens, link, L, R-1));
    L = R+1;
  }
}

std::pair<bool, std::shared_ptr<MyType>> CallingFunction::run(vector<vector<std::shared_ptr<Node>>>& vars) {
  if (TokenAutomaton::isReturn(name)) {
    if (next.size() > 1) {
      throw std::logic_error("you should return not more that one argument");
    }
    if (next.empty()) {
      return {true, std::make_shared<MyNullType>()};
    } else {
      return {true, next[0]->run(vars).second};
    }
  } else if (TokenAutomaton::isPrint(name)) {
    for (auto& i : next) {
      std::cout << i->run(vars).second << " ";
    }
    std::cout << std::endl;
    return {false, std::make_shared<MyNullType>()};
  } else if (TokenAutomaton::isScan(name)) {
    for (auto& i : next) {
      std::cin >> i->run(vars).second;
    }
    return {false, std::make_shared<MyNullType>()};
  }

  if (vars[name].empty()) {
    throw std::logic_error("undefined name of function");
  }
  std::shared_ptr<Def> def = std::dynamic_pointer_cast<Def>(vars[name].back());
  if (!def) {
    throw std::logic_error("calling function call not function");
  }
  vector<std::shared_ptr<MyType>> values;
  for (auto& expr : next) {
    values.emplace_back(expr->run(vars).second);
  }
  if (values.size() != def->args.size()) {
    throw std::logic_error("wrong number of parameters in function");
  }
  for (size_t i = 0; i < values.size(); ++i) {
    if (values[i]->id != (def->args[i].ptr)->id) {
      throw std::logic_error(std::to_string(i) + "-th variable has bad type");
    }
    vars[def->args[i].name].emplace_back(std::make_shared<Variable>(tokens, link, def->args[i].name, values[i]));
  }
  auto ret = def->run(vars);
  for (size_t i = 0; i < values.size(); ++i) {
    vars[def->args[i].name].pop_back();
  }
  return ret;
}

std::pair<bool, std::shared_ptr<MyType>> CallingFunction::add(vector<vector<std::shared_ptr<Node>>>& vars) {
  run(vars);
  return {false, std::make_shared<MyNullType>()};
}
