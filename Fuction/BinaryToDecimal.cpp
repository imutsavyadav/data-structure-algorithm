// #include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
  int n;

  cout<<"binary to decimal conversion is ---->>>"<<endl;
  cin >> n;
  int binaryToDecimal(int);
  cout<<binaryToDecimal(n)<<endl;

  int o;
  cout<<"Octal to decimal conversion is ------>>>"<<endl;
  cin>> o;
  int OctalToDeciamal(int);
  cout<< OctalToDeciamal(o)<<endl;

  string h;
  cout<<"hexadecimal to decimal conversion is ------>>>"<<endl;
  cin>> h;
  int HexaToDeciamal(string);// we pass here string as an data type.because in hexadecimal we use character A  B C D E F  as an number greater than the 9
  cout<< HexaToDeciamal(h)<<endl;
 
  int d;
  cout << "decimal to binary conversion is ------>>>>"<< endl;
  cin>> d;
  string decimalToBinary(int);
  cout<< decimalToBinary(d);
}

// 1001110101 --->>> 2^0*1+2^1*0+2^3*1+...=
int binaryToDecimal(int N) {
  int dec=0;
  int index=1;   //  here index represent the whole 2^0 is the first          index having the value 1 . And in further case 2^1 is the second index having the value 2. and so on so consclusion is that index having value of multiple of 2.
  while(N>0){
    int lastDigit=N%10;
    dec+= index*lastDigit;
    index*=2;  // Here it is .
    N/=10;
  }
  return dec;
}

//  54 ---------->>>>>>>  8^0*4+8^1*5
int OctalToDeciamal(int O){
   int oct=0;
   int index=1; // from above consideration is index having multiple of 8.

   // we chech the number till that the number became 0 by using the devide operation in each itrater.

   while(O>0){
     int lastDigit=O%10;
     oct+=index*lastDigit;
     index*=8;
     O/=10;
   }
     return oct;
}


 int HexaToDeciamal(string H){
     int hex=0;
     int index=1;

     int s = H.size(); // size is a inbuild funtion in the string .h header file library.

 /*
     Key notes that
     if we know that how many times we have to itrate the loop
     than we use for loop
     if not than we use the while lopp.
*/

// here we know that the size of the string . so use the  for loop

   /*
      1 C F  this the hexadecimal number so in decimal
            string index is like 0 -> 1; 1 -> C ; 2 -> F;
      Hexadecimal  index is like F -> 0; C -> 1 ; 1 -> 2;

      so loop will star from s-1 position of the string value and goes on decrease
    */
for(int i=s-1; i>=0; i--){

     if ( H[i] >= '0' && H[i] <= '9')
        hex += index * ( H[i] - '0'); // here sring change in no.

        else if ( H[i] >= 'A' && H[i] <= 'F')
            hex += index * ( H[i] - 'A' + 10);  //

            // example  1CF =  F - A + 10 = 5 + 10 = 15 ;

            index*=16;
}
    return hex;
 }
string decimalToBinary(int N){
    /*
        8 4 2 1
        1 1 1 0
        So here we have to convert the decimal to binary 
            14 - > 14 % 2 = 0 ,
            7 -> 7 % 2 = 1 , 
            3 -> 3 % 2 = 1 ,
            1 -> 1 % 2 = 1 ,
            0 
    */
    string s = "" ;
    while(N>0){
        s+=(N % 2) + '0' ;
        N/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
