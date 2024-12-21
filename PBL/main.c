// main.c
#include "main.h"
const char* rutaMusica = "musica/musica1.mp3";

int main(int argc, char* argv[]) {
    SDL_Window* window = initializeSDL();
    SDL_Renderer* renderer = initializeRenderer(window); 
    Mix_Music* musica = inicializarMusica(rutaMusica);

    reproducirMusica(musica);
    
    showMenu(renderer, window); // Menu sin terminar SOLO FUNCIONA BOTON CERRAR 

    // Liberar recursos
    liberarMusica(musica);
    closeSDL(renderer, window);
    close();

    return 0;
}