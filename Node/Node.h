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

  virtual std::pair<bool, std::shared_ptr<MyType>> run(std::vector<std::vector<std::shared_ptr<Node>>>& vars) = 0;
  virtual std::pair<bool, std::shared_ptr<MyType>> add(std::vector<std::vector<std::shared_ptr<Node>>>& vars) = 0;

  virtual ~Node() = default;
};
