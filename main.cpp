#include <iostream>
#include "RedBlackTree.cpp"

using namespace std;

int main(int argc, char const *argv[]){

    RedBlackTree *rbt = new RedBlackTree();

    rbt->insert(1);
    rbt->insert(2);
    rbt->insert(3);
    rbt->insert(4);
    rbt->insert(5);
    rbt->insert(6);
    rbt->insert(7);
    rbt->insert(8);
    rbt->insert(9);
    rbt->insert(10);
    
    rbt->inorder();
    rbt->inorder();
    
    return 0;
}
