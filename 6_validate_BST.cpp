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

// ____________________________ 2 approaches ______________________________//

// Approach 1)
                // > we know each element can lie within a range
                // > smaller than right parent and greater then left
                // > Or left subtree is smaller tahn root and right is greater

bool check_BST(node* root,int mini,int maxi){
    if(root == NULL){return true;}

    if(root->data <= maxi and root->data >= mini){

        bool left = check_BST(root->left,mini,root->data);
        bool right = check_BST(root->right,root->data,maxi);
        return left and right;
    }
    return false;
}

bool validate_BSt(node* root){

    return check_BST(root,INT_MIN,INT_MAX);

}


// Approach 2) 
//              > as inorder traversal of BST is sorted
//              > get inorder and check if it is sorted of not

void in_order(node* root,vector<int>&v){

    if(root == NULL){return;}

    in_order(root->left,v);
    v.push_back(root->data);
    in_order(root->right,v);
}
bool validate_BST(node* root){
    
    if(root == NULL){return true;}

    vector<int> inorder;
    in_order(root,inorder);

    for(int i = 0;i<inorder.size()-1;i++){
        if(inorder[i] > inorder[i+1]){
            return false;
        }
    }
    return true;
}