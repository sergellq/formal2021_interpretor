#pragma once

#include "MyType.h"
#include <vector>
#include <iostream>

template<typename T>
struct MyArray: public MyType, std::enable_shared_from_this<MyArray<T>> {
  std::vector<std::shared_ptr<T>> value;

  explicit MyArray(int size);
  ~MyArray() override = default;

  std::shared_ptr<T> get(int x) {
    return value[x];
  }

  std::shared_ptr<MyType> operator=(std::shared_ptr<MyType> other) {
    for (int i = 0; i < value.size(); ++i) {
      *value[i] = std::dynamic_pointer_cast<MyArray<T>>(other)->value[i];
    }
    return std::enable_shared_from_this<MyArray<T>>::shared_from_this();
  }

  std::shared_ptr<MyType> operator+=(std::shared_ptr<MyType> other) {
    throw std::logic_error("array has no operator +=");
  }

  std::shared_ptr<MyType> operator-=(std::shared_ptr<MyType> other) {
    throw std::logic_error("array has no operator -=");
  }

  std::shared_ptr<MyType> operator*=(std::shared_ptr<MyType> other) {
    throw std::logic_error("array has no operator *=");
  }

  std::shared_ptr<MyType> operator/=(std::shared_ptr<MyType> other) {
    throw std::logic_error("array has no operator /=");
  }

  std::shared_ptr<MyType> operator%=(std::shared_ptr<MyType> other) {
    throw std::logic_error("array has no operator %=");
  }

  std::shared_ptr<MyType> operator|(std::shared_ptr<MyType> other) {
    throw std::logic_error("array has no operator |");
  }

  std::shared_ptr<MyType> operator&(std::shared_ptr<MyType> other) {
    throw std::logic_error("array has no operator &");
  }

  std::shared_ptr<MyInt> operator==(std::shared_ptr<MyType> other) {
    for (int i = 0; i < value.size(); ++i) {
      if ((*value[i] != std::dynamic_pointer_cast<MyArray<T>>(other)->value[i])->value) {
        return std::make_shared<MyInt>(0);
      }
    }
    return std::make_shared<MyInt>(1);
  }

  std::shared_ptr<MyInt> operator!=(std::shared_ptr<MyType> other) {
    for (int i = 0; i < value.size(); ++i) {
      if ((*value[i] != std::dynamic_pointer_cast<MyArray<T>>(other)->value[i])->value) {
        return std::make_shared<MyInt>(0);
      }
    }
    return std::make_shared<MyInt>(1);
  }

  std::shared_ptr<MyInt> operator<(std::shared_ptr<MyType> other) {
    return std::make_shared<MyInt>(value < std::dynamic_pointer_cast<MyArray<T>>(other)->value);
  }

  std::shared_ptr<MyInt> operator>(std::shared_ptr<MyType> other) {
    return std::make_shared<MyInt>(value > std::dynamic_pointer_cast<MyArray<T>>(other)->value);
  }

  std::shared_ptr<MyInt> operator<=(std::shared_ptr<MyType> other) {
    return std::make_shared<MyInt>(value <= std::dynamic_pointer_cast<MyArray<T>>(other)->value);
  }

  std::shared_ptr<MyInt> operator>=(std::shared_ptr<MyType> other) {
    return std::make_shared<MyInt>(value >= std::dynamic_pointer_cast<MyArray<T>>(other)->value);
  }

  std::shared_ptr<MyType> operator+(std::shared_ptr<MyType> other) {
    throw std::logic_error("array has no operator +");
  }

  std::shared_ptr<MyType> operator-(std::shared_ptr<MyType> other) {
    throw std::logic_error("array has no operator -");
  }

  std::shared_ptr<MyType> operator*(std::shared_ptr<MyType> other) {
    throw std::logic_error("array has no operator *");
  }

  std::shared_ptr<MyType> operator/(std::shared_ptr<MyType> other) {
    throw std::logic_error("array has no operator /");
  }

  std::shared_ptr<MyType> operator%(std::shared_ptr<MyType> other) override {
    throw std::logic_error("array has no operator %");
  }

  std::shared_ptr<MyType> operator!() override {
    throw std::logic_error("array has no operator !");
  }

  std::shared_ptr<MyType> operator-() override {
    throw std::logic_error("array has no operator -");
  }

  void scan(std::istream& is) override {
    for (int i = 0; i < value.size(); ++i) {
      is >> value[i];
    }
  }

  void print(std::ostream& os) const override {
    os << "{";
    for (int i = 0; i+1 < value.size(); ++i) {
      os << value[i]->value << ", ";
    }
    os << value.back()->value << "}";
  }
};

template<typename T>
MyArray<T>::MyArray(int size): MyType(std::make_pair(T().id.first, size)), value(size) {
  static_assert(std::is_base_of_v<MyType, T>);
  for (auto& i : value) {
    i = std::make_shared<T>();
  }
}
