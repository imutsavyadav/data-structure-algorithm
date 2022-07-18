// left view of the binary tree 

/*
                                     1
    observer at left side           / \          
     of tree so                    2   3           
    node seen by him are          /   / \                      
      1,2,4,7                    4   5   6 
                                    /
                                  7     
*/

// Go  to each level and print the left most node  for each level . 
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

                if(i==0)  // hold the left most node of each level.
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