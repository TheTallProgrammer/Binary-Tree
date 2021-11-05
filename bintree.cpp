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

void BinTree::displayTree(){

} // End of displayTree


// Public methods that will call overload methods
void BinTree::clear() {
    clear(root);
} // End of clear

bool BinTree::addNode(int id, const string *data){
    root->data.id = id;
    root->data.information = *data;
    bool didAdd = addNode(root->data.id, &root->data.information);
    return didAdd;
} // End of addNode

bool BinTree::removeNode(int id){
    bool didRemove = removeNode(id, root);
    return didRemove;
} // End of removeNode

bool BinTree::getNode(Data *data, int id){
    bool gotNode = getNode(data, id, root);
    return gotNode;
} // End of getNode

bool BinTree::contains(int id){
    bool contained = contains(id, root);
    return contained;
} // End of contains

int BinTree::getHeight(){
   return getHeight(root);
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
    bool didAdd = false;
    return didAdd;

} // End of addNode

DataNode* BinTree::removeNode(int, DataNode *){
    return nullptr;
} // End of removeNode

bool BinTree::getNode(Data *, int, DataNode *){
    bool gotNode = false;
    return gotNode;
} // End of getNode

bool BinTree::contains(int, DataNode *){
    bool contained = false;
    return contained;
} // End of contains

int BinTree::getHeight(DataNode *){
    int height;
    return height;
} // End of getHeight

void BinTree::displayPreOrder(DataNode *){

} // End of displayPreOrder

void BinTree::displayPostOrder(DataNode *){

} // End of displayPostOrder

void BinTree::displayInOrder(DataNode *){

} // End of displayInOrder

