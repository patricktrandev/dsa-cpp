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

void init(Linkedlist &ll){
  Node* d= add(0);
  ll.head=d;
  ll.tail=d;
}

void insertTail(Node* p, Linkedlist &ll){
  ll.tail->next=p;
  ll.tail= p;
}

void insert(Node* p, Linkedlist &l){
  if(l.head==NULL){
    l.head= p;
    l.tail=p;
    return;
  }
  l.tail->next=p;
  l.tail=p;
}

Node* mergeTwoLists(Node* h1, Node* h2) {
  Node* c1= h1;
  Node* c2= h2;
  Linkedlist ll;
  init(ll);

  while(c1 != NULL && c2 != NULL){
    if(c1-> data < c2-> data){
      insertTail(c1, ll);
      c1= c1->next;
    }else{
      insertTail(c2, ll);
      c2= c2->next;
    }
  }

  if (c1 != NULL){
    insertTail(c1, ll);
  }else{
    insertTail(c2, ll);
  }

  return ll.head->next;
}

void print(Node* h){
  Node* cur=h;
  while(cur != NULL){
    cout<<cur->data<<"\t";
    cur= cur->next;
  }
}


int main(){

  /**
  @brief Main execution function.
 
Reads two sorted singly linked lists from standard input, merges them into
a single sorted linked list in non-decreasing order, and outputs the result.
Input Sample:
list1 = [1,2,4], list2 = [1,3,4]
Output Sample:
1  1    2    3    4    4
Purpose:
Demonstrates merging two sorted linked lists using the two-pointer technique
and a dummy node to simplify boundary conditions.*/

  Linkedlist l1;
  Node* a1=add(1);
  insert(a1, l1);
  Node* a2=add(2);
  insert(a2, l1);
  Node* a3=add(4);
  insert(a3, l1);

  Linkedlist l2;
  Node* b1=add(1);
  insert(b1, l2);
  Node* b2=add(3);
  insert(b2, l2);
  Node* b3=add(4);
  insert(b3, l2);

  Node* h1= l1.head;
  Node* h2= l2.head;

  Node* k=mergeTwoLists(h1, h2);
  print(k);

}