#include "Automaton.h"

const string Automaton::star = "@";
const string Automaton::loop = "$";
const int Automaton::min_variable_number = 10000;
const int Automaton::number_literal = -2;

int Automaton::insert(int v, const string& s, int cur) {
  if (cur == s.size()) {
    token[v] = ++last_token;
    return token[v];
  }
  if (s[cur] == loop[0]) {
    ++cur;
    if (nx[v].find(s[cur]) == nx[v].end()) {
      nx[v][s[cur]] = v;
    } else {
      if (nx[v][s[cur]] != v) {
        throw std::logic_error("duplicate edges in automaton");
      }
    }
    return insert(v, s, cur + 1);
  } else {
    if (nx[v].find(s[cur]) == nx[v].end()) {
      nx[v][s[cur]] = new_vertex();
    }
    return insert(nx[v][s[cur]], s, cur + 1);
  }
}

pair<int, int> Automaton::find_var_token(int v, const string& s, int cur, bool isVar, int len) {
  if (cur == s.size()) {
    return {token[v], len};
  }
  bool curIsVar = isVar & (len == 0 ? isStartVariableLetter(s[cur]) : isVariableLetter(s[cur]));
  if (nx[v].find(s[cur]) != nx[v].end()) {
    return find_var_token(nx[v][s[cur]], s, cur + 1, curIsVar, len + 1);
  }
  if (nx[v].find(star[0]) != nx[v].end()) {
    return find_var_token(nx[v][star[0]], s, cur + 1, curIsVar, len + 1);
  }
  if (curIsVar) {
    v = nx[v][s[cur]] = new_vertex();
    ++len;
    ++cur;
    while (cur < s.size() && isVariableLetter(s[cur])) {
      v = nx[v][s[cur]] = new_vertex();
      ++len;
      ++cur;
    }
    token[v] = ++last_var;
    return {token[v], len};
  }
  if (isVar) {
    if (len == 0) {
      return {-1, len};
    }
    if (token[v] == -1) {
      token[v] = ++last_var;
    }
    return {token[v], len};
  }
  return {token[v], len};
}

pair<int, int> Automaton::find_number(const string& s, int cur) {
  int len = 0;
  while (cur < s.size() && '0' <= s[cur] && s[cur] <= '9') {
    ++len;
    ++cur;
  }
  return {Automaton::number_literal, len};
}

int Automaton::new_vertex() {
  nx.emplace_back();
  token.emplace_back(-1);
  return nx.size() - 1;
}

bool Automaton::isStartVariableLetter(char c) {
  if (c == '_' || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) return true;
  return false;
}

bool Automaton::isVariableLetter(char c) {
  if (isStartVariableLetter(c)) return true;
  if ('0' <= c && c <= '1') return true;
  return false;
}

int Automaton::insert(const string& s, int cur) {
  return insert(root, s, cur);
}

pair<int, int> Automaton::find(const string& s, int cur) {
  if ('0' <= s[cur] && s[cur] <= '9') {
    return find_number(s, cur);
  }
  return find_var_token(root, s, cur, true, 0);
}

Automaton::Automaton() : nx(1), token(1, -1) {}
