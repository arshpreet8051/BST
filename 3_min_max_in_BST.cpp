#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

// min value will be the left most node in BST
// max value will be the right most node in BST

node* get_min(node* root){
    
    if(root == NULL){return NULL;}

    node* temp = root;

    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

node* get_max(node* root){

    if(root == NULL){return NULL;}

    node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}