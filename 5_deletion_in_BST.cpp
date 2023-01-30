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

// ____________________________ L O G I C ______________________________//

// 0 child  -----> delete node and return NULL
// 1 child  -----> left child  -----> store left child , delete root and return left child
// 1 child  -----> right child -----> store right child , delete root and return right child
// 2 children ---> 1) get min value from right subtree
//                 2) replace root's data with mini
//                 3) recursive call for min value root



node* min_value_node(node* root){

    while(root->left != NULL){
        root = root->left;
    }
    return root;
}


node* delete_from_BST(node* root,int key){

    if(root == NULL){return root;}
    
    if(root->data == key){ // delete krn wali root milgi

    // 0 child
    if(root->right == NULL and root->left == NULL){
        delete root;
        return NULL;
    }

    // 1 child

    //case 1) ----> left child
    else if(root->left!=NULL and root->right == NULL){
        node* temp = root->left;
        delete root;
        return temp;
    }

    //case 2) ----> right child
    else if(root->left==NULL and root->right!=NULL){
        node* temp = root->right;
        delete root;
        return temp;
    }

    // 2 child

    else{

        // get min val from right subtree , replce min val with root's data and delte min
        int mini = min_value_node(root->right)->data;
        root->data = mini;
        root->right = delete_from_BST(root->right,mini);
        return root;
    }

    }

    else if(root->data > key){
        root->left = delete_from_BST(root->left,key);
    }
    else{
        root->right = delete_from_BST(root->right,key);
    }
    return root;
}
