// wap to find 2 unique noumber in an array where
// all number except 2 are present twice

#include<bits/stdc++.h>
using namespace std ; 

int  set_bit(int n , int pos){
    return (n & (1<<pos))!=0 ;
}

void find_TwoUnique(int arr[] , int n ){
    // first calculate the xorsum of the array element
    int xorSum=0 ; 
    for(int i = 0 ; i< n ; i++){
        xorSum = xorSum ^ arr[i];
    }
    int tempXor = xorSum;

    // find the right most set bit postion in the xorSum 

    int setBit = 0 ; 
    int pos = 0 ; 
    while(setBit!=1){
        setBit = (xorSum & 1) ; 
        pos++;
        // and update the xorSum with right shift by 1
        xorSum = xorSum >> 1;
    }
    // now itrate over the array and find the element whose bit is 
    // set at the pos
    int newXor= 0 ; 
    for(int i = 0 ; i< n ; i++){
        // check for the setbit
        if(set_bit(arr[i] ,pos-1)){
            newXor = newXor ^ arr[i];
        }
    }
        cout << newXor << endl;
        int  ans = newXor^tempXor ;
        cout << ans << endl;
}
int main (){
    int arr[] = { 1, 2 , 3 , 1 , 2 , 3 , 5 ,7};
    // ans will be 4 and 6 
    find_TwoUnique(arr , 8);
}