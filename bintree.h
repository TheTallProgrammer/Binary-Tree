/*
 * Your comment header here
 */

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H
#include "data.h"

class BinTree{

    public:
        // Constructor/Destructor
        BinTree();
        ~BinTree();

        // Public Methods
        bool isEmpty();
        int getCount();
        bool getRootData(Data *);
        void displayTree();

        void clear();
        bool addNode(int, const string *);
        bool removeNode(int);
        bool getNode(Data *, int);
        bool contains(int);
        int getHeight();
        void displayPreOrder();
        void displayPostOrder();
        void displayInOrder();

        void clear(DataNode *);
        bool addNode(DataNode *, DataNode **);
        DataNode* removeNode(int, DataNode *);
        bool getNode(Data *, int, DataNode *);
        bool contains(int, DataNode *);
        int getHeight(DataNode *);
        void displayPreOrder(DataNode *);
        void displayPostOrder(DataNode *);
        void displayInOrder(DataNode *);

    private:
        DataNode *root;
        int count;

};


#endif /* BINTREE_BINTREE_H */

