#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <Box2D/Box2D.h>

#include "game.h" 


int main()
{

    Box2DRolling::Game game;
    game.init();
    game.run();
    
}
