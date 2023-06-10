// Searching on a B+ tree in C++

#include "Node.cpp"

// BP tree
class BPTree {
    public:
        Node *root;
        void insertInternal(int, Node *, Node *);
        Node *findParent(Node *, Node *);

        BPTree();
        void search(int);
        void insert(int);
        void display(Node *);
        Node *getRoot();
};

