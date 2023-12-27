// Binary Search Tree

// Build BST
// left child of tree is lesser value than its parent node 
// right child of the tree is greter value than its parent node 
// and above two apply for each node of the tree 
// than the tree is form is known to be a binary serch treee

// Search in BST

// delete in a BST 
// -> three type node in a bst have to be  deleted 
// -> first is the leaf node which have no left and right child . 
// -> second is the parent node which have only one child either it is left or right.
// -> third is the parent node which have both chlid left and right . 

// Check for the valid bst is or not ?
// so we have to check all the property of bst as study earlier 
// if all  condn is true for each node then the tree is valid bst
// so for check be maintain the minallowed node and maxAllowed node for
// each node initally we pass as NULL
// and  check for left subtree and right subtree and update the min and max



#include<bits/stdc++.h>

using namespace std ; 

   // structure of the BST
class node{
    public: 
    int data; 
    node* left ;
    node* right ; 
      node( int val){
          data = val ; 
          left = NULL ;
          right = NULL ;  
      }
};



   // print Inorder of tree 
 void inOrder(node*root){
    if (root == NULL ) return ; 
     inOrder(root->left);
     cout << root -> data  << " "; 
     inOrder(root->right); 
 }

    // construct a bst 
  node* buildBst(int val , node* root) { 
    // base case 
    if(root== NULL)
    return  new node(val);

    if(val < root->data) 
   root->left = buildBst(val , root->left) ; 
    else
   root->right = buildBst(val , root->right);

     return root ;
}


  // Serach an Key node is present in the BST or not?
node* searchInBst(node*root , int key){
    if(root == NULL) return NULL ; 
    
    // key is equal to the data of the root node 

    if(key == root->data) return root ; 

    if(key< root->data) return searchInBst(root->left , key); 

    return searchInBst(root->right , key) ; 
}


  // Inorder succesor of node in a BST
node* inorderSucc(node*root){
    node* curr = root ; 
    while(curr && curr->left !=NULL){
        curr= curr->left;
    }
    return curr ; 
}


  // Delete Node in a BST
node* deleteBst(node*root , int key){

    // search in the bst where it key present in the tree 
     if(root->data >key) 
      root->left = deleteBst(root->left , key);
      else if (root->data < key)
       root->right = deleteBst(root->right , key); 
        else {
            // handle the case 1st and 2nd
            if(root->left == NULL){
                node* temp = root->right ; // we store the right node of the deleted node
                free(root) ; // delete the root node 
                return temp ;  // return its right node  to its current postion
            }
            else if (root->right ==NULL){
                node* temp = root->left ; 
                free(root) ; 
                return temp ; 
            }
            // handle the case 3rd 
            node*temp = inorderSucc(root->right) ; // find the inorder succsesor of that node . 
            root->data = temp -> data ;  // swap the data with temp node to the root node.
            root->right = deleteBst(root->right , temp->data);
            // after swap we call the deletBst for the temp node .

        }
         return root ;    
      }

// Check the given tree is valid bst of not .
    bool isBST(node*root , node*min , node*max){
        // as reach on leaf node return true 
        if(root==NULL)
        return true ; 

        // think opposite and check for all false condn and compare 
        // data of the root and minAllowed and maxAllowed.
        if(min!=NULL && root->data <= min->data)
        return false; 
        if(max!=NULL && root->data >= max->data)
        return false;

        // so as of now we go in left subtree and update the max as root
        bool leftValid = isBST(root->left , min , root);
        // now go in right subtree and update the min as root
        bool rightValid = isBST(root->right,root , max);

        // both the leftValid and rightValid is true than we return true.

        return leftValid and rightValid;
    }
   
int main (){
    // create binary serch tree from an array .
    
    int arr [] = {5 , 4 , 2  , 9 , 3 , 6} ;
    
    node* root = NULL ; 

    for(int i = 0 ; i < 6 ; i++ ) { 
        root = buildBst( arr[i] , root); 
    }

    inOrder(root);

    // search in BST 
    cout << endl ; 
    if( searchInBst(root ,  4)  == NULL ) 
      cout << "key is not exist";
    else 
      cout << " key is exist";
    cout << endl ; 

    root = deleteBst(root , 9);

    inOrder(root);
         cout << endl ;
       if(isBST(root , NULL , NULL)) 
        cout << "valid Bst"; 
        else
        cout << "not valid Bst";
  
}