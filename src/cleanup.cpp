#include "Net.h"

void Net::cleanup() {
    
//    SDLNet_TCP_DelSocket(socketsetClient, socketClient);
    SDLNet_FreeSocketSet(socketSetClient);
    printf("\n\ncleanexit\n");
    SDLNet_Quit();
}
