//  -----Reverse the string using stack ------
// Be use the built in fuction of stack or STL stack 

#include<bits/stdc++.h>
using namespace std; 

int main (){
    string s;
    getline(cin,s);

    cout<< s;
    string ans =" ";
    stack <string> st;
    for(int i = 0 ; i < s.size() ; i++){
         string word;
         while(s[i]!=' '){
          word+=s[i];
          i++;
          }
          
          st.push(word);
    }

      while( !st.empty()){
       ans += st.top();
       st.pop();
     }

     cout << ans ; 
}