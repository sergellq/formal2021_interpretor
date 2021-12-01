#pragma once

#include "MyType.h"

struct MyInt: public MyType {
  int value;
  explicit MyInt(int value = 0);

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

  ~MyInt() override = default;
};
