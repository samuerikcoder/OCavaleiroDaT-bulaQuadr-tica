#include "libs.h"

void blit(SDL_Texture *texture, int x, int y) {
    SDL_Rect dest = {x, y, player.width, player.height};
    SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

void drawPlatforms(void) {
    SDL_SetRenderDrawColor(app.renderer, 100, 100, 100, 255);
    for (int i = 0; i < numPlatforms; i++) {
        SDL_RenderFillRect(app.renderer, &platforms[i].rect);
    }
}

void prepareScene(void) {
    SDL_SetRenderDrawColor(app.renderer, 135, 206, 235, 255);
    SDL_RenderClear(app.renderer);
    drawPlatforms();
}

void prepareMenuScene(void) {
    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene(void) {
    SDL_RenderPresent(app.renderer);
}
