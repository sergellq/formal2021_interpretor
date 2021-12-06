#pragma once

#include "Node.h"
#include "Automaton/token.h"

class Expression : public Node {
 private:
  std::shared_ptr<Node> left = nullptr;
  std::shared_ptr<Node> right = nullptr;
  int mid;

  static const int return_from_array;
  static const int calling_function;
  static const int new_variable;

 public:
  Expression(const std::vector<token>& tokens, const std::vector<int>& link, int l, int r);

  std::pair<bool, std::shared_ptr<MyType>> run(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;
  std::pair<bool, std::shared_ptr<MyType>> add(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;

  ~Expression() override = default;
};
