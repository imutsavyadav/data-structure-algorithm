// -------- Build Tree ------- 
// from postorder and inorder
//        L->Ri->R      L->R->Ri


#include<bits/stdc++.h>
#include"binary_1.h"
// #include"binary_4.h"
using namespace std; 

int search (int inorder[] , int start , int  curr , int end){
     // traverse in inorder
     for(int i = start ; i<=end; i++){
         if(inorder[i]==curr){
             return i ;  // as the current pos in the array.
         }
     }
     return -1;     
}

node* buildTree(int postorder[], int inorder[], int start, int end){
    if(end<=start){
        return NULL; 
    }
    // make an static pointer to traverse in postorder
    static int idx = 6;

    // take last value from postorder and save in curr pointer.
    // and traverse from back becouse root node comes in last.

    int curr = postorder[idx];

    node* root = new node(curr);
    
    idx--;

    int pos = search(inorder,start,curr,end);

    root->right = buildTree(postorder,inorder,pos+1,end);

    root->left = buildTree(postorder,inorder,start ,pos-1);

        return root;  


}

int main() {
     int postorder[] ={4,5,2,6,7,3,1};
     int inorder[] ={4,2,5,1,6,3,7};

     // start -> 0 and end -> 6

     node* root=buildTree(postorder , inorder , 0 , 6);



}