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

// we will create playing with range of node value of BST

node* BST_constructor(int pre[],int n,int &i,int mini,int maxi){

    if(i > n-1){return NULL;}

    if(pre[i] < mini or pre[i] > maxi){
        return NULL;
    }

    node* root = new node(pre[i++]);

    root->left = BST_constructor(pre,n,i,mini,root->data);
    root->right = BST_constructor(pre,n,i,root->data,maxi);

    return root;
}

node* BST_from_preorder(int pre[],int n){

    int maxi = INT_MAX;
    int mini = INT_MIN;
    int i = 0;
    return BST_constructor(pre,n,i,mini,maxi);


}
