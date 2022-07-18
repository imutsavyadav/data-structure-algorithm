#include<bits/stdc++.h>
using namespace std ; 

// Tower of Hanoi 
void tower(int n , char src , char des , char help){
    if(n==0)
      return ; 
    tower(n-1,src,help,des);
    cout << "Move from " << src << " to " << des << endl;
    tower(n-1,help,des,src);
}
int main(){
    tower(3,'A','C','B');
}