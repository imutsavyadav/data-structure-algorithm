// Print even element node after the odd element
// do by using two pointer odd and even 
#include<bits/stdc++.h>
#include"link_header.h"
using namespace std; 

void evenAfterOdd(node* &head){
    node* o = head; 
    node* e = head->next;
    node* eStart=e;
        while(!o->next and !e->next){
            o->next=e->next;
            o=o->next; 
            e->next=o->next;
            e=e->next;
        }
 
        o->next=eStart;
        e->next=NULL;
}

int main(){
    node*head=NULL;
    insertAthead(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    insertAttail(head,5);
    insertAttail(head,6);

    
    display(head);
}
