// count all the node in binary tree and sum 

// by the help of recursion first we count left subtree then right subtree
// then add 1 to it. 

#include<bits/stdc++.h>
#include"binary_1.h"

using namespace std; 

int sumNode (node*root){
    if(root==NULL)
    return 0 ;
    return sumNode (root->left) + sumNode(root->right) + root->data;
}

int countNode(node*root){
    if(root==NULL)
    return 0 ; 
    return countNode(root->left) + countNode(root->right) +1;
}

int main () {
    node* root = new node(1);
    root->left= new node(2);
    root->right= new node(3);
    
    cout << sumNode(root) << endl;

    cout << countNode(root);
}