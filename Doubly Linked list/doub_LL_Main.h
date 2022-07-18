#include <bits/stdc++.h>
using namespace std; 
class node{  // It is a user define data type 
  public:
  int data;
  node* next; // you design a variable next which store the address of the next node and its data type will be of node type 
  node* prev; // you design a variable pre which store the address of the prev node and its data type will ne of node type
  node(int val){  // you make the constructur so you can assign the value to it at the time of calling its instance 
  data = val ; 
  next = NULL; 
  prev = NULL; 
  }
};
void insertAthead(node*&head , int val){
    // first create a new node 
    node* n= new node(val);   // prev(NULL) -val - (NULL)next
   
    n->next=head;
    if(head!=NULL)
    head->prev=n;
    head=n;

}
void insertAttail(node*&head , int val){
// create an new node 
  node* n = new node(val);
  // traverse pointer temp
  node* temp = head;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void insertAtpos(node*&head , int val , int pos){
// create an new node 
  node* n = new node(val);
  // traverse pointer temp
  node* temp = head;
  int count=0;
    while(count<pos-1){
      temp=temp->next;
      count++;
    }
    n->next=temp->next;
    n->prev=temp;
    temp->next->prev=n;
    temp->next=n;
}
void del(node*&head , int val){
  if(head==NULL || head->next==NULL){
     head = NULL; 
     return;
  }
  // traverse pointer 
   node*temp=head;
   while(temp->data!=val){
    temp=temp->next;
   }

   node*todelete=temp;
   if(temp==head){
    // temp->next->prev=NULL;
    // head=temp->next;
    temp=temp->next;
    temp->prev=NULL;
    head=temp;
   }
   else if(temp->next!=NULL){
   temp->prev->next=temp->next;
   temp->next->prev=temp->prev;
   }else
   temp->prev->next=NULL;
   delete(todelete);
}
void display(node*head){
    // traverse pointer temp 
    node*temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }

    cout<< "NULL";
}

// void reverse the doubly linked list .
//   interchange the value of the prev and next pointer and return the newhead 

node* reverse(node*&head){ // return the newhead
  // traverse pointer 
  node*temp=head;
  node*t1=NULL;  // for swaping the prev and next
  while(temp!=NULL){
    // swaping 
    t1=temp->prev;
    temp->prev=temp->next;
    temp->next=t1;

    // move the loop
    temp=temp->prev;
  }
    return t1->prev;
}

// int main(){
//     // first create an head which store the address of the first node
//     node*head=NULL;
//     insertAthead(head,1);
//     insertAttail(head,2);
//     insertAttail(head,3);
//     insertAttail(head,4);
//     insertAtpos(head,5,3);

//     display(head);
//     del(head,5);
//     cout<<endl;
//     display(head);
//     cout<<endl;
//     node* newHead=reverse(head);
//     display(newHead);
// }