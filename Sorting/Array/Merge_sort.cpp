// #include<iostream>
// using namespace std;

// void Merge( int arr[], int l , int mid, int r){
//     int n1=mid-l+1;
//     int n2=r-mid;
//     int a[n1];
//     int b[n2];

//     for(int i=0;i<n1;i++){
//         a[i]=arr[l+i];
//     }

//     for(int i=0;i<n2;i++){
//         b[i]=arr[mid+i+1];
//     }

//     int i=0,j=0,k=l;

//     while(i<n1 && j<n2){

//         if(a[i]<b[j]){
//             arr[k]=a[i];
//             k++; i++;
//         }else{
//             arr[k]=b[j];
//             k++; j++;
//         }
        
//     }

//     while(i<n1){
//         arr[k]=a[i];
//             i++; k++;

//     }
//     while(j<n2){
//           arr[k]=b[j];
//             k++; j++;
//     }
// }

// void mergeSort(int arr[],int l, int r){
    
//         if ( l < r){
//             int mid=(l+r)/2;
//             mergeSort(arr,l,mid);
//             mergeSort(arr,mid+1,r);

//             Merge(arr,l,mid,r);

//         }
// }

// int main(){
    
//    int arr[] ={6,3,9,5,2,8,7,1};
//     mergeSort(arr,0,7);
//     for(int i=0; i<7; i++){
//         cout << arr[i]<< " ";
//     }
//     cout<<endl;
   
// }

#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair <int,int>
#define rep(i,a,b)for(int i = a ; i<b ; i++)
using namespace std;

void merge_arrays(int arr[] , int st , int mid , int en){
    // here we make two array as one and second half of the partition
    // than by the help of these array we change the value of the main array 

    // initialisation of both array 

    int n1 = mid-st+1 ; // include the mid element so add 1 
    int n2 = en - mid ; 

    int a[n1] , b[n2];

    // fillig the  a and b array 
    rep(i,0,n1) a[i] = arr[st+i];

    rep(i,0,n2) b[i] = arr[mid+1+i];


    // take three pointer to travese in all arrya 
    int i = 0 ,  j = 0 , k = st ; 

    while(i<n1 && j< n2 ){
        if(a[i]<b[j]){
            arr[k] = a[i];
            k++ ; i++; 
        }else{
            arr[k] = b[j];
            k++ ;  j++;
        }
    }

    // now check for the remaning element 

    while(i<n1){
        arr[k]=a[i];
        k++ ;i++;
    }

    while(j<n2){
        arr[k]=b[j];
        k++ ;j++;
    }
}
void mergeSort(int arr[] , int st , int en){
    if(st<en){
        // to partition the array we use the mid pointer
        int mid = (st+en)/2;
        // call for first part upto mid 
        mergeSort(arr,st,mid);
        // call for second part greater than mid
        mergeSort(arr,mid+1,en);

        // than we have to merge the partition array 
        merge_arrays(arr,st,mid,en);
    }
}
int main() {
    int n ;cin >>n;
    int arr[n];
    rep(i,0,n)cin>>arr[i];

    mergeSort(arr,0,n-1);

    rep(i,0,n)cout<<arr[i]<< " ";

}