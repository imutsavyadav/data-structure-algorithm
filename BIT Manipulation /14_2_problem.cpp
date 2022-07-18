// wap to generate all posible subset of a set {a, b , c} .
// total no. of subset is 2^n - 1 . 
// (1<<n) gave  2^n 


#include<bits/stdc++.h>
using namespace std ;
void subSet(int arr[],int n ){
    for(int i=0 ; i < (1<<n) ; i++){
        for(int j= 0 ; j <n ; j++){
            if(i & (1<<j)){
                cout <<arr[j]<<" ";
            }
        }
        // if(i!=(1<<n-1))
        cout<<endl;
    }
}
int main(){
    int arr[]={1,2,3,4};
    subSet(arr,4);
}