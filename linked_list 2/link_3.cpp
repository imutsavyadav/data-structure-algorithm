 /*
   LINKED LIST 
   1 -> find length of the linked list.
   2 -> Append last k node to start of the link list .
 */

#include <bits/stdc++.h>
#include"link_header.h"
using namespace std; 


  // length of the linked list .
  
    int length(node*&head){
    	int l=0;
    	node* temp=head;
    	while(temp!=NULL){
    		temp=temp->next;
    		l++;
    	}
    	return l ;
    }

// Append last k node to start of the linked list.

node* lastKnodeToStart(node*&head,int k ){
	node* newhead;
	node* newtail;
	node* tail=head; 
	int count=1;
	int l =length(head);
	k=k%l; 
	while(tail->next!=NULL){
		if(count==l-k){
			newtail=tail;
			newhead=tail->next;
		}
		
		tail=tail->next;
		count++;
	}
	newtail->next=NULL;
	tail->next=head;
	return newhead;

}
