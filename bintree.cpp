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
bool BinTree::isEmpty(){
    bool isEmpty = true;
    if(root){
        isEmpty = false;
    }
    return isEmpty;
} // End of isEmpty

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
    std::cout << "DISPLAY TREE\n=============================================="<< std::endl;
    if(isEmpty()){
        std::cout << "Tree is empty" << std::endl;
    } else {
        std::cout << "Tree is NOT empty" << std::endl;
    }
    std::cout << "Height: " << getHeight() << std::endl;
    std::cout << "Node Count: " << getCount() << std::endl;
    std::cout << "\nPre-Order Traversal" << std::endl;
    displayPreOrder();
    std::cout << "\nIn-Order Traversal" << std::endl;
    displayInOrder();
    std::cout << "\nPost-Order Traversal" << std::endl;
    displayPostOrder();
    std::cout << "==============================================" << std::endl;
} // End of displayTree


// Public methods that will call overload methods
void BinTree::clear() {
    clear(root);
} // End of clear

bool BinTree::addNode(int id, const string *data){
    bool didAdd = false;
    if(id > 0 && data->length() > 0){
        DataNode *newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *data;
        didAdd = addNode(newNode, &root);
        if(didAdd){
            count++;
        }
    }
    return didAdd;
} // End of addNode

bool BinTree::removeNode(int id){
    bool didRemove = false;
    int tempCount = count;
//    root = removeNode(id, root);
    if(count < tempCount){
        didRemove = true;
    }
    return didRemove;
} // End of removeNode

bool BinTree::getNode(Data *data, int id){
    bool gotNode = false;
    if(id > 0){
        gotNode = getNode(data, id, root);
    }
    return gotNode;
} // End of getNode

bool BinTree::contains(int id){
    bool contained = false;
    if(id > 0){
        contained = contains(id, root);
    }

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
    if(temproot){
        clear(temproot->left);
        clear(temproot->right);
        temproot->left = nullptr;
        temproot->right = nullptr;
        delete temproot;
        count--;
    }
    return;
} // End of clear

bool BinTree::addNode(DataNode *newNode, DataNode **temproot){
    bool didAdd = false;
    if(!(*temproot)){
        (*temproot) = newNode;
        didAdd = true;
    } else {
        if(newNode->data.id < (*temproot)->data.id){
            didAdd = addNode(newNode, &(*temproot)->left);
        }
        else if (newNode->data.id > (*temproot)->data.id) {
            didAdd = addNode(newNode, &(*temproot)->right);
        }
    }
    return didAdd;

} // End of addNode

DataNode* BinTree::removeNode(int id, DataNode *temproot){
    if(temproot){
        if(id < temproot->data.id){
            temproot->left = removeNode(id, temproot->left);
        } else if (id > root->data.id){
            temproot->right = removeNode(id, temproot->right);
        } else {
            DataNode *temp;
            if(temproot->left == nullptr){
                temp = temproot->right;
                delete temproot;
                temproot = temp;
                temproot--;
            } else if (temproot->right == nullptr){
                temp = temproot->left;
                delete temproot;
                temproot = temp;
                count--;
            } else {
                temp = minValueNode(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }
    }
    return temproot;
} // End of removeNode

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
} // End of minValueNode

bool BinTree::contains(int id, DataNode *temproot){
    bool contained = false;
    if(temproot){
        if (id == temproot->data.id) {
            contained = true;
        } else {
            if (id < temproot->data.id) {
                contained = contains(id, temproot->left);
            } else {
                contained = contains(id, temproot->right);
            }
        }
    }
    return contained;
} // End of contains

bool BinTree::getNode(Data *data, int id, DataNode *temproot){
    bool gotNode = false;
    if(temproot){
        if (id == temproot->data.id) {
            data->id = temproot->data.id;
            data->information = temproot->data.information;
            gotNode = true;
        } else {
            if (id < temproot->data.id) {
                gotNode = getNode(data, id, temproot->left);
            } else {
                gotNode = getNode(data, id, temproot->right);
            }
        }
    }
    if(!gotNode){
        data->id = -1;
        data->information = "";
    }
    return gotNode;
} // End of getNode

int BinTree::getHeight(DataNode *temproot){
    int lh = 0, rh = 0, maxHeight = 0;
    if(temproot){
        lh = getHeight(temproot->left);
        rh = getHeight(temproot->right);
        maxHeight = std::max(lh,rh) +1;
    }
    return maxHeight;
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



