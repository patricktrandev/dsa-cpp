#include <iostream>

using namespace std;

struct Node{
  int data;
  Node* next;
};

struct Linkedlist{
  Node* head;
  Node* tail;
};

Node* add(int x){
  Node* p= new Node;
  p->data=x;
  p->next=NULL;
  return p;
}

void insertTail(Node* p, Linkedlist &ll){
  if(ll.head == NULL){
    ll.head= p;
    ll.tail=p;
    return;
  }

  ll.tail->next=p;
  ll.tail=p;
}

Node* reverseList(Node* head){
  Node* prev= NULL;
  Node* curr= head;

  while(curr!= NULL){
    Node* nextNode= curr-> next;
    curr->next= prev;

    prev= curr;
    curr= nextNode;
  }
  return prev;

}

void print(Node* head){
  Node* cur= head;

  while(cur!= NULL){
    cout<<cur->data<<"\t";
    cur= cur->next;
  }
}


int main(){

  /**
 LEETCODE 206
@brief Main execution function.
Takes space-separated integer inputs from standard input until -1 is entered,
constructs a singly linked list, reverses it, and outputs the result.
Input Sample:
1 2 3 4 5 -1
Output Sample:
5  4    3    2    1
*/
Linkedlist ll;
ll.head= NULL; ll.tail= NULL;

  int x;
  while(cin>>x){
    if (x==-1) break;
    Node* t=add(x);
    insertTail(t, ll);
  }
  Node* h= ll.head;
  Node* rh= reverseList(h);
  print(rh);

  return 0;
}