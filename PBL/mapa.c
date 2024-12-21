#include "main.h"

int map_matriz[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 9, 0, 0, 2, 0, 2, 0, 0, 7, 0, 2, 0, 2, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 1, 1},
    {1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 0, 6, 1, 1, 1, 1, 1, 1, 1, 5, 5, 1, 1},
    {1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 2, 1, 1, 1, 0, 10, 0, 0, 11, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 6, 6, 1, 1},
    {1, 1, 1, 0, 1, 0, 2, 1, 1, 1, 1, 1, 0, 12, 12, 12, 12, 12, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 6, 6, 1, 1},
    {1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 8, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 4, 0, 5, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 6, 0, 2, 0, 2, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0, 2, 0, 6, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 10, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1},
    {1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 10, 0, 2, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1},
    {1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 7, 0, 0, 2, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1, 0, 2, 0, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
    {1, 1, 9, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 0, 2, 1, 1, 1, 1, 2, 0, 0, 7, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 2, 0, 0, 5, 0, 2, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 2, 0, 8, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 0, 2, 1, 1, 1, 1, 3, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void renderMap(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, SDL_Window* window, SDL_Event event) {
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            SDL_Rect rect = { j * 30, i * 30, 25, 25 };

            if (map_matriz[i][j] == 0) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            else if (map_matriz[i][j] == 1) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
            }
            else if (map_matriz[i][j] == 5) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
            }
            else if (map_matriz[i][j] == 6) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
            }
            else if (map_matriz[i][j] == 7) {
                SDL_SetRenderDrawColor(renderer, 100, 100, 255, 0);
            }
            else if (map_matriz[i][j] == 8) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
            }
            else if (map_matriz[i][j] == 9) {
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
            }
            else if (map_matriz[i][j] == 10) {
                SDL_SetRenderDrawColor(renderer, 100, 100, 0, 0);
            }
            else if (map_matriz[i][j] == 11) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            }
            else if (map_matriz[i][j] == 12) {
                SDL_SetRenderDrawColor(renderer, 100, 100, 100, 0);
            }
            else {
                SDL_SetRenderDrawColor(renderer, 20, 200, 25, 0);
            }
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        handleMouseClick(event, renderer, window, mouseX, mouseY);
    }

    SDL_RenderPresent(renderer);
}