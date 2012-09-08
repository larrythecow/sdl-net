#include "Net.h"
#include "Ip.h"

Ip::Ip() {
}

Ip::~Ip() {
}

IPaddress *Ip::getip() {
    return &ip;
}

int Ip::resolvehost(IPaddress * ip, const char * host, Uint16 port) {
    if (((SDLNet_ResolveHost(ip, host, port)) == -1)) {
        printf("resolvehost\t\tfailed\n");
    }
    printf("resolvehost\t\tOK\t%x:%x\n", (Uint32)this->ip.host, (Uint16)this->ip.port);
    return 0;
}

int Ip::resolvehost(const char * host, Uint16 port) {
    return Ip::resolvehost(&ip, host, port);
}

const char * Ip::resolveIP(IPaddress *ip) {
    if (!(host = SDLNet_ResolveIP(ip))) {
        printf("resolveIP:\t\tfailed\t%s\n", SDLNet_GetError());
    }
    printf("resolveIP:\t\tOK\t%s\t%x:%x\n", host, (Uint32) this->ip.host, (Uint16) this->ip.port);
    return host;
}

const char * Ip::resolveIP() {
    return resolveIP(&ip);
}























