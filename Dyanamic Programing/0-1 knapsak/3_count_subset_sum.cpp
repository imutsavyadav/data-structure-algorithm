#include<bits/stdc++.h>
using namespace std ; 

//  flow :-> 
//  problem statement 
//  similarity with previous problem 
//  code

// find the count of total subset +nt in the given array whose sum equal to the given sum 

 int count_subset_sum(int arr[] , int sum , int n);

int main(){
    // input 
    int n ; cin >> n ; 
    int sum ; cin >> sum ;
    int arr[n]; 
    for(int i = 0 ; i< n ; i++) cin>> arr[i];

   cout <<  count_subset_sum(arr ,sum ,n);
}

 int count_subset_sum(int arr[] , int sum , int n){
     // storage subproblem answer matrix
       int t[n+1][sum+1];

     // similar with subset sum 
     // same initilization change boolen to int means 0 and 1 
     
     for(int i = 0 ; i< n ; i++){
         for(int j = 0 ; j < sum ; j++){
             if(i==0) t[i][j]=0;
             if(j==0) t[i][j]=1;
         }
     }

     // code 

     for(int i = 1 ; i< n ; i++){
         for(int j = 1 ; j< sum ; j++){
             if(arr[i-1]<=j){
                 // include not include
                 t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
             }
             else{
                 t[i][j] = t[i-1][j];
             }
         }
     }
     return t[n][sum];
 }
