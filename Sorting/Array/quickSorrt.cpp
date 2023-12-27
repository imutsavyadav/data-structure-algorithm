// // Quick Sort Algorithm.

// #include<bits/stdc++.h>
// using namespace std; 

// void swap(int arr[] , int a , int b){
// 	int temp =arr[a]; 
// 	arr[a]=arr[b];
// 	arr[b]=temp;
// }

// int partition(int arr[] , int l , int r){
// 	// make an pivot pointer -> 
// 	int pivot = arr[r] ; 

// 	// make an i pointer denote the last no which is less than pivot
// 	int i = l-1;

// 	// traverse the arr from start of end-1 and find the correct positon for the pi as partion of the array in two part 
// 	// first part have all smaller element than pi 
// 	// second part have all greater element than pe

// 	for(int j = l ; j < r ; j++){
// 		if(arr[j] < pivot){
// 			i++;
// 			swap(arr,i,j);
// 		}
// 	}

// 	// after traverseing the i+1 position is correct for pivot to differentiate b/w first and second halves

// 	swap(arr,i+1,r);

// 	return i+1;

// }

// void quickSort(int arr[] , int l , int r){

// 	// make an pi 

// 	if(l<r){
// 		int pi = partition(arr,l,r);

// 		quickSort(arr,l,pi-1);
// 		quickSort(arr,pi+1,r);
// 	}
// }

// int main (){
//   // size of the array 

// 	int n ; 
// 	cin >> n ; 
     
//      int arr[n];

//     for(int i=0; i< n ; i++){
//     	cin >> arr[i];
//     }

	

// 	quickSort(arr,0,n-1);

// 	// quickSort(arr,l,r); l is the starting point r is the last point of the array .

// 	for(int i=0 ; i<n ; i++){
// 		cout << arr[i] <<" ";
// 	}
// }



#include <bits/stdc++.h>
using namespace std;
int partition_arr(int arr[] , int st , int en) {
    // take pivot element as last element of the array 
    int i = st -1 ; // fist set i to -1 
    // traverse in the array 
    for(int j = st ; j<=en ; j++){
        // compare the elemnet with the last element 
        // because that is our pivot element 
        // we have to partition the array in two half 
        // wrt pivot element 
        if(arr[j]<arr[en]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    // all element smaller than the pivot element is up to i
    // so we have to swap the postion b/w i+1 and en
    swap(arr[i+1],arr[en]);

    // return the index of the curr pos of the pivot element 
    return i+1;
}
void quickSort(int arr[] , int st , int en) {
    if(st<en){
        // pivot element index
        int pi = partition_arr(arr,st,en);
        // call for less than pivot element
        quickSort(arr,st,pi-1);
        // call for greater than pivot element 
        quickSort(arr,pi+1,en);
    }
    // here we have the hidden base case i.e. st==en
}

// }
int main(){
    int n  ; cin >> n ; int arr[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    // quick sort 
    // input arry , start and end point of the array 
    quickSort(arr,0,n-1);
    for(int i = 0 ; i< n ; i++) cout << arr[i] << " " ; 

}