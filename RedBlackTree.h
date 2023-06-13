#include <iostream>
#include <vector>
#include <algorithm>

#define BLACK 1
#define RED 0

using namespace std;

class RedBlackTree {

    private:

        struct Node {
            vector<string> value;
            bool color;
            Node *leftTree, *rightTree, *parent;

            Node() : color(RED), leftTree(NULL), rightTree(NULL), parent(NULL) { }        

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


        void insert(Node *p, vector<string> data);
        void insertCase(Node *p);


        Node *root, *NIL;

    public:

        RedBlackTree();
        void inorder();
        void insert(vector<string> x);
        vector<string> find(string x);

        vector<string> keyResult;
        vector<string> findKeyword(string x);
        void findKeyword(string x, Node *p);


    
};