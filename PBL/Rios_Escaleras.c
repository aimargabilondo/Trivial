#include "main.h"

void Escalera_Rios( int num_actu_fitxa, int jugadorFila, int jugadorColumna, Button* buttons, SDL_Event event, SDL_Renderer* renderer, SDL_Texture* backgroundTexture, SDL_Window* window, int buttonCount) {
    if (num_actu_fitxa == 3) { //ESCALERA
        if (jugadorFila == 22 && jugadorColumna == 19) {
            map_matriz[14][22] = 0;
            map_matriz[20][26] = 0;
            map_matriz[16][17] = 0;
            map_matriz[7][3] = 0;
            map_matriz[2][19] = 0;
            map_matriz[12][5] = 0;
            
            jugadorFila = 14;
            jugadorColumna = 21;

            buttons[2].rect.x = jugadorColumna * 30;
            buttons[2].rect.y = jugadorFila * 30;

            map_matriz[14][22] = 1;
        }
        else if (jugadorFila == 9 && jugadorColumna == 21) {
            map_matriz[14][22] = 0;
            map_matriz[20][26] = 0;
            map_matriz[16][17] = 0;
            map_matriz[7][3] = 0;
            map_matriz[2][19] = 0;
            map_matriz[12][5] = 0;
            
            jugadorFila = 2;
            jugadorColumna = 18;

            buttons[2].rect.x = jugadorColumna * 30;
            buttons[2].rect.y = jugadorFila * 30;

            map_matriz[2][19] = 1;
        }

        SDL_RenderClear(renderer);
        renderMap(renderer, backgroundTexture, NULL, event);

        for (int i = 0; i < buttonCount; ++i) {
            renderButton(renderer, buttons[i]);
        }

        // Presentar el contenido renderizado
        SDL_RenderPresent(renderer);

        SDL_Delay(500); // Pausa de medio segundo, puedes ajustar según sea necesario

        num_actu_fitxa = map_matriz[jugadorFila][jugadorColumna];

        if (num_actu_fitxa != 0 && num_actu_fitxa != 1 && num_actu_fitxa != 2 && num_actu_fitxa != 3 && num_actu_fitxa != 4 && num_actu_fitxa != 11 && num_actu_fitxa != 12) {
            // Llamar a la función preguntasDesdeArchivo con el número de pregunta obtenido
            preguntasDesdeArchivo(num_actu_fitxa, renderer, window);
        }
    }
    if (num_actu_fitxa == 4) { //RIO
        if (jugadorFila == 13 && jugadorColumna == 30) {
            map_matriz[14][22] = 0;
            map_matriz[20][26] = 0;
            map_matriz[16][17] = 0;
            map_matriz[7][3] = 0;
            map_matriz[2][19] = 0;
            map_matriz[12][5] = 0;
            
            jugadorFila = 19;
            jugadorColumna = 27;

            buttons[2].rect.x = jugadorColumna * 30;
            buttons[2].rect.y = jugadorFila * 30;

            map_matriz[20][26] = 1;

        }
        else if (jugadorFila == 17 && jugadorColumna == 9) {
            map_matriz[14][22] = 0;
            map_matriz[20][26] = 0;
            map_matriz[16][17] = 0;
            map_matriz[7][3] = 0;
            map_matriz[2][19] = 0;
            map_matriz[12][5] = 0;

            jugadorFila = 21;
            jugadorColumna = 5;

            buttons[2].rect.x = jugadorColumna * 30;
            buttons[2].rect.y = jugadorFila * 30;

            map_matriz[21][4] = 1;

        }
        else if (jugadorFila == 11 && jugadorColumna == 15) {
            map_matriz[14][22] = 0;
            map_matriz[20][26] = 0;
            map_matriz[16][17] = 0;
            map_matriz[7][3] = 0;
            map_matriz[2][19] = 0;
            map_matriz[12][5] = 0;

            jugadorFila = 16;
            jugadorColumna = 16;

            buttons[2].rect.x = jugadorColumna * 30;
            buttons[2].rect.y = jugadorFila * 30;

            map_matriz[16][17] = 1;
        }
        else if (jugadorFila == 8 && jugadorColumna == 4) {
            map_matriz[14][22] = 0;
            map_matriz[20][26] = 0;
            map_matriz[16][17] = 0;
            map_matriz[7][3] = 0;
            map_matriz[2][19] = 0;
            map_matriz[12][5] = 0;


            jugadorFila = 12;
            jugadorColumna = 6;

            buttons[2].rect.x = jugadorColumna * 30;
            buttons[2].rect.y = jugadorFila * 30;

            map_matriz[12][5] = 1;
        }

        SDL_RenderClear(renderer);
        renderMap(renderer, backgroundTexture, NULL, event);

        for (int i = 0; i < buttonCount; ++i) {
            renderButton(renderer, buttons[i]);
        }

        // Presentar el contenido renderizado
        SDL_RenderPresent(renderer);

        SDL_Delay(500); // Pausa de medio segundo, puedes ajustar según sea necesario

        num_actu_fitxa = map_matriz[jugadorFila][jugadorColumna];

        if (num_actu_fitxa != 0 && num_actu_fitxa != 1 && num_actu_fitxa != 2 && num_actu_fitxa != 3 && num_actu_fitxa != 4 && num_actu_fitxa != 11 && num_actu_fitxa != 12) {
            // Llamar a la función preguntasDesdeArchivo con el número de pregunta obtenido
            preguntasDesdeArchivo(num_actu_fitxa, renderer, window);

        }
    }
    if (num_actu_fitxa == 11) { //KALABERA
        if (jugadorFila == 6 && jugadorColumna == 11) {
            map_matriz[14][22] = 0;
            map_matriz[20][26] = 0;
            map_matriz[16][17] = 0;
            map_matriz[7][3] = 0;
            map_matriz[2][19] = 0;
            map_matriz[12][5] = 0;

            jugadorFila = 21;
            jugadorColumna = 2;

            buttons[2].rect.x = jugadorColumna * 30;
            buttons[2].rect.y = jugadorFila * 30;
        }
      
        SDL_RenderClear(renderer);
        renderMap(renderer, backgroundTexture, NULL, event);

        for (int i = 0; i < buttonCount; ++i) {
            renderButton(renderer, buttons[i]);
        }

        // Presentar el contenido renderizado
        SDL_RenderPresent(renderer);

        SDL_Delay(500); // Pausa de medio segundo, puedes ajustar según sea necesario

        num_actu_fitxa = map_matriz[jugadorFila][jugadorColumna];

        if (num_actu_fitxa != 0 && num_actu_fitxa != 1 && num_actu_fitxa != 2 && num_actu_fitxa != 3 && num_actu_fitxa != 4 && num_actu_fitxa != 11 && num_actu_fitxa != 12) {
            // Llamar a la función preguntasDesdeArchivo con el número de pregunta obtenido
            preguntasDesdeArchivo(num_actu_fitxa, renderer, window);
        }
    }
}