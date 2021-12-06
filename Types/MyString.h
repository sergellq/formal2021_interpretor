#pragma once

#include "MyType.h"
#include <string>

struct MyString: public MyType, std::enable_shared_from_this<MyString> {
  std::string value;

  explicit MyString(): MyType(MyType::string_id, -1) {}
  explicit MyString(std::string s);

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

  ~MyString() override = default;
};
