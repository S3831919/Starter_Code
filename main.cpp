#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"

// Helper test functions
void testNode();
void testNodeList();

// Read a environment from standard input.
void readEnvStdin(Env env);

// Print out a Environment to standard output with path.
// To be implemented for Milestone 3
// void printEnvStdout(Env env, NodeList* solution);

//  Real Main   
int main(int argc, char** argv){

    // THESE ARE SOME EXAMPLE FUNCTIONS TO HELP TEST YOUR CODE
    // AS YOU WORK ON MILESTONE 2. YOU CAN UPDATE THEM YOURSELF
    // AS YOU GO ALONG.
    // COMMENT THESE OUT BEFORE YOU SUBMIT!!!
    // std::cout << "TESTING - COMMENT THE OUT TESTING BEFORE YOU SUBMIT!!!" << std::endl;
    testNode();
    testNodeList();
    // std::cout << "DONE TESTING" << std::endl << std::endl;

    // Load Environment 
    Env env;
    readEnvStdin(env);
    
    // Solve using forwardSearch
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    // PathSolver* pathSolver = new PathSolver();
    // pathSolver->forwardSearch(env);

    // NodeList* exploredPositions = nullptr;
    // exploredPositions = pathSolver->getNodesExplored();

    // Get the path
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    // NodeList* solution = pathSolver->getPath(env);

    // printEnvStdout(env, solution);

    // delete pathSolver;
    // delete exploredPositions;
    // delete solution;

 // Find thg Goal Node and Start Node
   for (int row = 0; row < ENV_DIM; row++) {
     for (int col = 0; col < ENV_DIM; col++) {
        if(env[row][col] == SYMBOL_GOAL){
            //prints out the Goal Node Location
            std::cout << "Goal: " << row << "," << col << std::endl;

            // std::cout << env[row][col] << " ";
        }
        else if(env[row][col] == SYMBOL_START){
            //prints out the Start Node Location
            std::cout << "Start: " << row << "," << col << std::endl;

            // std::cout << env[row][col] << " ";
        }
        //  std::cout << std::endl;
   }
   }

}

void readEnvStdin(Env env) {
    
    // read in the environment from stdin
    std::string filePath = "C:\\Git Repo\\Starter_Code\\sampleTest\\test01.env";
    std::ifstream file(filePath);

    // check if file is open
    if (file.is_open()) {

        for (int row = 0; row < ENV_DIM; row++) {
            for (int col = 0; col < ENV_DIM; col++) {
                file >> env[row][col];
            }
        }

        file.close();
    }
    // if file is not open
    else {
        std::cerr << "Failed to open file: " << filePath << std::endl;
    }
}


// void printEnvStdout(Env env, NodeList* solution) {

    // std::cout << "Environment:" << std::endl;
    // for (int row = 0; row < ENV_DIM; row++) {
    //     for (int col = 0; col < ENV_DIM; col++) {
    //         std::cout << env[row][col] << " ";
    //     }
    //     std::cout << std::endl;
    // }
// }

void testNode() {
    // std::cout << "TESTING Node" << std::endl;

    // Make a Node and print out the contents
    // Node* node = new Node(1, 1, 2);
    // std::cout << node->getRow() << ",";
    // std::cout << node->getCol() << ",";
    // std::cout << node->getDistanceTraveled() << std::endl;
    // delete node;

    // Change Node and print again
    // node = new Node(4, 2, 3);
    // std::cout << node->getRow() << ",";
    // std::cout << node->getCol() << ",";
    // std::cout << node->getDistanceTraveled() << std::endl;
    // delete node;
}

void testNodeList() {
    // std::cout << "TESTING NodeList" << std::endl;

    // Make a simple NodeList, should be empty size
    NodeList* nodeList = new NodeList();
     
    // std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Node* node = new Node(1, 1, 2);

    // Add a Node to the NodeList, print size
    // Node* b1 = new Node(1, 1, 1);
    // nodeList->addElement(b1);
    // std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

// Populate the NodeList with 400 Nodes
        int r = 0;
        int c = 0;
        int d = 0;

    for(int i = 0; i < 400 ; i++){

        Node* x = new Node(r, c, d);
        nodeList->addElement(x);

        r++;  
        c++;

        }

    }

    // Add second Nodetest
    // Node* b2 = new Node(0, 0, 1);
    // nodeList->addElement(b2);
    // std::cout << "NodeList size: " << nodeList->getLength() << std::endl;

    // Test Get-ith - should be 0,0,1
    // Node* getB = nodeList->getNode(0);
    // std::cout << getB->getCol() << std::endl;
    // std::cout << getB->getRow() << ",";
    // std::cout << getB->getCol() << ",";
    // std::cout << getB->getDistanceTraveled() << std::endl;

//     // Print out the NodeList
//     std::cout << "PRINTING OUT A NODELIST IS AN EXERCISE FOR YOU TO DO" << std::endl;

// TESTING - COMMENT THE OUT TESTING BEFORE YOU SUBMIT
// Prints the Node List
    // for(int i = 0; i < nodeList->getLength(); i++){
    //     std::cout << nodeList->getNode(i)->getRow() << ",";
    //     std::cout << nodeList->getNode(i)->getCol() << ",";
    //     std::cout << nodeList->getNode(i)->getDistanceTraveled() << std::endl;
    // }




    // Clean up memory