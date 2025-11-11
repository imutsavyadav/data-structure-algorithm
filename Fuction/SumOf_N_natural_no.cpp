#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
   int sum(int);
   int ans=sum(n);
   cout<<ans;
}
// int sum(int N){ 
//    int Ans=0;
//   for(int i=N; i>0; i--){
//     Ans+=i;
//   }
//   return Ans;
// }
int sum(int N){
  return (N*(N+1))/2;
}
