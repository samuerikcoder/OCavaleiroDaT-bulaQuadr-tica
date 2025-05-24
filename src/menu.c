#include "libs.h"

int showMenu()
{
    if (TTF_Init() != 0)
    {
        printf("Erro ao iniciar SDL_ttf: %s\n", TTF_GetError());
        return 0;
    }

    TTF_Font *titleFont = TTF_OpenFont("fonts/Cabin_Condensed-Bold.ttf", 100);
    TTF_Font *buttonFont = TTF_OpenFont("fonts/Cabin_Condensed-Bold.ttf", 48);
    if (!titleFont)
    {
        printf("Erro ao carregar fonte: %s\n", TTF_GetError());
        return 0;
    }

    SDL_Color white = {255, 255, 255, 255};

    SDL_Surface *titleSurface = TTF_RenderText_Blended(titleFont, "One Pixel Knight", white);
    SDL_Texture *titleTexture = SDL_CreateTextureFromSurface(app.renderer, titleSurface);
    int titleW = titleSurface->w;
    int titleH = titleSurface->h;
    SDL_FreeSurface(titleSurface);

    SDL_Surface *startButtonSurface = TTF_RenderText_Blended(buttonFont, "Iniciar", white);
    SDL_Texture *startButtonTexture = SDL_CreateTextureFromSurface(app.renderer, startButtonSurface);
    int startButtonW = startButtonSurface->w;
    int startButtonH = startButtonSurface->h;
    SDL_FreeSurface(startButtonSurface);

    SDL_Surface *quitButtonSurface = TTF_RenderText_Blended(buttonFont, "Sair", white);
    SDL_Texture *quitButtonTexture = SDL_CreateTextureFromSurface(app.renderer, quitButtonSurface);
    int quitButtonW = quitButtonSurface->w;
    int quitButtonH = quitButtonSurface->h;
    SDL_FreeSurface(quitButtonSurface);

    SDL_Rect titleRect = {
        (SCREEN_WIDTH - titleW) / 2,
        SCREEN_HEIGHT / 3 - titleH / 2,
        titleW,
        titleH};

    SDL_Rect startButtonRect = {
        (SCREEN_WIDTH - startButtonW) / 2,
        SCREEN_HEIGHT / 2 + 100,
        startButtonW,
        startButtonH};

    SDL_Rect quitButtonRect = {
        (SCREEN_WIDTH - quitButtonW) / 2,
        SCREEN_HEIGHT / 2 + 200,
        quitButtonW,
        quitButtonH};

    SDL_Event event;
    int startGame = 0;

    while (!startGame)
    {
        prepareMenuScene();

        SDL_RenderCopy(app.renderer, titleTexture, NULL, &titleRect);
        SDL_RenderCopy(app.renderer, startButtonTexture, NULL, &startButtonRect);
        SDL_RenderCopy(app.renderer, quitButtonTexture, NULL, &quitButtonRect);

        presentScene();

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                exit(0);

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_RETURN)
                    startGame = 1;
                else if (event.key.keysym.sym == SDLK_ESCAPE)
                    return 0;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mx = event.button.x;
                int my = event.button.y;

                bool isMouseInStartButton = mx >= startButtonRect.x && mx <= startButtonRect.x + startButtonRect.w &&
                                            my >= startButtonRect.y && my <= startButtonRect.y + startButtonRect.h;

                bool isMouseInQuitButton = mx >= quitButtonRect.x && mx <= quitButtonRect.x + quitButtonRect.w &&
                                           my >= quitButtonRect.y && my <= quitButtonRect.y + quitButtonRect.h;
                if (isMouseInStartButton)
                {
                    startGame = 1;
                }

                if (isMouseInQuitButton)
                {
                    return 0;
                }
            }
        }

        SDL_Delay(16);
    }

    SDL_DestroyTexture(titleTexture);
    SDL_DestroyTexture(startButtonTexture);
    TTF_CloseFont(titleFont);
    TTF_CloseFont(buttonFont);
    TTF_Quit();

    return 1;
}
