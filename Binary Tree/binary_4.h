//   Leval order traversal in the binary tree. 
  /*
        Tree 
         1           pre order = R -> L -> Ri  = 1,2,4,5,3,6,7
       /   \        
     2       3       post order = L -> Ri -> R = 4,5,2,6,7,3,1
    / \     / \
   4   5   6   7     in order = L -> R -> Ri  = 4,2,5,1,6,3,7

  */ 

 #include<bits/stdc++.h>
 #include"binary_1.h"
 
 using namespace std; 
 
 void printLevelOrder(node* root){
     if(root==NULL)
     return ; 
     queue <node*> q ; 
     q.push(root);
     q.push(NULL);

     while(!q.empty()){
         node * temp = q.front() ; 
         q.pop();
         if(temp!=NULL){
           cout<<temp->data<<" ";
             if(temp->left)
           q.push(temp->left);
             if(temp->right)
           q.push(temp->right);
        }
         else if (!q.empty())
         q.push(NULL);
         
     }
 }

 int main () {
     node * root = new node(1);
    root->left = new node (2);
     root->right = new node (3);

     printLevelOrder(root);

 }


 