#pragma once

#include "MyType.h"
#include <string>

struct MyString: MyType {
  std::string value;

  explicit MyString(): MyType(MyType::string_id, -1) {}
  explicit MyString(std::string s);

  MyType* operator=(MyType* other) override;
  MyType* operator+=(MyType* other) override;
  MyType* operator-=(MyType* other) override;
  MyType* operator*=(MyType* other) override;
  MyType* operator/=(MyType* other) override;
  MyType* operator%=(MyType* other) override;

  MyType* operator|(MyType* other) override;
  MyType* operator&(MyType* other) override;

  MyInt* operator==(MyType* other) override;
  MyInt* operator!=(MyType* other) override;
  MyInt* operator<(MyType* other) override;
  MyInt* operator>(MyType* other) override;
  MyInt* operator<=(MyType* other) override;
  MyInt* operator>=(MyType* other) override;

  MyType* operator+(MyType* other) override;
  MyType* operator-(MyType* other) override;
  MyType* operator*(MyType* other) override;
  MyType* operator/(MyType* other) override;
  MyType* operator%(MyType* other) override;

  MyType* operator!() override;
  MyType* operator-() override;

  void scan(std::istream& is) override;
  void print(std::ostream& os) const override;

  ~MyString() override = default;
};
