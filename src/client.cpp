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
    int quit = 0;
    printf("init done!\n");


    ipPeer.resolvehost("localhost", 9999);
    tcpOpen();
    ipPeer.resolveIP();
    while (1) {

        SDL_Delay(1000);
        i++;
    }

    printf("main loop\n");
    while (running) {


        if (tcpAccept()) {
            snprintf(buffer, DIMBUFFER, "%s %d\n", "hello world", i);
            tcpSend();
            tcpGetPeerAddress();
            quit = 0;
//            while (!quit) {
//                if ((SDLNet_TCP_Recv(socketPeer, buffer, DIMBUFFER) > 0)) {
//                    fprintf(stdout, "reci: %s\n", buffer);
//                    snprintf(buffer, DIMBUFFER, "answer %d\n", i);
//                    tcpSend(socketPeer, buffer);
//                }
//                i++;
//            }
        }
        SDL_Delay(1000);
    }



    printf("\n\ncleanexit\n\n");
    return 0;
}

int main(int argc, char* argv[]) {
    Net client;
    return client.clientExecute();
}
