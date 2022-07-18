// ------  Queue emplementation using Linked list -------

// #include <bits/stdc++.h>
#include<iostream>
using namespace std; 

// create node  

class node {
      public:
            int data ; 
            node * next; 
        node(int val){
            data = val; 
            next = NULL; 
        }   
};

// create queue

class queue{
    // two node pointer 
       node* front;
       node* back;

         public:
         queue(){
             front=NULL;
             back=NULL;
         }

         // basic operation of queue. 

         // push operation or enque.

        void push(int val){
            // create node for store the data inserted in the queue.
               node* n= new node(val);
            if(front==NULL){
                // intialize both the pointer with first node.
                back=n;
                front=n; 
            }
               // Think like you have to insertAtlast in the linked list back signifies the last node.

               back->next=n;
               back=n;

        }

        // pop operation 

         void pop (){
            if ( front == NULL ){
                cout<< " No element in the Queue";
            }
            node* todelete = front;
            front = front -> next;
            delete(todelete);

        }

        // peek operation 
        
        int peek(){
             if ( front == NULL ){
                cout<< " No element in the Queue";
                return -1;
            }
            return front->data;

        }

        // empty operation 

        bool empty(){
            if ( front == NULL ){
                return true;
            }
            return false;
        }


};

int main(){
  queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  while(!q.empty()){
      cout << q.peek() << " ";
      q.pop();
  }
  if(q.empty()){
    cout<< "\nQueue is Empty Now!";
  }
}