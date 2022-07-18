 /*
   LINKED LIST 
   1 -> Reverse the linked list through itrative and recursive way.
   2 -> Reverse the k node in the linked list
 */

#include <bits/stdc++.h>
#include"link_header.h"
using namespace std; 

  // This is the irative method to print the reverse of the linked list.
  // Test case:- 1->2->3->4->5
  // solution :- 5->4->3->2->1
  // concept :- Here we use the three pointer and imagine in your mind to move the link btw the node
  // .......... how you reverse the the link so basically here you have the three poiter curr, prev and
  //............ next.
 node* reverseLinkedlist_1(node*&head){
  node * curr=head ; 
  node * prev=NULL ; 
  node * next ; 
  while(curr!=NULL){
  	next= curr->next;   
  	curr->next = prev;   
  	prev=curr; 
  	curr=next; 
  }
  return prev;
}
// This is the recursive method to print the linked list in the reverse order 
// Test case:- 1->2->3->4->5
// solution :- 5->4->3->2->1
node* reverseLinkedlist_2(node*&head){
	// base case
	if(head == NULL || head->next==NULL){
		return head ; 
	} // call on rest part of the linked list 
	node* newhead= reverseLinkedlist_2(head->next); 
  // just think that the you have to deal with the first two node of the linked list 
  // or the rest of the part is taken by recursion .
	head->next->next=head ; 
	head-> next=NULL ;
	return newhead;
}
//--------------------------reverse the k no. of nodes in the linked list ------------
// test case :- 1->2->3->4->5->6 and k = 2 
// solution :-  2->1->4->3->6->5
// concept :-  here we first use the itrative approach to reverse the first k node of the linked lisht
//............... then we call the recursivly for the next k node think in the mind or just imagine or use 
// ................ the paper for the traverseing that which pointer is where when the itrative work done
node* reverseKnode(node* head , int k ){
	// first reverse k node through itrative method.
	node*curr=head;
	node*prev=NULL; 
	node*nextptr;
	int count=0; 
	while(curr!=NULL && count<k){
		nextptr=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextptr;
		count++;
	}
	// second pass an recursive call with on the rest of the node.
	if(nextptr!=NULL){
		head->next=reverseKnode(nextptr,k);
	}
	return prev;
}








int main (){
// take an head  pointer of type node  which store the address of starting node of the linked list 
  node* head = NULL ; 

  // Basic function	
  // for creating the node and these fuction are basically in the 0_link_header.h
  insertAthead(head,1); 
  insertAttail(head,2);
  insertAttail(head,3);
  insertAtVal(head , 4 ,3);
  insertAttail(head,5);

   // Revese the linked list in the different manner 


  display(head);
  node*newhead_1=reverseLinkedlist_1(head);
  // time complexity :- 

  display(newhead_1);
  node*newhead_2=reverseLinkedlist_2(newhead_1);
  // time complexity :- 

  display(newhead_2);
  node*newhead_3=reverseKnode(newhead_2,2);
  // time complexity :-
  
  display(newhead_3);

  // cycle

//   addCycle(newhead_3,2);
  
//   cout<<detectCycle(newhead_3);

//   removeCycle(newhead_3);

//   cout<<detectCycle(newhead_3);

  // Extra question 

//   cout<<endl;
  

//   node* newhead_4=lastKnodeToStart(newhead_3, 2);
//   display(newhead_4);

//   display(newhead_3);

//   node * head1 = NULL;
//   node * head2 = NULL; 
//   insertAthead(head1,1); 
//   insertAttail(head1,2);
//   insertAttail(head1,3);
//   insertAttail(head1,4);
//   insertAttail(head1,6);

//   insertAthead(head2,5);
//   insertAttail(head2,7);
//   insertAttail(head2,9); 


 
  // intersctTwoll(head1 , head2 , 3);
  // cout << intersectPoint(head1, head2) << endl;
  // display(head1);
  // display(head2);

  // node*head3=mergeLL(head1,head2);
  // display(head3);

//   node*head3=mergeLL(head1,head2);
//   display(head3);

  


}