// find distance of two node of a binary tree.

// the distance b/w two node is the minimum no. of edges
// to be traversed to reach one node from another.

//    stratergy ->
// 1. find the LCA (lowest common ancestor) 
// 2. find the distance of n1(d1) & n2(d2) from LCA.
// 3. return (d1 + d2)

/*
             1
            / \                       
           2   3        n1 = 7 first node 
          /   / \       n2 = 6  second node
         4   5   6    so now LCA of both node is 3
            / \        d1 = distance of 7 and 3 i.e. two no. edges b/w both node.
           7   8       d2 = distance of 6 and 3 i.e one
                    so the ans is  d1 + d2 is 3 .
*/

  #include<bits/stdc++.h>
  #include"binary_1.h"

  using namespace std ; 

  node * LCA(node*root , int n1  , int n2){
      // base case 
      if(root==NULL) return NULL ; 
      if(root->data == n1 || root->data == n2) return root ; 

      // create and left and right pointer
      node*left = LCA (root->left , n1 , n2);
      node*right = LCA (root->right , n1 , n2); 

      if(left && right) return root ; 

      if(left) return left;

      return right ; 
  }

// find the distance of the node throught the lca node . 

  int find_Dist(node*root , int k , int dist){
    if(root==NULL) return -1 ; 

    if(root->data == k)  return dist ; 

    int left = find_Dist(root->left , k , dist+1) ; 

    if(left!=-1) return left ;  // we reach to the last node .

    return find_Dist(root->right , k , dist+1); 

  }


  int dist_b_N(node*root , int n1 , int n2) {

    node * lca = LCA( root , n1  , n2); 

    int d1 = find_Dist(lca , n1 , 0) ; 
    int d2 = find_Dist(lca , n2 , 0) ; 

    return d1 + d2 ; 


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
       // node*lca = LCA (root , n1 , n2);
       // cout << lca->data ; 

      

      cout << dist_b_N(root, 7 , 6);

      
  }


