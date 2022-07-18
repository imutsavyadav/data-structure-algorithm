// ------ Catalan Number -------
/*
	These are a sequence of Natural Number that occurs in various
	counting problem , often involving recursively defined object

	Mathematical form 
           2n
             C
     		  n
    Cn =  --------- =  ⨊ Ci * Cn-i  , where i = o to n-1
     	    n + 1

     	    C0 = 1 , 0th catalan number
     	    C1 = 1 , 1st catalan number
			
			C2 = C0C1 + C1C0 = 1*1 + 1*1 = 2 , 2nd calalan nunber


*/

// find the value of the  nth catalan number . 

#include <bits/stdc++.h>
using namespace std; 

// catalan number
  
  int catalan (int n ) {

  	  // base case 
  		 if(n<=1) return 1 ; 

  		 int res = 0 ;

  		 for(int i=0 ; i<n ; i++){
  		 	res+= catalan(i) * catalan(n-i-1);
  		 }

  		 return res;
  }

int main () {
		cout << catalan(5);
}

/* Application of the catalan number 
 1 -> Possible BSTs
 2 -> paranthesis / bracket combinations 
 3 -> possible of forests 
 4 -> way of triangulation 
 5 -> possible path in a matrix
 6 -> deviding a circle using N chords 
 7 -> dyck words of given length & much more.