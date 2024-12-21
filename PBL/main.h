// main.h
#ifndef MAIN_H
#define MAIN_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdbool.h>
#include <time.h>

#define MAP_WIDTH 36
#define MAP_HEIGHT 24
#define BUTTON_COUNT 5

#define MAX_PREGUNTAS 6
#define MAX_OPCIONES 3
#define MAX_LONGITUD_PREGUNTA 256
#define MAX_LONGITUD_OPCION 128

#define MAX_BLOQUEADAS 2

#define FPS 60

typedef enum {
    CLOSE_BUTTON,
    DICE_BUTTON,
    THIRD_BUTTON,
    FORD_BUTTON,
    MAP_BUTTON,  // Nuevo tipo de botón para abrir el mapa
    EXIT_BUTTON, // Nuevo tipo de botón para salir del programa
} ButtonType;

typedef struct {
    SDL_Rect rect;
    SDL_Texture* texture;
    int value;
    ButtonType type;
    int diceValue;  // Nuevo campo para almacenar el valor del dado
} Button;

typedef struct {
	char pregunta[MAX_LONGITUD_PREGUNTA];
	char opciones[MAX_OPCIONES][MAX_LONGITUD_OPCION];
	char respuesta_correcta;
} Pregunta;

extern int map_matriz[MAP_HEIGHT][MAP_WIDTH];

SDL_Window* initializeSDL();
SDL_Renderer* initializeRenderer(SDL_Window* window);
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* filePath);
Button createButton(int x, int y, SDL_Renderer* renderer, const char* texturePath, int value);
Mix_Music* inicializarMusica(const char* ruta);

void reproducirMusica(Mix_Music* musica);
void detenerMusica();
void liberarMusica(Mix_Music* musica);

void renderMap(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, SDL_Window* window, SDL_Event event);
void handleMouseClick(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window, int mouseX, int mouseY);
void closeSDL(SDL_Renderer* renderer, SDL_Window* window);
void closeCurrentWindow(SDL_Renderer* renderer, SDL_Window* window);
void renderButton(SDL_Renderer* renderer, Button button);

void iniciar();
void close();

//void jokalariaTablerotikMugitu(int mapa[MAP_HEIGHT][MAP_WIDTH], JOKALARIA jokalaria, int dadoa_kont);
void handleButtonClick(SDL_Event event, SDL_Renderer* renderer, SDL_Window* window, Button* buttons, int buttonCount, SDL_Texture* backgroundTexture);
void showMenu(SDL_Renderer* renderer, SDL_Window* window);
void showTrivial(SDL_Renderer* renderer, SDL_Window* window);
void showInfo(SDL_Renderer* renderer, SDL_Window* window);
void showCreditos(SDL_Renderer* renderer, SDL_Window* window);

int tirada_dado(Button buttons[BUTTON_COUNT], SDL_Renderer* renderer, SDL_Window* window);
int random(int min, int max);

void mover_ficha(SDL_Window* window, SDL_Event event, SDL_Renderer* renderer, Button* buttons, int buttonCount, SDL_Texture* backgroundTexture, int map_matriz[MAP_HEIGHT][MAP_WIDTH], int dado);
void jokalariaMugitu(SDL_Window* window, SDL_Event event, SDL_Renderer* renderer, Button* buttons, int buttonCount, SDL_Texture* backgroundTexture, int map_matriz[MAP_HEIGHT][MAP_WIDTH], int fila, int columna, int dado);
void Escalera_Rios(int num_actu_fitxa, int jugadorFila, int jugadorColumna, Button* buttons, SDL_Event event, SDL_Renderer* renderer, SDL_Texture* backgroundTexture, SDL_Window* window, int buttonCount);

void preguntasDesdeArchivo(int numero, SDL_Renderer* renderer, SDL_Window* window);
int respuesta(int respuestaUsuario, SDL_Window* window, Button* buttons, int buttonCount, SDL_Renderer* renderer);
void RespuestaMal(SDL_Renderer* renderer, SDL_Window* window, int vidas);
void RespuestaBien(SDL_Renderer* renderer, SDL_Window* window, int vidas);

void Lose(SDL_Renderer* renderer, SDL_Window* window);
void Win(SDL_Renderer * renderer, SDL_Window * window);


bool isClickInRect(int mouseX, int mouseY, SDL_Rect rect);
bool isClickInCell(int mouseX, int mouseY, int row, int col);

#endif // MAIN_H
