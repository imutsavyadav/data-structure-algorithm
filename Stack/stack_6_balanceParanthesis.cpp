
// Balance Paranthesis code
/*      {[( )]}   
    push form start all opening bracket 
    when close bracked comes than then check with the top of the stack is same then 
    pop() it and same process is done till last our string is gone emty so that string is balance 
    or if check fail or stack not empty then teh string is unbalance.
*/

// #include<bits/stdc++.h>
#include<iostream>
#include<stack>
using namespace std;

// create isvalid function .
    // ASCII code of       ( -> 40     ) ->41      { -> 123     } -> 125    [ -> 91    ]->93
bool isvalid(string s){
    stack <char> st;
    bool ans;
    for(int i=0 ; i<s.length() ; i++){
         if( s[i]!='}'  || s[i]!=')' || s[i]!=']'){
             st.push(s[i]);
         }
          else if (s[i] == ')') {
              if(!st.empty() and st.top()=='('){
                st.pop();
              }
              else
              {
                ans = false;
               break; 
             }
          }
          else if (s[i] == '}') {
              if(!st.empty() and st.top()=='}'){  
                st.pop(); 
              }
              else
              {
                ans = false;
               break; 
             }
          }
          else{
              if(!st.empty() and st.top()=='}'){
                 st.pop();
               }
               else
              {
                ans = false;
               break; 
             }
          }
    }

    if(!st.empty())
      return false;

    return ans;

}

int main (){
  cout << isvalid("{[()]}");
}