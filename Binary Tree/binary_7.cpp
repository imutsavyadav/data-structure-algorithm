// Height of the binary tree 

// it is the depth of the tree 's deepest node . 

#include<bits/stdc++.h>
#include"binary_1.h"

using namespace std ;

int calHeight(node*root){
    // base case
    if (root==NULL)
    return 0 ; 
    int lheight = calHeight(root->left);
    int rheight = calHeight(root->right);

    return( max(lheight,rheight) + 1 );
}
/*
        1 
       / \
      2   3
     / 
    4
   /
  5

*/
int main(){
    node* root = new node(1);
    root->left = new node(2); 
    root->right = new node(3); 
    root->left->left = new node(4);
    root->left->left->left=new node(5);

    cout << calHeight(root);
}