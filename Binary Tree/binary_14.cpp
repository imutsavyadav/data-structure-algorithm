  // Lowest common Ancestor for two node . 
  // It is that node where poin of path change occur for the two node.


/*
             1
            / \          
           2   3          n1 = 7  and n2 = 6 
          /   / \         then is LCA is 3  (point of divergence)          
         4   5   6 
            /
           7     
*/

// we could find this by the method given below . 
// we start from root node and search the n1 node and store the path if 
// it exist in the tree by the help of getPath function . 
// do same for n2 . 
// and check for common point or node in both store path 
// so the last common node in both the path is our LCA for node n1 and n2 

 #include<bits/stdc++.h>
 #include"binary_1.h"

 using namespace std;
     
   
   // getPath function check and search for the node n1 and n2 if exist then 
   // store the its path from root node to it.
 bool getPath(node*root , int key , vector<int> &path){
          // base case 
         if(root==NULL)
         return false; 
            // start with root node 
            path.push_back(root->data);

            // check 
            if (root->data==key){
                return true;
            }

            // now check for left and right subtree by the help of recursion.

            if(getPath(root->left , key , path)|| getPath(root->right , key , path)) {
                // if the node is exist than 
                    return true;
            }
              // we will pop the data from the path so the key node is not in that path or 
              // it is not in our tree.
            path.pop_back();
            //Backtraking 
            return false;


 }
 
 // Lowest common ancestor function 
 //               return the value of LCA 
 int LCA (node*root , int n1 , int n2){
          // first make two vector path1 and path2 
          // to store the path on both the node, 
          vector<int> path1  ,path2;

          if(!getPath(root , n1 , path1) ||   !getPath(root , n2 , path2))
            return -1;  // the one of them or may be both are not exist in the tree.

            int pc ; // path change pointer 

            for( pc =0 ; pc<path1.size() && path2.size() ; pc++){
                  // traverse in both the path and find the last common point in the both path.
                if(path1[pc] != path2[pc])
                break ; 
            }

            return path1[pc-1];  // pc-1 is the last common node in both path.
 }

   int main(){
      node * root = new node(1);
      // left subtree 
      root -> left = new node(2);
      root -> left ->left = new node(4);

      // Right subtree
      root->right = new node (3); 
      root->right->left = new node(5);
      root->right->left ->left = new node(7);
      root->right->right= new node(6);


      int n1 = 7 , n2 = 6 ; 
      cout << LCA (root , n1 , n2);


      
  }