#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#include "Types.h"
#include "Node.h"
#include "NodeList.h"
#include "PathSolver.h"

// Helper test functions
// void testNode();
// void testNodeList();

// Read a environment from standard input.
void readEnvStdin(Env env);

// Print out a Environment to standard output with path.
// To be implemented for Milestone 3
void printEnvStdout(Env env, NodeList* solution);

//  Real Main   
int main(int argc, char** argv){

    // Comment out before Submission 
    // testNode();
    // testNodeList();

    // Loads the Environment in to the Env object  
    Env env;

    // Read in the environment from stdin
    readEnvStdin(env);
    
    // Solve using forwardSearch
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 2
    // pathSolver pointer of PathSolver Class 
    PathSolver* pathSolver = new PathSolver();

    // Calls the forwardSearch function from PathSolver Class
    pathSolver->forwardSearch(env);

    // Creates a NodeList pointer and sets exploredPostions to nullptr to initialize
    NodeList* exploredPositions = nullptr;

    // exploredPositions is set to the return value of getNodesExplored() function
    exploredPositions = pathSolver->getNodesExplored();

    // Get the path
    // THIS WILL ONLY WORK IF YOU'VE FINISHED MILESTONE 3
    // Creates a NodeList pointer called solution and sets it to the return value from the getPath() function
    NodeList* solution = pathSolver->getPath(env);

    // Prints out the path - TODO
    printEnvStdout(env, solution);

    // Cleans up memory - TODO
    // delete pathSolver;
    // delete exploredPositions;
    // delete solution;

}

void readEnvStdin(Env env) {
    
    // reads in the environment from a file path 
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

// Function to print out the environment to the console 
void printEnvStdout(Env env, NodeList* solution) {

    std::cout << "Environment:" << std::endl;
    for (int row = 0; row < ENV_DIM; row++) {
        for (int col = 0; col < ENV_DIM; col++) {
            std::cout << env[row][col] << " ";
        }
        std::cout << std::endl;
    }
}


