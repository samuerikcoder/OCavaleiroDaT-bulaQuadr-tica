#include "libs.h"
#include "menu.h"

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

    if (!showMenu())
        return 0;

    player.texture = loadTexture("gfx/player.png");
    player.x = 100;
    player.y = 570;
    player.width = 28;
    player.height = 30;

    while (1)
    {
        prepareScene();
        doInput();

        // Física
        player.dy += 0.5f;
        if (player.dy > Y_MOVEMENT)
            player.dy = Y_MOVEMENT;

        if (app.left && player.x >= 0)
            player.dx = -X_MOVEMENT;
        else if (app.right)
            player.dx = X_MOVEMENT;
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

        printf("x: %f, y: %f, dx: %f, dy: %f\n", player.x, player.y, player.dx, player.dy);

        blit(player.texture, (int)player.x, (int)player.y);
        presentScene();
        SDL_Delay(16);
    }

    return 0;
}
