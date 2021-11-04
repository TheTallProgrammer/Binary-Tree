/*
 * Your comment header here
 */

#include "bintree.h"

// Constructor/Destructor
BinTree::BinTree(){

} // End of constructor

BinTree::~BinTree(){

} // End of destructor


// Public methods
bool BinTree::isEmpty(){
    bool isEmpt = false;
    return isEmpt;
} // End of isEmpty

int BinTree::getCount(){return count;} // End of getCount

bool BinTree::getRootData(Data *data){
    bool gotRootData = false;
    return gotRootData;
} // End of getRootData

void BinTree::diplayTree(){

} // End of displayTree


// Public methods that will call overload methods
void BinTree::clear() {
    clear(root);
} // End of clear

bool BinTree::addNode(int id, const string *data){
    addNode(root->data.id, &root->data.information);
} // End of addNode

bool BinTree::removeNode(int id){
    removeNode(id, root);
} // End of removeNode

bool BinTree::getNode(Data *data, int id){
    getNode(data, id, root);
} // End of getNode

bool BinTree::contains(int id){
    contains(id, root);
} // End of contains

int BinTree::getHeight(){
    getHeight(root);
} // End of getHeight

void BinTree::displayPreOrder(){
    displayPreOrder(root);
} // End of displayPreOrder

void BinTree::displayPostOrder(){
    displayPostOrder(root);
} // End of displayPostOrder

void BinTree::displayInOrder(){
    displayInOrder(root);
} // End of displayInOrder


// Overload methods
void BinTree::clear(DataNode *){

} // End of clear

bool BinTree::addNode(DataNode *, DataNode **){

} // End of addNode

DataNode* BinTree::removeNode(int, DataNode *){

} // End of removeNode

bool BinTree::getNode(Data *, int, DataNode *){

} // End of getNode

bool BinTree::contains(int, DataNode *){

} // End of contains

int BinTree::getHeight(DataNode *){

} // End of getHeight

void BinTree::displayPreOrder(DataNode *){

} // End of displayPreOrder

void BinTree::displayPostOrder(DataNode *){

} // End of displayPostOrder

void BinTree::displayInOrder(DataNode *){

} // End of displayInOrder

