#ifndef HEADERS_AND_GLOBALS_H_INCLUDED
#define HEADERS_AND_GLOBALS_H_INCLUDED

#include <stdio.h>
#include <SDL2/SDL.h>

#define pixelSize 1
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 480
#define BACKGROUND_COLOR 0x000000

// SDL event pool
SDL_Event event;
// SDL main window
SDL_Window *window = NULL;
// SDL main window surface
SDL_Surface *screen = NULL;

// main grid
struct pixels grid;

struct pixels createRectangle(int x, int y, int width, int height, int color);

// include other files
#include "function prototypes.h"
#include "pixel functions.h"
#include "SDL functions.h"

#endif // HEADERS_AND_GLOBALS_H_INCLUDED
