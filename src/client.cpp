#include "Net.h"

Net::Net() {
    running = true;
    type = 0;
    init();
}

Net::~Net() {
}

int Net::clientExecute() {
    int i = 0;
    printf("init done!\n");


    ipPeer.resolvehost("localhost", 9999);
    tcpOpen();
    ipPeer.resolveIP();
    tcpGetPeerAddress(socket);

    printf("main loop\n");
    while (running) {
        snprintf(buffer, DIMBUFFER, "%s %d\n", "client", i);
        tcpSend();
        printf("send:\t%s", buffer);
        if ((SDLNet_TCP_Recv(socket, buffer, DIMBUFFER) > 0)) {
            fprintf(stdout, "reci:\t%s", buffer);
            //snprintf(buffer, DIMBUFFER, "answer %d\n", i);
            //tcpSend(socketPeer, buffer);
            //fprintf(stdout, "send: %s", buffer);

        }
        i++;
        SDL_Delay(1000);
    }



    printf("\n\ncleanexit\n\n");
    return 0;
}

int main(int argc, char* argv[]) {
    Net client;
    return client.clientExecute();
}
