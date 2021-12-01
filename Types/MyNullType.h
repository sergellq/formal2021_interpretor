#pragma once

#include "MyType.h"

class MyNullType : public MyType {
 private:
 public:
  MyNullType();
 
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

  ~MyNullType() override = default;
};
