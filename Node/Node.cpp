#include "Node.h"

Node::Node(const std::vector<token>& tokens, const std::vector<int>& link, int l, int r) :
    tokens(tokens),
    link(link),
    l(l), r(r) {}

bool Node::empty() const {
  return l == -1 && r == -1;
}

Node::Node(const std::vector<token>& tokens, const std::vector<int>& link) :
    tokens(tokens),
    link(link),
    l(-1), r(-1) {}
