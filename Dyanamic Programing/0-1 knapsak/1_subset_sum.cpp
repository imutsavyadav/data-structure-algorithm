#include<bits/stdc++.h>
using namespace std;

// flow:-
// problem statement
// identification how this problem related with 0-1 knapSack
// similartiy with 0-1 kanpSack
// change in code

// find the subset is exit or not in the given array whoese sum is equal to given sum 

bool subset_sum(int arr[] , int sum , int n);
int main(){
    // input 
    int n; cin>> n ; // size of array 
    
    int sum ; cin >> sum ; 

    int arr[n];

    for(int i = 0 ; i<n ;i++){
        cin >> arr[i];
    }

    bool ans = subset_sum(arr,sum,n);

    if(ans) cout << "Exit";
    else cout << "Not Exit";

}

int subsetSumRec(int arr[] ,int n , int sum){
	// initialization part 
	if(n==0  && sum == 0 )
		return 1;
	if(n==0 && sum !=0) 
		return 0 ;

			if(arr[n-1]<=sum)
				return subsetSumRec(arr,n-1,sum-arr[n-1]) || subsetSumRec(arr,n-1,sum);
			else
				return subsetSumRec(arr,n-1,sum);
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