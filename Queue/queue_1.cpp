 //    Basic implementation of the queue ..

 //    --- It is a linear Data structure which store the data in form of FIFO technique 

 //  FIFO means First In First Out  for eg In any case where the user come first and serve first is siqnifies the queue behaviour .
 // so for define queue be  take to pointer from and back 
 // where at front postion store the element or data which come first 
 // and at back postion sotre the element or data which come last in the queue.
 // Basic operation in the queue is .. 
    //    1.   enqueue -- > whose work is add more element /  data in the  queue. code part we move or add the element in the back pointer.
    //    2.   dequeue -- > whose work is remove element from the queue . or task is completed for the first element and remove it from queue or code part we move front pointer in forward direction .
    //    3.   peek --> Tell about the element / data which come first or code part reutrn the value at front . 
    //    4.   empty --> Tell about queue is empty right now or not. code part if front pointer is equal to -1 or front pointer is greter than back pointer than return true.

//         Queue emplemantation using Array.

    // #include<bits/stdc++.h>
    #include<iostream>
    using namespace std; 
    
    #define n 100 // pre define the size of the array . 
    class queue{
        public: 
            int front;
            int back;
            int * arr;  // integer pointer make for hold the address of the Array .
                queue(){
                    front = -1;
                    back = -1;
                    arr = new int[n] ; // we make array by using dynamic memory allocation.
                }

                // Basic operation push operation or enque

                void push(int x){
                    if(back == n-1){
                        cout << "queue is overflow";
                        return;
                    }
                     back++;
                     arr[back]=x;

                     if(front==-1){
                         front++;
                     }
                }

                //  pop operation or dequeue 

                void pop(){
                    if(front==-1 || front > back){  
                        cout << "No element in the queue";
                        return ; 
                    }
                    front++ ; 
                }

                // peek operation 

                int peek(){
                    if(front==-1 || front > back){  
                        cout << "No element in the queue";
                        return -1; 
                    }
                    return arr[front];
                }

                // empty operation 

                bool empty (){
                    if(front==-1 || front > back){
                        return true;
                    }
                    return false;
                }
                
    };
  
  int main (){
      queue q;
      q.push(1);
      q.push(2);
      q.push(3);
      q.push(4);
      
      while(!q.empty()){
        if(q.front <=q.back)
        cout <<  q.peek() << " ";
        q.front++;
      }
   

  }