//
// Created by dazeo on 29/05/2024.
//

#include "Rat.h"

void Rat::FindNewPath(GameMap* map)
{
    aStarSearch.SetStartAndGoalStates(*position , nodeEnd);
    do
    {
        SearchState = aStarSearch.SearchStep(map);
    }
    while(SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);
    position = aStarSearch.GetSolutionStart();
}

void Rat::Step()
{
    position = aStarSearch.GetSolutionNext();
}

Rat::Rat(MapSearchNode start, MapSearchNode end, GameMap* map) : nodeStart(start) , nodeEnd(end)
{
    aStarSearch.SetStartAndGoalStates(start, end);
    do
    {
        SearchState = aStarSearch.SearchStep(map);
    }
    while(SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

    position = aStarSearch.GetSolutionStart();
}

void Rat::Draw(sf::RenderWindow* window)
{
    sf::CircleShape rat(16);
    rat.setFillColor(sf::Color::Magenta);
    rat.setPosition(position->x * 40, position->y * 40);
    window->draw(rat);
}
