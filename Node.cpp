#include "Node.h"
#include <iostream>

Node::Node(int row, int col, int dist_traveled)
{
    // TODO 
    // Constructor
    this->row = row;
    this->col = col;
    this->dist_traveled = dist_traveled;

}

Node::~Node(){
    // TODO
    // Destructor
    this->row = 0;
    this->col = 0;
    this->dist_traveled = 0;
}

int Node::getRow() {
    // TODO
    return row;
}

int Node::getCol(){
    // TODO
    return col;
}

int Node::getDistanceTraveled(){
    // TODO
    return dist_traveled;
}

void Node::setDistanceTraveled(int dist_traveled)
{
    // TODO
    this->dist_traveled = dist_traveled;
    return;
}

int Node::getEstimatedDist2Goal(Node* goal){
    // TODO
    return 0;

}
    
//--------------------------------                             