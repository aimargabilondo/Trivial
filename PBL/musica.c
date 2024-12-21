#include "main.h"

Mix_Music* inicializarMusica(const char* ruta) {
    // Inicializar SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer no pudo inicializarse. SDL_mixer Error: %s\n", Mix_GetError());
        return NULL;
    }

    // Cargar la m�sica
    Mix_Music* musica = Mix_LoadMUS(ruta);
    if (musica == NULL) {
        printf("No se pudo cargar la m�sica. SDL_mixer Error: %s\n", Mix_GetError());
        Mix_CloseAudio();
        return NULL;
    }

    return musica;
}

void reproducirMusica(Mix_Music* musica) {
    if (musica == NULL) {
        // Manejar error
        return -1;
    }
    // Reproducir la m�sica
    Mix_PlayMusic(musica, -1);  // El segundo par�metro (-1) indica reproducci�n continua
}

void detenerMusica() {
    Mix_HaltMusic();
}

void liberarMusica(Mix_Music* musica) {
    Mix_FreeMusic(musica);
    Mix_CloseAudio();
}