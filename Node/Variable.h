#pragma once

#include "Types/MyType.h"
#include "Node.h"

struct Variable : public Node {
  int name;
  std::shared_ptr<MyType> ptr;

  Variable(const std::vector<token>& tokens, const std::vector<int>& link, int name, std::shared_ptr<MyType> ptr);

  std::pair<bool, std::shared_ptr<MyType>> run(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;
  std::pair<bool, std::shared_ptr<MyType>> add(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;

  ~Variable() override = default;
};
