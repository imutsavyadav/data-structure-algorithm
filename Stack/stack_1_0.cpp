//      ------------------------ STACK -------------------------
//     -> It is linear datasturcture which store the data in form of last in first out (LIFO)
//    -> basic  function of stack is puch() pop()  top() empty() operation . 
//   -> top store the addrese of the element present on the top of the stack first intialize with -1 mean no element present in the stack
 #include <iostream>
#define n 100
using namespace std; 


// Stack implementaion using array 
class stack{
      int * arr; 
      int top ; 
      public : 
      stack(){
          // you create an  array using the dynamic memory allocation .
          arr= new int[n]; // predefine the value of  n 
          top = -1;
      }

      // push operation --> check the value of the top and perfrom operation according to it.
      

      void push(int x){
          if(top==n-1){
              cout << "Stack Overflow";
              return;
          }
           top++;
           arr[top]=x;
      }

      // pop operation --> check the valu of the top and perfrom opearion according to it. 

      void pop(){
          if(top==-1){
          cout << " No element present in the stack";
          return;
          }
          top--;
      }

      // top operation --> return the value present at the top 

      int Top(){
          if(top==-1){
          cout << " No element present in the stack";
          return -1;
          }
          return arr[top];
      }

     // empty operation --> check that stack is empty or not .

     bool empty(){
         return top==-1; // if cond is true return true if not return false 0 
     }

};

int main(){
    // create an instance or object.
    stack st; 
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
   cout<< st.Top();
    st.empty();

    return 0;
}