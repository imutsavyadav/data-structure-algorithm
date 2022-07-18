#include<bits/stdc++.h>
using namespace std ; 
void rev (string s){
    if(s.size()==0)
     return ; 
    char ch = s[0];
    rev(s.substr(1));
    cout << ch ; 
}
int main(){
    string s ; 
    getline(cin , s);
    rev(s);
}