// Find the Sun of nodes at kth level 

// we define an extra variable who tell's the level of the tree in levelOrder traversal

#include<bits/stdc++.h>
#include"binary_1.h"

using namespace std; 

int sumAtKlevel(node*root , int k){
     if(root==NULL)
        return -1; 
    queue<node*>q;

    q.push(root);
    q.push(NULL);

    int sum = 0 ;
    int level = 0 ; 
    while(!q.empty()){
        // temp variable 
        node* temp = q.front(); 
        q.pop();
        if(temp!=NULL){
             if(level==k){
                 sum+=temp->data;
             }
             if(temp->left)
             q.push(temp->left);
             if(temp->right)
             q.push(temp->right);
        }
        else if (!q.empty()){
            q.push(NULL);
            level++;
        }

    }
    return sum;
}

int main(){
    node * root = new node(1);
    root->left = new node(2);
    root->right = new node(50);

    cout<<sumAtKlevel(root,1);
}