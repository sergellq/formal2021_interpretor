#pragma once

#include "MyType.h"
#include <vector>
#include <iostream>

template<typename T>
struct MyArray: public MyType {
  std::vector<T*> value;

  explicit MyArray(int size);
  ~MyArray() override = default;

  T* get(int x) {
    return value[x];
  }

  MyType* operator=(MyType* other) {
    for (int i = 0; i < value.size(); ++i) {
      *value[i] = dynamic_cast<MyArray<T>*>(other)->value[i];
    }
    return this;
  }

  MyType* operator+=(MyType* other) {
    throw std::logic_error("array has no operator +=");
  }

  MyType* operator-=(MyType* other) {
    throw std::logic_error("array has no operator -=");
  }

  MyType* operator*=(MyType* other) {
    throw std::logic_error("array has no operator *=");
  }

  MyType* operator/=(MyType* other) {
    throw std::logic_error("array has no operator /=");
  }

  MyType* operator%=(MyType* other) {
    throw std::logic_error("array has no operator %=");
  }

  MyType* operator|(MyType* other) {
    throw std::logic_error("array has no operator |");
  }

  MyType* operator&(MyType* other) {
    throw std::logic_error("array has no operator &");
  }

  MyInt* operator==(MyType* other) {
    for (int i = 0; i < value.size(); ++i) {
      if ((*value[i] != dynamic_cast<MyArray<T>*>(other)->value[i])->value) {
        return new MyInt(0);
      }
    }
    return new MyInt(1);
  }

  MyInt* operator!=(MyType* other) {
    for (int i = 0; i < value.size(); ++i) {
      if ((*value[i] != dynamic_cast<MyArray<T>*>(other)->value[i])->value) {
        return new MyInt(0);
      }
    }
    return new MyInt(1);
  }

  MyInt* operator<(MyType* other) {
    return new MyInt(value < dynamic_cast<MyArray<T>*>(other)->value);
  }

  MyInt* operator>(MyType* other) {
    return new MyInt(value > dynamic_cast<MyArray<T>*>(other)->value);
  }

  MyInt* operator<=(MyType* other) {
    return new MyInt(value <= dynamic_cast<MyArray<T>*>(other)->value);
  }

  MyInt* operator>=(MyType* other) {
    return new MyInt(value >= dynamic_cast<MyArray<T>*>(other)->value);
  }

  MyType* operator+(MyType* other) {
    throw std::logic_error("array has no operator +");
  }

  MyType* operator-(MyType* other) {
    throw std::logic_error("array has no operator -");
  }

  MyType* operator*(MyType* other) {
    throw std::logic_error("array has no operator *");
  }

  MyType* operator/(MyType* other) {
    throw std::logic_error("array has no operator /");
  }

  MyType* operator%(MyType* other) override {
    throw std::logic_error("array has no operator %");
  }

  MyType* operator!() override {
    throw std::logic_error("array has no operator !");
  }

  MyType* operator-() override {
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
    i = new T();
  }
}
