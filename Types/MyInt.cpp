#include "MyInt.h"
#include <iostream>

MyInt::MyInt(int value): MyType(MyType::int_id, -1), value(value) {}

MyType* MyInt::operator=(MyType* other) {
  value = dynamic_cast<MyInt*>(other)->value;
  return this;
}

MyType* MyInt::operator+=(MyType* other) {
  value += dynamic_cast<MyInt*>(other)->value;
  return this;
}

MyType* MyInt::operator-=(MyType* other) {
  value -= dynamic_cast<MyInt*>(other)->value;
  return this;
}

MyType* MyInt::operator*=(MyType* other) {
  value *= dynamic_cast<MyInt*>(other)->value;
  return this;
}

MyType* MyInt::operator/=(MyType* other) {
  value /= dynamic_cast<MyInt*>(other)->value;
  return this;
}

MyType* MyInt::operator%=(MyType* other) {
  value %= dynamic_cast<MyInt*>(other)->value;
  return this;
}

MyType* MyInt::operator|(MyType* other) {
  MyInt* ptr = new MyInt(*this);
  ptr->value |= dynamic_cast<MyInt*>(other)->value;
  return ptr;
}

MyType* MyInt::operator&(MyType* other) {
  MyInt* ptr = new MyInt(*this);
  ptr->value &= dynamic_cast<MyInt*>(other)->value;
  return ptr;
}

MyInt* MyInt::operator==(MyType* other) {
  return new MyInt(value == dynamic_cast<MyInt*>(other)->value);
}

MyInt* MyInt::operator!=(MyType* other) {
  return new MyInt(value != dynamic_cast<MyInt*>(other)->value);
}

MyInt* MyInt::operator<(MyType* other) {
  return new MyInt(value < dynamic_cast<MyInt*>(other)->value);
}

MyInt* MyInt::operator>(MyType* other) {
  return new MyInt(value > dynamic_cast<MyInt*>(other)->value);
}

MyInt* MyInt::operator<=(MyType* other) {
  return new MyInt(value <= dynamic_cast<MyInt*>(other)->value);
}

MyInt* MyInt::operator>=(MyType* other) {
  return new MyInt(value >= dynamic_cast<MyInt*>(other)->value);
}

MyType* MyInt::operator+(MyType* other) {
  MyInt* ptr = new MyInt(*this);
  ptr->value += dynamic_cast<MyInt*>(other)->value;
  return ptr;
}

MyType* MyInt::operator-(MyType* other) {
  MyInt* ptr = new MyInt(*this);
  ptr->value -= dynamic_cast<MyInt*>(other)->value;
  return ptr;
}

MyType* MyInt::operator*(MyType* other) {
  MyInt* ptr = new MyInt(*this);
  ptr->value *= dynamic_cast<MyInt*>(other)->value;
  return ptr;
}

MyType* MyInt::operator/(MyType* other) {
  MyInt* ptr = new MyInt(*this);
  ptr->value /= dynamic_cast<MyInt*>(other)->value;
  return ptr;
}

MyType* MyInt::operator%(MyType* other) {
  MyInt* ptr = new MyInt(*this);
  ptr->value %= dynamic_cast<MyInt*>(other)->value;
  return ptr;
}

MyType* MyInt::operator!() {
  MyInt* ptr = new MyInt(*this);
  ptr->value = !ptr->value;
  return ptr;
}

MyType* MyInt::operator-() {
  MyInt* ptr = new MyInt(*this);
  ptr->value = -ptr->value;
  return ptr;
}

void MyInt::scan(std::istream& is) {
  is >> value;
}

void MyInt::print(std::ostream& os) const {
  os << value;
}
