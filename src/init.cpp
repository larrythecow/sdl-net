#include "Net.h"

bool Net::init() {

//    if (SDL_Init(0) == -1) {
//        fprintf(stderr, "SDL_Init: %s\n", SDL_GetError());
//        exit(-1);
//    }
//    fprintf(stdout, "SDL_Init:\t\tOK\n");

    if (SDLNet_Init() == -1) {
        fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
        exit(-2);
    }
    fprintf(stdout, "SDLNet_Init:\t\tOK\n");

    allocSocketSet();

    return true;
}
