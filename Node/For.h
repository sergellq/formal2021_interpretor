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

  std::pair<bool, std::shared_ptr<MyType>> run(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;
  std::pair<bool, std::shared_ptr<MyType>> add(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;

  ~For() override = default;
};
