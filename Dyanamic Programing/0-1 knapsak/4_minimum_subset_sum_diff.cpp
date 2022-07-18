#include <bits/stdc++.h>
using namespace std;


// subset sum problem -> the particular sum 
// exist in the array or not
// direct using dp 
int subsetSum(int arr[] ,int n , int sum){
	// initialization part 
	if(n==0  && sum == 0 )
		return 1;
	if(n==0 && sum !=0) 
		return 0 ;
	static vector<int> ans;
			if(arr[n-1]<=sum)
				 return subsetSum(arr,n-1,sum-arr[n-1]) || subsetSum(arr,n-1,sum);
			else
				return subsetSum(arr,n-1,sum);
}

int main(){ 
	int n ; // size of arr 
	cin >> n  ; 
	int arr[n];
	for(int & i : arr) cin>> i ; 
 	int sum =0; 
 	for(int  &i : arr) sum+=i  ;
 	vector<int>ans;
 	for(int i = 0 ; i<=sum/2 ; i++){
 		if(subsetSum(arr,n,i))
 			ans.push_back(i);
 	}
 	int res = INT_MAX;
 	for(int i = 0 ; i<ans.size() ; i++){
 		res = min(sum-2*ans[i] , res);
 	}
 	cout << res ;
}