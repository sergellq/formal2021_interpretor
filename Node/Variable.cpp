#include "Variable.h"
#include "stdexcept"

Variable::Variable(const std::vector<token>& tokens, const std::vector<int>& link, int name, MyType* ptr):
    Node(tokens, link),
    name(name),
    ptr(ptr) {}

std::pair<bool, MyType*> Variable::run(std::vector<std::vector<Node*>>& vars) {
  throw std::logic_error("running variable ???");
}

std::pair<bool, MyType*> Variable::add(std::vector<std::vector<Node*>>& vars) {
  return {false, ptr};
}

Variable::~Variable() {
//  I need shared_ptr to delete here.
//  delete ptr;
}
