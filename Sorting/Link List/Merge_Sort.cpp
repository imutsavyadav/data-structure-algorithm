// -------- Merge Sort --------

#include<bits/stdc++.h>
#include"link_header.h"
using namespace std;

    void split_list(node* head , node*&a , node*&b){
        // find mid of the list and make two new list 
        // first halve and second halve

        node*fast=head;
        node*slow=head;
        node*mid;
       while(fast!=NULL && fast->next!=NULL){
        mid=slow;
        slow=slow->next;
        fast=fast->next->next;
       }

        a=head;
        b=mid->next;
        mid->next=NULL;

    }

  node* mergeRecursive(node* a,node* b){

      if(a==NULL)
      return b;
      if(b==NULL)
      return a ;
      node* result=NULL;
    if(a->data <= b->data){
      result=a;
      result->next=mergeRecursive(a->next, b);
    }
    else{
      result = b;
      result->next=mergeRecursive(a,b->next);
    }
      return result;
  }

  node* mergeSort(node* &head){
  // node*head=refhead;

    if(head==NULL || head->next==NULL)
    return head ;

  node*a;
  node*b;

  split_list(head,a,b);

  mergeSort(a);
  mergeSort(b);

  head = mergeRecursive(a,b);
  return  head;
}

int main(){
    node*head=NULL;
    insertAthead(head,4);
    insertAttail(head,8);
    insertAttail(head,3);
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,6);
    insertAttail(head,10);
    insertAttail(head,9);
    insertAttail(head,7);
    insertAttail(head,11);


     display(head);
     cout<<endl;

    node*nhead=mergeSort(head);

    display(nhead);

}