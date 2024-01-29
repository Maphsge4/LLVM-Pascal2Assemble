
// Generated from /home/lhd/Desktop/antlr4-pas/grammar/pasLexer.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  pasLexer : public antlr4::Lexer {
public:
  enum {
    EXPONENT = 1, FUNCTION = 2, PROCEDURE = 3, NOT = 4, DIV = 5, MOD = 6, 
    AND = 7, DOWNTO = 8, TO = 9, UNTIL = 10, REPEAT = 11, FOR = 12, WHILE = 13, 
    DO = 14, CASE = 15, ASSIGNOP = 16, IF = 17, THEN = 18, LBRACK = 19, 
    RBRACK = 20, LEFTPAREN = 21, RIGHTPAREN = 22, INTEGER = 23, REAL = 24, 
    BOOLEAN = 25, CHAR = 26, PROGRAM = 27, CONST = 28, TYPE = 29, RECORD = 30, 
    BEGIN = 31, END = 32, ARRAY = 33, OF = 34, OR = 35, VAR = 36, SPOT = 37, 
    SEMICOLON = 38, COMMA = 39, EQUAL = 40, PLUS = 41, COLON = 42, MINUS = 43, 
    ELSE = 44, LETTER = 45, DIGIT = 46, ID = 47, STAR = 48, DIVIDE = 49, 
    NOTEQUAL = 50, LESS = 51, LESSEQUAL = 52, GREATE = 53, GREATEEQUAL = 54, 
    WS = 55, COMMENT_1 = 56, COMMENT_2 = 57
  };

  pasLexer(antlr4::CharStream *input);
  ~pasLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

