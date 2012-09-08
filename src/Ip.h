#ifndef _IP_H_
#define _IP_H_
#include "Net.h"

class Ip {
private:
    IPaddress ip;
    int a, b, c, d;
    int port;
    const char * host;

public:
    Ip();
    ~Ip();

    IPaddress * getip();
    int resolvehost(const char *, Uint16);
    const char * resolveIP();

};

#endif