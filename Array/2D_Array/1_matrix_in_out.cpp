#include<iostream>
using namespace std;
int main(){
    int n, m;
    cout<<"Enter the number of rows and columns : ";
    cin>>n>>m;
    cout << endl;
    int arr[n][m];

    // Taking input of the Matrix
    // E11 , E12 , E13 , E14 ... 
    // where 1 -> for the  row and 1,2,3.4.. -> for the coulumn 

    for (int i=0; i<n ; i++){
         for (int j=0; j<m ; j++){
            cin>>arr[i][j];
          }
    }

    for (int i=0; i<n ; i++){
        cout<<"Row "<<i+1<<" : ";
         for (int j=0; j<m ; j++){
             cout<<arr[i][j]<<" ";
          }
          cout<<endl;
    }
}