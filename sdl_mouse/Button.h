#ifndef __BUTTON_H
#define __BUTTON_H

const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;

const  SDL_Color Colors[] = { {255, 0, 0},  {0, 255, 0},  {0, 0, 255}};
const int COLORS = sizeof(Colors) / sizeof(SDL_Color);

class Button
{
    public:
        Button() {
            rect.x = 0;
            rect.y = 0;
            rect.w = BUTTON_WIDTH;
            rect.h = BUTTON_HEIGHT;
        }

        //Sets top left position
        void setPosition( int x, int y ) {
            rect.x = x;
            rect.y = y;
        }

        bool inside(int x, int y) {
             return ( x >= rect.x ) && ( x <= rect.x + rect.w ) &&
                                 ( y >= rect.y ) && ( y <= rect.y + rect.h );
        }

        void handleClick() {
                colorId = (colorId + 1) % COLORS;
        }

        void render( SDL_Renderer* renderer) {
            SDL_SetRenderDrawColor(renderer, Colors[colorId].r, Colors[colorId].g, Colors[colorId].b, 0 );
            SDL_RenderFillRect(renderer, &rect);
        }

    private:
        SDL_Rect rect;
        int colorId = 0;
};

#endif // __BUTTON_H
