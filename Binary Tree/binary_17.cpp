// Maximum path sum in a binary tree 
/*  maximum possible sum of a path in the binary tree, starting  & ending at any node . 

 stratergy -: 
  for each node , compute 
  1 -> node val 
  2 -> maxPath through left child + node val 
  3 -> maxPath through right child + node val 
  4 -> maxPath through left child + right child + node val 
*/ 

  #include<bits/stdc++.h>
  #include"binary_1.h"

    using namespace std ; 

    int maxPath()