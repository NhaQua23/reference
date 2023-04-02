/*

 */
#include <iostream>
#include <SDL.h>
#include <cstdlib>

#include "SDL_Utils.h"
#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{
    Game game;
    game.init();

    game.render();
    SDL_Event e;
    int x, y;
    do
    {
        while( SDL_PollEvent( &e ) != 0 );
        cerr << e.type<< endl;
        if (e.type == SDL_QUIT ) break;
        /*if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN
               || e.type == SDL_MOUSEBUTTONUP )*/
        if (e.type == SDL_MOUSEBUTTONDOWN ) {
                SDL_GetMouseState( &x, &y );      //Get mouse position
                cerr << x << ", " << y<< endl;
                game.handleClick(x, y);
                game.render();
        }
    } while (!game.over());
    game.renderGameOver();

    waitUntilKeyPressed();

    game.destroy();
    return 0;
}
