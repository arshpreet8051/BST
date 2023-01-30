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

// 2 approaches 

//recursive

bool search_in_BST(node* root,int x){

    if(root==NULL){return false;}

    if(root->data == x){return true;}

    if(root->data > x){
        search_in_BST(root->left,x);
    }
    else{
        search_in_BST(root->right,x);
    }
}

// iterative


bool search_in_BST_iterative(node* root,int x){

    node* temp = root;

    while(!temp!=NULL){
        
        if(temp->data == x){return true;}

        else if(temp->data > x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}