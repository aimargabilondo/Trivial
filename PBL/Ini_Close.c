#include "main.h"

void iniciar() {
    SDL_Window* window = initializeSDL();
    SDL_Renderer* renderer = initializeRenderer(window);
    SDL_Texture* backgroundTexture = loadTexture(renderer, NULL);
}


SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* filePath) {
    // Cargar imagen utilizando SDL_image
    SDL_Surface* surface = IMG_Load(filePath);
    if (!surface) {
        printf("Error al cargar la imagen: %s\n", IMG_GetError());
        return NULL;
    }

    // Crear textura desde la superficie
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        printf("Error al crear la textura: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return NULL;
    }

    SDL_FreeSurface(surface);
    return texture;
}

SDL_Window* initializeSDL() {
    SDL_Init(SDL_INIT_EVERYTHING);
    return SDL_CreateWindow("Mapa del Juego", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MAP_WIDTH * 30, MAP_HEIGHT * 30, SDL_WINDOW_SHOWN);
    ;
}

SDL_Renderer* initializeRenderer(SDL_Window* window) {
    return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void closeSDL(SDL_Renderer* renderer, SDL_Window* window) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void close() {
}

void closeCurrentWindow(SDL_Renderer* renderer, SDL_Window* window) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

