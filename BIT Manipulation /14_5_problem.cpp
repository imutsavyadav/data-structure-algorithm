// wap a program to find a unique number in an Array wherea ll number except 
// one , are present thrice . 

#include<bits/stdc++.h>
using namespace std ; 

bool getBit(int n , int pos){
    return ( n & (1 << pos)) !=0;
}

int setBit(int n , int pos){
    return (n | (1<<pos));
}

int find_unique(int arr[] ,int n){
    int result = 0;
    // we make an array of 64 bit size
    for(int i = 0  ; i < 64 ; i++){
        // itrate over the array 
        int sum = 0 ; 
        for(int j = 0 ; j< n ; j++ ){
            if(getBit(arr[j] , i)){
                sum++;
            }
        }
        if(sum%3!=0){
            result = setBit(result , i);
        }
    }
    return result;
}
int main(){
    int arr[] = {1, 2, 3 , 1 , 2 , 3 , 4 , 1 , 2 , 3 };
    cout << find_unique(arr , 11);
}