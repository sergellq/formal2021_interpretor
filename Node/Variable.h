#pragma once

#include "Types/MyType.h"
#include "Node.h"

struct Variable : public Node {
  int name;
  MyType* ptr;

  Variable(const std::vector<token>& tokens, const std::vector<int>& link, int name, MyType* ptr);

  std::pair<bool, MyType*> run(std::vector<std::vector<Node*>>& vars) override;
  std::pair<bool, MyType*> add(std::vector<std::vector<Node*>>& vars) override;

  ~Variable() override;
};
