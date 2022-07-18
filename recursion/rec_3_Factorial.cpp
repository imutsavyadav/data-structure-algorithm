// Print the factorial no. using recursion. 
#include<iostream>
using namespace std;

 int Fact ( int n){
    if ( n==0 || n==1){
        return 1;  // the value of 0 and 1 factorial is 1.
        // base case
    }
   return n * Fact(n-1);
   // this is the recursive function n * Fact(n-1).
}

int main(){
    int n;
    cin>>n;
    cout << Fact(n);
}