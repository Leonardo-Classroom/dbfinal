#include <iostream>

#define BLACK 1
#define RED 0

using namespace std;

class RedBlackTree {

    private:

        struct Node {
            int value;
            bool color;
            Node *leftTree, *rightTree, *parent;

            Node() : value(0), color(RED), leftTree(NULL), rightTree(NULL), parent(NULL) { }        

            Node* grandparent() {
                if(parent == NULL){
                    return NULL;
                }
                return parent->parent;
            }

            Node* uncle() {
                if(grandparent() == NULL) {
                    return NULL;
                }
                if(parent == grandparent()->rightTree)
                    return grandparent()->leftTree;
                else
                    return grandparent()->rightTree;
            }

            Node* sibling() {
                if(parent->leftTree == this)
                    return parent->rightTree;
                else
                    return parent->leftTree;
            }
        };

        void rotateRight(Node *p);
        void rotateLeft(Node *p);
        void inorder(Node *p);

        string outputColor (bool color);
        Node* getSmallestChild(Node *p);

        bool deleteChild(Node *p, int data);
        void deleteOneChild(Node *p);
        void deleteCase(Node *p);
        void insert(Node *p, int data);
        void insertCase(Node *p);
        void DeleteTree(Node *p);

        Node *root, *NIL;

    public:

        RedBlackTree();
        ~RedBlackTree();
        void inorder();
        void insert(int x);
        bool deleteValue(int data);

    
};