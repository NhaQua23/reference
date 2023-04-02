#ifndef GAME__H_
#define GAME__H_

#include <SDL.h>
#include <vector>
#include "Button.h"
#include "SDL_Utils.h"

const int TOTAL_BUTTONS = 2;

class Game {
public:
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const char* WINDOW_TITLE = "Mouse and Buttons Test";

    const SDL_Color BGR_COLOR = {255, 255, 255};

    SDL_Window* window;
    SDL_Renderer* renderer;
    Button buttons[TOTAL_BUTTONS];

    void init() {
        initSDL(window, renderer, WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);
        initButtons();
    }

    void clearScreen() {
        SDL_SetRenderDrawColor(renderer, BGR_COLOR.r, BGR_COLOR.g, BGR_COLOR.b, 0);
        SDL_RenderClear(renderer);
    }

    void initButtons() {
        buttons[0].setPosition(0,0);
        buttons[1].setPosition(200,200);
    }

    bool over() {
        return false;
    }

    void render() {
        clearScreen();

        for( int i = 0; i < TOTAL_BUTTONS; ++i ) {
            buttons[i].render(renderer);
        }

        SDL_RenderPresent( renderer );
    }

    void renderGameOver() {
        clearScreen();
        SDL_RenderPresent( renderer );
    }

    void destroy() {
        quitSDL(window, renderer);
    }

    void handleClick(int x, int y) {
        for( int i = 0; i < TOTAL_BUTTONS; ++i ) {
            if (buttons[ i ].inside(x,y)) buttons[i].handleClick();
        }
    }
};

#endif
