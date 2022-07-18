 /*
   LINKED LIST 
   1 -> create a new sorted linked list from the two sorted link list in Irative way.
   2 -> Do in recursive way .
 */

#include <bits/stdc++.h>
#include"link_header.h"
using namespace std; 


// Merge two sorted linked list in sorted manner

// In this we take two pointer on different linked list  and 
// compare them and make an dummy node and push the smaller one 

node * mergeLL(node*head1 , node*head2){
	node*p1=head1;
	node*p2=head2; 
	node * dummy = new node(-1);
	
	node*p3=dummy;
	while(p1!=NULL && p2!=NULL){
		if(p1->data < p2->data){
			p3->next = p1; 
			p1=p1->next;
		}else{
			p3->next=p2;
			p2=p2->next;
		}
		p3=p3->next;
	}
	// now if the some node in both linked list is remain so push in the new linked list 

	while(p1!=NULL){
		p3->next=p1;
		p1=p1->next;
		p3=p3->next;
	}

	while(p2!=NULL){
		p3->next=p2;
		p2=p2->next;
		p3=p3->next;
	}
	p3->next=NULL;
	return dummy->next;
}

// recursive method to merge linked list 

node* mergeRecursive(node*head1, node*head2){
	// base case 
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;
	node* result; 
	if(head1->data < head2->data){
		result=head1; 
		result -> next= mergeRecursive(head1->next, head2);
	}else{
		result=head2; 
		result->next= mergeRecursive(head1, head2->next);
	}
	return result;
}