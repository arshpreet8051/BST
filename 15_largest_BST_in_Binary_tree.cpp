// new thing learned ----> integration of a new class with recursive solution


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

//NOTE:
class info {
    public:
    int maxi;
    int mini;
    int size;
    bool isBST;
};

//function to return size of largest BST
int size_of_largest_BST(node* root){

    int maxsize = 0;

    info temp = solve(root,maxsize);

    return maxsize;
}

info solve(node* root,int &ans){

    //base case
    if(root == NULL){
        return {INT_MIN,INT_MAX,0,true};
    }

    info left = solve(root->left,ans);
    info right = solve(root->right,ans);

    info currNode;

    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);

    currNode.size = left.size + right.size + 1;

    if(left.isBST and right.isBST and (root->data > left.maxi and root->data < right.mini)){
            currNode.isBST = true;
        }

        else{
            currNode.isBST = false;
        }

        if(currNode.isBST){
            ans = max(ans,currNode.size);
        }

        return currNode;
    }

//---------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------

// function to return sum of node of max BST in a Binary Tree

class clue{
    public:
        int maxi;
        int mini;
        int sum;
        bool isBST;
};

int sum_of_max_BST(node* root){

    int ans = 0;
    clue temp = solvi(root,ans);

    return ans;
}

clue solvi(node* root,int &ans){

    //base case
    if(root==NULL){
        return {INT_MIN,INT_MAX,0,true};
    }

    clue left = solvi(root->left,ans);
    clue right = solvi(root->right,ans);

    clue present;

    present.maxi = max(root->data,right.maxi);
    present.mini = min(root->data,left.mini);

    present.sum = left.sum + right.sum + root->data;

    if(left.isBST and right.isBST and (root->data > left.maxi and root->data < right.mini)){
        present.isBST = true;
    }
    else{
        present.isBST = false;
    }

    if(present.isBST){
        ans = max(ans,present.sum);
    }
    return present;
}