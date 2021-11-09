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
    root = removeNode(id, root);
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
} // End of clear

bool BinTree::addNode(DataNode *newNode, DataNode **root){
    bool didAdd = false;
    if(!(*root)){
        *root = newNode;
        didAdd = true;
    }
    else{
        if(newNode->data.id < (*root)->data.id){
            addNode(newNode, &(*root)->left);
        } else if (newNode->data.id > (*root)->data.id) {
            addNode(newNode, &(*root)->right);
        }
    }
    return didAdd;

} // End of addNode

DataNode* BinTree::removeNode(int id, DataNode *root){
    if(root){
        if(id < root->data.id){
            removeNode(id, root->left);
        } else if (id > root->data.id){
            removeNode(id, root->right);
        } else {
            DataNode *temp;
            if(root->left == nullptr){
                temp = root->right;
                delete root;
                root = temp;
                count--;
            } else if (root->right == nullptr){
                temp = root->left;
                delete root;
                root = temp;
                count--;
            } else {
                temp = minValueNode(root->right);
                root->data.id = temp->data.id;
                root->data.information = temp->data.information;
                root->right = removeNode(temp->data.id, root->right);
            }
        }
    }
    return root;
} // End of removeNode

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

bool BinTree::getNode(Data *data, int id, DataNode *temproot){
    bool gotNode = false;
    if(temproot){
        if (id == temproot->data.id) {
            data->id = temproot->data.id;
            data->information = temproot->data.information;
            gotNode = true;
        } else {
            if (id < temproot->data.id) {
                contains(id, temproot->left);
            } else {
                contains(id, temproot->right);
            }
        }
    }
    if(!gotNode){
        data->id = -1;
        data->information = "";
    }
    return gotNode;
} // End of getNode

bool BinTree::contains(int id, DataNode *temproot){
    bool contained = false;
    if(temproot){
        if (id == temproot->data.id) {
            contained = true;
        } else {
            if (id < temproot->data.id) {
                contains(id, temproot->left);
            } else {
                contains(id, temproot->right);
            }
        }
    }
    return contained;
} // End of contains

int BinTree::getHeight(DataNode *temproot){
    int lh = 0, rh = 0, height = 0;
    if(root){
        if(lh > rh){
            height = lh + 1;
        } else {
            height = rh + 1;
        }
        getHeight(temproot->left);
        getHeight(temproot->right);
    }
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



