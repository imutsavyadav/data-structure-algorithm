 /*
   LINKED LIST 
   1 -> find length of the linked list.
   2 -> intersect  two linked list.
   3 -> find the interseciton point b/w two linked list if it is exixt. 
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

// Create an intersection point b/w two linked list

void intersctTwoll(node* head1 , node* head2 , int pos){
	node* temp1=head1;
	pos--;
	while(pos--){
		temp1=temp1->next;
		
	}
	node* temp2=head2;
	while(temp2->next!=NULL){
		temp2=temp2->next;
	}
	temp2->next=temp1;
}


// print the intersection point of the linked list.

int intersectPoint(node* head1 , node* head2){
	int l1= length(head1);
	int l2= length(head2);

	node* ptr1;
	node* ptr2;  // make two pointer
	int d=0 ;
     if(l1>l2){    // Difference d and make ptr1 to long linked list
     	d=l1-l2;   
     	ptr1=head1;
     	ptr2=head2;
     }else{
     	d=l2-l1;
     	ptr1=head2;
     	ptr2=head1;
     }

     
     while(d){
     	ptr1=ptr1->next;
     	if(ptr1==NULL)
     		return -1;
     	d--;
     }
     while(ptr1!=NULL && ptr2!=NULL){
     	if(ptr1==ptr2)
     		return ptr1->data;
     	ptr1=ptr1->next;
     	ptr2=ptr2->next;
     }
    return -1;
}