#pragma once

#include "MyType.h"

struct MyInt: public MyType, std::enable_shared_from_this<MyInt> {
  int value;
  explicit MyInt(int value = 0);

  std::shared_ptr<MyType> operator=(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyType> operator+=(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyType> operator-=(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyType> operator*=(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyType> operator/=(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyType> operator%=(std::shared_ptr<MyType> other) override;

  std::shared_ptr<MyType> operator|(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyType> operator&(std::shared_ptr<MyType> other) override;

  std::shared_ptr<MyInt> operator==(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyInt> operator!=(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyInt> operator<(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyInt> operator>(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyInt> operator<=(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyInt> operator>=(std::shared_ptr<MyType> other) override;

  std::shared_ptr<MyType> operator+(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyType> operator-(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyType> operator*(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyType> operator/(std::shared_ptr<MyType> other) override;
  std::shared_ptr<MyType> operator%(std::shared_ptr<MyType> other) override;

  std::shared_ptr<MyType> operator!() override;
  std::shared_ptr<MyType> operator-() override;

  void scan(std::istream& is) override;
  void print(std::ostream& os) const override;

  ~MyInt() override = default;
};
