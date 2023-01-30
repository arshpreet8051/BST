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

void level_order(node* root){
    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp==NULL and q.size()<=0){return;}
        else if(temp==NULL and q.size()>0){
            q.push(NULL);
            cout<<endl;
            }
        else{
            cout<<temp->data<<" ";
            if(temp->left){q.push(temp->left);}
            if(temp->right){q.push(temp->right);}
        }
    }
}

node* build_BST(node*& root,int d){
    
    if(root==NULL){
        node* temp = new node(d);
        return temp;
    }

    if(root->data < d){
        root->right = build_BST(root->right,d);
    }
    else{
        root->left = build_BST(root->left,d);
    }

    return root;
}

void take_input(node* &root){

    int d;
    cin>>d;
    while(d!=-1){
        root = build_BST(root,d);
        cin>>d;
    }
}

int main(){

node* root = NULL;
cout<<"Enter data : "<<endl;
take_input(root);
level_order(root);


}
// 10 8 21 7 27 5 4 3 -1