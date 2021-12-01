#pragma once

#include "Node.h"
#include "Expression.h"
#include "Brackets.h"

class For : public Node {
 private:
  Expression init;
  Expression logic;
  Expression step;
  Brackets body;

 public:
  For(const std::vector<token>& tokens, const std::vector<int>& link, int start, int l, int r);

  std::pair<bool, MyType*> run(std::vector<std::vector<Node*>>& vars) override;
  std::pair<bool, MyType*> add(std::vector<std::vector<Node*>>& vars) override;

  ~For() override = default;
};
