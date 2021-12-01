#pragma once

#include "Node.h"
#include "Expression.h"
#include "Types/MyType.h"

class CallingFunction: public Node {
 private:
  std::vector<Expression*> next;
  int name;

 public:
  CallingFunction(const std::vector<token>& tokens, const std::vector<int>& link, int l, int r);

  std::pair<bool, MyType*> run(std::vector<std::vector<Node*>>& vars) override;
  std::pair<bool, MyType*> add(std::vector<std::vector<Node*>>& vars) override;

  ~CallingFunction() override;
};
