// Quick sort Algorithm through the linked list .

#include<bits/stdc++.h>
#include"link_header.h"
using namespace std; 

   // function to find tail of the list.
   
   node* get_tail(node *head){
   		while(head->next!=NULL){
   			head=head->next;
   		}
   		return head;
   }


void segregate(node* &head , node * end ){

	 node * temp = head; 


	 // traverse the linked list.

  		//    5 3 8 6 7 

	    // temp = 5  end = 7  prev = NULL 
	 	//  5 < 7  temp = 3	  prev = 5
	 	//  3 < 7  temp = 8	  prev = 3
	 	//  8 > 7 cond false  new list 5 3 6 7 8
	 	//         prev->next = temp->next;
	    //         end->next =  temp;
	    //		   temp ->next = NULL 
	    //         temp= prev;
	 node * prev = NULL; 
	 while(temp!=end){
	 	if(temp->data < end->data){
	 		prev=temp;
	 		temp=temp->next;
	 	}else{
	 		// prev=temp;
	 		prev->next = temp->next;
	 		end->next=temp;
	 		temp->next=NULL;
	 		temp=prev;
	 	}
	 }

}


int main () {
    // make a linked list first . 

    node* head=NULL;

    insertAthead(head,1);
    insertAttail(head,3);
    insertAttail(head,8);
    insertAttail(head,6);
    insertAttail(head,7);
    // insertAttail(head,4);

    display(head);

    // quickSort(head,get_tail(head));

    segregate (head , get_tail(head));

    display(head);


}