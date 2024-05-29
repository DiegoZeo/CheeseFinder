//
// Created by dazeo on 29/05/2024.
//

#ifndef CHEESEFINDER_RAT_H
#define CHEESEFINDER_RAT_H

#include "GameMap.h"
#include "MapSeachNode.h"
#include "stlastar.h"

class Rat {
public:
    explicit Rat(MapSearchNode start, MapSearchNode end, GameMap* map);

    void FindNewPath(GameMap* map);

    void Step();

    void Draw(sf::RenderWindow* window);

    AStarSearch<MapSearchNode> aStarSearch;
    unsigned int SearchState{};
    MapSearchNode nodeStart;
    MapSearchNode nodeEnd;
    MapSearchNode* position;
};


#endif //CHEESEFINDER_RAT_H
