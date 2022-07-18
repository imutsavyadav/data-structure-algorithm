// ----------- Binary tree -----------
// it is a data structure which store the element in higherical order or in levels from 

#include<bits/stdc++.h>
using namespace std; 

// create a structure of binary tree node . 

class node{
    public : 
    int data ; 
    node* left; 
    node* right; 
       node(int val){
           data = val ; 
           left = NULL; 
           right = NULL; 
       }                     
};
/*   

    left       right
     &2  - 1 -  &3
          / \ 
        2     3

        left part of the node store the address of left node 
        right part of the node store the address of right node.
*/

// Signature of the traversla function. 

void preorder(node*root);
void inorder(node*root);
void postorder(node*root);

int main (){
      // create a root node  . 
        node * root = new node (1);
        
        root -> left = new node (2);
        root -> right = new node (3);



        // traversal 

        preorder(root) ; 
        
        cout<< endl ; 

        inorder(root); 

        cout << endl ; 

        postorder(root); 
        

}

// Binary tree traversal 
//                             --------- print node -------
// 1.  pre order traversal    root_node -> left_node -> right_node
// 2.  in order traversal     left_node -> root_node -> right_node
// 3.  post order traversal   left_node -> right_node -> root_node 


void preorder (node*root){
       // base case 
    if(root==NULL)
    return ;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void inorder (node*root){
       // base case 
    if(root==NULL)
    return;
    inorder(root->left);
    cout << root->data << " "; 
    inorder(root->right);
}


void postorder (node*root){
       // base case 
    if(root==NULL)
    return ;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}