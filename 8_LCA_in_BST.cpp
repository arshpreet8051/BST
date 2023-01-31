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
 

// __________________________ LOGIC ___________________________

// as inorder of BST is sorted
// find a node which is smaller than one target node and greater than another target node

node* LCA_BST_recursive(node* root,int n1,int n2){

    if(root==NULL){return NULL;}

    if(root->data > n1 and root->data > n2){ // means root is greater, find in left
        return LCA_BST_recursive(root->left,n1,n2);
    }

    else if(root->data < n1 and root->data < n2){ // means root is smaller, find in right
        return LCA_BST_recursive(root->right,n1,n2);
    }

    else{ // we got the LCA root
        return root;
    }

}

// Iterative

node* LCA_BST_iterative(node* root,int n1,int n2){

    while(root!=NULL){

        if(root->data < n1 and root->data <n2){
            root = root->right;
        }

        else if(root->data > n1 and root->data > n2){
            root=root->left;
        }
        else{
            return root;
        }

    }

}