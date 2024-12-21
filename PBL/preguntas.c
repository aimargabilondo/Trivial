#include "main.h"

extern int vidas = 3;
extern int solucion = 0;

void preguntasDesdeArchivo(int numero, SDL_Renderer* renderer, SDL_Window* window) {
    if (TTF_Init() != 0) {
        fprintf(stderr, "Error al inicializar SDL_ttf: %s\n", TTF_GetError());
        return;
    }

    SDL_Texture* BackgroundTexture = loadTexture(renderer, "foto/fondos/fondo_preguntas.bmp");

    SDL_Surface* fondoPreguntas = IMG_Load("foto/fondos/pregunta.bmp");
    SDL_Texture* fonPregunta = SDL_CreateTextureFromSurface(renderer, fondoPreguntas);

    SDL_Rect fPregunta = { 175, 20, 700, 150 };
    SDL_Rect fRespuesta1 = { 195, 200, 600, 150 };
    SDL_Rect fRespuesta2 = { 195, 380, 600, 150 };
    SDL_Rect fRespuesta3 = { 195, 560, 600, 150 };

    TTF_Font* font = TTF_OpenFont(".\\TEXTO\\arial.ttf", 22);
    SDL_Color textColor = { 0, 0, 0 }; // Black color

    int respuestaUsuario = 0;
    const int buttonCount = 3;
    Button buttons[BUTTON_COUNT];
    buttons[0] = createButton(28 * 30, 230, renderer, "foto/botones/1.bmp", 7);
    buttons[1] = createButton(28 * 30, 410, renderer, "foto/botones/2.bmp", 8);
    buttons[2] = createButton(28 * 30, 590, renderer, "foto/botones/3.bmp", 9);

    char nombre_archivo[20];
    sprintf(nombre_archivo, "preguntas/%d.txt", numero);

    FILE* archivo = fopen(nombre_archivo, "r");

    int numPregunta, pregunta_random;
    char pregunta[256], respuesta1[256], respuesta2[256], respuesta3[256];

    pregunta_random = random(1, 6);

    while (fscanf(archivo, "%d", &numPregunta) == 1) {
        fscanf_s(archivo, " ");
        fgets(pregunta, sizeof(pregunta), archivo);
        fgets(respuesta1, sizeof(respuesta1), archivo);
        fgets(respuesta2, sizeof(respuesta2), archivo);
        fgets(respuesta3, sizeof(respuesta3), archivo);
        fscanf_s(archivo, "%d", &solucion);

        // Eliminar caracteres de nueva línea
        pregunta[strcspn(pregunta, "\n")] = ' ';
        respuesta1[strcspn(respuesta1, "\n")] = ' ';
        respuesta2[strcspn(respuesta2, "\n")] = ' ';
        respuesta3[strcspn(respuesta3, "\n")] = ' ';

        if (numPregunta == pregunta_random) {
            // Renderizar pregunta en la ventana
            SDL_Surface* questionSurface = TTF_RenderText_Blended_Wrapped(font, pregunta, textColor, 650);

            if (questionSurface == NULL) {
                fprintf(stderr, "Error al crear la superficie de la pregunta: %s\n", TTF_GetError());
            }
            else {
                SDL_Texture* questionTexture = SDL_CreateTextureFromSurface(renderer, questionSurface);

                // Definir posición de renderizado para la pregunta
                SDL_Rect questionRect = { 200, 2 * 30, questionSurface->w, questionSurface->h };

                // Renderizar fondo antes de la pregunta
                SDL_RenderCopy(renderer, BackgroundTexture, NULL, NULL);

                // Renderizar fonod pregunta en la ventana
                SDL_RenderCopy(renderer, fonPregunta, NULL, &fPregunta);

                // Renderizar pregunta en la ventana
                SDL_RenderCopy(renderer, questionTexture, NULL, &questionRect);

            }

            // Renderizar respuesta1 en la ventana
            SDL_Surface* respuesta1Surface = TTF_RenderText_Blended_Wrapped(font, respuesta1, textColor, 550);

            if (respuesta1Surface == NULL) {
                fprintf(stderr, "Error al crear la superficie de la respuesta: %s\n", TTF_GetError());
            }
            else {
                SDL_Texture* respuesta1Texture = SDL_CreateTextureFromSurface(renderer, respuesta1Surface);

                // Definir posición de renderizado para la respuesta
                SDL_Rect respuesta1Rect = { 225, 8 * 30, respuesta1Surface->w, respuesta1Surface->h };

                // Renderizar fonod pregunta en la ventana
                SDL_RenderCopy(renderer, fonPregunta, NULL, &fRespuesta1);

                // Renderizar respuesta en la ventana
                SDL_RenderCopy(renderer, respuesta1Texture, NULL, &respuesta1Rect);

            }

            // Renderizar respuesta2 en la ventana
            SDL_Surface* respuesta2Surface = TTF_RenderText_Blended_Wrapped(font, respuesta2, textColor, 550);

            if (respuesta2Surface == NULL) {
                fprintf(stderr, "Error al crear la superficie de la respuesta: %s\n", TTF_GetError());
            }
            else {
                SDL_Texture* respuesta2Texture = SDL_CreateTextureFromSurface(renderer, respuesta2Surface);

                // Definir posición de renderizado para la respuesta
                SDL_Rect respuesta2Rect = { 225, 14 * 30, respuesta2Surface->w, respuesta2Surface->h };

                // Renderizar fonod pregunta en la ventana
                SDL_RenderCopy(renderer, fonPregunta, NULL, &fRespuesta2);

                // Renderizar respuesta en la ventana
                SDL_RenderCopy(renderer, respuesta2Texture, NULL, &respuesta2Rect);

            }

            // Renderizar respuesta3 en la ventana
            SDL_Surface* respuesta3Surface = TTF_RenderText_Blended_Wrapped(font, respuesta3, textColor, 550);

            if (respuesta3Surface == NULL) {
                fprintf(stderr, "Error al crear la superficie de la respuesta: %s\n", TTF_GetError());
            }
            else {
                SDL_Texture* respuesta3Texture = SDL_CreateTextureFromSurface(renderer, respuesta3Surface);

                // Definir posición de renderizado para la respuesta
                SDL_Rect respuesta3Rect = { 225, 20 * 30, respuesta3Surface->w, respuesta3Surface->h };

                // Renderizar fonod pregunta en la ventana
                SDL_RenderCopy(renderer, fonPregunta, NULL, &fRespuesta3);

                // Renderizar respuesta en la ventana
                SDL_RenderCopy(renderer, respuesta3Texture, NULL, &respuesta3Rect);

            }

            // Renderizar botones
            for (int i = 0; i < buttonCount; ++i) {
                renderButton(renderer, buttons[i]);
            }

            // Presentar el renderizado
            SDL_RenderPresent(renderer);
            

            bool quitMenu = false;
            SDL_Event menuEvent;

            while (!quitMenu) {
                while (SDL_PollEvent(&menuEvent) != 0) {
                    if (menuEvent.type == SDL_QUIT) {
                        quitMenu = true;
                    }

                    if (menuEvent.type == SDL_MOUSEBUTTONDOWN) {
                        int mouseX, mouseY;
                        SDL_GetMouseState(&mouseX, &mouseY);

                        // Verificar clic en botones
                        for (int i = 0; i < buttonCount; ++i) {
                            if (mouseX >= buttons[i].rect.x && mouseX < buttons[i].rect.x + buttons[i].rect.w &&
                                mouseY >= buttons[i].rect.y && mouseY < buttons[i].rect.y + buttons[i].rect.h) {
                                handleButtonClick(menuEvent, renderer, window, buttons, buttonCount, BackgroundTexture);
                                quitMenu = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    fclose(archivo);
    TTF_Quit();  // Finalizar SDL_ttf al salir de la función
}


int respuesta(int respuestaUsuario, SDL_Window* window, Button* buttons, int buttonCount, SDL_Renderer* renderer) {
    if (respuestaUsuario == 1) {
        respuestaUsuario = 1;
    }
    else if (respuestaUsuario == 2) {
        respuestaUsuario = 2;
    }
    else if (respuestaUsuario == 3) {
        respuestaUsuario = 3;
    }
    for (int i = 0; i < buttonCount; ++i) {
        SDL_DestroyTexture(buttons[i].texture);
        SDL_RenderClear(renderer);
    }
    if (respuestaUsuario == solucion) {
        RespuestaBien(renderer, window, vidas);
    }
    else {
        vidas = vidas - 1;
        if (vidas != 0) {
            RespuestaMal(renderer, window, vidas);
        }
        if (vidas == 0) {
            Lose(renderer, window);
        }
    }
    return respuestaUsuario;
}