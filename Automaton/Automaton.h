#pragma once

#include <unordered_map>
#include <vector>

using std::vector;
using std::pair;
using std::string;
using std::unordered_map;

class Automaton {
 private:
  int insert(int v, const string& s, int cur);

  pair<int, int> find_var_token(int v, const string& s, int cur, bool isVar, int len);
  static pair<int, int> find_number(const string& s, int cur);

  static bool isStartVariableLetter(char c);
  static bool isVariableLetter(char c);
  int new_vertex();

  vector<unordered_map<char, int>> nx;
  vector<int> token;
  int last_token = -1;
  int root = 0;
 protected:
  int last_var = min_variable_number - 1;
  static const int min_variable_number;
  static const int number_literal;
  static const string star;
  static const string loop;

 public:
  int insert(const string& s, int cur);
  pair<int, int> find(const string& s, int cur);

  Automaton();
};
