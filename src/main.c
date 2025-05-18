#include "libs.h"

extern Platform platforms[];
extern int numPlatforms;
extern void checkPlatformCollisions(Entity *player);

App app;
Entity player;

int main(void)
{
    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Entity));

    initSDL();
    atexit(cleanup);

    player.texture = loadTexture("gfx/player.png");
    player.x = 100;
    player.y = 100;
    player.width = 32;
    player.height = 64;

    while (1)
    {
        prepareScene();
        doInput();

        // Física
        player.dy += 0.5f;
        if (player.dy > 15.0f)
            player.dy = 15.0f;

        if (app.left)
            player.dx = -5.0f;
        else if (app.right)
            player.dx = 5.0f;
        else
            player.dx = 0.0f;

        player.x += player.dx;
        player.y += player.dy;

        player.grounded = 0;

        // Checa se colidiu com o "chão"
        if (player.y + player.height > 600)
        {
            player.y = 600 - player.height;
            player.dy = 0;
            player.grounded = 1;
        }

        // Checa colisão com plataformas
        checkPlatformCollisions(&player);

        blit(player.texture, (int)player.x, (int)player.y);
        presentScene();
        SDL_Delay(16);
    }

    return 0;
}
