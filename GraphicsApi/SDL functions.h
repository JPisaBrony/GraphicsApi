#include "headers and globals.h"

#ifndef SDL_FUNCTIONS_H_INCLUDED
#define SDL_FUNCTIONS_H_INCLUDED

// initialize everything
void init() {
    SDL_Init(SDL_INIT_EVERYTHING);

    // create dat window
    window = SDL_CreateWindow("Graphics Api", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);

    // check to see if dat window exists
    if(window == NULL)
        exit(123);

    // get the screen
    screen = SDL_GetWindowSurface(window);

    // check to see if dat screen exists
    if(screen == NULL)
        exit(124);

    // create the main grid that every pixel will be added to
    grid = createRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, BACKGROUND_COLOR);
}

void cleanup() {
    // quit sdl
    SDL_Quit();
}

#endif // SDL_FUNCTIONS_H_INCLUDED
