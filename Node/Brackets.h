#pragma once

#include "Node.h"
#include "Automaton/token.h"

class Brackets : public Node {
 private:
  std::vector<Node*> next;
 public:
  Brackets(const std::vector<token>& tokens, const std::vector<int>& link, int l, int r);

  std::pair<bool, MyType*> run(std::vector<std::vector<Node*>>& vars) override;
  std::pair<bool, MyType*> add(std::vector<std::vector<Node*>>& vars) override;

  ~Brackets() override;
};
