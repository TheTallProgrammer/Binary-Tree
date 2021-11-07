/*
 * Your comment header here
 */

#include "bintree.h"

// Constructor/Destructor
BinTree::BinTree(){
    root = nullptr;
    count = 0;
} // End of constructor

BinTree::~BinTree(){
    clear();
} // End of destructor


// Public methods
bool BinTree::isEmpty(){return root;} // End of isEmpty

int BinTree::getCount(){return count;} // End of getCount

bool BinTree::getRootData(Data *data){
    if(root){
        data->id = root->data.id;
        data->information = root->data.information;
    } else {
        data->id = -1;
        data->information = "";
    }
    return root;
} // End of getRootData

void BinTree::displayTree(){
    displayPreOrder();
    displayInOrder();
    displayPostOrder();
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
void BinTree::clear(DataNode *temproot){
    if(root){
        clear(root->left);
        clear(root->right);
        root->left = nullptr;
        root->right = nullptr;
        delete root;
        count--;
    }
} // End of clear

bool BinTree::addNode(DataNode *temproot, DataNode **rootadd){
    bool didAdd = false;
    return didAdd;

} // End of addNode

DataNode* BinTree::removeNode(int id, DataNode *temproot){
    return nullptr;
} // End of removeNode

bool BinTree::getNode(Data *data, int id, DataNode *temproot){
    bool gotNode = false;
    return gotNode;
} // End of getNode

bool BinTree::contains(int id, DataNode *temproot){
    bool contained = false;
    return contained;
} // End of contains

int BinTree::getHeight(DataNode *temproot){
    int height;
    return height;
} // End of getHeight

void BinTree::displayPreOrder(DataNode *temproot){
    if(temproot){
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
        displayInOrder(temproot->left);
        displayInOrder(temproot->right);
    }
} // End of displayPreOrder

void BinTree::displayInOrder(DataNode *temproot){
    if(temproot){
        displayInOrder(temproot->left);
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
        displayInOrder(temproot->right);
    }
} // End of displayInOrder

void BinTree::displayPostOrder(DataNode *temproot){
    if(temproot){
        displayInOrder(temproot->left);
        displayInOrder(temproot->right);
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
    }
} // End of displayPostOrder



