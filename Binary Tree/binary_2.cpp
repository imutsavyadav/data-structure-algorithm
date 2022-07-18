// ---------- Build Binary tree -----------
// from preorder and inorder gave 
//      r->l->ri      l->ri->r       

#include<bits/stdc++.h>
#include"binary_1.h"
using namespace std; 
// search fucntion for inorder to find the curr  position in the inorder because before its all consider in the left subtree of that particular curr node and after this all are consider as right subtree for that curr node . 

int search (int inorder[] , int start , int  curr , int end){
     // traverse in inorder
     for(int i = start ; i<=end; i++){
         if(inorder[i]==curr){
             return i ;  // as the current pos in the array.
         }
     }
     return -1;     
}

// Build Tree function 

  node * buildTree(int preorder[] , int inorder[] , int start , int end){
      if(start>end) {
          return NULL;  // base case 
      }
    // make idx to itrate in preorder 
   static int idx = 0 ; 
    // make curr 
    int curr = preorder[idx];
    node * root = new node (curr);
      idx++;

      if(start == end){
        return root;     // special case 
      }

    // make an pos pointer to itrate in the inorder 
    int pos = search(inorder , start , curr , end) ; // at pos we have curr node

    // now call recusively in bulid tree first make left sub tree than right subtree

     root->left = buildTree(preorder,inorder,start ,pos-1);

     root->right = buildTree(preorder,inorder,pos+1,end);

        return root;
      
  }

  /*
        Tree 
         1           pre order = R -> L -> Ri  = 1,2,4,5,3,6,7
       /   \        
     2       3       post order = L -> Ri -> R = 4,5,2,6,7,3,1
    / \     / \
   4   5   6   7     in order = L -> R -> Ri  = 4,2,5,1,6,3,7

  */            
 
int main(){
    int preorder[]={1,2,4,5,3,6,7};
    int inorder[]={4,2,5,1,6,3,7} ;

    node*root= buildTree(preorder,inorder,0 , 6) ;

    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
}