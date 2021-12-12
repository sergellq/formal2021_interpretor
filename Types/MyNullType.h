#pragma once

#include "MyType.h"

class MyNullType : public MyType, std::enable_shared_from_this<MyNullType> {
 private:
 public:
  MyNullType();
 
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

  ~MyNullType() override = default;
};
