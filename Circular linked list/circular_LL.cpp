#include<bits/stdc++.h>
using namespace std ; 
class node{
   public:    
   int data;
   node* next;    
   node(int val){
       data=val;
       next=NULL;
   }
};
void insertAthead(node* &head,int val){
    //create a new node
    node* n = new node(val);
    if(head==NULL){
    head=n;
    n->next=head;
    return;
    }
   // traverse pointer 
    node*temp=head;
     
    do{
        temp=temp->next;
    }while(temp->next!=head);  // Now it have acces the last node
    
    n->next=head;
    head=n;
    temp->next=head;
}

void insertAttail(node* &head, int val){
  // create a new node 
  node* n = new node(val);
  
  if(head==NULL)
  {
     insertAthead(head,val);
     return;
  }
  // traverse pointer
  node*temp=head;

  while(temp->next!=head){

     temp=temp->next;// Now it have acces the last node
  }    

  temp->next=n;
  n->next=head;

}
void insetAtval(node*&head,int val , int value){

}

// Delete the given node.

void del(node*&head , int val){
  node*todelete=NULL;
   if(head->next==head && head->data==val){
       todelete=head;
       head = NULL ; 
       delete(todelete);
       return;
   }
   if(head->data==val && head->next!=head){
      node*temp=head;
      while(temp->next!=head){
        temp=temp->next;
      }
      todelete=head;
      head=head->next;
      temp->next=head;
      delete(todelete);
      return;
   }
   // traverse pointer 
   node*temp=head;
   while(temp->next->data!=val){
    temp=temp->next;
   }
   todelete=temp->next;
   temp->next=temp->next->next;
   delete(todelete);
}
void display (node*&head){
  // travarse pointer 
  node*temp=head;
  if(head==NULL)
    cout << "No node +nt in the list";
  do{
    cout << temp->data << "->";
    temp=temp->next;
  }while(temp!=head);
    
}

int main(){
    // Head pointer to store the address of the starting node of list
    node*head=NULL;
    insertAthead(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);    

    display(head);

    del(head,4);
    cout<<endl;
    display(head);
}