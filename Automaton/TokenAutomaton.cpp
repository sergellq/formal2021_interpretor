#include "TokenAutomaton.h"

const vector<string> TokenAutomaton::tokens = {
    "#" + Automaton::loop + Automaton::star + "\n", // 0
    "//" + Automaton::loop + Automaton::star + "\n",
    "/*" + Automaton::loop + Automaton::star + "*/",
    "\"" + Automaton::loop + Automaton::star + "\"",
    "=",
    "+=", // 5
    "-=",
    "*=",
    "/=",
    "%=",
    "|", // 10
    "&",
    "==",
    "!=",
    "<",
    ">", // 15
    "<=",
    ">=",
    "+",
    "-",
    "*", // 20
    "/",
    "%",
    "!",
    "(",
    ")", // 25
    "[",
    "]",
    "{",
    "}",
    ";", // 30
    "int",
    "string",
    "void",
    "main",
    "def", // 35
    ",",
    "->",
    "return",
    "for",
    "while", // 40
    "if",
    "else",
    "print",
    "scan"
};

TokenAutomaton::TokenAutomaton() {
  for (const auto& i: tokens) {
    insert(i, 0);
  }
}

bool TokenAutomaton::isComment(int x) {
  if (0 <= x && x <= 2) return true;
  return false;
}

bool TokenAutomaton::isBracket(int x) {
  return (24 <= x && x <= 29);
}

bool TokenAutomaton::isOpenBracket(int x) {
  return isBracket(x) && !(x & 1);
}

bool TokenAutomaton::isCloseBracket(int x) {
  return isBracket(x) && (x & 1);
}

bool TokenAutomaton::isNumberLiteral(int x) {
  return x == Automaton::number_literal;
}

bool TokenAutomaton::isStringLiteral(int x) {
  return x == 3;
}

int TokenAutomaton::oppositeBracket(int x) {
  return x ^ 1;
}

bool TokenAutomaton::isVariable(int x) {
  return x >= Automaton::min_variable_number;
}

bool TokenAutomaton::isType(int x) {
  return (31 <= x && x <= 33);
}

bool TokenAutomaton::isReturn(int x) {
  return x == 38;
}

bool TokenAutomaton::isPrint(int x) {
  return x == 43;
}

bool TokenAutomaton::isScan(int x) {
  return x == 44;
}

int TokenAutomaton::getPriopity(int x) {
  static const int size[8] = {6, 1, 1, 2, 4, 2, 3, 1};
  int start = 4;
  for (int prio = 0; prio < 8; ++prio) {
    if (start <= x && x < start + size[prio]) return prio;
    start += size[prio];
  }
  return -1;
}
int TokenAutomaton::getNumberOfVariables() {
  return last_var + 1;
}
