// botones.c
#include "main.h"

// Funci�n para crear un bot�n con una textura
Button createButton(int x, int y, SDL_Renderer * renderer, const char* texturePath, int value) {
    Button button;
    button.rect.x = x;
    button.rect.y = y;

    // Cargar la textura desde el archivo
    button.texture = loadTexture(renderer, texturePath);
    if (!button.texture) {
        printf("Error al cargar la textura del bot�n.\n");
        exit(EXIT_FAILURE);
    }

    // Obtener las dimensiones de la textura para ajustar el rect�ngulo del bot�n
    SDL_QueryTexture(button.texture, NULL, NULL, &button.rect.w, &button.rect.h);

    button.value = value;
    return button;
}

// Funci�n para renderizar un bot�n en el renderer
void renderButton(SDL_Renderer* renderer, Button button) {
    SDL_RenderCopy(renderer, button.texture, NULL, &button.rect);
}

// Funci�n para manejar clics en los botones
void handleButtonClick(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window, Button* buttons, int buttonCount, SDL_Texture* backgroundTexture) {
    int mouseX, mouseY;
    int respuestaUsuario = 0;

    SDL_GetMouseState(&mouseX, &mouseY);

    for (int i = 0; i < buttonCount; ++i) {
        if (isClickInRect(mouseX, mouseY, buttons[i].rect)) {
            if (buttons[i].value == 1) {
                // Boton nola jokatu
                showCreditos(renderer, window);

            }
            else if (buttons[i].value == 2) {
                // Boton nola jokatu
                showInfo(renderer, window);  

            }
            else if (buttons[i].value == 3) {
                // Boton comenzar juego 
                showTrivial(renderer, window);

            }
            else if (buttons[i].value == 4) {
                closeSDL(renderer, window);
                close();
            }
            else if (buttons[i].value == 5) {
                // Boton volver al menu del juego
                showMenu(renderer, window); // Menu sin terminar 
            }
            else if (buttons[i].value == 6) {
                // Simular el lanzamiento de un dado (1-6)
                buttons[i].diceValue = random(0,6);
                int dadoa = buttons[i].diceValue;
                int ense�ar_dado = tirada_dado(buttons, renderer, window);
                mover_ficha(window, event, renderer, buttons, buttonCount, backgroundTexture, map_matriz, dadoa);

            }
            else if (buttons[i].value == 7) {
                // Boton 1 pregunta
                respuestaUsuario = 1;
                respuestaUsuario = respuesta(respuestaUsuario, window, buttons, buttonCount, renderer);

            }
            else if (buttons[i].value == 8) {
                // Boton 2 pregunta
                respuestaUsuario = 2;
                respuestaUsuario = respuesta(respuestaUsuario, window, buttons, buttonCount, renderer);

            }
            else if (buttons[i].value == 9) {
                // Boton 3 pregunta
                respuestaUsuario = 3;
                respuestaUsuario = respuesta(respuestaUsuario, window, buttons, buttonCount, renderer);
            }
            break;
        }
    }
}
