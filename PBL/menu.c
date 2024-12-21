// menu.c
#include "main.h"

void showMenu(SDL_Renderer* renderer, SDL_Window* window) {

    SDL_RenderClear(renderer);

    SDL_Texture* menuBackgroundTexture = loadTexture(renderer, "foto/fondos/menu.bmp");

    SDL_RenderPresent(renderer);

    const int buttonCount = 4;
    Button menuButtons[BUTTON_COUNT];
    menuButtons[0] = createButton(32 * 30, 2 * 30, renderer, "foto/botones/itxi2.bmp", 4);
    menuButtons[1] = createButton(32 * 30, 8 * 30, renderer, "foto/botones/jokatubot.bmp", 3);
    menuButtons[2] = createButton(32 * 30, 14 * 30, renderer, "foto/botones/nolajokatubot.bmp", 2);
    menuButtons[3] = createButton(32 * 30, 20 * 30, renderer, "foto/botones/creditos.bmp", 1);


    bool quitMenu = false;
    bool needRenderMenu = true;
    SDL_Event menuEvent;

    while (!quitMenu) {
        while (SDL_PollEvent(&menuEvent) != 0) {
            if (menuEvent.type == SDL_QUIT) {
                quitMenu = true;
            }

            if (menuEvent.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                handleButtonClick(menuEvent, renderer, window, menuButtons, buttonCount, menuBackgroundTexture);
                needRenderMenu = true;
            }
        }

        if (needRenderMenu) {
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, menuBackgroundTexture, NULL, NULL);

            for (int i = 0; i < buttonCount; ++i) {
                renderButton(renderer, menuButtons[i]);
            }

            SDL_RenderPresent(renderer);
            needRenderMenu = false;
        }
    }

    for (int i = 0; i < buttonCount; ++i) {
        SDL_DestroyTexture(menuButtons[i].texture);
        SDL_DestroyWindow(window);
    }

}


