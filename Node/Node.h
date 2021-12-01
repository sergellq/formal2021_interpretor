#pragma once

#include "vector"
#include "Types/MyType.h"

class Node {
 protected:
  int l;
  int r;
  const std::vector<token>& tokens;
  const std::vector<int>& link;

 public:
  Node(const std::vector<token>& tokens, const std::vector<int>& link);
  Node(const std::vector<token>& tokens, const std::vector<int>& link, int l, int r);
  [[nodiscard]] bool empty() const;

  virtual std::pair<bool, MyType*> run(std::vector<std::vector<Node*>>& vars) = 0;
  virtual std::pair<bool, MyType*> add(std::vector<std::vector<Node*>>& vars) = 0;

  virtual ~Node() = default;
};
