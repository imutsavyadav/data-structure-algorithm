// print upto N in 
// Increasing and decreasing order using recursion
#include<bits/stdc++.h>
using namespace std ; 

// Increasing  order 
void inc (int n ){
    // base case 
    if(n==1){
        cout << 1<<" ";
        return ;
    }
    inc(n-1);
    cout << n << " ";
}

// Decreasing order 
void dec ( int n ) {
    // base case 
    if(n==1){
        cout << 1 ; 
        return ;
    }
    cout <<  n << " ";
    dec(n-1);
}
int main()
{
    int n; 
    cin >> n ; 
    // first print in increasing order 
    // means 1 to n .
    inc(n);
    cout << endl;
    // second print in dresing order
    // means n to 1 . 
    dec(n);
}