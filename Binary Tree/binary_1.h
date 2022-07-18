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

void preOrder(node*root);
void inOrder(node*root);
void postOrder(node*root);

// int main (){
//       // create a root node  . 
//         node * root = new node (1);
        
//         root -> left = new node (2);
//         root -> right = new node (3);



//         // traversal 

//         preOrder(root) ; 
        
//         cout<< endl ; 

//         inOrder(root); 

//         cout << endl ; 

//         postOrder(root); 
        

// }

// Binary tree traversal 
//                             --------- print node -------
// 1.  pre order traversal    root_node -> left_node -> right_node
// 2.  in order traversal     left_node -> root_node -> right_node
// 3.  post order traversal   left_node -> right_node -> root_node 


void preOrder (node*root){
       // base case 
    if(root==NULL)
    return ;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void inOrder (node*root){
       // base case 
    if(root==NULL)
    return;
    inOrder(root->left);
    cout << root->data << " "; 
    inOrder(root->right);
}


void postOrder (node*root){
       // base case 
    if(root==NULL)
    return ;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// void printLevelOrder(node* root){
//      if(root==NULL)
//      return ; 
//      queue <node*> q ; 
//      q.push(root);
//      q.push(NULL);

//      while(!q.empty()){
//          node * temp = q.front() ; 
//          q.pop();
//          if(temp!=NULL){
//             cout<<temp->data<<" ";
//              if(temp->left)
//             q.push(temp->left);
//              if(temp->right)
//             q.push(temp->right);
//       }
//        else if (!q.empty())
//          q.push(NULL);
         
//      }
//  }