#ifndef FUNCTION_PROTOTYPES_H_INCLUDED
#define FUNCTION_PROTOTYPES_H_INCLUDED

void init();
void cleanup();
struct pixels createRectangle(int x, int y, int width, int height, int color);
void printGrid();
void updatePixels(struct pixels rect);
void addColorAtCords(int color, int x, int y);
void addRectToGrid(struct pixels rect);


#endif // FUNCTION_PROTOTYPES_H_INCLUDED
