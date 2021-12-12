#pragma once

#include "Node.h"
#include "Types/MyType.h"
#include "Variable.h"
#include "Brackets.h"

class Def : public Node, public std::enable_shared_from_this<Def> {
 private:
  std::shared_ptr<MyType> ret_type;
  int name;
  Brackets body;

 public:
  std::vector<Variable> args;

  Def(const std::vector<token>& tokens, const std::vector<int>& link, int start, int l, int r);

  std::pair<bool, std::shared_ptr<MyType>> run(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;
  std::pair<bool, std::shared_ptr<MyType>> add(std::vector<std::vector<std::shared_ptr<Node>>>& vars) override;

  ~Def() override = default;
};
