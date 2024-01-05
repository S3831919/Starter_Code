#include "PathSolver.h"
#include <iostream>

PathSolver::PathSolver(){
    // TODO
    // Initialize any necessary variables here
    // This will be called when an instance of PathSolver is created
    nodesExplored = new NodeList(); 
    nodesOpen = new NodeList();   
    nodesClosed = new NodeList();   
    nodesActive = new NodeList();
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

    // Declare the start variable
    Node* empty = nullptr; 

    // Initialise Estimate Distance variable 
    int estimateDistance = 0;

    // Declare the Manhatten variable
    int manhatten = 0;

    // Declare the distanceCounter variable
    int distanceCounter = 0; 

    for (int row = 0; row < ENV_DIM; row++) {
        for (int col = 0; col < ENV_DIM; col++) {
         
            if(env[row][col] == SYMBOL_START){
                
                // Finds the start node and adds it to the nodesOpen list
                start = new Node(row, col, 0);
                nodesExplored->addElement(start);

                // sets the active node coordinates to start
                p->setRow(row);
                p->setCol(col);
                p->setDistanceTraveled(0);      

                std::cout << "Start Node = " << start->getRow() << "," << start->getCol() << std::endl;         

            }

            if((env[row][col] == SYMBOL_GOAL)){

                // Finds the goal node
                goal = new Node(row, col, 0);

                std::cout << "Goal Node = " << goal->getRow() << "," << goal->getCol() << std::endl;

                manhatten = std::abs(p->getCol() - goal->getCol()) + std::abs(p->getRow() - goal->getRow());

                while(p->getCol() != goal->getCol()){

                    if(env[p->getRow()][p->getCol() + 1] == SYMBOL_EMPTY || env[p->getRow()][p->getCol() + 1] == SYMBOL_GOAL){
                        
                        p = new Node(p->getRow(), p->getCol(), p->getDistanceTraveled());
                        nodesExplored->addElement(p);

                        p->setCol(p->getCol() + 1);
                        p->setDistanceTraveled(p->getDistanceTraveled() + 1);
                        // std::cout << p->getRow() << "," << p->getCol()  << "," << p->getDistanceTraveled() << std::endl;

                    }

                  

                    // std::cout << "Manhatten before = " << manhatten << std::endl; 

                    manhatten = manhatten + p->getDistanceTraveled();

                    // std::cout << "Manhatten after = " << manhatten << std::endl;

                }     
                
                while(p->getRow() != goal->getRow()){
                    
                    if(env[p->getRow() + 1][p->getCol()] == SYMBOL_EMPTY || env[p->getRow() + 1][p->getCol()] == SYMBOL_GOAL){
                      
                        p = new Node(p->getRow(), p->getCol(), p->getDistanceTraveled());
                        nodesExplored->addElement(p);

                        p->setRow(p->getRow() + 1);
                        p->setDistanceTraveled(p->getDistanceTraveled() + 1);
                        // std::cout << p->getRow() << "," << p->getCol()  << "," << p->getDistanceTraveled() << std::endl;

                      
                    }
                       manhatten = manhatten + p->getDistanceTraveled();
        
                } 

            }

            if(env[row][col] == SYMBOL_EMPTY){

                // Finds the empty nodes
                empty = new Node(row, col, 0);

                distanceCounter++;
                empty->setDistanceTraveled(distanceCounter); 

                // Add the empty node to the active list 
                nodesActive->addElement(empty); 

                }

            }
           
        }       

        // Testing - Delete prior to submission 
       
       
        // std::cout << "nodesExplored = " << nodesExplored->getNode(0)->getDistanceTraveled() << std::endl;
        // std::cout << "Estimated distance = " << estimateDistance << std::endl; 
        // std::cout << "p final = "<< p->getRow() << "," << p->getCol() << "," << p->getDistanceTraveled() << std::endl;
        // std::cout << "p right = "<< p->getRow() << "," << p->getCol() << "," << p->getDistanceTraveled() << std::endl;

    for(int i = 0; i < nodesExplored->getLength(); i++){
        std::cout << nodesExplored->getNode(i)->getRow() << "," << nodesExplored->getNode(i)->getCol() << std::endl;
    }

    
        std::cout << "Goal Node Found: " << p->getRow() << "," << p->getCol()  << " Number of steps: " << p->getDistanceTraveled() << std::endl;

 }

       
NodeList* PathSolver::getNodesExplored(){
    //TODO
    // Return a DEEP COPY of nodesExplored
    return nodesExplored;
}

NodeList* PathSolver::getPath(Env env){
    // TODO
    // Return a DEEP COPY of the path
    // for(int i = 0; i < nodesExplored->getLength(); i++){
     // std::cout << nodesExplored->getNode(i)->getRow() << "," << nodesExplored->getNode(i)->getCol() << std::endl;
    // }
    return nullptr;
}

//-----------------------------