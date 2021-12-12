#pragma once

#include "Automaton/token.h"
#include <utility>
#include <vector>
#include <memory>

class MyInt;

class MyType {
 protected:
  explicit MyType(std::pair<int, int> id): id(std::move(id)) {}
  explicit MyType(int id, int size): id(id, size) {}

 public:
  const std::pair<int, int> id;

  static const int null_id;
  static const int int_id;
  static const int string_id;

  virtual std::shared_ptr<MyType> operator=(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyType> operator+=(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyType> operator-=(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyType> operator*=(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyType> operator/=(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyType> operator%=(std::shared_ptr<MyType> other) = 0;

  virtual std::shared_ptr<MyType> operator|(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyType> operator&(std::shared_ptr<MyType> other) = 0;

  virtual std::shared_ptr<MyInt> operator==(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyInt> operator!=(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyInt> operator<(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyInt> operator>(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyInt> operator<=(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyInt> operator>=(std::shared_ptr<MyType> other) = 0;

  virtual std::shared_ptr<MyType> operator+(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyType> operator-(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyType> operator*(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyType> operator/(std::shared_ptr<MyType> other) = 0;
  virtual std::shared_ptr<MyType> operator%(std::shared_ptr<MyType> other) = 0;

  virtual std::shared_ptr<MyType> operator!() = 0;
  virtual std::shared_ptr<MyType> operator-() = 0;

  virtual void scan(std::istream& is) = 0;
  virtual void print(std::ostream& os) const = 0;

  friend std::istream& operator>>(std::istream& is, std::shared_ptr<MyType> ptr);
  friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<MyType> ptr);

  virtual ~MyType() = default;
};

std::shared_ptr<MyType> getTypeByTokens(const std::vector<token>& tokens, int l, int r);
