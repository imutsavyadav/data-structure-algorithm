
#include "factorialOfNo.h"
#include<iostream>
// using namespace N;
using namespace std;
int main(){
   //  n         !n
   //   C  =    ------
   //     r     !r !n-r
   int n, r;
   int com;
   com= fact(n)/fact(r)*fact(n-r);
   cout<<com;
}
