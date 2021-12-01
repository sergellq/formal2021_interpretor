#include <iostream>
#include "Automaton/TokenAutomaton.h"
#include "Node/Brackets.h"
#include <fstream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

void read(std::ifstream& in, string& text) {
  string tmp;
  while (getline(in, tmp)) {
    text += tmp;
    text += '\n';
  }
}

void parse_on_tokens(TokenAutomaton& token_parser, vector<token>& tokens, const string& text) {
  for (int cur = 0; cur < text.size();) {
    auto[num, len] = token_parser.find(text, cur);
    if (num == -1) {
      if (len != 0) {
        throw std::logic_error("wrong tresh parsing");
      }
      cur += 1;
      continue;
    }
    if (len == 0) {
      throw std::logic_error("zero size token");
    }
    if (cur + len > text.size()) {
      throw std::logic_error("very big token in the end");
    }
    if (!TokenAutomaton::isComment(num)) {
      tokens.emplace_back(num, text.substr(cur, len));
    }
    cur += len;
  }
}

void create_links_to_opposite_bracket(vector<token>& tokens, vector<int>& link) {
  vector<pair<int, int>> stack;
  int pos = -1;
  for (const auto& i: tokens) {
    ++pos;
    if (!TokenAutomaton::isBracket(i.type)) continue;
    if (TokenAutomaton::isOpenBracket(i.type)) {
      stack.emplace_back(pos, i.type);
    } else {
      if (stack.empty()) {
        throw std::logic_error("wrong bracket balance");
      }
      if (stack.back().second != TokenAutomaton::oppositeBracket(i.type)) {
        throw std::logic_error("wrong opposite bracket");
      }
      link[stack.back().first] = pos;
      link[pos] = stack.back().first;
      stack.pop_back();
    }
  }
}

void add_brackets_to_unary_operators(vector<token>& tokens) {
  for (int i = tokens.size()-1; i >= 0; --i) {
    if (tokens[i].s == "-" || tokens[i].s == "!") {
      if (TokenAutomaton::getPriopity(tokens[i].type) == -1 ||
          TokenAutomaton::isOpenBracket(tokens[i].type)) {
        tokens.insert(tokens.begin()+i+2, token(25, ")"));
        tokens.insert(tokens.begin()+i, token(24, "("));
      }
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    return 1;
  }
  std::ifstream in(argv[1]);

  TokenAutomaton token_parser;

  string text;
  read(in, text);
  text = "{" + text + "}";

  vector<token> tokens;
  parse_on_tokens(token_parser, tokens, text);

  add_brackets_to_unary_operators(tokens);

  vector<int> link(tokens.size(), -1);
  create_links_to_opposite_bracket(tokens, link);

  Node* tree = new Brackets(tokens, link, 0, link[0]);
  vector<vector<Node*>> vars(token_parser.getNumberOfVariables());
  tree->run(vars);
  for (auto i : vars) {
    for (auto j : i) {
      delete j;
    }
  }

  return 0;
}
