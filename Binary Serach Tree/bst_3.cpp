// sorted array to balanced bst or make bst from inorder

// balanced tree -> the diff of heifht of left subtree and right subtree is eqal less than one 

// stratergy 
// make middle element as the root node. 
// recursively do the same for subtrees 
//   start to mid-1 for left subtree 
//   mid+1 to end for right subtree

#include<bits/stdc++.h>

using namespace std ;

// structure of bst 
struct node
{
	int data;
	node* left;
	node* right;
	   node(int val){
	   	data=val;
	   	left=NULL;
	   	right=NULL;
	   }
};
	node* sortedArrayToBst(int arr[] , int start , int end){
		// base case 
		// when start is greater than eqaul to end
		if(start>end){
			return NULL;
		}

		// mid pointer 
		int mid = (start+end)/2;

		// create root node of the bst
		node*root = new node(arr[mid]);

		// call for make left subtree and then right subtree.

		root->left= sortedArrayToBst(arr , start , mid-1);

		root->right = sortedArrayToBst(arr , mid+1 , end) ; 

		return root ;
	}

	void inorder(node*root){
		if(root==NULL) return ; 
		 inorder(root->left);
		 cout<<root->data<<" "; 
		 inorder(root->right);
	}

	


int main(){
	 int arr[] = {1 , 2, 3 , 4 , 5};
	 // we pass as argument 
	 // array , starting index and , ending index .
	 node*root=sortedArrayToBst(arr,0,4);
	 inorder(root);
}