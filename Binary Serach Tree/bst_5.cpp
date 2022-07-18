// Print All Possibel no of BSTs from n nodes 

// we construct the all possible structure of bst 
// store in a vector 
// finaly we call preorder for all Bst and print it. 

#include<bits/stdc++.h>
using namespace std; 

struct node
{
    int data;
    node*left;
    node*right;
        node(int val){
            data=val; 
            left=NULL;
            right=NULL;
        }
};
      
      // construct trees 

      vector<node*> constructTrees(int start , int end){
            vector<node*> trees; // for store the all possibel sturcture of lasrge BSTs 
            // Base case 
            if(start>end){
            	trees.push_back(NULL);
            	return trees;
            }
            for(int i=start ; i<=end ; i++){
                // store the all left and right possible subtrees 
                vector<node*>leftsubtree = constructTrees(start , i-1);
                vector<node*>rightsubtree = constructTrees(i+1,end);

                // Now merge the curr node to its all possible LST and RST 
                // actual catalan work is start
                for(int j=0 ; j<leftsubtree.size() ; j++){
                      // make l pointer store the leftsubtree 
                      node* l = leftsubtree[j];
                    for(int k=0 ; k<rightsubtree.size() ; k++){
                            node* r= rightsubtree[k];

                            // make the curr node and add l and r to its left and right subtree
                            // form the large BSTs by merging
                            node* root = new node(i);
                            root->left=l;
                            root->right=r;

                            // push  the ans in tree
                            trees.push_back(root);
                    }
                }
            }
            return trees;
      }


void preorder(node*root){
    if(root==NULL) return; 

    cout<<root->data<<" "; 
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<node*> totalTrees = constructTrees(1,3);
     for(int i = 0 ; i< totalTrees.size() ; i++){
        cout<< i+1 <<":- ";
        preorder(totalTrees[i]);
        cout << endl ; 
    }

  


}