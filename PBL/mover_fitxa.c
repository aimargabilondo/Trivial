#include "main.h"

extern int posx = 0;
extern int posy = 0;

extern int anteprevFila = 0;
extern int anteprevColumna = 0;

void mover_ficha(SDL_Window* window, SDL_Event event, SDL_Renderer* renderer, Button* buttons, int buttonCount, SDL_Texture* backgroundTexture, int map_matriz[MAP_HEIGHT][MAP_WIDTH], int dado){
    // Obtener la posición del botón buttons[2]
    int x_bot = buttons[2].rect.x / 30;
    int y_bot = buttons[2].rect.y / 30;


    // Utilizar la posición del botón para obtener la posición en map_matriz[][]
    int fila = y_bot;
    int columna = x_bot;
    // Utilizar la posición obtenida en map_matriz[][] para mover la ficha por el camino de 0s
    jokalariaMugitu(window, event, renderer, buttons, buttonCount, backgroundTexture, map_matriz, fila, columna, dado);
}

void jokalariaMugitu(SDL_Window* window,SDL_Event event, SDL_Renderer* renderer, Button* buttons, int buttonCount, SDL_Texture* backgroundTexture, int map_matriz[MAP_HEIGHT][MAP_WIDTH], int fila, int columna, int dado) {
    int jugadorFila = fila; // Inicializar con la fila obtenida
    int jugadorColumna = columna; // Inicializar con la columna obtenida

    int prevFila = jugadorFila; // Mantener la posición anterior
    int prevColumna = jugadorColumna; // Mantener la posición anterior

    int num_anterior = map_matriz[jugadorFila][jugadorColumna];

    
    // Definir las direcciones laterales (izquierda, derecha, arriba, abajo, diagonal superior izquierda, diagonal superior derecha, diagonal inferior izquierda, diagonal inferior derecha)
    int direcciones[][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

    while (dado > 0) {
        // Recorrer todas las direcciones
        int anteprevFila = 0;
        int anteprevColumna = 0;
        if (num_anterior == 1) {
            map_matriz[anteprevFila][anteprevColumna] = num_anterior;
        }
       
        for (int i = 0; i < 8; ++i) {
            int nuevaFila = jugadorFila + direcciones[i][0];
            int nuevaColumna = jugadorColumna + direcciones[i][1];
            

            // Verificar si la nueva posición está dentro de los límites y es 0 en la matriz y no es la posición anterior
            if (nuevaFila >= 0 && nuevaFila < MAP_HEIGHT && nuevaColumna >= 0 && nuevaColumna < MAP_WIDTH &&
                map_matriz[nuevaFila][nuevaColumna] != 1 &&
                (nuevaFila != prevFila || nuevaColumna != prevColumna)) {

                if (map_matriz[nuevaFila][nuevaColumna] != 0) {
                    dado = dado - 1;
                }

                // Mover la ficha
                buttons[2].rect.x = nuevaColumna * 30;
                buttons[2].rect.y = nuevaFila * 30;
                
                anteprevFila = prevFila;
                anteprevColumna = prevColumna;

                
                // Actualizar la posición anterior

                prevFila = jugadorFila;
                prevColumna = jugadorColumna;

                
                // Renderizar solo si es necesario
                SDL_RenderClear(renderer);
                renderMap(renderer, backgroundTexture, NULL, event);

                // Renderizado de botones
                for (int i = 0; i < buttonCount; ++i) {
                    renderButton(renderer, buttons[i]);
                }

                // Presentar el contenido renderizado
                SDL_RenderPresent(renderer);

                SDL_Delay(500); // Pausa de medio segundo, puedes ajustar según sea necesario

                // Actualizar la posición en map_matriz para el siguiente movimiento
                jugadorFila = nuevaFila;
                jugadorColumna = nuevaColumna;

                break; // Salir del bucle después de mover la ficha
            }
        }

    }
    
    int num_actu_fitxa = map_matriz[jugadorFila][jugadorColumna];
    if (num_actu_fitxa == 11) {
        Escalera_Rios(num_actu_fitxa, jugadorFila, jugadorColumna, buttons, event, renderer, backgroundTexture, window, buttonCount);
    }
    if (num_actu_fitxa == 12) {
        Win(renderer, window);

    }
    if (map_matriz[prevFila][prevColumna] != map_matriz[jugadorFila][jugadorColumna]) {

        if (num_actu_fitxa != 0 && num_actu_fitxa != 1 && num_actu_fitxa != 2 && num_actu_fitxa != 3 && num_actu_fitxa != 4 && num_actu_fitxa != 11 && num_actu_fitxa != 12) {
            // Llamar a la función preguntasDesdeArchivo con el número de pregunta obtenido
            preguntasDesdeArchivo(num_actu_fitxa, renderer, window);

        }

        jugadorFila = jugadorFila;
        jugadorColumna = jugadorColumna;

        if (num_actu_fitxa == 3) { //ESCALERA
            Escalera_Rios(num_actu_fitxa, jugadorFila, jugadorColumna, buttons, event, renderer, backgroundTexture, window, buttonCount);
        }
        if (num_actu_fitxa == 4) { //RIO
            Escalera_Rios(num_actu_fitxa, jugadorFila, jugadorColumna, buttons, event, renderer, backgroundTexture, window, buttonCount);
        }
       
        int c = map_matriz[prevFila][prevColumna];
        if (num_actu_fitxa != 3 && num_actu_fitxa != 4) {
            if (map_matriz[posy][posx] == 1) {
                map_matriz[posy][posx] = c;
            }

            map_matriz[anteprevFila][anteprevColumna] = 1;

            map_matriz[prevFila][prevColumna] = 1;

            posy = prevFila;
            posx = prevColumna;
        }
    }
}