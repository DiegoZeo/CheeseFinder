#include <SFML/Graphics.hpp>

#include "GameMap.h"

int main()
{
    sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;
    auto window = sf::RenderWindow{ { 800u, 800u }, "ChesseFinder", style};
    window.setFramerateLimit(144);

    sf::Vector2i mousePos(0,0);

    GameMap* map = new GameMap();

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
            }
        }

        window.clear();

        map->DrawMap(&window, mousePos);

        window.display();
    }
}