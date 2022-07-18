#include<bits/stdc++.h>
using namespace std ; 

// first Occurense 
int firstOcc(int arr[] , int key , int n , int i){
    // Base case 
    if(i==n){
        return -1;
    }    

    if(arr[i] == key){
        return i ;
    }
    return firstOcc(arr,key , n , i+1);
}
// last Occurence
int lastOcc(int arr[] , int key , int n , int i){
    // Base case 
    if(i == n){
        return -1; 
    }
   int restarray = lastOcc(arr,key,n,i+1);
    if(restarray!=-1){
        return restarray;
    }
    //check for key in backtrack 
    if(arr[i]==key){
        return i;
    }
  return -1;
}
int main(){
    int n,key ; 
    cin >> n >> key; 

    int arr[n];
    for(int i = 0 ; i< n ; i++){
        cin >> arr[i];
    }
    // tell about the first occurence of an no. in the input array 
    cout <<firstOcc(arr , key , n , 0);

    cout << endl; 
    // tell about the last Occuresce of an no. in the input array 
    cout <<lastOcc(arr , key , n , 0);

}