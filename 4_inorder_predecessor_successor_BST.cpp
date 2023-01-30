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

// Note                  -------> Inorder traversal of BST is always sorted
// Successor of a node   -------> Imediate greater value node
// Predecessor of a node -------> Imediate smaller value node

node* inorder_successor(node* root,int key){
    if(root == NULL){return NULL;}

    node* suc = NULL;

    while(root!=NULL){

        if(root->data > key){ // greater value means can be a worthy candidate
            suc = root;
            root = root->left; // moved left to find imediate greater node
        }
        else{
            root = root->right;
        }
    }
    return suc;

}

node* inorder_predcessor(node* root,int key){
    if(root == NULL){return NULL;}

    node* pre = NULL;

    while(root!=NULL){

        if(root->data > key){ // smaller value means can be a worthy candidate
            pre = root;
            root = root->right; // moved right to find imediate smaller node
        }
        else{
            root = root->left;
        }
    }
    return pre;

}

