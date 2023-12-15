#include "Logger.h"

Logger::Logger(std::ostream& out_line) : out_line(out_line) {}

void Logger::addLog(const LogLine& line) {
    lines.push_back(&line);
}

void Logger::writeLogs() {
    for (const auto& line : lines) {
        out_line << *line;
    }
    lines.clear();
}