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
// get mid and form a node with it
// node->left = from start to mid - 1
// node->right = from mid+1 to end

void inorder(node* root,vector<int>& v){
    if(root == NULL){return;}

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);

}

node* BST_to_Balanced_BST(int s,int e,vector<int>&in){

    if(s > e){return NULL;}

    int mid = s+(e-s)/2;

    node* temp = new node(in[mid]);

    temp->left = BST_to_Balanced_BST(s,mid-1,in);
    temp->right = BST_to_Balanced_BST(mid+1,e,in);

    return temp;

}

node* balance_BST(node*root){

    vector<int> in;
    inorder(root,in);

    return BST_to_Balanced_BST(0,in.size()-1,in);

}