#pragma once
#include "RedBlackTree.h"

void RedBlackTree::rotate_right(Node *p){
    Node *gp = p->grandparent();
    Node *fa = p->parent;
    Node *y = p->rightTree;

    fa->leftTree = y;

    if(y != NIL)
        y->parent = fa;
    p->rightTree = fa;
    fa->parent = p;

    if(root == fa)
        root = p;
    p->parent = gp;

    if(gp != NULL){
        if(gp->leftTree == fa)
            gp->leftTree = p;
        else
            gp->rightTree = p;
    }

}

void RedBlackTree::rotate_left(Node *p){
    if(p->parent == NULL){
        root = p;
        return;
    }
    Node *gp = p->grandparent();
    Node *fa = p->parent;
    Node *y = p->leftTree;

    fa->rightTree = y;

    if(y != NIL)
        y->parent = fa;
    p->leftTree = fa;
    fa->parent = p;

    if(root == fa)
        root = p;
    p->parent = gp;

    if(gp != NULL){
        if(gp->leftTree == fa)
            gp->leftTree = p;
        else
            gp->rightTree = p;
    }
}

void RedBlackTree::inorder(Node *p){
    if(p == NIL)
        return;

    if(p->leftTree)
        inorder(p->leftTree);

    cout << p->value << " ";
            
    if(p->rightTree)
        inorder(p->rightTree);
}

string RedBlackTree::outputColor (bool color) {
    return color ? "BLACK" : "RED";
}

RedBlackTree::Node* RedBlackTree::getSmallestChild(RedBlackTree::Node *p){
    if(p->leftTree == NIL)
        return p;
    return getSmallestChild(p->leftTree);
}

bool RedBlackTree::delete_child(Node *p, int data){
    if(p->value > data){
        if(p->leftTree == NIL){
            return false;
        }
        return delete_child(p->leftTree, data);
    } else if(p->value < data){
        if(p->rightTree == NIL){
            return false;
        }
        return delete_child(p->rightTree, data);
    } else if(p->value == data){
        if(p->rightTree == NIL){
            delete_one_child (p);
            return true;
        }
        Node *smallest = getSmallestChild(p->rightTree);
        swap(p->value, smallest->value);
        delete_one_child (smallest);

        return true;
    }else{
        return false;
        }
}

void RedBlackTree::delete_one_child(Node *p){
    Node *child = p->leftTree == NIL ? p->rightTree : p->leftTree;
    if(p->parent == NULL && p->leftTree == NIL && p->rightTree == NIL){
        p = NULL;
        root = p;
        return;
    }
    
    if(p->parent == NULL){
        delete  p;
        child->parent = NULL;
        root = child;
        root->color = BLACK;
        return;
    }
    
    if(p->parent->leftTree == p){
        p->parent->leftTree = child;
    } else {
        p->parent->rightTree = child;
    }
    child->parent = p->parent;

    if(p->color == BLACK){
        if(child->color == RED){
            child->color = BLACK;
        } else
            delete_case (child);
    }

    delete p;
}

void RedBlackTree::delete_case(Node *p){
    if(p->parent == NULL){
        p->color = BLACK;
        return;
    }
    if(p->sibling()->color == RED) {
        p->parent->color = RED;
        p->sibling()->color = BLACK;
        if(p == p->parent->leftTree)
            //rotate_left(p->sibling());
            rotate_left(p->parent);
        else
            //rotate_right(p->sibling());
            rotate_right(p->parent);
    }
    if(p->parent->color == BLACK && p->sibling()->color == BLACK
            && p->sibling()->leftTree->color == BLACK && p->sibling()->rightTree->color == BLACK) {
        p->sibling()->color = RED;
        delete_case(p->parent);
    } else if(p->parent->color == RED && p->sibling()->color == BLACK
            && p->sibling()->leftTree->color == BLACK && p->sibling()->rightTree->color == BLACK) {
        p->sibling()->color = RED;
        p->parent->color = BLACK;
    } else {
        if(p->sibling()->color == BLACK) {
            if(p == p->parent->leftTree && p->sibling()->leftTree->color == RED
                    && p->sibling()->rightTree->color == BLACK) {
                p->sibling()->color = RED;
                p->sibling()->leftTree->color = BLACK;
                rotate_right(p->sibling()->leftTree);
            } else if(p == p->parent->rightTree && p->sibling()->leftTree->color == BLACK
                    && p->sibling()->rightTree->color == RED) {
                p->sibling()->color = RED;
                p->sibling()->rightTree->color = BLACK;
                rotate_left(p->sibling()->rightTree);
            }
        }
        p->sibling()->color = p->parent->color;
        p->parent->color = BLACK;
        if(p == p->parent->leftTree){
            p->sibling()->rightTree->color = BLACK;
            rotate_left(p->sibling());
        } else {
            p->sibling()->leftTree->color = BLACK;
            rotate_right(p->sibling());
        }
    }
}

void RedBlackTree::insert(Node *p, int data){
    if(p->value >= data){
        if(p->leftTree != NIL)
            insert(p->leftTree, data);
        else {
            Node *tmp = new Node();
            tmp->value = data;
            tmp->leftTree = tmp->rightTree = NIL;
            tmp->parent = p;
            p->leftTree = tmp;
            insert_case (tmp);
        }
    } else {
        if(p->rightTree != NIL)
            insert(p->rightTree, data);
        else {
            Node *tmp = new Node();
            tmp->value = data;
            tmp->leftTree = tmp->rightTree = NIL;
            tmp->parent = p;
            p->rightTree = tmp;
            insert_case (tmp);
        }
    }
}

void RedBlackTree::insert_case(Node *p){
    if(p->parent == NULL){
        root = p;
        p->color = BLACK;
        return;
    }
    if(p->parent->color == RED){
        if(p->uncle()->color == RED) {
            p->parent->color = p->uncle()->color = BLACK;
            p->grandparent()->color = RED;
            insert_case(p->grandparent());
        } else {
            if(p->parent->rightTree == p && p->grandparent()->leftTree == p->parent) {
                rotate_left(p);
                p->color = BLACK;
                p->parent->color = RED;
                rotate_right(p);
            } else if(p->parent->leftTree == p && p->grandparent()->rightTree == p->parent) {
                rotate_right(p);
                p->color = BLACK;
                p->parent->color = RED;
                rotate_left(p);
            } else if(p->parent->leftTree == p && p->grandparent()->leftTree == p->parent) {
                p->parent->color = BLACK;
                p->grandparent()->color = RED;
                rotate_right(p->parent);
            } else if(p->parent->rightTree == p && p->grandparent()->rightTree == p->parent) {
                p->parent->color = BLACK;
                p->grandparent()->color = RED;
                rotate_left(p->parent);
            }
        }
    }
}

void RedBlackTree::DeleteTree(Node *p){
    if(!p || p == NIL){
        return;
    }
    DeleteTree(p->leftTree);
    DeleteTree(p->rightTree);
    delete p;
}

RedBlackTree::RedBlackTree() {
    NIL = new Node();
    NIL->color = BLACK;
    root = NULL;
}

RedBlackTree::~RedBlackTree() {
    if (root)
        DeleteTree (root);
    delete NIL;
}

void RedBlackTree::inorder() {
    if(root == NULL)
        return;
    inorder (root);
    cout << endl;
}

void RedBlackTree::insert (int x) {
    if(root == NULL){
        root = new Node();
        root->color = BLACK;
        root->leftTree = root->rightTree = NIL;
        root->value = x;
    } else {
        insert(root, x);
    }
}

bool RedBlackTree::delete_value (int data) {
    return delete_child(root, data);
}