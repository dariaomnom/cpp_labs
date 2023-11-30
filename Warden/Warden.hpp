#ifndef WARDEN_HPP
#define WARDEN_HPP

class Warden {
public:
    virtual bool updateInfo() = 0;
    virtual ~Warden() = default;
};

#endif
