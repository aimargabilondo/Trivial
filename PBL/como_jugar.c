#include "main.h"


void showInfo(SDL_Renderer* renderer, SDL_Window* window) { // Menu sin terminar SOLO FUNCIONA BOTON CERRAR 

    SDL_RenderClear(renderer);

    SDL_Texture* backgroundTexture = loadTexture(renderer, "foto/fondos/comojugar.bmp");

    SDL_RenderPresent(renderer);

    const int buttonCount = 1;  // Aumenta el contador de botones a 3
    Button buttons[BUTTON_COUNT];
    buttons[0] = createButton(31 * 30, 4 * 30, renderer, "foto/botones/itxi.bmp", 5);
    
    for (int i = 0; i < buttonCount; ++i) {
        renderButton(renderer, buttons[i]);
    }


    bool quit = false;
    bool needRender = true;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                handleMouseClick(e, renderer, window, mouseX, mouseY);
                handleButtonClick(e, renderer, window, buttons, buttonCount, backgroundTexture);
                needRender = true;  // Se ha producido un cambio que requiere renderizado
            }
        }

        // Renderizado solo si es necesario
        if (needRender) {
            SDL_RenderClear(renderer);
            renderMap(renderer, backgroundTexture, window, e);

            // Renderizado de botones
            for (int i = 0; i < buttonCount; ++i) {
                renderButton(renderer, buttons[i]);
            }

            // Presentar el contenido renderizado
            SDL_RenderPresent(renderer);

            needRender = false;  // Restablecer la bandera de renderizado
        }
    }

    for (int i = 0; i < buttonCount; ++i) {
        SDL_DestroyTexture(buttons[i].texture);
        SDL_DestroyWindow(window);
    }
}