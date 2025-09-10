#ifndef IGAMEIO_H
#define IGAMEIO_H
#include <string>

class IGameIO {
public:
    virtual ~IGameIO() = default;
    virtual void print(const std::string& msg) = 0;
    virtual void println(const std::string& msg) = 0;
    virtual void readInt(int& value) = 0;
};
#endif
