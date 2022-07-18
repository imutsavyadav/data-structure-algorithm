// check whether the given array is sorted or not?
#include<iostream>
using namespace std;
// arr[0]< arr[1] and remaining send to rec 
bool sort( int arr[] , int n){
    if (n==1){
        return true;
    }
    bool restArr = sort( arr+1 , n-1);
    return (arr[0]< arr[1] && restArr);
}
int main(){
    int arr[]={ 2,7,5,6,9};
    cout << sort(arr,5);
}