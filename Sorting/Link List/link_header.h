 /*
   LINKED LIST 
 */

#include <bits/stdc++.h>
using namespace std; 
class node{  // It is a user define data type 
  public:
  int data;
  node* next; // you design a variable next which store the address of the next node and its data type will be of node type 
  node(int val){  // you make the constructur so you can assign the value to it at the time of calling its instance 
  data = val ; 
  next = NULL ; 
  }

};
void insertAthead(node * &head , int val){
   // first create the new node. 
   node * n = new node(val); // we pass value as constructor does.
   n->next = head ; // And swap the value with head first node and the new node.
   head = n ; 
}
void insertAttail(node * &head , int val){
    // first create the new node. 
    node *n = new node(val) ; 
    // for traverse the linked list create the temp pointer intialize with head. 
    node *temp = head ; 
    while(temp->next!=NULL){
        temp=temp->next; 
    }
    temp->next=n;
}

void insertAtVal(node * head , int val , int value){
    // first creat node. 
    node * n = new node(val);
    // traverse node 
    if(head==NULL){
        insertAthead(head,val);
    }
    node* temp=head; 
    

    while(temp->data!=value ){
        temp=temp->next; 
    }

    n->next=temp->next; 
    temp->next=n; 


}
void display(node * & head){
    // traverse pointer temp 
    node* temp = head; 
    while(temp!=NULL){
        cout << temp->data <<"->"; 
        temp=temp->next;
    }
  cout <<"NULL"<<endl; 
}