#include "Logger.h"

Logger::Logger(std::ostream& os) : m_os(os) {}


void Logger::addLog(const LogLine& msg) {
    m_messages.push_back(&msg);
}

void Logger::writeLogs() {
    for (const auto& msg : m_messages) {
//        m_os << *msg << '\n';
        m_os << *msg;
//        delete msg;
    }
    m_messages.clear();
}