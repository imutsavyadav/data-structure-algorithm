#include<bits/stdc++.h>
using namespace std ;
long long subsequenceK(vector<int> &arr, int n, int k){
    // Write your code here.
  vector <vector<int>> v1(52);
  vector <pair<int,int>> dif;
;
  for(int i = 0 ; i< n-1 ; i++){
    for(int j = i+1 ; j < n ; j++){
      dif.push_back({make_pair(arr[j]-arr[i] ,i)});
    }
  }
  for(int i = 0 ; i<dif.size() ; i+n){
    int j = 0 , k = 0 ; 
    while(j<n){
      k = dif[j].first;
      v1[k].push_back(dif[j].second);
      j++;
      n--;
    }
  }
  int ans = 0 ; 
  for(int i = 0 ; i<v1.size();  i++){
    if(v1[i].size()==k)
      ans++;
  }
  return ans ; 
}

int main(){
   int n  ,  k ; 
   cin >> n >> k ; 
   vector<int> arr(n);
   for(int i = 0 ; i<n ; i++){
    cin>> arr[i];
   }
   cout << subsequenceK(arr,n,k);
}