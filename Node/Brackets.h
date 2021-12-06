#pragma once

#include "Node.h"
#include "Automaton/token.h"

class Brackets : public Node {
 private:
  std::vector<std::shared_ptr<Node>> next;
 public:
  Brackets(const std::vector<token>& tokens, const std::vector<int>& link, int l, int r);

  std::pair<bool, std::shared_ptr<MyType>> run(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;
  std::pair<bool, std::shared_ptr<MyType>> add(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;

  ~Brackets() override = default;
};
