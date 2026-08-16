#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
struct LinkedList{
	Node* head;
	Node* tail;
};
Node* addNode(int x){
	Node* p=new Node;
	p->data=x;
	p->next=NULL;
	return p;
}
void insertTail(Node* p, LinkedList &ll){
	if(ll.head==NULL){
		ll.head=p;
		ll.tail=p;
		return;
	}
	
	ll.tail->next=p;
	ll.tail=p;
	
}


int main(){

  LinkedList ll;
  ll.head=NULL;
  ll.tail=NULL;
  int min=1000001;

  while(true){
  	int x; cin>>x;
  	if(x==0) break;
  	Node* t= addNode(x);
  	insertTail(t,ll);
  	if(t->data<min){
  		min=t->data;
	  }
  	
  	
  }
  cout<<min;
  
  return 0;
}