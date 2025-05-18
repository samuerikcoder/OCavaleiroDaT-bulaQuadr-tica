#ifndef LIBS_H
#define LIBS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define X_MOVEMENT 5.0f
#define Y_MOVEMENT 8.0f

// Estruturas
typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int up;
    int down;
    int left;
    int right;
} App;

typedef struct Entity {
    float x, y;
    float dx, dy;
    SDL_Texture *texture;
    int grounded;
    int width, height;
} Entity;

typedef struct {
    SDL_Rect rect;
} Platform;

extern App app;
extern Entity player;
extern Platform platforms[];
extern int numPlatforms;

void initSDL(void);
void cleanup(void);
void prepareScene(void);
void doInput(void);
void presentScene(void);
SDL_Texture *loadTexture(const char *filename);
void blit(SDL_Texture *texture, int x, int y);
void drawPlatforms(void);

#endif
