#include "Net.h"

TCPsocket Net::tcpOpen() {
    return tcpOpen(ipPeer.getip());
}

TCPsocket Net::tcpOpen(IPaddress * ip) {
    if (((socket = SDLNet_TCP_Open(ip)) == NULL)) {
        printf("tcpOpen:\t\tfail\t%s\n", SDLNet_GetError());
        exit(-1);
    }
    printf("tcpOpen:\t\tOK\t\n");
    return socket;
}

int Net::tcpSend() {
    return tcpSend(socket, buffer);
}

int Net::tcpSend(TCPsocket socket, const void *buffer) {
    return tcpSend(socket, buffer, (strlen((const char *) buffer) + 1));
}

int Net::tcpSend(TCPsocket socket, const void * buffer, int len) {
    int res;
    if ((res = SDLNet_TCP_Send(socket, buffer, len)) < len) {
        printf("tcpSend:\t\tfail\t%s\n", SDLNet_GetError());
    } else {
        //printf("tcpSend:\t\tOK\t%s\n", (char *)buffer);
    }
    return res;
}

IPaddress * Net::tcpGetPeerAddress() {
    return tcpGetPeerAddress(socketPeer);
}

IPaddress * Net::tcpGetPeerAddress(TCPsocket socket) {
    IPaddress *ip;

    if (((ip = SDLNet_TCP_GetPeerAddress(socket)) == NULL)) {
        printf("tcpGetPeerAddress:\tfailed\t%s\n", SDLNet_GetError());
    } else {

        printf("tcpGetPeerAddress:\tOK\t%x:%x\n", (Uint32) ip->host, (Uint16) ip->port);
    }
    return ip;
}

TCPsocket Net::tcpAccept() {

    return tcpAccept(socket);
}

TCPsocket Net::tcpAccept(TCPsocket socket) {
    socketPeer = SDLNet_TCP_Accept(socket);
    if (!socketPeer) {
        //printf("tcpAccept:\t\tfailed\t%s\n", SDLNet_GetError());
        return NULL;
    }
    printf("tcpAccept:\t\tOK\n");
    return socketPeer;
}

SDLNet_SocketSet Net::allocSocketSet() {
    return allocSocketSet(DIMCLIENT);
}

SDLNet_SocketSet Net::allocSocketSet(int maxSockets) {
    SDLNet_SocketSet socketSet;
    if (!(socketSet = SDLNet_AllocSocketSet(maxSockets))) {
        printf("SDLNet_AllocSocketSet: %s\n", SDLNet_GetError());
        exit(1);
    } else {
        fprintf(stdout, "SDLNet_AllocSocketSet:\tOK %d\n", DIMCLIENT);
    }
    return socketSet;
}

int Net::addSocket() {
    addSocket(socketSetClient, socket);
    return addSocket(socketSetClient, socketPeer);
}

int Net::addSocket(SDLNet_SocketSet set, TCPsocket sock) {
    if ((clientCount = SDLNet_TCP_AddSocket(set, sock)) == -1) {
        printf("SDLNet_TCP_AddSocket:\t\tailed\t%s\n", SDLNet_GetError());
    }
    fprintf(stdout, "SDLNet_TCP_AddSocket:\t\tOK\t%d\n", clientCount);
    return clientCount;
}

int Net::checkSockets(Uint32 timeout) {
     return checkSockets(socketSetClient, timeout);
}

int Net::checkSockets(SDLNet_SocketSet set, Uint32 timeout) {
    int ret;

    if (((ret = SDLNet_CheckSockets(set, 1000)) == -1)) {
        printf("SDLNet_CheckSockets:\t\tfailed\t%s\n", SDLNet_GetError());
    } else {
        printf("There are %d sockets with activity!\n", ret);
    }
    return ret;
}