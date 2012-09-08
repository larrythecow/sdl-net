#include "Net.h"

void Net::tcpOpen() {
    if (((socket = SDLNet_TCP_Open(ipPeer.getip())) == NULL)) {
        printf("tcpOpen:\t\tfail\t%s\n", SDLNet_GetError());
        exit(-1);
    }
    printf("tcpOpen:\t\tOK\t\n");
}

void Net::tcpSend() {
    int len, result;

    len = strlen(buffer) + 1; // add one for the terminating NULL
    result = SDLNet_TCP_Send(socket, buffer, len);
    if (result < len) {
        printf("tcpSend:\t\tfail\t%s\n", SDLNet_GetError());
    }
}

void Net::tcpGetPeerAddress() {
    IPaddress *remote_ip;

    remote_ip = SDLNet_TCP_GetPeerAddress(socket);
    if (!remote_ip) {
        printf("tcpGetPeerAddress:\tfailed\t%s\n", SDLNet_GetError());
    } else {
        printf("tcpGetPeerAddress:\tOK\n");
    }
}

int Net::tcpAccept() {
//    TCPsocket new_tcpsock;

    socketPeer = SDLNet_TCP_Accept(socket);
    if (!socketPeer) {
        //printf("tcpAccept:\t\tfailed\t%s\n", SDLNet_GetError());
        return 0;
    }
    printf("tcpAccept:\t\tOK\n");
    return 1;
}