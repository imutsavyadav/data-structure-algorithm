// wap to fid unique number in an array where all numebers
// except one are present twice.

// we use the xor operator here 

#include<bits/stdc++.h>
using namespace std; 

// here we calculate the xor sum for the 
// array so all duplicate elemtent gone to 
// zero and at last we have the unique no.
int find_unique(int arr[] , int n){
    int xorSum = 0 ; 
    for(int i = 0 ; i < n ; i++){
        xorSum = xorSum ^ arr[i];
    }
    return xorSum ;
}

int main(){
    int arr[] = {1 , 3 , 3 , 5 , 5 , 9 , 1 ,8 , 8};

    cout << find_unique(arr , 9);
    
}