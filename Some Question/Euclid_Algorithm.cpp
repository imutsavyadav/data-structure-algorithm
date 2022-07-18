// to find the GCD / HCF of two no. 

#include<bits/stdc++.h>
using namespace std;

void Gcd(int a  , int b ){
    while(b!=0){
        int rem = a % b ;
        a = b ; 
        b = rem ;
    }
    cout << a ;
}
int main(){
    int a , b ; 
    cin >> a >> b ; 
     cout<< __gcd(a , b);
     Gcd(a,b);
}