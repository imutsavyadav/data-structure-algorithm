// Recursion -> It is function call it self to make an the problem smaller

// Another way to define it --> We write an function in itself form so we create an recursion 

// Basically think about the recursive function by which you can shorter your problem

// and aslo think about the base case or end point of the rucursive fun . 

// Question -> Add all number till n using the recursion 
#include<iostream>
using namespace std;


int sumOfN(int n){
    if(n==0){    
        return 0;  // base case
    }
    return n + sumOfN(n-1);

    // this is the recursive function n + sumOfN(n-1)
}

int main(){
    int n;
    cin >>n;
    cout<<sumOfN(n);
}