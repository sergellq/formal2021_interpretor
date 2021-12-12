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

  std::pair<bool, std::shared_ptr<MyType>> run(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;
  std::pair<bool, std::shared_ptr<MyType>> add(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;

  ~While() override = default;
};
