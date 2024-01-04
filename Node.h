#ifndef COSC_ASSIGN_ONE_NODE
#define COSC_ASSIGN_ONE_NODE

#include "Types.h"

class Node{
public:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */

    // Constructor/Desctructor
    Node(int row, int col, int dist_traveled);
    ~Node();

    // get row-coodinate of the node
    int getRow();

    // get column-coodinate of the node
    int getCol();

    //getter and setter for distance traveled
    int getDistanceTraveled();
    void setDistanceTraveled(int dist_traveled);

    //getter for estimated dist to goal - need to return -> Manhatten distance + distance traveled
    int getEstimatedDist2Goal(Node* goal);

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

    // GRLA - setter for row and col - Each node is created each time so may not need setters 
    int setRow(int row){
        this->row = row;
        return row;
    }

     int setCol(int col){
        this->col = col;
        return col;
    }


private:
    /*                                           */
    /* DO NOT MOFIFY THESE VARIABLES             */
    /*                                           */

    int row;
    int col;
    int dist_traveled;  // distance from start node

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */

    Node* start;
    Node* goal;

};

#endif //COSC_ASSIGN_ONE_NODE