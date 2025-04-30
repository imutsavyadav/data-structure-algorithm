 /*
   LINKED LIST 
   1 -> How to add a cycle in the linked list at particular positionl
   2 -> Check wheather a cycle is present in the link list or not. 
   3 -> Remove the cycle from the link list if it is present.
 */

#include <bits/stdc++.h>
#include"link_header.h"
using namespace std; 

// Add cycle to the linked list 

void addCycle(node*&head,int pos){
	// traverse pointer temp
	node* temp = head;
	int count=1;
	node*targetNode;
	while(temp->next!=NULL){
		if(count==pos){
			targetNode=temp;
		}
		temp=temp->next;
		count++;
	}
		temp->next=targetNode;
}


// Detect cycle is present or not in the linked list .
// this is based on the floyid's algorithm or hare and tortoise algorithm 
// In this we make a two pointer and fast and slow and move fast by 2 and slow by 1 
// if the both pointer meets and there is a cycle +nt other wise not .

bool detectCycle(node*&head){
	node*fast=head;
	node*slow=head;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow){
			return true;
		}
	}
	return false;
}

// removal of the cycle 
// first intialize both the pointer 

void removeCycle(node*head){
	node* fast=head;
	node* slow=head;

	do{
		fast=fast->next->next;
		slow=slow->next;
	}while(slow!=fast);
    fast=head;
    while(fast->next!=slow->next){
    	slow=slow->next; 
    	fast=fast->next;
    }
    slow->next=NULL;
}