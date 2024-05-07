#include <SFML/Graphics.hpp>

#include "GameMap.h"
#include "MapSeachNode.h"
#include "stlastar.h"

int main()
{
    sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;
    auto window = sf::RenderWindow{ { 800u, 800u }, "ChesseFinder", style};
    window.setFramerateLimit(144);

    sf::CircleShape rat(20);
    rat.setFillColor(sf::Color::Magenta);
    sf::RectangleShape cheese(sf::Vector2f (40, 40));
    cheese.setFillColor(sf::Color::Blue);

    sf::Vector2i mousePos(0,0);

    sf::Clock clock;
    sf::Time time;

    GameMap* map = new GameMap();

    AStarSearch<MapSearchNode> astarsearch;
    unsigned int SearchState;

    MapSearchNode nodeStart;
    nodeStart.x = 0;
    nodeStart.y = 1;

    MapSearchNode nodeEnd;
    nodeEnd.x = 3;
    nodeEnd.y = 0;

    MapSearchNode* nodeCurrent;

    astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

    do
    {
          SearchState = astarsearch.SearchStep(map);
    }
    while(SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

    nodeCurrent = astarsearch.GetSolutionStart();

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
            }
        }

        window.clear();

        map->DrawMap(&window, mousePos);
        cheese.setPosition(nodeEnd.x * 40, nodeEnd.y * 40);
        window.draw((cheese));
        rat.setPosition(nodeCurrent->x * 40, nodeCurrent->y * 40);
        window.draw(rat);

        window.display();

        if(nodeCurrent->x != nodeEnd.x || nodeCurrent->y != nodeEnd.y)
        {
            if(time.asSeconds() > 0.25)
            {
                clock.restart();
                nodeCurrent = astarsearch.GetSolutionNext();
            }
        }

        time = clock.getElapsedTime();
    }
}