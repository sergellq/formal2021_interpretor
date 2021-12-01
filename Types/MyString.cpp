#include "MyString.h"
#include "stdexcept"
#include "MyInt.h"
#include "iostream"

MyString::MyString(std::string s): MyType(MyType::string_id, -1), value(std::move(s)) {}

MyType* MyString::operator=(MyType* other) {
  value = dynamic_cast<MyString*>(other)->value;
  return this;
}

MyType* MyString::operator+=(MyType* other) {
  value += dynamic_cast<MyString*>(other)->value;
  return this;
}

MyType* MyString::operator-=(MyType* other) {
  throw std::logic_error("string has no operator -=");
}

MyType* MyString::operator*=(MyType* other) {
  throw std::logic_error("string has no operator *=");
}

MyType* MyString::operator/=(MyType* other) {
  throw std::logic_error("string has no operator /=");
}

MyType* MyString::operator%=(MyType* other) {
  throw std::logic_error("string has no operator %=");
}

MyType* MyString::operator|(MyType* other) {
  throw std::logic_error("string has no operator |");
}

MyType* MyString::operator&(MyType* other) {
  throw std::logic_error("string has no operator &");
}

MyInt* MyString::operator==(MyType* other) {
  return new MyInt(value == dynamic_cast<MyString*>(other)->value);
}

MyInt* MyString::operator!=(MyType* other) {
  return new MyInt(value != dynamic_cast<MyString*>(other)->value);
}

MyInt* MyString::operator<(MyType* other) {
  return new MyInt(value < dynamic_cast<MyString*>(other)->value);
}

MyInt* MyString::operator>(MyType* other) {
  return new MyInt(value > dynamic_cast<MyString*>(other)->value);
}

MyInt* MyString::operator<=(MyType* other) {
  return new MyInt(value <= dynamic_cast<MyString*>(other)->value);
}

MyInt* MyString::operator>=(MyType* other) {
  return new MyInt(value >= dynamic_cast<MyString*>(other)->value);
}

MyType* MyString::operator+(MyType* other) {
  MyString* ptr = new MyString(*this);
  ptr->value += dynamic_cast<MyString*>(other)->value;
  return ptr;
}

MyType* MyString::operator-(MyType* other) {
  throw std::logic_error("string has no operator -");
}

MyType* MyString::operator*(MyType* other) {
  throw std::logic_error("string has no operator *");
}

MyType* MyString::operator/(MyType* other) {
  throw std::logic_error("string has no operator /");
}

MyType* MyString::operator%(MyType* other) {
  throw std::logic_error("string has no operator %");
}

MyType* MyString::operator!() {
  throw std::logic_error("string has no operator !");
}

MyType* MyString::operator-() {
  throw std::logic_error("string has no operator -");
}

void MyString::scan(std::istream& is) {
  is >> value;
}

void MyString::print(std::ostream& os) const {
  os << value;
}
