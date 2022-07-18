// Diameter of th Binary tree. 

// Number of nodes in hte longest path between any 2 leaves. 

// it can be pass through the root node or may be not. 

// here we calculate 

//  max ( left height + right height + 1 ,  left Dimeter , right Diameter)

#include<bits/stdc++.h>
#include"binary_1.h"

using namespace std; 

int calHeight(node*root){
    // base case
    if (root==NULL)
    return 0 ; 
    int lheight = calHeight(root->left);
    int rheight = calHeight(root->right);

    return( max(lheight,rheight) + 1 );
}

int calDiameter(node*root){
    // base case 
    if(root==NULL)
    return 0; 

    int lheight = calHeight(root->left);
    int rheight = calHeight(root->right);

    int curDiameter = lheight + rheight + 1 ; 

    int lDiameter = calDiameter(root->left);
    int rDiameter = calDiameter(root->right);

    return max(curDiameter,max(lDiameter,rDiameter));

}

int main(){
    
}
