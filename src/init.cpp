#include "Net.h"

bool Net::init() {

    if (SDL_Init(0) == -1) {
        fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
        exit(-1);
    }
    fprintf(stdout, "SDL_Init:\t\tOK\n");

    if (SDLNet_Init() == -1) {
        fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
        exit(-2);
    }
    fprintf(stdout, "SDLNet_Init:\t\tOK\n");

//    if (!(socketsetClient = SDLNet_AllocSocketSet(DIMCLIENT))) {
//        printf("SDLNet_AllocSocketSet: %s\n", SDLNet_GetError());
//        exit(1);
//    }
//    fprintf(stdout, "SDLNet_AllocSocketSet:\tOK %d\n", DIMCLIENT);
//
//
//    if (!(clientCount = SDLNet_TCP_AddSocket(socketsetClient, socketClient))) {
//        printf("SDLNet_TCP_AddSocket: %s\n", SDLNet_GetError());
//    }
//    fprintf(stdout, "SDLNet_TCP_AddSocket:\tOK %d\n", clientCount);


    return true;
}
