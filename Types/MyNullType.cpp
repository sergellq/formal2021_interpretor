#include "MyNullType.h"
#include "stdexcept"

MyNullType::MyNullType(): MyType(MyType::null_id, -1) {}

MyType* MyNullType::operator=(MyType* other) {
  throw std::logic_error("NullType has no operator =");
}

MyType* MyNullType::operator+=(MyType* other) {
  throw std::logic_error("NullType has no operator +=");
}

MyType* MyNullType::operator-=(MyType* other) {
  throw std::logic_error("NullType has no operator -=");
}

MyType* MyNullType::operator*=(MyType* other) {
  throw std::logic_error("NullType has no operator *=");
}

MyType* MyNullType::operator/=(MyType* other) {
  throw std::logic_error("NullType has no operator /=");
}

MyType* MyNullType::operator%=(MyType* other) {
  throw std::logic_error("NullType has no operator %=");
}

MyType* MyNullType::operator|(MyType* other) {
  throw std::logic_error("NullType has no operator |");
}

MyType* MyNullType::operator&(MyType* other) {
  throw std::logic_error("NullType has no operator &");
}

MyInt* MyNullType::operator==(MyType* other) {
  throw std::logic_error("NullType has no operator ==");
}

MyInt* MyNullType::operator!=(MyType* other) {
  throw std::logic_error("NullType has no operator !=");
}

MyInt* MyNullType::operator<(MyType* other) {
  throw std::logic_error("NullType has no operator <");
}

MyInt* MyNullType::operator>(MyType* other) {
  throw std::logic_error("NullType has no operator >");
}

MyInt* MyNullType::operator<=(MyType* other) {
  throw std::logic_error("NullType has no operator <=");
}

MyInt* MyNullType::operator>=(MyType* other) {
  throw std::logic_error("NullType has no operator >=");
}

MyType* MyNullType::operator+(MyType* other) {
  throw std::logic_error("NullType has no operator +");
}

MyType* MyNullType::operator-(MyType* other) {
  throw std::logic_error("NullType has no operator -");
}

MyType* MyNullType::operator*(MyType* other) {
  throw std::logic_error("NullType has no operator *");
}

MyType* MyNullType::operator/(MyType* other) {
  throw std::logic_error("NullType has no operator /");
}

MyType* MyNullType::operator%(MyType* other) {
  throw std::logic_error("NullType has no operator %");
}

MyType* MyNullType::operator!() {
  throw std::logic_error("NullType has no operator !");
}

MyType* MyNullType::operator-() {
  throw std::logic_error("NullType has no operator -");
}

void MyNullType::scan(std::istream& is) {
  throw std::logic_error("NullType has no void scan");
}

void MyNullType::print(std::ostream& os) const {
  throw std::logic_error("NullType has no void print");
}
