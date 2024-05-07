//
// Created by dazeo on 07/05/2024.
//

#ifndef CHEESEFINDER_MAPSEACHNODE_H
#define CHEESEFINDER_MAPSEACHNODE_H

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

#include "GameMap.h"
#include "MapSeachNode.h"
#include "stlastar.h"

class MapSearchNode
{
public:
    MapSearchNode();
    MapSearchNode( int px, int py );

    float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    bool IsGoal( MapSearchNode &nodeGoal );
    bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node , GameMap* map);
    float GetCost( MapSearchNode &successor , GameMap* map);
    bool IsSameState( MapSearchNode &rhs );
    size_t Hash();

    void PrintNodeInfo();

    int x;	 // the (x,y) positions of the node
    int y;
};


#endif //CHEESEFINDER_MAPSEACHNODE_H
