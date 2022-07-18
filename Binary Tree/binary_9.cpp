// Sum replacment in the binary tree . 

// replace the value of each node with the sum of all subtree node and itself.

/*              1                 15  (11+3+1)
               / \              /    \
              2   3  = (4+5+2) 11      3 
             / \              /  \
            4   5            4    5

inOrder    4,2,5,1,3
 l-r-ri    
*/

  #include<bits/stdc++.h>
  #include"binary_1.h"

  using namespace std;

  // Sum Replacement function
    
    void sumReplacement(node* root){
       // base case 
       if(root==NULL)
        return ; 
          // recursive call on  left subtree.
        sumReplacement(root->left);  
          // recursive call on right subtree.
        sumReplacement(root->right);

        if(root->left!=NULL)
          root->data+=root->left->data;
        if(root->right!=NULL)
          root->data+=root->right->data;

   }

         


  int main(){
      node * root = new node(1);
      // left subtree 
      root -> left = new node(2);
      root -> left -> left = new node(4);
      root -> left -> right = new node(5);
      // right subtree.
      root -> right = new node(3);
       
        inOrder(root); cout<<endl;

       sumReplacement(root);

        inOrder(root);

  }