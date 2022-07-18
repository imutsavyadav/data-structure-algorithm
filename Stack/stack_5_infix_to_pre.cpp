 // Infix to Prefix conversion 

// Take input in string and use the stack Data Structure.

 #include<bits/stdc++.h>
  // #include<iostream>
  // #include<stack>
  #include<string>
 using namespace std;

 // Firsty make the precedence function for the operator

 int prec( char c){ 
    if( c == '^'){
      return 3; 
    }else if( c == '*' || c == '/'){
       return 2;
    }else if( c == '+' || c == '-'){
      return 1;
    }else{
      return -1;  
      // Represent the open and close pranthesis.
    }
 }
     
      // Infix to Prefix function convert function 
      //  --> fisty you have to reverse the string given in infix string
      //  --> and when you reverse it then u see that open paranthesis is like close and viseversa 
      //  --> so consider open bracted as close  and     viseversa  '(' <-> ')' 

 string infixToprefix(string s){

      stack <char> st;
      //using STL container stack which take input as string.
      reverse(s.begin(),s.end());
      string res;
      //Store the result string. 

      //Traverse the String.
      for(int i=0 ; i<s.length() ; i++){
        //Check the charcter in the string
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                // character is equal to operand.
            res+=s[i];
        }else if (s[i]==')'){   // '(' <-> ')'
                // character is equal to open paranthesis.
             st.push(s[i]);
        }else if (s[i]=='('){  
             while(!st.empty() && st.top()!=')'){ 
                // character is equal to close paranthesis.
              res+=st.top(); 
              st.pop();
             }
             if(!st.empty())
              st.pop();

        }else{
                // character is equal to operator
                // then we push in stack first and check that the precence of the curr opr is less or greater than the opr at top of the stack.
                // If less than push 
              while(!st.empty() && prec(st.top()) > prec(s[i]) ) {

                res+=st.top();
                st.pop();
              } 
              st.push(s[i]);
             } 

      }

          while(!st.empty()){
            res+=st.top();     
                // If something is remaining in the stack than put in the res string and pop it from the stack;
            st.pop();
          }
       reverse(res.begin(),res.end()) ;
    return res;
 }

 int main (){
  cout << infixToprefix("(a-b/c)*(a/k-l)");
 }



