#include "headers and globals.h"

int main(int argc, char* args[])
{
    // initilize everything
    init();

    int i, j;
    // main timer
    int timer = 0;

    // create a rectangle
    // in order to not "streak" the screen
    // the rectangle must be 1 larger than what is intended
    // notice the negative values
    // they are accepted because the print function will make sure that
    // the arrays don't go out of bounds
    // it also allows for the rectangle to be partially printed allowing for
    // the rectangle to move onto and off of the screen
    struct pixels s = createRectangle(-101, -101, 101, 101, 0xFFFFFF);

    // add on the top edge of the rectangle
    // the background color to prevent "streaking"
    for(i = 0; i < s.width; i++) {
        s.color[i][0] = BACKGROUND_COLOR;
    }

    // add on the left edge of the rectangle
    // the background color to prevent "streaking"
    for(i = 0; i < s.height; i++) {
        s.color[0][i] = BACKGROUND_COLOR;
    }

    // insert the new rectangle into the grid
    addRectToGrid(s);

    // print the grid for the first time
    printGrid();

    // while the user hasnt quit
    while(1) {
        // pool for events
        while(SDL_PollEvent(&event)) {
            // if the window is closed
            if(event.type == SDL_QUIT) {
                cleanup();
                return 0;
            }
            // check for key presses
            if(event.type == SDL_KEYDOWN) {
                // check for specific keys
                switch(event.key.keysym.sym) {
                    // q key
                    case SDLK_q:
                        // quit the program
                        cleanup();
                        return 0;
                        break;
                }
            }
        }

        // animate the square every so often
        if(timer % 10 == 0) {
            for(i = 0; i < s.width; i++) {
                for(j = 0; j < s.height; j++) {
                    s.pixel[i][j].x++;
                    s.pixel[i][j].y++;
                }
            }
            // update the cords of the square
            addRectToGrid(s);
            updatePixels(s);
        }

        // update the screen
        SDL_UpdateWindowSurface(window);

        // increment timer
        timer++;
    }

    return 0;
}
