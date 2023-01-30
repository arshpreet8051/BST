// Given a BST and a key K. If K is not present in the BST,
// Insert a new Node with a value equal to K into the BST. 
// Note: If K is already present in the BST, don't modify the BST.

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

node* insert_in_BST(node* root,int key){

    if(root == NULL){
        node* temp = new node(key);
        return temp;
    }

    else if(root->data==key){
        return root;
    }

    else if(root->data > key){
        insert_in_BST(root->left,key);
    }
    else{
        insert_in_BST(root->right,key);
    }
    return root;
}