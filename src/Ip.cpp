#include "Net.h"
#include "Ip.h"

Ip::Ip() {
}

Ip::~Ip() {
}

IPaddress *Ip::getip(){
    return &ip;
}

int Ip::resolvehost(const char * host, Uint16 port) {
    if (((SDLNet_ResolveHost(&ip, host, port)) == -1)) {
        printf("resolvehost\t\tfailed\n");
    }
    printf("resolvehost\t\tOK\t%x:%x\n", (Uint32)ip.host, (Uint16)ip.port);
    return 0;
}

const char * Ip::resolveIP() {
    if (!(host = SDLNet_ResolveIP(&ip))) {
        printf("resolveIP:\t\tfailed\t%s\n", SDLNet_GetError());
    }
    printf("resolveIP:\t\tOK\t%s\t%x:%x\n", host, (Uint32)ip.host, (Uint16)ip.port);
    return host;
}

