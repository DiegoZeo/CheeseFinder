#include <SFML/Graphics.hpp>

// The world map

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 20;

int world_map[ MAP_WIDTH * MAP_HEIGHT ] =
        {

// 0001020304050607080910111213141516171819
                1,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 00
                1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,   // 01
                1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 02
                1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 03
                1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 04
                1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 05
                1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 06
                1,9,9,9,9,9,9,9,9,1,1,1,9,9,9,9,9,9,9,1,   // 07
                1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 08
                1,9,1,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,1,   // 09
                1,9,1,1,1,1,9,1,1,9,1,1,1,1,1,1,1,1,1,1,   // 10
                1,9,9,9,9,9,1,9,1,9,1,9,9,9,9,9,1,1,1,1,   // 11
                1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 12
                1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 13
                1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 14
                1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 15
                1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 16
                1,1,9,9,9,9,9,9,9,1,1,1,9,9,9,1,9,9,9,9,   // 17
                1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 18
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 19

        };

int GetMap( int x, int y )
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

int main()
{
    sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;
    auto window = sf::RenderWindow{ { 800u, 800u }, "ChesseFinder", style};
    window.setFramerateLimit(144);

    sf::RectangleShape cell(sf::Vector2f (40,40));
    sf::Vector2 mousePos(0,0);


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
                    mousePos = sf::Vector2(event.mouseMove.x, event.mouseMove.y);
            }
        }

        window.clear();

        for(int i = 0; i<MAP_HEIGHT; i++)
        {
            for(int j = 0; j<MAP_HEIGHT; j++)
            {
                if (GetMap(j,i) == 1)
                    cell.setFillColor(sf::Color::White);
                else
                    cell.setFillColor(sf::Color::Black);
                if (i == mousePos.y/40 && j == mousePos.x/40)
                    cell.setFillColor(sf::Color::Green);
                cell.setPosition(j * MAP_HEIGHT * 2, i * MAP_WIDTH * 2);
                window.draw(cell);
            }
        }
        window.display();
    }
}