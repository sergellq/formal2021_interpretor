#pragma once

#include "Automaton.h"
#include "token.h"

class TokenAutomaton : public Automaton {
 public:
  static const vector<string> tokens;

  TokenAutomaton();

  int getNumberOfVariables();

  static bool isComment(int x);
  static bool isBracket(int x);
  static bool isOpenBracket(int x);
  static bool isCloseBracket(int x);
  static bool isNumberLiteral(int x);
  static bool isStringLiteral(int x);
  static bool isType(int x);
  static bool isVariable(int x);
  static bool isReturn(int x);
  static bool isPrint(int x);
  static bool isScan(int x);

  static int oppositeBracket(int x);
  static int getPriopity(int x);
};
