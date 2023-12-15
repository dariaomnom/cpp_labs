#include "LogLine.hpp"

std::ostream& operator<<(std::ostream& out, const LogLine& log) {
    log.print(out);
    return out;
}