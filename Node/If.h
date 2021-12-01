#pragma once

#include "Node.h"
#include "Expression.h"
#include "Brackets.h"

class If : public Node {
 private:
  Expression logic;
  Brackets true_logic;
  Brackets false_logic;
 public:
  If(const std::vector<token>& tokens, const std::vector<int>& link, int start, int l, int r, int L = -1, int R = -1);

  std::pair<bool, MyType*> run(std::vector<std::vector<Node*>>& vars) override;
  std::pair<bool, MyType*> add(std::vector<std::vector<Node*>>& vars) override;

  ~If() override = default;
};