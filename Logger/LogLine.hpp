#include <ostream>
#ifndef LABS_LOGGER_HPP
#define LABS_LOGGER_HPP

class LogLine {
public:
    virtual ~LogLine() = default;
    virtual void/*std::ostream&*/ print(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& out, const LogLine& log);
};

//std::ostream& operator<<(std::ostream& out, const Logger& log);

#endif //LABS_LOGGER_HPP
