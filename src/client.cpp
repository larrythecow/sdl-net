#include "Net.h"

Net::Net() {
    running = true;
    type = 0;
    init();
}

Net::~Net() {
}

int Net::clientExecute() {
    printf("init done!\n");


    ipPeer.resolvehost("localhost", 9999);
    tcpOpen();
    ipPeer.resolveIP();
    while (1) {
        snprintf(buffer, DIMBUFFER, "%s", "hello world\n");
        tcpSend();
    }

    printf("\n\ncleanexit\n\n");
    return 0;
}

int main(int argc, char* argv[]) {
    Net client;
    return client.clientExecute();
}
