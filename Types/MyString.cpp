#include "MyString.h"
#include "stdexcept"
#include "MyInt.h"
#include "iostream"

MyString::MyString(std::string s): MyType(MyType::string_id, -1), value(std::move(s)) {}

std::shared_ptr<MyType> MyString::operator=(std::shared_ptr<MyType> other) {
  value = std::dynamic_pointer_cast<MyString>(other)->value;
  return shared_from_this();
}

std::shared_ptr<MyType> MyString::operator+=(std::shared_ptr<MyType> other) {
  value += std::dynamic_pointer_cast<MyString>(other)->value;
  return shared_from_this();
}

std::shared_ptr<MyType> MyString::operator-=(std::shared_ptr<MyType> other) {
  throw std::logic_error("string has no operator -=");
}

std::shared_ptr<MyType> MyString::operator*=(std::shared_ptr<MyType> other) {
  throw std::logic_error("string has no operator *=");
}

std::shared_ptr<MyType> MyString::operator/=(std::shared_ptr<MyType> other) {
  throw std::logic_error("string has no operator /=");
}

std::shared_ptr<MyType> MyString::operator%=(std::shared_ptr<MyType> other) {
  throw std::logic_error("string has no operator %=");
}

std::shared_ptr<MyType> MyString::operator|(std::shared_ptr<MyType> other) {
  throw std::logic_error("string has no operator |");
}

std::shared_ptr<MyType> MyString::operator&(std::shared_ptr<MyType> other) {
  throw std::logic_error("string has no operator &");
}

std::shared_ptr<MyInt> MyString::operator==(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value == std::dynamic_pointer_cast<MyString>(other)->value);
}

std::shared_ptr<MyInt> MyString::operator!=(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value != std::dynamic_pointer_cast<MyString>(other)->value);
}

std::shared_ptr<MyInt> MyString::operator<(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value < std::dynamic_pointer_cast<MyString>(other)->value);
}

std::shared_ptr<MyInt> MyString::operator>(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value > std::dynamic_pointer_cast<MyString>(other)->value);
}

std::shared_ptr<MyInt> MyString::operator<=(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value <= std::dynamic_pointer_cast<MyString>(other)->value);
}

std::shared_ptr<MyInt> MyString::operator>=(std::shared_ptr<MyType> other) {
  return std::make_shared<MyInt>(value >= std::dynamic_pointer_cast<MyString>(other)->value);
}

std::shared_ptr<MyType> MyString::operator+(std::shared_ptr<MyType> other) {
  std::shared_ptr<MyString> ptr = shared_from_this();
  ptr->value += std::dynamic_pointer_cast<MyString>(other)->value;
  return ptr;
}

std::shared_ptr<MyType> MyString::operator-(std::shared_ptr<MyType> other) {
  throw std::logic_error("string has no operator -");
}

std::shared_ptr<MyType> MyString::operator*(std::shared_ptr<MyType> other) {
  throw std::logic_error("string has no operator *");
}

std::shared_ptr<MyType> MyString::operator/(std::shared_ptr<MyType> other) {
  throw std::logic_error("string has no operator /");
}

std::shared_ptr<MyType> MyString::operator%(std::shared_ptr<MyType> other) {
  throw std::logic_error("string has no operator %");
}

std::shared_ptr<MyType> MyString::operator!() {
  throw std::logic_error("string has no operator !");
}

std::shared_ptr<MyType> MyString::operator-() {
  throw std::logic_error("string has no operator -");
}

void MyString::scan(std::istream& is) {
  is >> value;
}

void MyString::print(std::ostream& os) const {
  os << value;
}
