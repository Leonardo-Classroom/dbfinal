#pragma once
#include "RedBlackTree.h"

void RedBlackTree::rotateRight(Node *p){

    Node *gp=p->grandparent();
    Node *fa=p->parent;
    Node *y=p->rightTree;

    fa->leftTree=y;

    if(y!=NIL){
        y->parent=fa;
    }
    p->rightTree=fa;
    fa->parent=p;

    if(root==fa){
        root=p;
    }
    p->parent=gp;

    if(gp!=NULL){
        if(gp->leftTree==fa){
            gp->leftTree=p;
        }else{
            gp->rightTree=p;
        }    
    }

}

void RedBlackTree::rotateLeft(Node *p){

    if(p->parent==NULL){
        root = p;
        return;
    }

    Node *gp=p->grandparent();
    Node *fa=p->parent;
    Node *y=p->leftTree;

    fa->rightTree=y;

    if(y!=NIL){
        y->parent=fa;
    }
    p->leftTree=fa;
    fa->parent=p;

    if(root==fa){
        root=p;
    }
    p->parent=gp;

    if(gp!=NULL){
        if(gp->leftTree==fa){
            gp->leftTree=p;
        }else{
            gp->rightTree=p;
        }
    }
}

void RedBlackTree::inorder(Node *p){

    if(p==NIL){
        return;
    }
        
    if(p->leftTree){
        inorder(p->leftTree);
    }

    cout<<p->value<<" ";
            
    if(p->rightTree){
        inorder(p->rightTree);
    }       
}

string RedBlackTree::outputColor (bool color){
    return color?"BLACK":"RED";
}

RedBlackTree::Node* RedBlackTree::getSmallestChild(RedBlackTree::Node *p){

    if(p->leftTree == NIL){
        return p;
    }

    return getSmallestChild(p->leftTree);
}



void RedBlackTree::insert(Node *p, int data){

    if(p->value>=data){
        if(p->leftTree!=NIL){
            insert(p->leftTree, data);
        }else{
            Node *tmp=new Node();
            tmp->value=data;
            tmp->leftTree=tmp->rightTree = NIL;
            tmp->parent=p;
            p->leftTree=tmp;
            insertCase(tmp);
        }
    }else{
        if(p->rightTree != NIL){
            insert(p->rightTree, data);
        }else{
            Node *tmp=new Node();
            tmp->value=data;
            tmp->leftTree=tmp->rightTree=NIL;
            tmp->parent=p;
            p->rightTree=tmp;
            insertCase(tmp);
        }
    }
}

void RedBlackTree::insertCase(Node *p){
    if(p->parent==NULL){
        root=p;
        p->color=BLACK;
        return;
    }
    if(p->parent->color==RED){
        if(p->uncle()->color==RED){
            p->parent->color=p->uncle()->color=BLACK;
            p->grandparent()->color=RED;
            insertCase(p->grandparent());
        }else{
            if(
                p->parent->rightTree==p && 
                p->grandparent()->leftTree==p->parent
            ){
                rotateLeft(p);
                p->color=BLACK;
                p->parent->color=RED;
                rotateRight(p);
            }else if(
                p->parent->leftTree==p && 
                p->grandparent()->rightTree==p->parent
            ){
                rotateRight(p);
                p->color = BLACK;
                p->parent->color=RED;
                rotateLeft(p);
            }else if(
                p->parent->leftTree==p && 
                p->grandparent()->leftTree==p->parent
            ){
                p->parent->color=BLACK;
                p->grandparent()->color=RED;
                rotateRight(p->parent);
            } else if(
                p->parent->rightTree==p && 
                p->grandparent()->rightTree==p->parent
            ){
                p->parent->color=BLACK;
                p->grandparent()->color=RED;
                rotateLeft(p->parent);
            }
        }
    }
}



RedBlackTree::RedBlackTree(){
    NIL=new Node();
    NIL->color=BLACK;
    root=NULL;
}


void RedBlackTree::inorder() {
    if(root==NULL){
        return;
    }
    inorder(root);
    cout<<endl;
}

void RedBlackTree::insert(int x){
    if(root==NULL){
        root=new Node();
        root->color=BLACK;
        root->leftTree=root->rightTree=NIL;
        root->value=x;
    }else{
        insert(root, x);
    }
}

