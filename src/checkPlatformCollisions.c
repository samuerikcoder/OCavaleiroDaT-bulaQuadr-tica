#include "libs.h"

void checkPlatformCollisions(Entity *player) {
    for (int i = 0; i < numPlatforms; i++) {
        Platform *p = &platforms[i];

        SDL_Rect r1 = {
            (int)player->x,
            (int)player->y,
            player->width,
            player->height
        };

        SDL_Rect r2 = p->rect;

        // Verifica colisão somente se o jogador estiver caindo
        if (player->dy >= 0 &&
            r1.y + r1.h <= r2.y && // topo do jogador acima da plataforma
            r1.y + r1.h + player->dy >= r2.y && // jogador está caindo até a plataforma
            r1.x + r1.w > r2.x && // sobreposição horizontal
            r1.x < r2.x + r2.w) {

            player->y = r2.y - player->height;
            player->dy = 0;
            player->grounded = 1;
        }
    }
}
