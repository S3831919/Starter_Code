#include "NodeList.h"
#include <iostream>

NodeList::NodeList(){
    // TODO
    NodeList::length = 0; 
}

NodeList::~NodeList(){
    // TODO
    NodeList::length = NODE_LIST_ARRAY_MAX_SIZE; 
}

NodeList::NodeList(NodeList& other){
    // TODO 
}

int NodeList::getLength(){
    // TODO
    return length;
}

void NodeList::addElement(Node* newPos){
    // TODO
    nodes[length] = newPos;
    length++;
    return;
}

Node* NodeList::getNode(int i){
    // TODO
    return nodes[i];
}