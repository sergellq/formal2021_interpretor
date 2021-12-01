#pragma once

#include "Node.h"
#include "Expression.h"
#include "Automaton/token.h"
#include "Brackets.h"

class While : public Node {
 private:
  Expression logic;
  Brackets body;

 public:
  While(const std::vector<token>& tokens, const std::vector<int>& link, int start, int l, int r);

  std::pair<bool, MyType*> run(std::vector<std::vector<Node*>>& vars) override;
  std::pair<bool, MyType*> add(std::vector<std::vector<Node*>>& vars) override;

  ~While() override = default;
};
