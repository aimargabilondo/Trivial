#include "main.h"

void RespuestaMal(SDL_Renderer* renderer, SDL_Window* window, int vidas) {
    
    const char* respuestamal = NULL;

    if (vidas == 1) {
        respuestamal = "foto/respuesta/respuestamal1.bmp";
    }
    else if (vidas == 2) {
        respuestamal = "foto/respuesta/respuestamal2.bmp";
    }

    SDL_Texture* backgroundTexture = loadTexture(renderer, respuestamal);

    SDL_RenderPresent(renderer);

    bool quitMenu = false;
    bool needRenderMenu = true;
    SDL_Event menuEvent;
    Uint32 startTime = SDL_GetTicks(); // Obtener el tiempo de inicio del bucle

    while (!quitMenu) {
        while (SDL_PollEvent(&menuEvent) != 0) {
            if (menuEvent.type == SDL_QUIT) {
                // quitMenu = true;
            }
        }

        Uint32 currentTime = SDL_GetTicks();
        Uint32 elapsedTime = currentTime - startTime;

        if (elapsedTime >= 1000) { // Cerrar el menú después de 1000 milisegundos
            quitMenu = true;
        }

        if (needRenderMenu) {
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

            SDL_RenderPresent(renderer);
            needRenderMenu = false;
        }
    }

    SDL_RenderClear(renderer);
}

void RespuestaBien(SDL_Renderer* renderer, SDL_Window* window, int vidas) { // Menu sin terminar SOLO FUNCIONA BOTON CERRAR 
    const char* respuestabien = NULL;

    if (vidas == 1) {
       respuestabien = "foto/respuesta/respuestabien1.bmp";
    }
    else if (vidas == 2) {
        respuestabien = "foto/respuesta/respuestabien2.bmp";
    }
    else if (vidas == 3) {
        respuestabien = "foto/respuesta/respuestabien3.bmp";
    }

    SDL_Texture* backgroundTexture = loadTexture(renderer, respuestabien);

    SDL_RenderPresent(renderer);

    bool quitMenu = false;
    bool needRenderMenu = true;
    SDL_Event menuEvent;
    Uint32 startTime = SDL_GetTicks(); // Obtener el tiempo de inicio del bucle

    while (!quitMenu) {
        while (SDL_PollEvent(&menuEvent) != 0) {
            if (menuEvent.type == SDL_QUIT) {
                // quitMenu = true;
            }
        }

        Uint32 currentTime = SDL_GetTicks();
        Uint32 elapsedTime = currentTime - startTime;

        if (elapsedTime >= 1000) { // Cerrar el menú después de 1000 milisegundos
            quitMenu = true;
        }

        if (needRenderMenu) {
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

            SDL_RenderPresent(renderer);
            needRenderMenu = false;
        }
    }

    SDL_RenderClear(renderer);
}