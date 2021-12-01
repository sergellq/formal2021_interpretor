#include "Def.h"
#include "Types/MyType.h"
#include "jump_function.h"
#include "stdexcept"
#include "Types/MyNullType.h"

using std::vector;

Def::Def(const vector<token>& tokens, const vector<int>& link, int start, int l, int r) :
    Node(tokens, link, l, r),
    body(tokens, link, l, r) {
  int right_bracket = jump(link, start, 2);
  ret_type = getTypeByTokens(tokens, right_bracket + 2, l-1);
  name = tokens[start+1].type;
  int L = start+3;
  while (L < right_bracket) {
    int R = L;
    while (R < right_bracket && tokens[R].s != ",") ++R;
    args.emplace_back(Variable(tokens, link, tokens[R-1].type, getTypeByTokens(tokens, L, R-2)));
    L = R+1;
  }
}

std::pair<bool, MyType*> Def::run(vector<std::vector<Node*>>& vars) {
  auto ret = body.run(vars);
  ret.first = false;
  if (ret.second->id != ret_type->id) {
    throw std::logic_error("wront returned type");
  }
  return ret;
}

std::pair<bool, MyType*> Def::add(vector<std::vector<Node*>>& vars) {
  vars[name].emplace_back(this);
  return {false, new MyNullType()};
}

Def::~Def() {
  delete ret_type;
}
