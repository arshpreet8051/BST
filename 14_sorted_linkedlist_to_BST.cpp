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

class lnode{

    public:
    int data;
    lnode* next;

    lnode(int ele){
        this->data = ele;
        this->next = NULL;
    }
};

// step -> 1  .Store data elements of LL in a vector
// step -> 2  .Apply inserion in BST logic


node* sorted_ll_to_BST(lnode* head){

    //step -> 1
    vector<int> v;
    store_LL(head,v);

    //step -> 2
    node* root;
    int start = 0;
    int end = v.size()-1;

    return insert_in_BST(root,v,start,end);
}

void store_LL(lnode* head,vector<int> &v){

    while(head!=NULL){
        v.push_back(head->data);
        head = head->next;
    }
}

node* insert_in_BST(node* root,vector<int>&v,int s,int e){

    if(s>e){return NULL;}

    int mid = s+(e-s+1)/2;
    root = new node(v[mid]);

    root->left = insert_in_BST(root->left,v,s,mid-1);
    root->right = insert_in_BST(root->right,v,mid+1,e);

    return root;

}
