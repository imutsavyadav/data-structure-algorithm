// Sieve of Erotosthenis 
// use for to print all of the prime no. in a given range 
// create an array up to given n.
// we mark the multiple of prime no in that array 

#include <bits/stdc++.h>
using namespace std ; 

void primeSeive(int n ){
    int prime[n] = {0}; 
    
    // itrate the loop and and marked the multiple of each index
    for(int i = 2 ; i< n ; i++){
        if(prime[i] == 0){
            for(int j = i*i ; j < n ; j+=i){
                prime[j] = i ;
            }
        }
    }

    for(int i =2 ; i< n ;i++){
        if(prime[i] == 0){
                cout << i << endl;
        }
    }
}

int main(){
    int n ; 
    cin >> n ; 



    primeSeive(n);

}