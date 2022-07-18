#include<bits/stdc++.h>
using namespace std; 

    // flow:->
    // problem statement 
    // similarty
    // initializaiton 
    // code

    // find that two subset is present in the given array such that both the subset have same sum

bool equal_subset_sum(int arr[] , int n);
bool subset_sum(int arr[] , int sum , int n);

int main(){
    int n ; cin >> n ; 
    int arr[n] ; 
    for(int i = 0 ; i< n ; i++) cin >> arr[i] ; 

    equal_subset_sum(arr,n);
}

// equal subset sum 
bool equal_subset_sum(int arr[] , int n ){
    // first check that the total sum is even or not of the array
    int sum = 0 ; 
    for(int i = 0 ; i < n ; i++) sum+= arr[i];
    // if the sum is odd than can not partion of  array in equaly with same sum
    if(sum%2!=0) return false; 
    else return subset_sum(arr, sum/2 , n); 
}

// return type is bool 
// use the top down approch 
bool subset_sum(int arr[] , int sum , int n ){
    // storage subproblem answer matrix 
    
   bool t[n+1][sum+1];

    // intitalization 
    for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j< sum ; j++){
            if(i==0) t[i][j]= false;
            if(j==0) t[i][j]= true;
        }
    }

    // choice digram part 

    for(int i = 1 ; i< n ;i++){
        for(int j = 1 ; j< sum ; j++){
            if(arr[i-1]<=j){
                // include or not include
                // in bool ans max funciton change to OR 
                // here no val property so negect that part
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
}