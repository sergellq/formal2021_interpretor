#include "MyType.h"

#include "Automaton/TokenAutomaton.h"
#include "MyInt.h"
#include "MyString.h"
#include "MyArray.h"
#include "MyNullType.h"

using std::vector;

const int MyType::null_id = 0;
const int MyType::int_id = 1;
const int MyType::string_id = 2;

std::istream& operator>>(std::istream& is, std::shared_ptr<MyType> ptr) {
  ptr->scan(is);
  return is;
}
std::ostream& operator<<(std::ostream& os, std::shared_ptr<MyType> ptr) {
  ptr->print(os);
  return os;
}

std::shared_ptr<MyType> getTypeByTokens(const vector<token>& tokens, int l, int r) {
  if (!TokenAutomaton::isType(tokens[l].type)) {
    throw std::logic_error("type expected");
  }
  if (l == r) {
    if (tokens[l].s == "int") {
      return std::make_shared<MyInt>();
    } else if (tokens[l].s == "string") {
      return std::make_shared<MyString>();
    } else if (tokens[l].s == "void") {
      return std::make_shared<MyNullType>();
    }
  } else {
    if (tokens[l+1].s != "[" || tokens[l+3].s != "]") {
      throw std::logic_error("expected [], found " + tokens[l+1].s + tokens[l+3].s);
    }
    if (!TokenAutomaton::isNumberLiteral(tokens[l+2].type)) {
      throw std::logic_error("expected number literal");
    }
    if (tokens[l].s == "int") {
      return std::make_shared<MyArray<MyInt>>(atoi(tokens[l+2].s.c_str()));
    } else if (tokens[l].s == "string") {
      return std::make_shared<MyArray<MyString>>(atoi(tokens[l+2].s.c_str()));
    } else {
      throw std::logic_error("i should add new types here!");
    }
  }
  throw std::logic_error("you sould not be here");
}
