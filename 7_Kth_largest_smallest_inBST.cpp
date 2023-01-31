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

//-----------------------------  Approach 1)  ------------------------------- 

//             case 1) ----> k-th smallest element
//                        > recursive inorder traversal
//                        > when reach node decrease k
//                        > when k==0 return that particular node

int kth_smallest(node* root ,int &k){  // Note --> passing k by reference

    if(root == NULL){return -1;} // base case

    int left = kth_smallest(root->left,k);

    if(left!=-1){return left;}

    k--;

    if(k==0){return root->data;}

    return kth_smallest(root->right,k);
}

//          case 2) ----> k-th largest element
//                     > recursive traversal but rigth call first then left
//                     > when reach node decrease k
//                     > when k == 0 return node
int kth_largest(node* root,int &k){
        
        if(root == NULL){return -1;}
        
        int left = kth_largest(root->right,k);
        if(left!=-1){
            return left;
        }
        
        k--;
        if(k==0){return root->data;}
        
        return kth_largest(root->left,k);
}


//--------------------------- Approach 2) -------------------
//  ----> use vector to dtore inorder and return k-th smallest or largest