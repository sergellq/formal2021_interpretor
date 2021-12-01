#pragma once

#include "Node.h"
#include "Types/MyType.h"
#include "Variable.h"
#include "Brackets.h"

class Def : public Node {
 private:
  MyType* ret_type;
  int name;
  Brackets body;

 public:
  std::vector<Variable> args;

  Def(const std::vector<token>& tokens, const std::vector<int>& link, int start, int l, int r);

  std::pair<bool, MyType*> run(std::vector<std::vector<Node*>>& vars) override;
  std::pair<bool, MyType*> add(std::vector<std::vector<Node*>>& vars) override;

  ~Def() override;
};
