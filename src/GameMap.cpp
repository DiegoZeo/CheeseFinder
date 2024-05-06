//
// Created by dazeo on 06/05/2024.
//

#include "GameMap.h"
#include "SFML/Graphics.hpp"

GameMap::GameMap() = default;

int GameMap::GetMap(int x, int y)
{
    if( x < 0 ||
        x >= MAP_WIDTH ||
        y < 0 ||
        y >= MAP_HEIGHT
            )
    {
        return 9;
    }

    return world_map[(y*MAP_WIDTH)+x];
}

void GameMap::DrawMap(sf::RenderWindow* window , sf::Vector2i pos)
{
    sf::RectangleShape cell(sf::Vector2f(40,40));
    for(int i = 0; i<MAP_HEIGHT; i++)
    {
        for(int j = 0; j<MAP_HEIGHT; j++)
        {
            if (GetMap(j,i) == 1)
                cell.setFillColor(sf::Color::White);
            else
                cell.setFillColor(sf::Color::Black);
            if (i == pos.y/40 && j == pos.x/40)
                cell.setFillColor(sf::Color::Green);
            cell.setPosition(j * MAP_HEIGHT * 2, i * MAP_WIDTH * 2);
            window->draw(cell);
        }
    }
}