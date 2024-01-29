
// Generated from /home/lhd/Desktop/antlr4-pas/grammar/pasParser.g4 by ANTLR 4.8


#include "pasParserListener.h"
#include "pasParserVisitor.h"

#include "pasParser.h"


using namespace antlrcpp;
using namespace antlr4;

pasParser::pasParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

pasParser::~pasParser() {
  delete _interpreter;
}

std::string pasParser::getGrammarFileName() const {
  return "pasParser.g4";
}

const std::vector<std::string>& pasParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& pasParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

pasParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pasParser::Program_headContext* pasParser::ProgramContext::program_head() {
  return getRuleContext<pasParser::Program_headContext>(0);
}

pasParser::Program_bodyContext* pasParser::ProgramContext::program_body() {
  return getRuleContext<pasParser::Program_bodyContext>(0);
}

tree::TerminalNode* pasParser::ProgramContext::SPOT() {
  return getToken(pasParser::SPOT, 0);
}


size_t pasParser::ProgramContext::getRuleIndex() const {
  return pasParser::RuleProgram;
}

void pasParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void pasParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any pasParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

pasParser::ProgramContext* pasParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, pasParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    program_head();
    setState(65);
    program_body();
    setState(66);
    match(pasParser::SPOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Program_headContext ------------------------------------------------------------------

pasParser::Program_headContext::Program_headContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::Program_headContext::PROGRAM() {
  return getToken(pasParser::PROGRAM, 0);
}

std::vector<tree::TerminalNode *> pasParser::Program_headContext::ID() {
  return getTokens(pasParser::ID);
}

tree::TerminalNode* pasParser::Program_headContext::ID(size_t i) {
  return getToken(pasParser::ID, i);
}

tree::TerminalNode* pasParser::Program_headContext::LEFTPAREN() {
  return getToken(pasParser::LEFTPAREN, 0);
}

tree::TerminalNode* pasParser::Program_headContext::RIGHTPAREN() {
  return getToken(pasParser::RIGHTPAREN, 0);
}

tree::TerminalNode* pasParser::Program_headContext::SEMICOLON() {
  return getToken(pasParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> pasParser::Program_headContext::COMMA() {
  return getTokens(pasParser::COMMA);
}

tree::TerminalNode* pasParser::Program_headContext::COMMA(size_t i) {
  return getToken(pasParser::COMMA, i);
}


size_t pasParser::Program_headContext::getRuleIndex() const {
  return pasParser::RuleProgram_head;
}

void pasParser::Program_headContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram_head(this);
}

void pasParser::Program_headContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram_head(this);
}


antlrcpp::Any pasParser::Program_headContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitProgram_head(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Program_headContext* pasParser::program_head() {
  Program_headContext *_localctx = _tracker.createInstance<Program_headContext>(_ctx, getState());
  enterRule(_localctx, 2, pasParser::RuleProgram_head);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(pasParser::PROGRAM);
    setState(69);
    match(pasParser::ID);
    setState(70);
    match(pasParser::LEFTPAREN);
    setState(71);
    match(pasParser::ID);
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pasParser::COMMA) {
      setState(72);
      match(pasParser::COMMA);
      setState(73);
      match(pasParser::ID);
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(79);
    match(pasParser::RIGHTPAREN);
    setState(80);
    match(pasParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Program_bodyContext ------------------------------------------------------------------

pasParser::Program_bodyContext::Program_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pasParser::Compound_statementContext* pasParser::Program_bodyContext::compound_statement() {
  return getRuleContext<pasParser::Compound_statementContext>(0);
}

tree::TerminalNode* pasParser::Program_bodyContext::CONST() {
  return getToken(pasParser::CONST, 0);
}

std::vector<pasParser::Const_deContext *> pasParser::Program_bodyContext::const_de() {
  return getRuleContexts<pasParser::Const_deContext>();
}

pasParser::Const_deContext* pasParser::Program_bodyContext::const_de(size_t i) {
  return getRuleContext<pasParser::Const_deContext>(i);
}

std::vector<tree::TerminalNode *> pasParser::Program_bodyContext::SEMICOLON() {
  return getTokens(pasParser::SEMICOLON);
}

tree::TerminalNode* pasParser::Program_bodyContext::SEMICOLON(size_t i) {
  return getToken(pasParser::SEMICOLON, i);
}

tree::TerminalNode* pasParser::Program_bodyContext::TYPE() {
  return getToken(pasParser::TYPE, 0);
}

std::vector<pasParser::Type_deContext *> pasParser::Program_bodyContext::type_de() {
  return getRuleContexts<pasParser::Type_deContext>();
}

pasParser::Type_deContext* pasParser::Program_bodyContext::type_de(size_t i) {
  return getRuleContext<pasParser::Type_deContext>(i);
}

tree::TerminalNode* pasParser::Program_bodyContext::VAR() {
  return getToken(pasParser::VAR, 0);
}

std::vector<pasParser::Var_deContext *> pasParser::Program_bodyContext::var_de() {
  return getRuleContexts<pasParser::Var_deContext>();
}

pasParser::Var_deContext* pasParser::Program_bodyContext::var_de(size_t i) {
  return getRuleContext<pasParser::Var_deContext>(i);
}

std::vector<pasParser::Subprogram_declarationContext *> pasParser::Program_bodyContext::subprogram_declaration() {
  return getRuleContexts<pasParser::Subprogram_declarationContext>();
}

pasParser::Subprogram_declarationContext* pasParser::Program_bodyContext::subprogram_declaration(size_t i) {
  return getRuleContext<pasParser::Subprogram_declarationContext>(i);
}


size_t pasParser::Program_bodyContext::getRuleIndex() const {
  return pasParser::RuleProgram_body;
}

void pasParser::Program_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram_body(this);
}

void pasParser::Program_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram_body(this);
}


antlrcpp::Any pasParser::Program_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitProgram_body(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Program_bodyContext* pasParser::program_body() {
  Program_bodyContext *_localctx = _tracker.createInstance<Program_bodyContext>(_ctx, getState());
  enterRule(_localctx, 4, pasParser::RuleProgram_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(94);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pasParser::CONST: {
        setState(82);
        match(pasParser::CONST);
        setState(83);
        const_de();
        setState(88);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(84);
            match(pasParser::SEMICOLON);
            setState(85);
            const_de(); 
          }
          setState(90);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
        }
        setState(91);
        match(pasParser::SEMICOLON);
        break;
      }

      case pasParser::FUNCTION:
      case pasParser::PROCEDURE:
      case pasParser::TYPE:
      case pasParser::BEGIN:
      case pasParser::VAR: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pasParser::TYPE: {
        setState(96);
        match(pasParser::TYPE);
        setState(97);
        type_de();
        setState(102);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(98);
            match(pasParser::SEMICOLON);
            setState(99);
            type_de(); 
          }
          setState(104);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
        }
        setState(105);
        match(pasParser::SEMICOLON);
        break;
      }

      case pasParser::FUNCTION:
      case pasParser::PROCEDURE:
      case pasParser::BEGIN:
      case pasParser::VAR: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(122);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pasParser::VAR: {
        setState(110);
        match(pasParser::VAR);
        setState(111);
        var_de();
        setState(116);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(112);
            match(pasParser::SEMICOLON);
            setState(113);
            var_de(); 
          }
          setState(118);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
        }
        setState(119);
        match(pasParser::SEMICOLON);
        break;
      }

      case pasParser::FUNCTION:
      case pasParser::PROCEDURE:
      case pasParser::BEGIN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(132);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pasParser::FUNCTION:
      case pasParser::PROCEDURE: {
        setState(125); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(124);
          subprogram_declaration();
          setState(127); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == pasParser::FUNCTION

        || _la == pasParser::PROCEDURE);
        setState(129);
        match(pasParser::SEMICOLON);
        break;
      }

      case pasParser::BEGIN: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(134);
    compound_statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subprogram_declarationContext ------------------------------------------------------------------

pasParser::Subprogram_declarationContext::Subprogram_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::Subprogram_declarationContext::FUNCTION() {
  return getToken(pasParser::FUNCTION, 0);
}

tree::TerminalNode* pasParser::Subprogram_declarationContext::ID() {
  return getToken(pasParser::ID, 0);
}

tree::TerminalNode* pasParser::Subprogram_declarationContext::COLON() {
  return getToken(pasParser::COLON, 0);
}

pasParser::Standrad_typeContext* pasParser::Subprogram_declarationContext::standrad_type() {
  return getRuleContext<pasParser::Standrad_typeContext>(0);
}

std::vector<tree::TerminalNode *> pasParser::Subprogram_declarationContext::SEMICOLON() {
  return getTokens(pasParser::SEMICOLON);
}

tree::TerminalNode* pasParser::Subprogram_declarationContext::SEMICOLON(size_t i) {
  return getToken(pasParser::SEMICOLON, i);
}

tree::TerminalNode* pasParser::Subprogram_declarationContext::BEGIN() {
  return getToken(pasParser::BEGIN, 0);
}

pasParser::Statement_listContext* pasParser::Subprogram_declarationContext::statement_list() {
  return getRuleContext<pasParser::Statement_listContext>(0);
}

tree::TerminalNode* pasParser::Subprogram_declarationContext::END() {
  return getToken(pasParser::END, 0);
}

tree::TerminalNode* pasParser::Subprogram_declarationContext::LEFTPAREN() {
  return getToken(pasParser::LEFTPAREN, 0);
}

std::vector<pasParser::Para_deContext *> pasParser::Subprogram_declarationContext::para_de() {
  return getRuleContexts<pasParser::Para_deContext>();
}

pasParser::Para_deContext* pasParser::Subprogram_declarationContext::para_de(size_t i) {
  return getRuleContext<pasParser::Para_deContext>(i);
}

tree::TerminalNode* pasParser::Subprogram_declarationContext::RIGHTPAREN() {
  return getToken(pasParser::RIGHTPAREN, 0);
}

std::vector<tree::TerminalNode *> pasParser::Subprogram_declarationContext::VAR() {
  return getTokens(pasParser::VAR);
}

tree::TerminalNode* pasParser::Subprogram_declarationContext::VAR(size_t i) {
  return getToken(pasParser::VAR, i);
}

std::vector<pasParser::Var_deContext *> pasParser::Subprogram_declarationContext::var_de() {
  return getRuleContexts<pasParser::Var_deContext>();
}

pasParser::Var_deContext* pasParser::Subprogram_declarationContext::var_de(size_t i) {
  return getRuleContext<pasParser::Var_deContext>(i);
}

tree::TerminalNode* pasParser::Subprogram_declarationContext::PROCEDURE() {
  return getToken(pasParser::PROCEDURE, 0);
}


size_t pasParser::Subprogram_declarationContext::getRuleIndex() const {
  return pasParser::RuleSubprogram_declaration;
}

void pasParser::Subprogram_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubprogram_declaration(this);
}

void pasParser::Subprogram_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubprogram_declaration(this);
}


antlrcpp::Any pasParser::Subprogram_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitSubprogram_declaration(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Subprogram_declarationContext* pasParser::subprogram_declaration() {
  Subprogram_declarationContext *_localctx = _tracker.createInstance<Subprogram_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, pasParser::RuleSubprogram_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(214);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pasParser::FUNCTION: {
        enterOuterAlt(_localctx, 1);
        setState(136);
        match(pasParser::FUNCTION);
        setState(137);
        match(pasParser::ID);
        setState(153);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case pasParser::LEFTPAREN: {
            setState(138);
            match(pasParser::LEFTPAREN);
            setState(139);
            para_de();
            setState(147);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == pasParser::SEMICOLON) {
              setState(140);
              match(pasParser::SEMICOLON);
              setState(142);
              _errHandler->sync(this);

              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
              case 1: {
                setState(141);
                match(pasParser::VAR);
                break;
              }

              }
              setState(144);
              para_de();
              setState(149);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            setState(150);
            match(pasParser::RIGHTPAREN);
            break;
          }

          case pasParser::COLON: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(155);
        match(pasParser::COLON);
        setState(156);
        standrad_type();
        setState(157);
        match(pasParser::SEMICOLON);
        setState(170);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case pasParser::VAR: {
            setState(158);
            match(pasParser::VAR);
            setState(159);
            var_de();
            setState(164);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
            while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
              if (alt == 1) {
                setState(160);
                match(pasParser::SEMICOLON);
                setState(161);
                var_de(); 
              }
              setState(166);
              _errHandler->sync(this);
              alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
            }
            setState(167);
            match(pasParser::SEMICOLON);
            break;
          }

          case pasParser::BEGIN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(172);
        match(pasParser::BEGIN);
        setState(173);
        statement_list();
        setState(174);
        match(pasParser::END);
        break;
      }

      case pasParser::PROCEDURE: {
        enterOuterAlt(_localctx, 2);
        setState(176);
        match(pasParser::PROCEDURE);
        setState(177);
        match(pasParser::ID);
        setState(193);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case pasParser::LEFTPAREN: {
            setState(178);
            match(pasParser::LEFTPAREN);
            setState(179);
            para_de();
            setState(187);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == pasParser::SEMICOLON) {
              setState(180);
              match(pasParser::SEMICOLON);
              setState(182);
              _errHandler->sync(this);

              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
              case 1: {
                setState(181);
                match(pasParser::VAR);
                break;
              }

              }
              setState(184);
              para_de();
              setState(189);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            setState(190);
            match(pasParser::RIGHTPAREN);
            break;
          }

          case pasParser::SEMICOLON: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(195);
        match(pasParser::SEMICOLON);
        setState(208);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case pasParser::VAR: {
            setState(196);
            match(pasParser::VAR);
            setState(197);
            var_de();
            setState(202);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
            while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
              if (alt == 1) {
                setState(198);
                match(pasParser::SEMICOLON);
                setState(199);
                var_de(); 
              }
              setState(204);
              _errHandler->sync(this);
              alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
            }
            setState(205);
            match(pasParser::SEMICOLON);
            break;
          }

          case pasParser::BEGIN: {
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(210);
        match(pasParser::BEGIN);
        setState(211);
        statement_list();
        setState(212);
        match(pasParser::END);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Para_deContext ------------------------------------------------------------------

pasParser::Para_deContext::Para_deContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> pasParser::Para_deContext::ID() {
  return getTokens(pasParser::ID);
}

tree::TerminalNode* pasParser::Para_deContext::ID(size_t i) {
  return getToken(pasParser::ID, i);
}

tree::TerminalNode* pasParser::Para_deContext::COLON() {
  return getToken(pasParser::COLON, 0);
}

pasParser::Standrad_typeContext* pasParser::Para_deContext::standrad_type() {
  return getRuleContext<pasParser::Standrad_typeContext>(0);
}

tree::TerminalNode* pasParser::Para_deContext::VAR() {
  return getToken(pasParser::VAR, 0);
}

std::vector<tree::TerminalNode *> pasParser::Para_deContext::COMMA() {
  return getTokens(pasParser::COMMA);
}

tree::TerminalNode* pasParser::Para_deContext::COMMA(size_t i) {
  return getToken(pasParser::COMMA, i);
}


size_t pasParser::Para_deContext::getRuleIndex() const {
  return pasParser::RulePara_de;
}

void pasParser::Para_deContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPara_de(this);
}

void pasParser::Para_deContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPara_de(this);
}


antlrcpp::Any pasParser::Para_deContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitPara_de(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Para_deContext* pasParser::para_de() {
  Para_deContext *_localctx = _tracker.createInstance<Para_deContext>(_ctx, getState());
  enterRule(_localctx, 8, pasParser::RulePara_de);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == pasParser::VAR) {
      setState(216);
      match(pasParser::VAR);
    }
    setState(219);
    match(pasParser::ID);
    setState(224);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pasParser::COMMA) {
      setState(220);
      match(pasParser::COMMA);
      setState(221);
      match(pasParser::ID);
      setState(226);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(227);
    match(pasParser::COLON);
    setState(228);
    standrad_type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_deContext ------------------------------------------------------------------

pasParser::Type_deContext::Type_deContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::Type_deContext::ID() {
  return getToken(pasParser::ID, 0);
}

tree::TerminalNode* pasParser::Type_deContext::EQUAL() {
  return getToken(pasParser::EQUAL, 0);
}

pasParser::TypeContext* pasParser::Type_deContext::type() {
  return getRuleContext<pasParser::TypeContext>(0);
}


size_t pasParser::Type_deContext::getRuleIndex() const {
  return pasParser::RuleType_de;
}

void pasParser::Type_deContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_de(this);
}

void pasParser::Type_deContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_de(this);
}


antlrcpp::Any pasParser::Type_deContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitType_de(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Type_deContext* pasParser::type_de() {
  Type_deContext *_localctx = _tracker.createInstance<Type_deContext>(_ctx, getState());
  enterRule(_localctx, 10, pasParser::RuleType_de);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(pasParser::ID);
    setState(231);
    match(pasParser::EQUAL);
    setState(232);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_deContext ------------------------------------------------------------------

pasParser::Const_deContext::Const_deContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::Const_deContext::ID() {
  return getToken(pasParser::ID, 0);
}

tree::TerminalNode* pasParser::Const_deContext::EQUAL() {
  return getToken(pasParser::EQUAL, 0);
}

pasParser::Const_variableContext* pasParser::Const_deContext::const_variable() {
  return getRuleContext<pasParser::Const_variableContext>(0);
}


size_t pasParser::Const_deContext::getRuleIndex() const {
  return pasParser::RuleConst_de;
}

void pasParser::Const_deContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_de(this);
}

void pasParser::Const_deContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_de(this);
}


antlrcpp::Any pasParser::Const_deContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitConst_de(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Const_deContext* pasParser::const_de() {
  Const_deContext *_localctx = _tracker.createInstance<Const_deContext>(_ctx, getState());
  enterRule(_localctx, 12, pasParser::RuleConst_de);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    match(pasParser::ID);
    setState(235);
    match(pasParser::EQUAL);
    setState(236);
    const_variable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_deContext ------------------------------------------------------------------

pasParser::Var_deContext::Var_deContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pasParser::IdentifierContext *> pasParser::Var_deContext::identifier() {
  return getRuleContexts<pasParser::IdentifierContext>();
}

pasParser::IdentifierContext* pasParser::Var_deContext::identifier(size_t i) {
  return getRuleContext<pasParser::IdentifierContext>(i);
}

tree::TerminalNode* pasParser::Var_deContext::COLON() {
  return getToken(pasParser::COLON, 0);
}

pasParser::TypeContext* pasParser::Var_deContext::type() {
  return getRuleContext<pasParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> pasParser::Var_deContext::COMMA() {
  return getTokens(pasParser::COMMA);
}

tree::TerminalNode* pasParser::Var_deContext::COMMA(size_t i) {
  return getToken(pasParser::COMMA, i);
}


size_t pasParser::Var_deContext::getRuleIndex() const {
  return pasParser::RuleVar_de;
}

void pasParser::Var_deContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_de(this);
}

void pasParser::Var_deContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_de(this);
}


antlrcpp::Any pasParser::Var_deContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitVar_de(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Var_deContext* pasParser::var_de() {
  Var_deContext *_localctx = _tracker.createInstance<Var_deContext>(_ctx, getState());
  enterRule(_localctx, 14, pasParser::RuleVar_de);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    identifier();
    setState(243);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pasParser::COMMA) {
      setState(239);
      match(pasParser::COMMA);
      setState(240);
      identifier();
      setState(245);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(246);
    match(pasParser::COLON);
    setState(247);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

pasParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::IdentifierContext::ID() {
  return getToken(pasParser::ID, 0);
}


size_t pasParser::IdentifierContext::getRuleIndex() const {
  return pasParser::RuleIdentifier;
}

void pasParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void pasParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}


antlrcpp::Any pasParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

pasParser::IdentifierContext* pasParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 16, pasParser::RuleIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(pasParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

pasParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pasParser::Standrad_typeContext* pasParser::TypeContext::standrad_type() {
  return getRuleContext<pasParser::Standrad_typeContext>(0);
}

tree::TerminalNode* pasParser::TypeContext::RECORD() {
  return getToken(pasParser::RECORD, 0);
}

pasParser::Record_bodyContext* pasParser::TypeContext::record_body() {
  return getRuleContext<pasParser::Record_bodyContext>(0);
}

tree::TerminalNode* pasParser::TypeContext::END() {
  return getToken(pasParser::END, 0);
}

tree::TerminalNode* pasParser::TypeContext::ARRAY() {
  return getToken(pasParser::ARRAY, 0);
}

tree::TerminalNode* pasParser::TypeContext::LBRACK() {
  return getToken(pasParser::LBRACK, 0);
}

std::vector<pasParser::PeriodContext *> pasParser::TypeContext::period() {
  return getRuleContexts<pasParser::PeriodContext>();
}

pasParser::PeriodContext* pasParser::TypeContext::period(size_t i) {
  return getRuleContext<pasParser::PeriodContext>(i);
}

tree::TerminalNode* pasParser::TypeContext::RBRACK() {
  return getToken(pasParser::RBRACK, 0);
}

tree::TerminalNode* pasParser::TypeContext::OF() {
  return getToken(pasParser::OF, 0);
}

pasParser::TypeContext* pasParser::TypeContext::type() {
  return getRuleContext<pasParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> pasParser::TypeContext::COMMA() {
  return getTokens(pasParser::COMMA);
}

tree::TerminalNode* pasParser::TypeContext::COMMA(size_t i) {
  return getToken(pasParser::COMMA, i);
}


size_t pasParser::TypeContext::getRuleIndex() const {
  return pasParser::RuleType;
}

void pasParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void pasParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any pasParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

pasParser::TypeContext* pasParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 18, pasParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(270);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pasParser::INTEGER:
      case pasParser::REAL:
      case pasParser::BOOLEAN:
      case pasParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(251);
        standrad_type();
        break;
      }

      case pasParser::RECORD: {
        enterOuterAlt(_localctx, 2);
        setState(252);
        match(pasParser::RECORD);
        setState(253);
        record_body();
        setState(254);
        match(pasParser::END);
        break;
      }

      case pasParser::ARRAY: {
        enterOuterAlt(_localctx, 3);
        setState(256);
        match(pasParser::ARRAY);
        setState(257);
        match(pasParser::LBRACK);
        setState(258);
        period();
        setState(263);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == pasParser::COMMA) {
          setState(259);
          match(pasParser::COMMA);
          setState(260);
          period();
          setState(265);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(266);
        match(pasParser::RBRACK);
        setState(267);
        match(pasParser::OF);
        setState(268);
        type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Standrad_typeContext ------------------------------------------------------------------

pasParser::Standrad_typeContext::Standrad_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::Standrad_typeContext::INTEGER() {
  return getToken(pasParser::INTEGER, 0);
}

tree::TerminalNode* pasParser::Standrad_typeContext::REAL() {
  return getToken(pasParser::REAL, 0);
}

tree::TerminalNode* pasParser::Standrad_typeContext::BOOLEAN() {
  return getToken(pasParser::BOOLEAN, 0);
}

tree::TerminalNode* pasParser::Standrad_typeContext::CHAR() {
  return getToken(pasParser::CHAR, 0);
}


size_t pasParser::Standrad_typeContext::getRuleIndex() const {
  return pasParser::RuleStandrad_type;
}

void pasParser::Standrad_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStandrad_type(this);
}

void pasParser::Standrad_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStandrad_type(this);
}


antlrcpp::Any pasParser::Standrad_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitStandrad_type(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Standrad_typeContext* pasParser::standrad_type() {
  Standrad_typeContext *_localctx = _tracker.createInstance<Standrad_typeContext>(_ctx, getState());
  enterRule(_localctx, 20, pasParser::RuleStandrad_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pasParser::INTEGER)
      | (1ULL << pasParser::REAL)
      | (1ULL << pasParser::BOOLEAN)
      | (1ULL << pasParser::CHAR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Record_bodyContext ------------------------------------------------------------------

pasParser::Record_bodyContext::Record_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pasParser::Var_deContext *> pasParser::Record_bodyContext::var_de() {
  return getRuleContexts<pasParser::Var_deContext>();
}

pasParser::Var_deContext* pasParser::Record_bodyContext::var_de(size_t i) {
  return getRuleContext<pasParser::Var_deContext>(i);
}

std::vector<tree::TerminalNode *> pasParser::Record_bodyContext::SEMICOLON() {
  return getTokens(pasParser::SEMICOLON);
}

tree::TerminalNode* pasParser::Record_bodyContext::SEMICOLON(size_t i) {
  return getToken(pasParser::SEMICOLON, i);
}

pasParser::EmptyContext* pasParser::Record_bodyContext::empty() {
  return getRuleContext<pasParser::EmptyContext>(0);
}


size_t pasParser::Record_bodyContext::getRuleIndex() const {
  return pasParser::RuleRecord_body;
}

void pasParser::Record_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecord_body(this);
}

void pasParser::Record_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecord_body(this);
}


antlrcpp::Any pasParser::Record_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitRecord_body(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Record_bodyContext* pasParser::record_body() {
  Record_bodyContext *_localctx = _tracker.createInstance<Record_bodyContext>(_ctx, getState());
  enterRule(_localctx, 22, pasParser::RuleRecord_body);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pasParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(274);
        var_de();
        setState(279);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == pasParser::SEMICOLON) {
          setState(275);
          match(pasParser::SEMICOLON);
          setState(276);
          var_de();
          setState(281);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case pasParser::END: {
        enterOuterAlt(_localctx, 2);
        setState(282);
        empty();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PeriodContext ------------------------------------------------------------------

pasParser::PeriodContext::PeriodContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pasParser::Const_variableContext *> pasParser::PeriodContext::const_variable() {
  return getRuleContexts<pasParser::Const_variableContext>();
}

pasParser::Const_variableContext* pasParser::PeriodContext::const_variable(size_t i) {
  return getRuleContext<pasParser::Const_variableContext>(i);
}

std::vector<tree::TerminalNode *> pasParser::PeriodContext::SPOT() {
  return getTokens(pasParser::SPOT);
}

tree::TerminalNode* pasParser::PeriodContext::SPOT(size_t i) {
  return getToken(pasParser::SPOT, i);
}


size_t pasParser::PeriodContext::getRuleIndex() const {
  return pasParser::RulePeriod;
}

void pasParser::PeriodContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPeriod(this);
}

void pasParser::PeriodContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPeriod(this);
}


antlrcpp::Any pasParser::PeriodContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitPeriod(this);
  else
    return visitor->visitChildren(this);
}

pasParser::PeriodContext* pasParser::period() {
  PeriodContext *_localctx = _tracker.createInstance<PeriodContext>(_ctx, getState());
  enterRule(_localctx, 24, pasParser::RulePeriod);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    const_variable();
    setState(286);
    match(pasParser::SPOT);
    setState(287);
    match(pasParser::SPOT);
    setState(288);
    const_variable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_variableContext ------------------------------------------------------------------

pasParser::Const_variableContext::Const_variableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::Const_variableContext::PLUS() {
  return getToken(pasParser::PLUS, 0);
}

tree::TerminalNode* pasParser::Const_variableContext::ID() {
  return getToken(pasParser::ID, 0);
}

tree::TerminalNode* pasParser::Const_variableContext::MINUS() {
  return getToken(pasParser::MINUS, 0);
}

pasParser::NumContext* pasParser::Const_variableContext::num() {
  return getRuleContext<pasParser::NumContext>(0);
}

tree::TerminalNode* pasParser::Const_variableContext::LETTER() {
  return getToken(pasParser::LETTER, 0);
}


size_t pasParser::Const_variableContext::getRuleIndex() const {
  return pasParser::RuleConst_variable;
}

void pasParser::Const_variableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_variable(this);
}

void pasParser::Const_variableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_variable(this);
}


antlrcpp::Any pasParser::Const_variableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitConst_variable(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Const_variableContext* pasParser::const_variable() {
  Const_variableContext *_localctx = _tracker.createInstance<Const_variableContext>(_ctx, getState());
  enterRule(_localctx, 26, pasParser::RuleConst_variable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(301);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(290);
      match(pasParser::PLUS);
      setState(291);
      match(pasParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(292);
      match(pasParser::MINUS);
      setState(293);
      match(pasParser::ID);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(294);
      match(pasParser::ID);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(295);
      match(pasParser::PLUS);
      setState(296);
      num();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(297);
      match(pasParser::MINUS);
      setState(298);
      num();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(299);
      num();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(300);
      match(pasParser::LETTER);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

pasParser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::Compound_statementContext::BEGIN() {
  return getToken(pasParser::BEGIN, 0);
}

pasParser::Statement_listContext* pasParser::Compound_statementContext::statement_list() {
  return getRuleContext<pasParser::Statement_listContext>(0);
}

tree::TerminalNode* pasParser::Compound_statementContext::END() {
  return getToken(pasParser::END, 0);
}


size_t pasParser::Compound_statementContext::getRuleIndex() const {
  return pasParser::RuleCompound_statement;
}

void pasParser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void pasParser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}


antlrcpp::Any pasParser::Compound_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitCompound_statement(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Compound_statementContext* pasParser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 28, pasParser::RuleCompound_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(303);
    match(pasParser::BEGIN);
    setState(304);
    statement_list();
    setState(305);
    match(pasParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_listContext ------------------------------------------------------------------

pasParser::Statement_listContext::Statement_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pasParser::StatementContext *> pasParser::Statement_listContext::statement() {
  return getRuleContexts<pasParser::StatementContext>();
}

pasParser::StatementContext* pasParser::Statement_listContext::statement(size_t i) {
  return getRuleContext<pasParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> pasParser::Statement_listContext::SEMICOLON() {
  return getTokens(pasParser::SEMICOLON);
}

tree::TerminalNode* pasParser::Statement_listContext::SEMICOLON(size_t i) {
  return getToken(pasParser::SEMICOLON, i);
}


size_t pasParser::Statement_listContext::getRuleIndex() const {
  return pasParser::RuleStatement_list;
}

void pasParser::Statement_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_list(this);
}

void pasParser::Statement_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_list(this);
}


antlrcpp::Any pasParser::Statement_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitStatement_list(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Statement_listContext* pasParser::statement_list() {
  Statement_listContext *_localctx = _tracker.createInstance<Statement_listContext>(_ctx, getState());
  enterRule(_localctx, 30, pasParser::RuleStatement_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(307);
    statement();
    setState(312);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pasParser::SEMICOLON) {
      setState(308);
      match(pasParser::SEMICOLON);
      setState(309);
      statement();
      setState(314);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

pasParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t pasParser::StatementContext::getRuleIndex() const {
  return pasParser::RuleStatement;
}

void pasParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ComContext ------------------------------------------------------------------

tree::TerminalNode* pasParser::ComContext::BEGIN() {
  return getToken(pasParser::BEGIN, 0);
}

pasParser::Statement_listContext* pasParser::ComContext::statement_list() {
  return getRuleContext<pasParser::Statement_listContext>(0);
}

tree::TerminalNode* pasParser::ComContext::END() {
  return getToken(pasParser::END, 0);
}

pasParser::ComContext::ComContext(StatementContext *ctx) { copyFrom(ctx); }

void pasParser::ComContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCom(this);
}
void pasParser::ComContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCom(this);
}

antlrcpp::Any pasParser::ComContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitCom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Call_pro_statementContext ------------------------------------------------------------------

pasParser::Call_procedure_statementContext* pasParser::Call_pro_statementContext::call_procedure_statement() {
  return getRuleContext<pasParser::Call_procedure_statementContext>(0);
}

pasParser::Call_pro_statementContext::Call_pro_statementContext(StatementContext *ctx) { copyFrom(ctx); }

void pasParser::Call_pro_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall_pro_statement(this);
}
void pasParser::Call_pro_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall_pro_statement(this);
}

antlrcpp::Any pasParser::Call_pro_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitCall_pro_statement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RepeatContext ------------------------------------------------------------------

tree::TerminalNode* pasParser::RepeatContext::REPEAT() {
  return getToken(pasParser::REPEAT, 0);
}

pasParser::Statement_listContext* pasParser::RepeatContext::statement_list() {
  return getRuleContext<pasParser::Statement_listContext>(0);
}

tree::TerminalNode* pasParser::RepeatContext::UNTIL() {
  return getToken(pasParser::UNTIL, 0);
}

pasParser::ExpressionContext* pasParser::RepeatContext::expression() {
  return getRuleContext<pasParser::ExpressionContext>(0);
}

pasParser::RepeatContext::RepeatContext(StatementContext *ctx) { copyFrom(ctx); }

void pasParser::RepeatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRepeat(this);
}
void pasParser::RepeatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRepeat(this);
}

antlrcpp::Any pasParser::RepeatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitRepeat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Statement1Context ------------------------------------------------------------------

pasParser::VariableContext* pasParser::Statement1Context::variable() {
  return getRuleContext<pasParser::VariableContext>(0);
}

tree::TerminalNode* pasParser::Statement1Context::ASSIGNOP() {
  return getToken(pasParser::ASSIGNOP, 0);
}

pasParser::ExpressionContext* pasParser::Statement1Context::expression() {
  return getRuleContext<pasParser::ExpressionContext>(0);
}

pasParser::Statement1Context::Statement1Context(StatementContext *ctx) { copyFrom(ctx); }

void pasParser::Statement1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement1(this);
}
void pasParser::Statement1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement1(this);
}

antlrcpp::Any pasParser::Statement1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitStatement1(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileContext ------------------------------------------------------------------

tree::TerminalNode* pasParser::WhileContext::WHILE() {
  return getToken(pasParser::WHILE, 0);
}

pasParser::ExpressionContext* pasParser::WhileContext::expression() {
  return getRuleContext<pasParser::ExpressionContext>(0);
}

tree::TerminalNode* pasParser::WhileContext::DO() {
  return getToken(pasParser::DO, 0);
}

pasParser::StatementContext* pasParser::WhileContext::statement() {
  return getRuleContext<pasParser::StatementContext>(0);
}

pasParser::WhileContext::WhileContext(StatementContext *ctx) { copyFrom(ctx); }

void pasParser::WhileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile(this);
}
void pasParser::WhileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile(this);
}

antlrcpp::Any pasParser::WhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- If_elseContext ------------------------------------------------------------------

tree::TerminalNode* pasParser::If_elseContext::IF() {
  return getToken(pasParser::IF, 0);
}

pasParser::ExpressionContext* pasParser::If_elseContext::expression() {
  return getRuleContext<pasParser::ExpressionContext>(0);
}

tree::TerminalNode* pasParser::If_elseContext::THEN() {
  return getToken(pasParser::THEN, 0);
}

std::vector<pasParser::StatementContext *> pasParser::If_elseContext::statement() {
  return getRuleContexts<pasParser::StatementContext>();
}

pasParser::StatementContext* pasParser::If_elseContext::statement(size_t i) {
  return getRuleContext<pasParser::StatementContext>(i);
}

tree::TerminalNode* pasParser::If_elseContext::ELSE() {
  return getToken(pasParser::ELSE, 0);
}

pasParser::If_elseContext::If_elseContext(StatementContext *ctx) { copyFrom(ctx); }

void pasParser::If_elseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_else(this);
}
void pasParser::If_elseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_else(this);
}

antlrcpp::Any pasParser::If_elseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitIf_else(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Statement2Context ------------------------------------------------------------------

pasParser::EmptyContext* pasParser::Statement2Context::empty() {
  return getRuleContext<pasParser::EmptyContext>(0);
}

pasParser::Statement2Context::Statement2Context(StatementContext *ctx) { copyFrom(ctx); }

void pasParser::Statement2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement2(this);
}
void pasParser::Statement2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement2(this);
}

antlrcpp::Any pasParser::Statement2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitStatement2(this);
  else
    return visitor->visitChildren(this);
}
pasParser::StatementContext* pasParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 32, pasParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(344);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<pasParser::Statement1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(315);
      variable();
      setState(316);
      match(pasParser::ASSIGNOP);
      setState(317);
      expression();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<pasParser::ComContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(319);
      match(pasParser::BEGIN);
      setState(320);
      statement_list();
      setState(321);
      match(pasParser::END);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<pasParser::Call_pro_statementContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(323);
      call_procedure_statement();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<pasParser::If_elseContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(324);
      match(pasParser::IF);
      setState(325);
      expression();
      setState(326);
      match(pasParser::THEN);
      setState(327);
      statement();
      setState(331);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
      case 1: {
        setState(328);
        match(pasParser::ELSE);
        setState(329);
        statement();
        break;
      }

      case 2: {
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<pasParser::WhileContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(333);
      match(pasParser::WHILE);
      setState(334);
      expression();
      setState(335);
      match(pasParser::DO);
      setState(336);
      statement();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<pasParser::RepeatContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(338);
      match(pasParser::REPEAT);
      setState(339);
      statement_list();
      setState(340);
      match(pasParser::UNTIL);
      setState(341);
      expression();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<pasParser::Statement2Context>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(343);
      empty();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Call_procedure_statementContext ------------------------------------------------------------------

pasParser::Call_procedure_statementContext::Call_procedure_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::Call_procedure_statementContext::ID() {
  return getToken(pasParser::ID, 0);
}

tree::TerminalNode* pasParser::Call_procedure_statementContext::LEFTPAREN() {
  return getToken(pasParser::LEFTPAREN, 0);
}

pasParser::Expression_listContext* pasParser::Call_procedure_statementContext::expression_list() {
  return getRuleContext<pasParser::Expression_listContext>(0);
}

tree::TerminalNode* pasParser::Call_procedure_statementContext::RIGHTPAREN() {
  return getToken(pasParser::RIGHTPAREN, 0);
}


size_t pasParser::Call_procedure_statementContext::getRuleIndex() const {
  return pasParser::RuleCall_procedure_statement;
}

void pasParser::Call_procedure_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall_procedure_statement(this);
}

void pasParser::Call_procedure_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall_procedure_statement(this);
}


antlrcpp::Any pasParser::Call_procedure_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitCall_procedure_statement(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Call_procedure_statementContext* pasParser::call_procedure_statement() {
  Call_procedure_statementContext *_localctx = _tracker.createInstance<Call_procedure_statementContext>(_ctx, getState());
  enterRule(_localctx, 34, pasParser::RuleCall_procedure_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(352);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(346);
      match(pasParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(347);
      match(pasParser::ID);
      setState(348);
      match(pasParser::LEFTPAREN);
      setState(349);
      expression_list();
      setState(350);
      match(pasParser::RIGHTPAREN);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

pasParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::VariableContext::ID() {
  return getToken(pasParser::ID, 0);
}

std::vector<pasParser::Id_varpartContext *> pasParser::VariableContext::id_varpart() {
  return getRuleContexts<pasParser::Id_varpartContext>();
}

pasParser::Id_varpartContext* pasParser::VariableContext::id_varpart(size_t i) {
  return getRuleContext<pasParser::Id_varpartContext>(i);
}


size_t pasParser::VariableContext::getRuleIndex() const {
  return pasParser::RuleVariable;
}

void pasParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void pasParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}


antlrcpp::Any pasParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

pasParser::VariableContext* pasParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 36, pasParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(354);
    match(pasParser::ID);
    setState(358);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(355);
        id_varpart(); 
      }
      setState(360);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Id_varpartContext ------------------------------------------------------------------

pasParser::Id_varpartContext::Id_varpartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::Id_varpartContext::LBRACK() {
  return getToken(pasParser::LBRACK, 0);
}

pasParser::Expression_listContext* pasParser::Id_varpartContext::expression_list() {
  return getRuleContext<pasParser::Expression_listContext>(0);
}

tree::TerminalNode* pasParser::Id_varpartContext::RBRACK() {
  return getToken(pasParser::RBRACK, 0);
}

tree::TerminalNode* pasParser::Id_varpartContext::SPOT() {
  return getToken(pasParser::SPOT, 0);
}

tree::TerminalNode* pasParser::Id_varpartContext::ID() {
  return getToken(pasParser::ID, 0);
}


size_t pasParser::Id_varpartContext::getRuleIndex() const {
  return pasParser::RuleId_varpart;
}

void pasParser::Id_varpartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId_varpart(this);
}

void pasParser::Id_varpartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId_varpart(this);
}


antlrcpp::Any pasParser::Id_varpartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitId_varpart(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Id_varpartContext* pasParser::id_varpart() {
  Id_varpartContext *_localctx = _tracker.createInstance<Id_varpartContext>(_ctx, getState());
  enterRule(_localctx, 38, pasParser::RuleId_varpart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(367);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pasParser::LBRACK: {
        enterOuterAlt(_localctx, 1);
        setState(361);
        match(pasParser::LBRACK);
        setState(362);
        expression_list();
        setState(363);
        match(pasParser::RBRACK);
        break;
      }

      case pasParser::SPOT: {
        enterOuterAlt(_localctx, 2);
        setState(365);
        match(pasParser::SPOT);
        setState(366);
        match(pasParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_listContext ------------------------------------------------------------------

pasParser::Expression_listContext::Expression_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pasParser::ExpressionContext *> pasParser::Expression_listContext::expression() {
  return getRuleContexts<pasParser::ExpressionContext>();
}

pasParser::ExpressionContext* pasParser::Expression_listContext::expression(size_t i) {
  return getRuleContext<pasParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> pasParser::Expression_listContext::COMMA() {
  return getTokens(pasParser::COMMA);
}

tree::TerminalNode* pasParser::Expression_listContext::COMMA(size_t i) {
  return getToken(pasParser::COMMA, i);
}


size_t pasParser::Expression_listContext::getRuleIndex() const {
  return pasParser::RuleExpression_list;
}

void pasParser::Expression_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_list(this);
}

void pasParser::Expression_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_list(this);
}


antlrcpp::Any pasParser::Expression_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitExpression_list(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Expression_listContext* pasParser::expression_list() {
  Expression_listContext *_localctx = _tracker.createInstance<Expression_listContext>(_ctx, getState());
  enterRule(_localctx, 40, pasParser::RuleExpression_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    expression();
    setState(374);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == pasParser::COMMA) {
      setState(370);
      match(pasParser::COMMA);
      setState(371);
      expression();
      setState(376);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

pasParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pasParser::Simple_expressionContext *> pasParser::ExpressionContext::simple_expression() {
  return getRuleContexts<pasParser::Simple_expressionContext>();
}

pasParser::Simple_expressionContext* pasParser::ExpressionContext::simple_expression(size_t i) {
  return getRuleContext<pasParser::Simple_expressionContext>(i);
}

pasParser::RelopContext* pasParser::ExpressionContext::relop() {
  return getRuleContext<pasParser::RelopContext>(0);
}


size_t pasParser::ExpressionContext::getRuleIndex() const {
  return pasParser::RuleExpression;
}

void pasParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void pasParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any pasParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

pasParser::ExpressionContext* pasParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 42, pasParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(382);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(377);
      simple_expression(0);
      setState(378);
      relop();
      setState(379);
      simple_expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(381);
      simple_expression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

pasParser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pasParser::TermContext* pasParser::Simple_expressionContext::term() {
  return getRuleContext<pasParser::TermContext>(0);
}

tree::TerminalNode* pasParser::Simple_expressionContext::PLUS() {
  return getToken(pasParser::PLUS, 0);
}

tree::TerminalNode* pasParser::Simple_expressionContext::MINUS() {
  return getToken(pasParser::MINUS, 0);
}

pasParser::Simple_expressionContext* pasParser::Simple_expressionContext::simple_expression() {
  return getRuleContext<pasParser::Simple_expressionContext>(0);
}

pasParser::AddopContext* pasParser::Simple_expressionContext::addop() {
  return getRuleContext<pasParser::AddopContext>(0);
}


size_t pasParser::Simple_expressionContext::getRuleIndex() const {
  return pasParser::RuleSimple_expression;
}

void pasParser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void pasParser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


antlrcpp::Any pasParser::Simple_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitSimple_expression(this);
  else
    return visitor->visitChildren(this);
}


pasParser::Simple_expressionContext* pasParser::simple_expression() {
   return simple_expression(0);
}

pasParser::Simple_expressionContext* pasParser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  pasParser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  pasParser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, pasParser::RuleSimple_expression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(390);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pasParser::NOT:
      case pasParser::LEFTPAREN:
      case pasParser::LETTER:
      case pasParser::DIGIT:
      case pasParser::ID: {
        setState(385);
        term(0);
        break;
      }

      case pasParser::PLUS: {
        setState(386);
        match(pasParser::PLUS);
        setState(387);
        term(0);
        break;
      }

      case pasParser::MINUS: {
        setState(388);
        match(pasParser::MINUS);
        setState(389);
        term(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(398);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(392);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(393);
        addop();
        setState(394);
        term(0); 
      }
      setState(400);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

pasParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pasParser::FactorContext* pasParser::TermContext::factor() {
  return getRuleContext<pasParser::FactorContext>(0);
}

pasParser::TermContext* pasParser::TermContext::term() {
  return getRuleContext<pasParser::TermContext>(0);
}

pasParser::MulopContext* pasParser::TermContext::mulop() {
  return getRuleContext<pasParser::MulopContext>(0);
}


size_t pasParser::TermContext::getRuleIndex() const {
  return pasParser::RuleTerm;
}

void pasParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void pasParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


antlrcpp::Any pasParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}


pasParser::TermContext* pasParser::term() {
   return term(0);
}

pasParser::TermContext* pasParser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  pasParser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  pasParser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, pasParser::RuleTerm, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(402);
    factor();
    _ctx->stop = _input->LT(-1);
    setState(410);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(404);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(405);
        mulop();
        setState(406);
        factor(); 
      }
      setState(412);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

pasParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

pasParser::Unsign_const_variableContext* pasParser::FactorContext::unsign_const_variable() {
  return getRuleContext<pasParser::Unsign_const_variableContext>(0);
}

pasParser::VariableContext* pasParser::FactorContext::variable() {
  return getRuleContext<pasParser::VariableContext>(0);
}

tree::TerminalNode* pasParser::FactorContext::ID() {
  return getToken(pasParser::ID, 0);
}

tree::TerminalNode* pasParser::FactorContext::LEFTPAREN() {
  return getToken(pasParser::LEFTPAREN, 0);
}

pasParser::Expression_listContext* pasParser::FactorContext::expression_list() {
  return getRuleContext<pasParser::Expression_listContext>(0);
}

tree::TerminalNode* pasParser::FactorContext::RIGHTPAREN() {
  return getToken(pasParser::RIGHTPAREN, 0);
}

pasParser::ExpressionContext* pasParser::FactorContext::expression() {
  return getRuleContext<pasParser::ExpressionContext>(0);
}

tree::TerminalNode* pasParser::FactorContext::NOT() {
  return getToken(pasParser::NOT, 0);
}

pasParser::FactorContext* pasParser::FactorContext::factor() {
  return getRuleContext<pasParser::FactorContext>(0);
}


size_t pasParser::FactorContext::getRuleIndex() const {
  return pasParser::RuleFactor;
}

void pasParser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void pasParser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}


antlrcpp::Any pasParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

pasParser::FactorContext* pasParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 48, pasParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(426);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(413);
      unsign_const_variable();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(414);
      variable();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(415);
      match(pasParser::ID);
      setState(416);
      match(pasParser::LEFTPAREN);
      setState(417);
      expression_list();
      setState(418);
      match(pasParser::RIGHTPAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(420);
      match(pasParser::LEFTPAREN);
      setState(421);
      expression();
      setState(422);
      match(pasParser::RIGHTPAREN);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(424);
      match(pasParser::NOT);
      setState(425);
      factor();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unsign_const_variableContext ------------------------------------------------------------------

pasParser::Unsign_const_variableContext::Unsign_const_variableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::Unsign_const_variableContext::ID() {
  return getToken(pasParser::ID, 0);
}

pasParser::NumContext* pasParser::Unsign_const_variableContext::num() {
  return getRuleContext<pasParser::NumContext>(0);
}

tree::TerminalNode* pasParser::Unsign_const_variableContext::LETTER() {
  return getToken(pasParser::LETTER, 0);
}


size_t pasParser::Unsign_const_variableContext::getRuleIndex() const {
  return pasParser::RuleUnsign_const_variable;
}

void pasParser::Unsign_const_variableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnsign_const_variable(this);
}

void pasParser::Unsign_const_variableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnsign_const_variable(this);
}


antlrcpp::Any pasParser::Unsign_const_variableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitUnsign_const_variable(this);
  else
    return visitor->visitChildren(this);
}

pasParser::Unsign_const_variableContext* pasParser::unsign_const_variable() {
  Unsign_const_variableContext *_localctx = _tracker.createInstance<Unsign_const_variableContext>(_ctx, getState());
  enterRule(_localctx, 50, pasParser::RuleUnsign_const_variable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(431);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case pasParser::ID: {
        enterOuterAlt(_localctx, 1);
        setState(428);
        match(pasParser::ID);
        break;
      }

      case pasParser::DIGIT: {
        enterOuterAlt(_localctx, 2);
        setState(429);
        num();
        break;
      }

      case pasParser::LETTER: {
        enterOuterAlt(_localctx, 3);
        setState(430);
        match(pasParser::LETTER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumContext ------------------------------------------------------------------

pasParser::NumContext::NumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<pasParser::DigitsContext *> pasParser::NumContext::digits() {
  return getRuleContexts<pasParser::DigitsContext>();
}

pasParser::DigitsContext* pasParser::NumContext::digits(size_t i) {
  return getRuleContext<pasParser::DigitsContext>(i);
}

tree::TerminalNode* pasParser::NumContext::SPOT() {
  return getToken(pasParser::SPOT, 0);
}

tree::TerminalNode* pasParser::NumContext::EXPONENT() {
  return getToken(pasParser::EXPONENT, 0);
}


size_t pasParser::NumContext::getRuleIndex() const {
  return pasParser::RuleNum;
}

void pasParser::NumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNum(this);
}

void pasParser::NumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNum(this);
}


antlrcpp::Any pasParser::NumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitNum(this);
  else
    return visitor->visitChildren(this);
}

pasParser::NumContext* pasParser::num() {
  NumContext *_localctx = _tracker.createInstance<NumContext>(_ctx, getState());
  enterRule(_localctx, 52, pasParser::RuleNum);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    digits();
    setState(437);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(434);
      match(pasParser::SPOT);
      setState(435);
      digits();
      break;
    }

    case 2: {
      break;
    }

    }
    setState(441);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      setState(439);
      match(pasParser::EXPONENT);
      break;
    }

    case 2: {
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyContext ------------------------------------------------------------------

pasParser::EmptyContext::EmptyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t pasParser::EmptyContext::getRuleIndex() const {
  return pasParser::RuleEmpty;
}

void pasParser::EmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmpty(this);
}

void pasParser::EmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmpty(this);
}


antlrcpp::Any pasParser::EmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitEmpty(this);
  else
    return visitor->visitChildren(this);
}

pasParser::EmptyContext* pasParser::empty() {
  EmptyContext *_localctx = _tracker.createInstance<EmptyContext>(_ctx, getState());
  enterRule(_localctx, 54, pasParser::RuleEmpty);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DigitsContext ------------------------------------------------------------------

pasParser::DigitsContext::DigitsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> pasParser::DigitsContext::DIGIT() {
  return getTokens(pasParser::DIGIT);
}

tree::TerminalNode* pasParser::DigitsContext::DIGIT(size_t i) {
  return getToken(pasParser::DIGIT, i);
}


size_t pasParser::DigitsContext::getRuleIndex() const {
  return pasParser::RuleDigits;
}

void pasParser::DigitsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDigits(this);
}

void pasParser::DigitsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDigits(this);
}


antlrcpp::Any pasParser::DigitsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitDigits(this);
  else
    return visitor->visitChildren(this);
}

pasParser::DigitsContext* pasParser::digits() {
  DigitsContext *_localctx = _tracker.createInstance<DigitsContext>(_ctx, getState());
  enterRule(_localctx, 56, pasParser::RuleDigits);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(446); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(445);
              match(pasParser::DIGIT);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(448); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulopContext ------------------------------------------------------------------

pasParser::MulopContext::MulopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::MulopContext::STAR() {
  return getToken(pasParser::STAR, 0);
}

tree::TerminalNode* pasParser::MulopContext::DIVIDE() {
  return getToken(pasParser::DIVIDE, 0);
}

tree::TerminalNode* pasParser::MulopContext::DIV() {
  return getToken(pasParser::DIV, 0);
}

tree::TerminalNode* pasParser::MulopContext::MOD() {
  return getToken(pasParser::MOD, 0);
}

tree::TerminalNode* pasParser::MulopContext::AND() {
  return getToken(pasParser::AND, 0);
}


size_t pasParser::MulopContext::getRuleIndex() const {
  return pasParser::RuleMulop;
}

void pasParser::MulopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulop(this);
}

void pasParser::MulopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulop(this);
}


antlrcpp::Any pasParser::MulopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitMulop(this);
  else
    return visitor->visitChildren(this);
}

pasParser::MulopContext* pasParser::mulop() {
  MulopContext *_localctx = _tracker.createInstance<MulopContext>(_ctx, getState());
  enterRule(_localctx, 58, pasParser::RuleMulop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(450);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pasParser::DIV)
      | (1ULL << pasParser::MOD)
      | (1ULL << pasParser::AND)
      | (1ULL << pasParser::STAR)
      | (1ULL << pasParser::DIVIDE))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddopContext ------------------------------------------------------------------

pasParser::AddopContext::AddopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::AddopContext::PLUS() {
  return getToken(pasParser::PLUS, 0);
}

tree::TerminalNode* pasParser::AddopContext::MINUS() {
  return getToken(pasParser::MINUS, 0);
}

tree::TerminalNode* pasParser::AddopContext::OR() {
  return getToken(pasParser::OR, 0);
}


size_t pasParser::AddopContext::getRuleIndex() const {
  return pasParser::RuleAddop;
}

void pasParser::AddopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddop(this);
}

void pasParser::AddopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddop(this);
}


antlrcpp::Any pasParser::AddopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitAddop(this);
  else
    return visitor->visitChildren(this);
}

pasParser::AddopContext* pasParser::addop() {
  AddopContext *_localctx = _tracker.createInstance<AddopContext>(_ctx, getState());
  enterRule(_localctx, 60, pasParser::RuleAddop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pasParser::OR)
      | (1ULL << pasParser::PLUS)
      | (1ULL << pasParser::MINUS))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelopContext ------------------------------------------------------------------

pasParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* pasParser::RelopContext::EQUAL() {
  return getToken(pasParser::EQUAL, 0);
}

tree::TerminalNode* pasParser::RelopContext::NOTEQUAL() {
  return getToken(pasParser::NOTEQUAL, 0);
}

tree::TerminalNode* pasParser::RelopContext::LESS() {
  return getToken(pasParser::LESS, 0);
}

tree::TerminalNode* pasParser::RelopContext::LESSEQUAL() {
  return getToken(pasParser::LESSEQUAL, 0);
}

tree::TerminalNode* pasParser::RelopContext::GREATE() {
  return getToken(pasParser::GREATE, 0);
}

tree::TerminalNode* pasParser::RelopContext::GREATEEQUAL() {
  return getToken(pasParser::GREATEEQUAL, 0);
}


size_t pasParser::RelopContext::getRuleIndex() const {
  return pasParser::RuleRelop;
}

void pasParser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void pasParser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<pasParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}


antlrcpp::Any pasParser::RelopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<pasParserVisitor*>(visitor))
    return parserVisitor->visitRelop(this);
  else
    return visitor->visitChildren(this);
}

pasParser::RelopContext* pasParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 62, pasParser::RuleRelop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << pasParser::EQUAL)
      | (1ULL << pasParser::NOTEQUAL)
      | (1ULL << pasParser::LESS)
      | (1ULL << pasParser::LESSEQUAL)
      | (1ULL << pasParser::GREATE)
      | (1ULL << pasParser::GREATEEQUAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool pasParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 22: return simple_expressionSempred(dynamic_cast<Simple_expressionContext *>(context), predicateIndex);
    case 23: return termSempred(dynamic_cast<TermContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool pasParser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool pasParser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> pasParser::_decisionToDFA;
atn::PredictionContextCache pasParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN pasParser::_atn;
std::vector<uint16_t> pasParser::_serializedATN;

std::vector<std::string> pasParser::_ruleNames = {
  "program", "program_head", "program_body", "subprogram_declaration", "para_de", 
  "type_de", "const_de", "var_de", "identifier", "type", "standrad_type", 
  "record_body", "period", "const_variable", "compound_statement", "statement_list", 
  "statement", "call_procedure_statement", "variable", "id_varpart", "expression_list", 
  "expression", "simple_expression", "term", "factor", "unsign_const_variable", 
  "num", "empty", "digits", "mulop", "addop", "relop"
};

std::vector<std::string> pasParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "':='", 
  "", "", "'['", "']'", "'('", "')'", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "'.'", "';'", "','", "'='", "'+'", "':'", "'-'", "", 
  "", "", "", "'*'", "'/'", "'<>'", "'<'", "'<='", "'>'", "'>='"
};

std::vector<std::string> pasParser::_symbolicNames = {
  "", "EXPONENT", "FUNCTION", "PROCEDURE", "NOT", "DIV", "MOD", "AND", "DOWNTO", 
  "TO", "UNTIL", "REPEAT", "FOR", "WHILE", "DO", "CASE", "ASSIGNOP", "IF", 
  "THEN", "LBRACK", "RBRACK", "LEFTPAREN", "RIGHTPAREN", "INTEGER", "REAL", 
  "BOOLEAN", "CHAR", "PROGRAM", "CONST", "TYPE", "RECORD", "BEGIN", "END", 
  "ARRAY", "OF", "OR", "VAR", "SPOT", "SEMICOLON", "COMMA", "EQUAL", "PLUS", 
  "COLON", "MINUS", "ELSE", "LETTER", "DIGIT", "ID", "STAR", "DIVIDE", "NOTEQUAL", 
  "LESS", "LESSEQUAL", "GREATE", "GREATEEQUAL", "WS", "COMMENT_1", "COMMENT_2"
};

dfa::Vocabulary pasParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> pasParser::_tokenNames;

pasParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x3b, 0x1cb, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x4d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x50, 
    0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x7, 0x4, 0x59, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x5c, 0xb, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x61, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x67, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x6a, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x6f, 0xa, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x75, 0xa, 0x4, 0xc, 
    0x4, 0xe, 0x4, 0x78, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x7d, 0xa, 0x4, 0x3, 0x4, 0x6, 0x4, 0x80, 0xa, 0x4, 0xd, 0x4, 0xe, 0x4, 
    0x81, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x87, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x91, 0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0x94, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x97, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x9c, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x7, 0x5, 0xa5, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xa8, 0xb, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xad, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0xb9, 0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0xbc, 0xa, 
    0x5, 0xc, 0x5, 0xe, 0x5, 0xbf, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0xc4, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x7, 0x5, 0xcb, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xce, 0xb, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xd3, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xd9, 0xa, 0x5, 0x3, 0x6, 0x5, 0x6, 0xdc, 
    0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0xe1, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0xe4, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xf4, 0xa, 0x9, 0xc, 0x9, 0xe, 
    0x9, 0xf7, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x108, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0x10b, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0x111, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 
    0xd, 0x118, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x11b, 0xb, 0xd, 0x3, 0xd, 
    0x5, 0xd, 0x11e, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x130, 0xa, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x7, 0x11, 0x139, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x13c, 0xb, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x14e, 0xa, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x15b, 
    0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x5, 0x13, 0x163, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 
    0x167, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x16a, 0xb, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x172, 
    0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x177, 0xa, 0x16, 
    0xc, 0x16, 0xe, 0x16, 0x17a, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x181, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x189, 0xa, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x18f, 0xa, 0x18, 
    0xc, 0x18, 0xe, 0x18, 0x192, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x19b, 0xa, 0x19, 
    0xc, 0x19, 0xe, 0x19, 0x19e, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x1ad, 0xa, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x1b2, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x1b8, 0xa, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x5, 0x1c, 0x1bc, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 
    0x6, 0x1e, 0x1c1, 0xa, 0x1e, 0xd, 0x1e, 0xe, 0x1e, 0x1c2, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x2, 
    0x4, 0x2e, 0x30, 0x22, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 
    0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x2, 
    0x6, 0x3, 0x2, 0x19, 0x1c, 0x4, 0x2, 0x7, 0x9, 0x32, 0x33, 0x5, 0x2, 
    0x25, 0x25, 0x2b, 0x2b, 0x2d, 0x2d, 0x4, 0x2, 0x2a, 0x2a, 0x34, 0x38, 
    0x2, 0x1e6, 0x2, 0x42, 0x3, 0x2, 0x2, 0x2, 0x4, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x60, 0x3, 0x2, 0x2, 0x2, 0x8, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0xdb, 0x3, 0x2, 0x2, 0x2, 0xc, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x12, 0xfb, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x110, 0x3, 0x2, 0x2, 0x2, 0x16, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x11f, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x131, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x135, 0x3, 0x2, 0x2, 0x2, 0x22, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x162, 0x3, 0x2, 0x2, 0x2, 0x26, 0x164, 0x3, 0x2, 0x2, 0x2, 0x28, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x173, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x180, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x188, 0x3, 0x2, 0x2, 0x2, 0x30, 0x193, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x34, 0x1b1, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x38, 0x1bd, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x1c6, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 
    0x5, 0x4, 0x3, 0x2, 0x43, 0x44, 0x5, 0x6, 0x4, 0x2, 0x44, 0x45, 0x7, 
    0x27, 0x2, 0x2, 0x45, 0x3, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x1d, 
    0x2, 0x2, 0x47, 0x48, 0x7, 0x31, 0x2, 0x2, 0x48, 0x49, 0x7, 0x17, 0x2, 
    0x2, 0x49, 0x4e, 0x7, 0x31, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x29, 0x2, 0x2, 
    0x4b, 0x4d, 0x7, 0x31, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x50, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x18, 0x2, 0x2, 0x52, 0x53, 0x7, 0x28, 
    0x2, 0x2, 0x53, 0x5, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 0x1e, 0x2, 
    0x2, 0x55, 0x5a, 0x5, 0xe, 0x8, 0x2, 0x56, 0x57, 0x7, 0x28, 0x2, 0x2, 
    0x57, 0x59, 0x5, 0xe, 0x8, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x59, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x28, 0x2, 0x2, 0x5e, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x5f, 0x61, 0x3, 0x2, 0x2, 0x2, 0x60, 0x54, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0x62, 0x63, 0x7, 0x1f, 0x2, 0x2, 0x63, 0x68, 0x5, 0xc, 0x7, 0x2, 0x64, 
    0x65, 0x7, 0x28, 0x2, 0x2, 0x65, 0x67, 0x5, 0xc, 0x7, 0x2, 0x66, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x28, 0x2, 
    0x2, 0x6c, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x62, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0x26, 0x2, 0x2, 0x71, 0x76, 
    0x5, 0x10, 0x9, 0x2, 0x72, 0x73, 0x7, 0x28, 0x2, 0x2, 0x73, 0x75, 0x5, 
    0x10, 0x9, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 0x78, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x79, 0x3, 0x2, 0x2, 0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 
    0x79, 0x7a, 0x7, 0x28, 0x2, 0x2, 0x7a, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x70, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0x7d, 0x86, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x80, 0x5, 
    0x8, 0x5, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x7, 0x28, 0x2, 0x2, 
    0x84, 0x87, 0x3, 0x2, 0x2, 0x2, 0x85, 0x87, 0x3, 0x2, 0x2, 0x2, 0x86, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x86, 0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x5, 0x1e, 0x10, 0x2, 0x89, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x4, 0x2, 0x2, 0x8b, 0x9b, 0x7, 0x31, 
    0x2, 0x2, 0x8c, 0x8d, 0x7, 0x17, 0x2, 0x2, 0x8d, 0x95, 0x5, 0xa, 0x6, 
    0x2, 0x8e, 0x90, 0x7, 0x28, 0x2, 0x2, 0x8f, 0x91, 0x7, 0x26, 0x2, 0x2, 
    0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x94, 0x5, 0xa, 0x6, 0x2, 0x93, 0x8e, 
    0x3, 0x2, 0x2, 0x2, 0x94, 0x97, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 
    0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0x18, 0x2, 
    0x2, 0x99, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9c, 0x3, 0x2, 0x2, 0x2, 
    0x9b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x2c, 0x2, 0x2, 0x9e, 0x9f, 
    0x5, 0x16, 0xc, 0x2, 0x9f, 0xac, 0x7, 0x28, 0x2, 0x2, 0xa0, 0xa1, 0x7, 
    0x26, 0x2, 0x2, 0xa1, 0xa6, 0x5, 0x10, 0x9, 0x2, 0xa2, 0xa3, 0x7, 0x28, 
    0x2, 0x2, 0xa3, 0xa5, 0x5, 0x10, 0x9, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0xa6, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x28, 0x2, 0x2, 0xaa, 0xad, 
    0x3, 0x2, 0x2, 0x2, 0xab, 0xad, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa0, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xaf, 0x7, 0x21, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x20, 0x11, 
    0x2, 0xb0, 0xb1, 0x7, 0x22, 0x2, 0x2, 0xb1, 0xd9, 0x3, 0x2, 0x2, 0x2, 
    0xb2, 0xb3, 0x7, 0x5, 0x2, 0x2, 0xb3, 0xc3, 0x7, 0x31, 0x2, 0x2, 0xb4, 
    0xb5, 0x7, 0x17, 0x2, 0x2, 0xb5, 0xbd, 0x5, 0xa, 0x6, 0x2, 0xb6, 0xb8, 
    0x7, 0x28, 0x2, 0x2, 0xb7, 0xb9, 0x7, 0x26, 0x2, 0x2, 0xb8, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0xbc, 0x5, 0xa, 0x6, 0x2, 0xbb, 0xb6, 0x3, 0x2, 0x2, 
    0x2, 0xbc, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 
    0xbd, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0x18, 0x2, 0x2, 0xc1, 0xc4, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0xc3, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 
    0x2, 0x2, 0xc5, 0xd2, 0x7, 0x28, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x26, 0x2, 
    0x2, 0xc7, 0xcc, 0x5, 0x10, 0x9, 0x2, 0xc8, 0xc9, 0x7, 0x28, 0x2, 0x2, 
    0xc9, 0xcb, 0x5, 0x10, 0x9, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xcb, 
    0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 
    0x3, 0x2, 0x2, 0x2, 0xcd, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 
    0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x28, 0x2, 0x2, 0xd0, 0xd3, 0x3, 0x2, 
    0x2, 0x2, 0xd1, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xc6, 0x3, 0x2, 0x2, 
    0x2, 0xd2, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 
    0xd4, 0xd5, 0x7, 0x21, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x20, 0x11, 0x2, 0xd6, 
    0xd7, 0x7, 0x22, 0x2, 0x2, 0xd7, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0xd8, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xd9, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0xda, 0xdc, 0x7, 0x26, 0x2, 0x2, 0xdb, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 
    0x2, 0xdd, 0xe2, 0x7, 0x31, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x29, 0x2, 0x2, 
    0xdf, 0xe1, 0x7, 0x31, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe1, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe2, 0x3, 
    0x2, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x2c, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x16, 
    0xc, 0x2, 0xe7, 0xb, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x7, 0x31, 0x2, 
    0x2, 0xe9, 0xea, 0x7, 0x2a, 0x2, 0x2, 0xea, 0xeb, 0x5, 0x14, 0xb, 0x2, 
    0xeb, 0xd, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 0x31, 0x2, 0x2, 0xed, 
    0xee, 0x7, 0x2a, 0x2, 0x2, 0xee, 0xef, 0x5, 0x1c, 0xf, 0x2, 0xef, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0xf0, 0xf5, 0x5, 0x12, 0xa, 0x2, 0xf1, 0xf2, 0x7, 
    0x29, 0x2, 0x2, 0xf2, 0xf4, 0x5, 0x12, 0xa, 0x2, 0xf3, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0xf4, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 
    0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 0x3, 0x2, 0x2, 0x2, 
    0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x2c, 0x2, 0x2, 0xf9, 
    0xfa, 0x5, 0x14, 0xb, 0x2, 0xfa, 0x11, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 
    0x7, 0x31, 0x2, 0x2, 0xfc, 0x13, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x111, 0x5, 
    0x16, 0xc, 0x2, 0xfe, 0xff, 0x7, 0x20, 0x2, 0x2, 0xff, 0x100, 0x5, 0x18, 
    0xd, 0x2, 0x100, 0x101, 0x7, 0x22, 0x2, 0x2, 0x101, 0x111, 0x3, 0x2, 
    0x2, 0x2, 0x102, 0x103, 0x7, 0x23, 0x2, 0x2, 0x103, 0x104, 0x7, 0x15, 
    0x2, 0x2, 0x104, 0x109, 0x5, 0x1a, 0xe, 0x2, 0x105, 0x106, 0x7, 0x29, 
    0x2, 0x2, 0x106, 0x108, 0x5, 0x1a, 0xe, 0x2, 0x107, 0x105, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 
    0x2, 0x2, 0x109, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10c, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x7, 0x16, 
    0x2, 0x2, 0x10d, 0x10e, 0x7, 0x24, 0x2, 0x2, 0x10e, 0x10f, 0x5, 0x14, 
    0xb, 0x2, 0x10f, 0x111, 0x3, 0x2, 0x2, 0x2, 0x110, 0xfd, 0x3, 0x2, 0x2, 
    0x2, 0x110, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x110, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0x111, 0x15, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x9, 0x2, 0x2, 0x2, 0x113, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x114, 0x119, 0x5, 0x10, 0x9, 0x2, 0x115, 
    0x116, 0x7, 0x28, 0x2, 0x2, 0x116, 0x118, 0x5, 0x10, 0x9, 0x2, 0x117, 
    0x115, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x119, 
    0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11a, 
    0x11e, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11c, 
    0x11e, 0x5, 0x38, 0x1d, 0x2, 0x11d, 0x114, 0x3, 0x2, 0x2, 0x2, 0x11d, 
    0x11c, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x19, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 
    0x5, 0x1c, 0xf, 0x2, 0x120, 0x121, 0x7, 0x27, 0x2, 0x2, 0x121, 0x122, 
    0x7, 0x27, 0x2, 0x2, 0x122, 0x123, 0x5, 0x1c, 0xf, 0x2, 0x123, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x7, 0x2b, 0x2, 0x2, 0x125, 0x130, 
    0x7, 0x31, 0x2, 0x2, 0x126, 0x127, 0x7, 0x2d, 0x2, 0x2, 0x127, 0x130, 
    0x7, 0x31, 0x2, 0x2, 0x128, 0x130, 0x7, 0x31, 0x2, 0x2, 0x129, 0x12a, 
    0x7, 0x2b, 0x2, 0x2, 0x12a, 0x130, 0x5, 0x36, 0x1c, 0x2, 0x12b, 0x12c, 
    0x7, 0x2d, 0x2, 0x2, 0x12c, 0x130, 0x5, 0x36, 0x1c, 0x2, 0x12d, 0x130, 
    0x5, 0x36, 0x1c, 0x2, 0x12e, 0x130, 0x7, 0x2f, 0x2, 0x2, 0x12f, 0x124, 
    0x3, 0x2, 0x2, 0x2, 0x12f, 0x126, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x128, 
    0x3, 0x2, 0x2, 0x2, 0x12f, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12b, 
    0x3, 0x2, 0x2, 0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12e, 
    0x3, 0x2, 0x2, 0x2, 0x130, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x7, 
    0x21, 0x2, 0x2, 0x132, 0x133, 0x5, 0x20, 0x11, 0x2, 0x133, 0x134, 0x7, 
    0x22, 0x2, 0x2, 0x134, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x135, 0x13a, 0x5, 
    0x22, 0x12, 0x2, 0x136, 0x137, 0x7, 0x28, 0x2, 0x2, 0x137, 0x139, 0x5, 
    0x22, 0x12, 0x2, 0x138, 0x136, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13c, 0x3, 
    0x2, 0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x3, 
    0x2, 0x2, 0x2, 0x13b, 0x21, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 
    0x2, 0x2, 0x13d, 0x13e, 0x5, 0x26, 0x14, 0x2, 0x13e, 0x13f, 0x7, 0x12, 
    0x2, 0x2, 0x13f, 0x140, 0x5, 0x2c, 0x17, 0x2, 0x140, 0x15b, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x142, 0x7, 0x21, 0x2, 0x2, 0x142, 0x143, 0x5, 0x20, 
    0x11, 0x2, 0x143, 0x144, 0x7, 0x22, 0x2, 0x2, 0x144, 0x15b, 0x3, 0x2, 
    0x2, 0x2, 0x145, 0x15b, 0x5, 0x24, 0x13, 0x2, 0x146, 0x147, 0x7, 0x13, 
    0x2, 0x2, 0x147, 0x148, 0x5, 0x2c, 0x17, 0x2, 0x148, 0x149, 0x7, 0x14, 
    0x2, 0x2, 0x149, 0x14d, 0x5, 0x22, 0x12, 0x2, 0x14a, 0x14b, 0x7, 0x2e, 
    0x2, 0x2, 0x14b, 0x14e, 0x5, 0x22, 0x12, 0x2, 0x14c, 0x14e, 0x3, 0x2, 
    0x2, 0x2, 0x14d, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14c, 0x3, 0x2, 
    0x2, 0x2, 0x14e, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x7, 0xf, 
    0x2, 0x2, 0x150, 0x151, 0x5, 0x2c, 0x17, 0x2, 0x151, 0x152, 0x7, 0x10, 
    0x2, 0x2, 0x152, 0x153, 0x5, 0x22, 0x12, 0x2, 0x153, 0x15b, 0x3, 0x2, 
    0x2, 0x2, 0x154, 0x155, 0x7, 0xd, 0x2, 0x2, 0x155, 0x156, 0x5, 0x20, 
    0x11, 0x2, 0x156, 0x157, 0x7, 0xc, 0x2, 0x2, 0x157, 0x158, 0x5, 0x2c, 
    0x17, 0x2, 0x158, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15b, 0x5, 0x38, 
    0x1d, 0x2, 0x15a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x141, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x145, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x146, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x154, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x15c, 0x163, 0x7, 0x31, 0x2, 0x2, 0x15d, 0x15e, 0x7, 0x31, 0x2, 
    0x2, 0x15e, 0x15f, 0x7, 0x17, 0x2, 0x2, 0x15f, 0x160, 0x5, 0x2a, 0x16, 
    0x2, 0x160, 0x161, 0x7, 0x18, 0x2, 0x2, 0x161, 0x163, 0x3, 0x2, 0x2, 
    0x2, 0x162, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x162, 0x15d, 0x3, 0x2, 0x2, 
    0x2, 0x163, 0x25, 0x3, 0x2, 0x2, 0x2, 0x164, 0x168, 0x7, 0x31, 0x2, 
    0x2, 0x165, 0x167, 0x5, 0x28, 0x15, 0x2, 0x166, 0x165, 0x3, 0x2, 0x2, 
    0x2, 0x167, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x168, 0x166, 0x3, 0x2, 0x2, 
    0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x16a, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x7, 0x15, 0x2, 0x2, 
    0x16c, 0x16d, 0x5, 0x2a, 0x16, 0x2, 0x16d, 0x16e, 0x7, 0x16, 0x2, 0x2, 
    0x16e, 0x172, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 0x7, 0x27, 0x2, 0x2, 
    0x170, 0x172, 0x7, 0x31, 0x2, 0x2, 0x171, 0x16b, 0x3, 0x2, 0x2, 0x2, 
    0x171, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x172, 0x29, 0x3, 0x2, 0x2, 0x2, 0x173, 
    0x178, 0x5, 0x2c, 0x17, 0x2, 0x174, 0x175, 0x7, 0x29, 0x2, 0x2, 0x175, 
    0x177, 0x5, 0x2c, 0x17, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x177, 
    0x17a, 0x3, 0x2, 0x2, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x178, 
    0x179, 0x3, 0x2, 0x2, 0x2, 0x179, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x178, 
    0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 0x5, 0x2e, 0x18, 0x2, 0x17c, 0x17d, 
    0x5, 0x40, 0x21, 0x2, 0x17d, 0x17e, 0x5, 0x2e, 0x18, 0x2, 0x17e, 0x181, 
    0x3, 0x2, 0x2, 0x2, 0x17f, 0x181, 0x5, 0x2e, 0x18, 0x2, 0x180, 0x17b, 
    0x3, 0x2, 0x2, 0x2, 0x180, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x181, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x182, 0x183, 0x8, 0x18, 0x1, 0x2, 0x183, 0x189, 0x5, 
    0x30, 0x19, 0x2, 0x184, 0x185, 0x7, 0x2b, 0x2, 0x2, 0x185, 0x189, 0x5, 
    0x30, 0x19, 0x2, 0x186, 0x187, 0x7, 0x2d, 0x2, 0x2, 0x187, 0x189, 0x5, 
    0x30, 0x19, 0x2, 0x188, 0x182, 0x3, 0x2, 0x2, 0x2, 0x188, 0x184, 0x3, 
    0x2, 0x2, 0x2, 0x188, 0x186, 0x3, 0x2, 0x2, 0x2, 0x189, 0x190, 0x3, 
    0x2, 0x2, 0x2, 0x18a, 0x18b, 0xc, 0x3, 0x2, 0x2, 0x18b, 0x18c, 0x5, 
    0x3e, 0x20, 0x2, 0x18c, 0x18d, 0x5, 0x30, 0x19, 0x2, 0x18d, 0x18f, 0x3, 
    0x2, 0x2, 0x2, 0x18e, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x192, 0x3, 
    0x2, 0x2, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x3, 
    0x2, 0x2, 0x2, 0x191, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 
    0x2, 0x2, 0x193, 0x194, 0x8, 0x19, 0x1, 0x2, 0x194, 0x195, 0x5, 0x32, 
    0x1a, 0x2, 0x195, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0xc, 0x4, 
    0x2, 0x2, 0x197, 0x198, 0x5, 0x3c, 0x1f, 0x2, 0x198, 0x199, 0x5, 0x32, 
    0x1a, 0x2, 0x199, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x196, 0x3, 0x2, 
    0x2, 0x2, 0x19b, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19a, 0x3, 0x2, 
    0x2, 0x2, 0x19c, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x19e, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1ad, 0x5, 0x34, 0x1b, 
    0x2, 0x1a0, 0x1ad, 0x5, 0x26, 0x14, 0x2, 0x1a1, 0x1a2, 0x7, 0x31, 0x2, 
    0x2, 0x1a2, 0x1a3, 0x7, 0x17, 0x2, 0x2, 0x1a3, 0x1a4, 0x5, 0x2a, 0x16, 
    0x2, 0x1a4, 0x1a5, 0x7, 0x18, 0x2, 0x2, 0x1a5, 0x1ad, 0x3, 0x2, 0x2, 
    0x2, 0x1a6, 0x1a7, 0x7, 0x17, 0x2, 0x2, 0x1a7, 0x1a8, 0x5, 0x2c, 0x17, 
    0x2, 0x1a8, 0x1a9, 0x7, 0x18, 0x2, 0x2, 0x1a9, 0x1ad, 0x3, 0x2, 0x2, 
    0x2, 0x1aa, 0x1ab, 0x7, 0x6, 0x2, 0x2, 0x1ab, 0x1ad, 0x5, 0x32, 0x1a, 
    0x2, 0x1ac, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1a0, 0x3, 0x2, 0x2, 
    0x2, 0x1ac, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1a6, 0x3, 0x2, 0x2, 
    0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0x1ae, 0x1b2, 0x7, 0x31, 0x2, 0x2, 0x1af, 0x1b2, 0x5, 0x36, 0x1c, 0x2, 
    0x1b0, 0x1b2, 0x7, 0x2f, 0x2, 0x2, 0x1b1, 0x1ae, 0x3, 0x2, 0x2, 0x2, 
    0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b0, 0x3, 0x2, 0x2, 0x2, 
    0x1b2, 0x35, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b7, 0x5, 0x3a, 0x1e, 0x2, 
    0x1b4, 0x1b5, 0x7, 0x27, 0x2, 0x2, 0x1b5, 0x1b8, 0x5, 0x3a, 0x1e, 0x2, 
    0x1b6, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b4, 0x3, 0x2, 0x2, 0x2, 
    0x1b7, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1bb, 0x3, 0x2, 0x2, 0x2, 
    0x1b9, 0x1bc, 0x7, 0x3, 0x2, 0x2, 0x1ba, 0x1bc, 0x3, 0x2, 0x2, 0x2, 
    0x1bb, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1ba, 0x3, 0x2, 0x2, 0x2, 
    0x1bc, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1be, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c1, 0x7, 0x30, 0x2, 0x2, 0x1c0, 
    0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c2, 
    0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x9, 0x3, 0x2, 0x2, 0x1c5, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x9, 0x4, 0x2, 0x2, 0x1c7, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x9, 0x5, 0x2, 0x2, 0x1c9, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x2e, 0x4e, 0x5a, 0x60, 0x68, 0x6e, 0x76, 0x7c, 0x81, 0x86, 
    0x90, 0x95, 0x9b, 0xa6, 0xac, 0xb8, 0xbd, 0xc3, 0xcc, 0xd2, 0xd8, 0xdb, 
    0xe2, 0xf5, 0x109, 0x110, 0x119, 0x11d, 0x12f, 0x13a, 0x14d, 0x15a, 
    0x162, 0x168, 0x171, 0x178, 0x180, 0x188, 0x190, 0x19c, 0x1ac, 0x1b1, 
    0x1b7, 0x1bb, 0x1c2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

pasParser::Initializer pasParser::_init;
