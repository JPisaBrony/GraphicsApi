#ifndef PIXEL_FUNCTIONS_H_INCLUDED
#define PIXEL_FUNCTIONS_H_INCLUDED

/// structure for each pixel on the screen
/// contains the x, y, width, height of each pixel in a SDL_Rect
/// contains the width and height of each array for
/// adding new pixels to the screen
struct pixels {
    SDL_Rect **pixel;
    int **color;
    int width;
    int height;
};

// create a rectangle pixels structure
struct pixels createRectangle(int x, int y, int width, int height, int color) {
    int i, j;
    // create blank structure
    struct pixels p;

    // set the size of the arrays
    p.width = width;
    p.height = height;

    // allocate dat memory
    p.pixel = malloc(sizeof(SDL_Rect*) * width);
    p.color = malloc(sizeof(int*) * width);

    for(i = 0; i < width; i++) {
        p.pixel[i] = malloc(sizeof(SDL_Rect) * height);
        p.color[i] = malloc(sizeof(int) * height);
    }

    // set each pixel and color
    for(i = 0; i < width; i++) {
        for(j = 0; j < height; j++) {
            p.pixel[i][j].x = i + x;
            p.pixel[i][j].y = j + y;
            p.pixel[i][j].w = pixelSize;
            p.pixel[i][j].h = pixelSize;
            p.color[i][j] = color;
        }
    }
    return p;
}

// print the whole grid to the screen
void printGrid() {
    int i, j;

    // print each pixel in the grid
    for(i = 0; i < WINDOW_WIDTH; i++) {
        for(j = 0; j < WINDOW_HEIGHT; j++) {
            // fill dat screen with dem pixels
            SDL_FillRect(screen, &grid.pixel[i][j], grid.color[i][j]);
        }
    }
}

// update only the pixels needed for the rectangle
void updatePixels(struct pixels rect) {
    int i, j;
    // get the upper left corner coordinates
    int x = rect.pixel[0][0].x;
    int y = rect.pixel[0][0].y;

    // iterate through the rectangle
    for(i = 0; i < rect.width; i++) {
        for(j = 0; j < rect.height; j++) {
            // make sure that the array is within the grid bounds or else don't add it
            if(rect.pixel[i][j].x > -1 && rect.pixel[i][j].x < WINDOW_WIDTH && rect.pixel[i][j].y > -1 && rect.pixel[i][j].y < WINDOW_HEIGHT) {
                // fill dat screen with dem pixels
                SDL_FillRect(screen, &grid.pixel[x+i][y+j], grid.color[x+i][y+j]);
            }
        }
    }
}

// add a color at specific cordiantes
void addColorAtCords(int color, int x, int y) {
    grid.color[x][y] = color;
}

// add a rectangle to the grid to be displayed later
void addRectToGrid(struct pixels rect) {
    int i, j;

    // iterate through the rectangle
    for(i = 0; i < rect.width; i++) {
        for(j = 0; j < rect.height; j++) {
            // make sure that the array is within the grid bounds or else don't add it
            if(rect.pixel[i][j].x > -1 && rect.pixel[i][j].x < WINDOW_WIDTH && rect.pixel[i][j].y > -1 && rect.pixel[i][j].y < WINDOW_HEIGHT) {
                grid.pixel[rect.pixel[i][j].x][rect.pixel[i][j].y].x = rect.pixel[i][j].x;
                grid.pixel[rect.pixel[i][j].x][rect.pixel[i][j].y].y = rect.pixel[i][j].y;
                grid.pixel[rect.pixel[i][j].x][rect.pixel[i][j].y].w = rect.pixel[i][j].w;
                grid.pixel[rect.pixel[i][j].x][rect.pixel[i][j].y].h = rect.pixel[i][j].h;
                grid.color[rect.pixel[i][j].x][rect.pixel[i][j].y] = rect.color[i][j];
            }
        }
    }
}

#endif // PIXEL_FUNCTIONS_H_INCLUDED
