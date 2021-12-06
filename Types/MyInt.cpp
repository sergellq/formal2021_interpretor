#include "MyInt.h"
#include <iostream>

MyInt::MyInt(int value): MyType(MyType::int_id, -1), value(value) {}

std::shared_ptr<MyType> MyInt::operator=(std::shared_ptr<MyType> other) {
  value = std::dynamic_pointer_cast<MyInt>(other)->value;
  return shared_from_this();
}

std::shared_ptr<MyType> MyInt::operator+=(std::shared_ptr<MyType> other) {
  value += std::dynamic_pointer_cast<MyInt>(other)->value;
  return shared_from_this();
}

std::shared_ptr<MyType> MyInt::operator-=(std::shared_ptr<MyType> other) {
  value -= std::dynamic_pointer_cast<MyInt>(other)->value;
  return shared_from_this();
}

std::shared_ptr<MyType> MyInt::operator*=(std::shared_ptr<MyType> other) {
  value *= std::dynamic_pointer_cast<MyInt>(other)->value;
  return shared_from_this();
}

std::shared_ptr<MyType> MyInt::operator/=(std::shared_ptr<MyType> other) {
  value /= std::dynamic_pointer_cast<MyInt>(other)->value;
  return shared_from_this();
}

std::shared_ptr<MyType> MyInt::operator%=(std::shared_ptr<MyType> other) {
  value %= std::dynamic_pointer_cast<MyInt>(other)->value;
  return shared_from_this();
}

std::shared_ptr<MyType> MyInt::operator|(std::shared_ptr<MyType> other) {
  std::shared_ptr<MyInt> ptr = shared_from_this();
  ptr->value |= std::dynamic_pointer_cast<MyInt>(other)->value;
  return ptr;
}

std::shared_ptr<MyType> MyInt::operator&(std::shared_ptr<MyType> other) {
  std::shared_ptr<MyInt> ptr = shared_from_this();
  ptr->value &= std::dynamic_pointer_cast<MyInt>(other)->value;
  return ptr;
}

std::shared_ptr<MyInt> MyInt::operator==(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value == std::dynamic_pointer_cast<MyInt>(other)->value);
}

std::shared_ptr<MyInt> MyInt::operator!=(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value != std::dynamic_pointer_cast<MyInt>(other)->value);
}

std::shared_ptr<MyInt> MyInt::operator<(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value < std::dynamic_pointer_cast<MyInt>(other)->value);
}

std::shared_ptr<MyInt> MyInt::operator>(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value > std::dynamic_pointer_cast<MyInt>(other)->value);
}

std::shared_ptr<MyInt> MyInt::operator<=(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value <= std::dynamic_pointer_cast<MyInt>(other)->value);
}

std::shared_ptr<MyInt> MyInt::operator>=(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value >= std::dynamic_pointer_cast<MyInt>(other)->value);
}

std::shared_ptr<MyType> MyInt::operator+(std::shared_ptr<MyType> other) {
  std::shared_ptr<MyInt> ptr = shared_from_this();
  ptr->value += std::dynamic_pointer_cast<MyInt>(other)->value;
  return ptr;
}

std::shared_ptr<MyType> MyInt::operator-(std::shared_ptr<MyType> other) {
  std::shared_ptr<MyInt> ptr = shared_from_this();
  ptr->value -= std::dynamic_pointer_cast<MyInt>(other)->value;
  return ptr;
}

std::shared_ptr<MyType> MyInt::operator*(std::shared_ptr<MyType> other) {
  std::shared_ptr<MyInt> ptr = shared_from_this();
  ptr->value *= std::dynamic_pointer_cast<MyInt>(other)->value;
  return ptr;
}

std::shared_ptr<MyType> MyInt::operator/(std::shared_ptr<MyType> other) {
  std::shared_ptr<MyInt> ptr = shared_from_this();
  ptr->value /= std::dynamic_pointer_cast<MyInt>(other)->value;
  return ptr;
}

std::shared_ptr<MyType> MyInt::operator%(std::shared_ptr<MyType> other) {
  std::shared_ptr<MyInt> ptr = shared_from_this();
  ptr->value %= std::dynamic_pointer_cast<MyInt>(other)->value;
  return ptr;
}

std::shared_ptr<MyType> MyInt::operator!() {
  std::shared_ptr<MyInt> ptr = shared_from_this();
  ptr->value = !ptr->value;
  return ptr;
}

std::shared_ptr<MyType> MyInt::operator-() {
  std::shared_ptr<MyInt> ptr = shared_from_this();
  ptr->value = -ptr->value;
  return ptr;
}

void MyInt::scan(std::istream& is) {
  is >> value;
}

void MyInt::print(std::ostream& os) const {
  os << value;
}
