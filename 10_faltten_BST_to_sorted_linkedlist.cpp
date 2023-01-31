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

// ___________________________ LOGIC _________________________________

// get inorder of BST (as it is already sorted)
// make left of every node as NULL
// and make right to point to next node


void inorder(node* root,vector<node*>&v){
    if(root == NULL){return;}

    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}
node* flatten_BST_to_sorted_linkedlist(node* root){

    vector<node*> v;
    inorder(root,v);

    for(int i = 0;i<v.size()-1;i++){

        node* temp = v[i];
        temp->left = NULL;
        temp->right = v[i+1];
    }

    // make last node's left and right to point to NULL

    node* last_node = v[v.size()-1];
    last_node->left = NULL;
    last_node->right = NULL;

    //return first root;
    return v[0];

}