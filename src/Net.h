#ifndef _NET_H_
#define _NET_H_

#include <iostream>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_net.h>
#include "Ip.h"

#define DIMBUFFER 1024
#define DIMCLIENT 16

class Net {
private:
    bool running;
    bool type; // 0=client; 1=server

    TCPsocket socket;
    TCPsocket socketPeer;
    //    TCPsocket socketClient;
    SDLNet_SocketSet socketsetClient;
    Ip ipPeer;

    char buffer[DIMBUFFER];
    int clientCount;

public:
    Net();
    ~Net();

    bool init();
    int clientExecute();
    int serverExecute();
    void cleanup();
    void logic();

    TCPsocket tcpOpen();
    TCPsocket tcpOpen(IPaddress *);
    int tcpSend();
    int tcpSend(TCPsocket socket, const void *);
    int tcpSend(TCPsocket socket, const void *, int len);
    IPaddress * tcpGetPeerAddress();
    IPaddress * tcpGetPeerAddress(TCPsocket socket);

    TCPsocket tcpAccept(TCPsocket);    TCPsocket tcpAccept();
};

#endif