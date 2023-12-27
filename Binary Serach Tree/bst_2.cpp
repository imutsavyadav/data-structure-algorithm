// Build BST from preorder 
// stratergy we use to maintain minimum and maximum for each node 
// and the upcoming node is compare with its previous node min and max value
// and insert in the bst if the curr node value is less them previous node
// max value than insert it in left and greter than its min value than insert in 
// right . 

#include<bits/stdc++.h>
using namespace std ; 

// structure of bst 

struct node
{
    int data; 
    node* left;
    node* right; 
      node(int val) {
          data = val; 
          left = NULL ; 
          right = NULL ; 
      }
};


// construct bst 

node* constructBST(int preorder[],int* preidx , int key ,int min , int max , int n){
       // base case 
        if( *preidx >= n ){
            return NULL ;
        }
       // create a node pointer
       node* root ; 

       if(key > min && key < max ){
            root = new node(key); // create the node 
            // update the preidx 
            *preidx= *preidx+1 ; 

            if(*preidx < n)
            // build left subtree 
             root->left = constructBST( preorder , preidx  , preorder[*preidx] ,min , key , n) ; 
            
            if(*preidx<n)
            // build right subtree 
            root->right = constructBST( preorder , preidx , preorder[*preidx] , key , max , n);
       }
       return root ; 

}
void printPreOrder(node*root){
    cout<< root ->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
int main (){
    int preorder[] = {7,5,4,6,8,9};
    int n = 6;
    int preIdx = 0 ; // preorder index for traverse in preorder 

    node*root ;
   root=constructBST(preorder , &preIdx , preorder[0] , INT_MIN , INT_MAX , n);

    printPreOrder(root);
}


