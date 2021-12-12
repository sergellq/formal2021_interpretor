#pragma once

#include <string>

struct token {
  int type;
  std::string s;

  token(int type, const std::string& s);
};
