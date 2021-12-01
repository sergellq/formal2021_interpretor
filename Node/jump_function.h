#pragma once

#include <vector>

template<typename A>
int jump(const std::vector<int>& link, int R, A x) {
  R += x;
  R = link[R];
  return R;
}
template<typename A, typename... Args>
int jump(const std::vector<int>& link, int R, A x, Args... args) {
  R += x;
  R = link[R];
  return jump(link, R, args...);
}
