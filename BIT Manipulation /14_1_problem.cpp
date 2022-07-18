// Wap to check if given no is power of 2 or not 
//   and 
// Wap to count the no. of 1 in any binary no.

#include<iostream>
using namespace std; 

bool isPowerOf(int n){
    return (n && !(n&(n-1))) ; 
}

int numberOfsetBIT(int n){
    int count=0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count ; 
}
int main (){
     
     // Program 1 
      
    // Method 1:- As we all know just devide the no. by as at last remainder is zero or not
    // Method 2:- This is nothing but we trace pattern of binary no. as such 
        // firstly if we know a no. n=6 (0110) than from its 
        // right most setBIT we interchange 0 and 1 then be get
        // binary form of its n-1 no. (means of 5 (0101) )

        // secondly if we do & operation b/w n and n-1 then the coming 
        // ans has same bit as n except right most bit .

        // the 2^n types of no like N = 8 (1000) , 16 (10000) also represent as 1<<n 
        // take N-1 of that no. is 7 (0111) , 15 (01111) 
        // now N & N-1 is  always 0000 

        cout<<isPowerOf(8)<<endl;
 
    // Program 2 
     
     // for count total no. for one we constantly take 
     // and operation b/w  n and n-1 so from right all set bit become uset 
     // and be count this operation as time it run is ans of  set bit in binary no.

        cout<< numberOfsetBIT(7);


}