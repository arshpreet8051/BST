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

// step -> 1  .Store inorder of both BST's
// step -> 2  .Sort the inorder of BST's
// step -> 3  .Apply inserion in BST logic


node* merge_2_BST(node* root1,node* root2){

    vector<int> v;

    //step -> 1;
    inorder(root1,v);
    inorder(root2,v);

    //step -> 2;
    sort(v.begin(),v.end());

    //step -> 3;
    node* root = NULL;
    int start = 0;
    int end = v.size()-1;
    return insert_in_BST(root,v,start,end);
}

void inorder(node* root,vector<int>&v){
    
    if(root == NULL){return;}

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);

}

node* insert_in_BST(node* root,vector<int>&v,int s,int e){

    if(s>e){return NULL;}

    int mid = s+(e-s)/2;
    root = new node(v[mid]);

    root->left = insert_in_BST(root->left,v,s,mid-1);
    root->right = insert_in_BST(root->right,v,mid+1,e);

    return root;
}