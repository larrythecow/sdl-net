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
    }
    return res;
}

IPaddress * Net::tcpGetPeerAddress() {
    //ip = tcpGetPeerAddress(socketPeer);
    return tcpGetPeerAddress(socketPeer);
}

IPaddress * Net::tcpGetPeerAddress(TCPsocket socket) {
    IPaddress *ip;

    if (((ip = SDLNet_TCP_GetPeerAddress(socket)) == NULL)) {
        printf("tcpGetPeerAddress:\tfailed\t%s\n", SDLNet_GetError());
    } else {

        printf("tcpGetPeerAddress:\tOK\t\tOK\t%x:%x\n", (Uint32) ip->host, (Uint16) ip->port);
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