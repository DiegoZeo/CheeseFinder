#include <SFML/Graphics.hpp>

#include "GameMap.h"
#include "MapSeachNode.h"
#include "Rat.h"

int main()
{
    // Open window
    sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;
    auto window = sf::RenderWindow{ { 1000u, 800u }, "ChesseFinder", style};
    window.setFramerateLimit(144);

    //Game assets declaration
    sf::RectangleShape cheese(sf::Vector2f (32, 32));
    cheese.setFillColor(sf::Color::Blue);

    sf::Vector2i mousePos(0,0);

    sf::Clock clock;
    sf::Time time;

    auto* map = new GameMap();

    MapSearchNode nodeStart;
    nodeStart.x = 0;
    nodeStart.y = 1;

    MapSearchNode nodeEnd;
    nodeEnd.x = 3;
    nodeEnd.y = 0;

    Rat* nezumi = new Rat(nodeStart, nodeEnd, map);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            switch(event.type)
            {
                case sf::Event::EventType::Closed:
                    window.close();
                    break;
                case sf::Event::EventType::KeyPressed:
                    if(event.key.code == sf::Keyboard::Key::Escape)
                        window.close();
                    break;
                case sf::Event::EventType::MouseMoved:
                    mousePos = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);
                    break;
                case sf::Event::EventType::MouseButtonPressed:
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        map->SwitchCellState(mousePos.x / 40, mousePos.y /40);
                        nezumi->FindNewPath(map);
                        break;
                    }
            }
        }

        window.clear();

        map->DrawMap(&window, mousePos);
        cheese.setPosition(nodeEnd.x * 40, nodeEnd.y * 40);
        window.draw((cheese));
        nezumi->Draw(&window);

        window.display();

        if(nezumi->position->x != nodeEnd.x || nezumi->position->y != nodeEnd.y)
        {
            if(time.asSeconds() > 0.50)
            {
                clock.restart();
                nezumi->Step();
            }
        }

        time = clock.getElapsedTime();
    }
}
