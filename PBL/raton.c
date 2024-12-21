// raton.c
#include "main.h"

void handleMouseClick(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window, int mouseX, int mouseY) {
    for (int row = 0; row < MAP_HEIGHT; ++row) {
        for (int col = 0; col < MAP_WIDTH; ++col) {
            if (isClickInCell(mouseX, mouseY, row, col)) {
                if (map_matriz[row][col] == 5) {
                    closeSDL(renderer, window);
                    close();
                    return;
                }
                break;
            }
        }
    }
}

bool isClickInCell(int mouseX, int mouseY, int row, int col) {
    const int CELL_WIDTH = MAP_WIDTH / 24;
    const int CELL_HEIGHT = MAP_HEIGHT / 36;

    return mouseX >= col * CELL_WIDTH && mouseX < (col + 1)* CELL_WIDTH&&
        mouseY >= row * CELL_HEIGHT && mouseY < (row + 1)* CELL_HEIGHT;
}

// Función para verificar si un punto está dentro de un rectángulo
bool isClickInRect(int mouseX, int mouseY, SDL_Rect rect) {
    return mouseX >= rect.x && mouseX < rect.x + rect.w &&
        mouseY >= rect.y && mouseY < rect.y + rect.h;
}