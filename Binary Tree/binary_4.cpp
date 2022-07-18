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
 
  vector<int> printLevelOrder(node* root)
    {
      //Your code here
     vector <int> ans;
     
      if(root==NULL){
          return {}; 
      }
      
      // we make an queue 
      
      queue < node* > q ; 
      
      // first we push the root node and NULL to the queue
      q.push(root);

      
      while(!q.empty()){

        // size of the queue

            int n = q.size();

            for(int i= 0 ; i< n  ; i++){
              // temp node . 
              node * temp = q.front() ; 

              ans.push_back(temp->data);

              q.pop();

              if(temp->left) 
                q.push(temp->left);
              if(temp->right)
                 q.push(temp->right);
       
                }
          }
      
      return ans ; 
    }

 int main () {
     node * root = new node(1);
    root->left = new node (2);
     root->right = new node (3);

    vector<int>ans = printLevelOrder(root);

    for(int i =0 ; i<ans.size() ; i++){
      cout <<ans[i];
    }

 }


 