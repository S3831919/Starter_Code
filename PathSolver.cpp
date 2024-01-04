#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){
    // TODO
    // Initialize any necessary variables here
    // This will be called when an instance of PathSolver is created
    nodesExplored = new NodeList(); 
    nodesOpen = new NodeList();   
}

PathSolver::~PathSolver(){
    // TODO
    // Free any dynamically allocated memory here
    // This will be called when an instance of PathSolver is destroyed
    delete nodesExplored;

}

void PathSolver::forwardSearch(Env env){
    // TODO 
    // Implement the forward search algorithm here
    // Save the nodes explored in nodesExplored

    // create the active node variable
    Node* p = new Node(0, 0, 0);

    // Declare the goal variable
    Node* goal = nullptr; 

    // Declare the start variable
    Node* start = nullptr; 

    // Declare the Manhatten variable
    int manhatten = 0;

    for (int row = 0; row < ENV_DIM; row++) {
        for (int col = 0; col < ENV_DIM; col++) {
         
            if(env[row][col] == SYMBOL_START){
                
                // Finds the start node and adds it to the nodesOpen list
                start = new Node(row, col, 0);
                nodesOpen->addElement(start);

                // sets the active node coordinates to start
                p->setRow(row);
                p->setCol(col);
                p->setDistanceTraveled(1);

                // Add the already explored node to the nodesExplored list
                nodesExplored->addElement(p);

            }

            if((env[row][col] == SYMBOL_GOAL)){

                // Finds the goal node
                goal = new Node(row, col, 0);
             
                manhatten = (p->getCol() - goal->getCol()) + (p->getRow() - goal->getRow());
            
                std::cout << "manhatten = " << manhatten << std::endl;

            }

        }

    }

        // Testing - Delete prior to submission 
        std::cout << "p = "<< p->getRow() << "," << p->getCol() << "," << p->getDistanceTraveled() << std::endl;
        std::cout << "Goal = " << goal->getRow() << "," << goal->getCol() << std::endl;
        std::cout << "Start = " << start->getRow() << "," << start->getCol() << std::endl;
        std::cout << "nodesExplored = " << nodesExplored->getNode(0)->getDistanceTraveled() << std::endl;

 }

       
NodeList* PathSolver::getNodesExplored(){
    //TODO
    // Return a DEEP COPY of nodesExplored
    return nodesExplored;
}

NodeList* PathSolver::getPath(Env env){
    // TODO
    // Return a DEEP COPY of the path
    for(int i = 0; i < nodesExplored->getLength(); i++){
        std::cout << nodesExplored->getNode(i)->getRow() << "," << nodesExplored->getNode(i)->getCol() << std::endl;
    }
    return nullptr;
}

//-----------------------------