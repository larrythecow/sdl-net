#include "Net.h"

Net::Net() {
    running = true;
    type = 1;
    init();
}

Net::~Net() {
}

int Net::serverExecute() {
    int i=0;
    printf("init done!\n");
    int quit = 0;

    ipPeer.resolvehost("NULL", 9999);
    tcpOpen();
    ipPeer.resolveIP();

    printf("main loop\n");
    while (running) {
        if (tcpAccept()) {
            tcpGetPeerAddress();
            fprintf(stdout, "client connected:\n");
            quit = 0;
            while (!quit) {
                if ((SDLNet_TCP_Recv(socketPeer, buffer, DIMBUFFER) > 0)) {
                    fprintf(stdout, "reci:\t%s", buffer);
                    snprintf(buffer, DIMBUFFER, "server123\t%d\n", i);
                    tcpSend(socketPeer, buffer);
                    fprintf(stdout, "send:\t%s", buffer);
                }
                //                if ((strcmp(buffer, "exit") == 0)) {
                //                    fprintf(stdout, "session terminated\n");
                //                    quit2 = 1;
                //                }
                //                if ((strcmp(buffer, "quit") == 0)) {
                //                    fprintf(stdout, "programm terminated\n");
                //                    quit2 = 1;
                //                    quit = 1;
                //                }
                //                SDL_Delay(100);
                i++;
            }
        }
        SDL_Delay(100);
    }
    //    SDLNet_TCP_Close(socketClient);

    cleanup();
    return 0;
}

int main(int argc, char* argv[]) {
    Net server;
    return server.serverExecute();
}
