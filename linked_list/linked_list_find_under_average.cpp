#include <iostream>
using namespace std;
struct Node{
  double data;
  Node* next;
};

struct Linkedlist{
  Node* head;
  Node* tail;
};

Node* add(double x){
  Node* p= new Node;
  p->data=x;
  p->next= NULL;
  return p;
}

void insertTail(Node* p, Linkedlist &ll){
  if(ll.head==NULL){
    ll.head= p;
    ll.tail=p;
    return;
  }
  ll.tail->next=p;
  ll.tail=p;
}
void print(Node* head){
  Node* cur=head;
  while(cur!=NULL){
    if(cur->data<5.0){
      cout<<cur->data<<endl;
    }
    
    cur=cur->next;
  }
}


int main(){
   /**
 * INPUT:
 * 2.5
 * 3
 * 5.2
 * 0
 * -1
 *
 * OUTPUT:
 * 2.5
 * 3
 * 0
 *
 * DESCRIPTION:
 * Read numbers and insert them into the linked list
 * until -1 is entered.
 * Then print only the elements that are less than 5.
 */


  Linkedlist ll;
  ll.head=NULL; ll.tail=NULL;
  double x;
  while(cin>>x){
    if(x==-1)break;
    Node* t=add(x);
    insertTail(t,ll);
  }
  Node* h= ll.head;
  print(h);
  
  return 0;
}