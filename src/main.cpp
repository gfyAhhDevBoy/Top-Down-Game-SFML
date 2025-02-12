#include "Game.h"

int main()
{
    Game game;
    game.init();
    while (!game.should_close())
    {
        game.update();
        game.render();
    }
}
