// to find nodes whose sum is equal to given target

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
// apply 2 pointer approach
// T.C. -------> O(n)

bool two_sum_BST(node*root,int target){

        vector<int> v;
        inorder(root,v);

        int i = 0;
        int j = v.size()-1;

        int sum = 0;

        while(i < j){

            sum = v[i] + v[j];

            if(sum == target){return true;}

            else if(sum > target){j--;}    // Note: as inorder of BST in already sorted

            else{i++;}
        }
        return false;

}

void inorder(node* root,vector<int>&v){

    if(root==NULL){return;}

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}