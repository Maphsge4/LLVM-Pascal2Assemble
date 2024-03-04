
#ifndef _PAS_ERROR_LISTENER_H_
#define _PAS_ERROR_LISTENER_H_

#include <BaseErrorListener.h>
#include <pasrecognizer/error_reporter.h>

namespace pas_recognizer
{

class error_listener : public antlr4::BaseErrorListener
{
  public:
    error_listener(error_reporter &_err);

    virtual void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                             size_t charPositionInLine, const std::string &msg, std::exception_ptr e) override;

    int get_errors_count();

  private:
    error_reporter &err;
    int count;
};
}

#endif
