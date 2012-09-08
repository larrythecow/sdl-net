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
    const char * getip(IPaddress *);

    int resolvehost(IPaddress * ip, const char * host, Uint16 port);
    int resolvehost(const char * host, Uint16 port);
    const char * resolveIP();
    const char * resolveIP(IPaddress *ip);

};

#endif