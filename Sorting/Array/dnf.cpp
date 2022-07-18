// ------ dutch national flag algorithm ---- or 0 , 1 ,2 sort -------
#include<bits/stdc++.h>
using namespace std; 

// swap function 

void swap ( int arr[] , int a , int b ) {
    int temp = arr[a]; 
    arr[a] = arr[b]; 
    arr[b] = temp ;  
}

// dnfSort function ˚˚˚˚ ̊̊̊̊

void dnfSort(int arr[] , int n){
    // we make three pointer low , mid and high 
    // initaly low and mid stating to 0th index
    // when mid == high then our array is sort.
    // use swaping .

    int low = 0, mid = 0  , high = n-1 ; 

        // traverse the array till mid != < high

     while(mid<=high) {

        if(arr[mid]==0){

            swap(arr , low , mid);
            mid++;
            low++;

        } else if (arr[mid]==1) {

            mid++;

        } else {

            swap(arr , mid , high);
            high--; 

        }
    }

}

int main (){
    int n ; 
    cin >> n ; 

    int arr [n];

    for ( int i=0 ; i< n  ; i++){
        cin >> arr[i]; 
    }

    dnfSort(arr, n );

    for( int i=0 ; i<n ;i++){
        cout << arr[i] << " ";
    }
}