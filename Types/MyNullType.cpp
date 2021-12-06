#include "MyNullType.h"
#include "stdexcept"

MyNullType::MyNullType(): MyType(MyType::null_id, -1) {}

std::shared_ptr<MyType> MyNullType::operator=(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator =");
}

std::shared_ptr<MyType> MyNullType::operator+=(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator +=");
}

std::shared_ptr<MyType> MyNullType::operator-=(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator -=");
}

std::shared_ptr<MyType> MyNullType::operator*=(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator *=");
}

std::shared_ptr<MyType> MyNullType::operator/=(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator /=");
}

std::shared_ptr<MyType> MyNullType::operator%=(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator %=");
}

std::shared_ptr<MyType> MyNullType::operator|(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator |");
}

std::shared_ptr<MyType> MyNullType::operator&(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator &");
}

std::shared_ptr<MyInt> MyNullType::operator==(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator ==");
}

std::shared_ptr<MyInt> MyNullType::operator!=(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator !=");
}

std::shared_ptr<MyInt> MyNullType::operator<(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator <");
}

std::shared_ptr<MyInt> MyNullType::operator>(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator >");
}

std::shared_ptr<MyInt> MyNullType::operator<=(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator <=");
}

std::shared_ptr<MyInt> MyNullType::operator>=(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator >=");
}

std::shared_ptr<MyType> MyNullType::operator+(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator +");
}

std::shared_ptr<MyType> MyNullType::operator-(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator -");
}

std::shared_ptr<MyType> MyNullType::operator*(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator *");
}

std::shared_ptr<MyType> MyNullType::operator/(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator /");
}

std::shared_ptr<MyType> MyNullType::operator%(std::shared_ptr<MyType> other) {
  throw std::logic_error("NullType has no operator %");
}

std::shared_ptr<MyType> MyNullType::operator!() {
  throw std::logic_error("NullType has no operator !");
}

std::shared_ptr<MyType> MyNullType::operator-() {
  throw std::logic_error("NullType has no operator -");
}

void MyNullType::scan(std::istream& is) {
  throw std::logic_error("NullType has no void scan");
}

void MyNullType::print(std::ostream& os) const {
  throw std::logic_error("NullType has no void print");
}
