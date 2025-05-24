#include "libs.h"

void initSDL(void)
{
    if (IMG_Init(IMG_INIT_PNG) == 0)
    {
        printf("Erro ao inicializar SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        exit(1);
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        exit(1);
    }

    app.window = SDL_CreateWindow("Meu Jogo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!app.window)
    {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    if (!app.renderer)
    {
        printf("Erro ao criar renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(app.window);
        SDL_Quit();
        exit(1);
    }
}

SDL_Texture *loadTexture(const char *filename)
{
    SDL_Surface *surface = IMG_Load(filename);
    if (!surface)
    {
        printf("Erro ao carregar imagem %s: %s\n", filename, IMG_GetError());
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(app.renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}