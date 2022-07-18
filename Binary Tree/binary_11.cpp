//  Right View of a Binary tree.

/*
             1
            / \          
           2   3         <--  observer is this side so what the observer is seen 
          /   / \                       1 , 3 , 6 , 7 
         4   5   6 
            /
           7     
*/

// Go  to each level and print the right most node  for each level . 
// for level order Traversal 

  #include<bits/stdc++.h>
  #include"binary_1.h"

  using namespace std; 

  // first do level order traversal 

   vector<int> rightView(node*root){
       
       // we make an queue 
       queue <node * > q ; 

       q.push(root);

       vector <int> ans;
       
       while(!q.empty()){
           // size of the queue
            int n = q.size();
           // temp which store the front of the queue

            for(int i=0 ; i< n ; i++){

            node*temp = q.front();
                q.pop();

                if(i==n-1)  // hold the right most node of each level.
              ans.push_back(temp->data);

                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);

            }
       }
       return ans ; 
  }

  int main(){
      node * root = new node(1);
      // left subtree 
      root -> left = new node(2);
      root -> left = new node(4);

      // Right subtree
      root->right = new node (3); 
      root->right->left = new node(5);
      root->right->left ->left = new node(7);
      root->right->right= new node(6);

      vector <int> ans = rightView(root);

      for(int i = 0 ; i< ans.size() ; i++){
          cout << ans[i] <<" ";
      }
  }