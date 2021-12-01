cmake_minimum_required(VERSION 3.20)
project(formal_practice)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
add_executable(formal_practice main.cpp Node/Node.cpp Node/Node.h Automaton/Automaton.cpp Automaton/Automaton.h Automaton/TokenAutomaton.cpp Automaton/TokenAutomaton.h Automaton/token.cpp Automaton/token.h Node/Def.cpp Node/Def.h Node/For.cpp Node/For.h Node/Expression.cpp Node/Expression.h Node/While.cpp Node/While.h Node/If.cpp Node/If.h Node/jump_function.h Types/MyType.h Types/MyInt.cpp Types/MyInt.h Types/MyString.cpp Types/MyString.h Types/MyArray.h Types/MyType.cpp Node/Variable.cpp Node/Variable.h Node/CallingFunction.cpp Node/CallingFunction.h Node/Brackets.cpp Node/Brackets.h Types/MyNullType.cpp Types/MyNullType.h)
