#pragma once

#include "Node.h"
#include "Expression.h"
#include "Types/MyType.h"

class CallingFunction: public Node {
 private:
  std::vector<std::shared_ptr<Expression>> next;
  int name;

 public:
  CallingFunction(const std::vector<token>& tokens, const std::vector<int>& link, int l, int r);

  std::pair<bool, std::shared_ptr<MyType>> run(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;
  std::pair<bool, std::shared_ptr<MyType>> add(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;

  ~CallingFunction() override = default;
};
