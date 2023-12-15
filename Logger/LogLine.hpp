#include <ostream>
#ifndef LABS_LOGLINE_HPP
#define LABS_LOGLINE_HPP

class LogLine {
public:
    virtual void print(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& out, const LogLine& log);
    virtual ~LogLine() = default;
};

#endif //LABS_LOGLINE_HPP
