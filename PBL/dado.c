#include "main.h"

int random(int min, int max) {
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }

    int rango = max - min + 1;
    int numeroAleatorio;

    do {
        numeroAleatorio = rand() % rango + min;
    } while (numeroAleatorio == 0);
    return numeroAleatorio;
}

int tirada_dado(Button buttons[BUTTON_COUNT], SDL_Renderer* renderer, SDL_Window* window) {
    // Cambiar la imagen del dado si es necesario

    if (buttons[1].diceValue != 0) {
        char diceImagePath[20];
        sprintf(diceImagePath, "foto/dado/%d.bmp", buttons[1].diceValue);
        SDL_DestroyTexture(buttons[1].texture);
        buttons[1].texture = loadTexture(renderer, diceImagePath);

    }

    return buttons[1].diceValue;
}
