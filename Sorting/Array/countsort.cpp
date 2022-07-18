// count sort Algorithm in this algorithm you sort an of multiple occurence of element.
#include<bits/stdc++.h>
using namespace std; 

 void countSort(int arr[] , int n){
 	// define the size of the count array . 

 	// the maximum no. in source arr plus 1 is size of the count array 

 	int M_arr = arr[0];

 	for(int i=0 ; i<n ; i++){
 		if(arr[i]>=M_arr)   
 			M_arr=arr[i];   // 4
 	}

   int count[M_arr+1]={0};  // count array  size is 5

     // traverse the source arr and save the count of each element in the count array.

   	for(int i=0 ; i<n ; i++){
   		++count[arr[i]];
   	}

     // count array     -->   0 2 2 2 1
   	 //              index    0 1 2 3 4  

   	// Now change the count array 

   	for(int i=1 ; i<= M_arr ; i++){
          count[i]+=count[i-1];
   	}

   	// updated count array is  -> 0 2 4 6 7

   	int output[n];  // output array 

   	for(int i=n-1 ; i>=0 ; i--){
   		// pre-decrement
   		output[-- count[ arr[i] ] ]= arr[i] ;
   	} 



   	// output arr -->      1 1 2 2 3 3 2 
   	//				index  0 1 2 3 4 5 6 
   			// pre decrement 
   	// arr[6]=1 count[1]=1 		-- 0    output[1]=1
   	// arr[5]=2 count[2]=3 		-- 2    output[3]=2
   	// arr[4]=2 count[2]=2 		-- 1    output[2]=2
   	// arr[3]=4 count[4]=6 		-- 5    output[6]=4
   	// arr[2]=3 count[3]=5 		-- 4    output[5]=3
   	// arr[1]=3 count[3]=4 		-- 3    output[4]=3
   	// arr[0]=1 count[1]=0 		-- 0    output[0]=1

    
    // update the source array 

    for(int i= 0 ; i<n ; i++){
    	arr[i]=output[i];
    }

 }

 int main (){
     // size of the array 

 	int n ;     // 7
 	cin >> n ; 
    
 	int arr[n];  //  1 3 3 4 2 2 1

 	for(int i=0 ; i<n ; i++){
 		cin >> arr[i] ;
 	}

 	countSort(arr , n);

 	for(int i=0 ; i< n ; i++ ){
 		cout << arr[i] << " ";
 	}
 }