// balanced height Tree 

//  for each node, the difference between the height of the left subtree right subtree is equal less than 1

#include<bits/stdc++.h>
#include"binary_1.h"

using namespace std ; 

/*
                1    
               / \
              2   3  
             / \        lh = 4 
            4   5       rh = 2
           /            dif = 4-2 = 2 >=0 so not a balanced tree
          6  
*/

// height of the binary tree 
 
 int height (node*root){
     if(root==NULL)
     return 0;
     int lh = height(root->left);
     int rh = height(root->right);

     return max ( lh , rh) + 1 ; 
 }


// Check Balance height Tree or Not function 



bool isBalanced(node*root){
    if(root==NULL)
    return true; 

    if(isBalanced(root->left)==false)
    return false;
    
    if(isBalanced(root->right)==false)
    return false;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }
}

int main(){
  node * root = new node(1);
      // left subtree 
      root -> left = new node(2);
      root -> left -> left = new node(4);
      root -> left -> left ->left = new node(6);  
      root -> left -> right = new node(5);
      // right subtree.
      root -> right = new node(3);

      cout << isBalanced(root);
       
}