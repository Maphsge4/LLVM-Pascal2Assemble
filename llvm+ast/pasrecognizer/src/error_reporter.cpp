// 与error_listener.cpp合作进行报错和监控
#include <pasrecognizer/error_reporter.h>

using namespace pas_recognizer;

error_reporter::error_reporter(std::ostream &error_stream) : err(error_stream) {}

void error_reporter::error(size_t line, size_t charPositionInLine, const std::string &msg)
{
    report(line, charPositionInLine, msg, "Error");
}

void error_reporter::warn(size_t line, size_t charPositionInLine, const std::string &msg)
{
    report(line, charPositionInLine, msg, "Warning");
}

void error_reporter::report(size_t line, size_t charPositionInLine, const std::string &msg, const std::string &prefix)
{
    err << prefix << " at position " << line << ":" << charPositionInLine << " " << msg << std::endl;
}
