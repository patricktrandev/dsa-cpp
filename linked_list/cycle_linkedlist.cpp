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

Node* add(int x){
  Node* p= new Node;
  p->data= x;
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

void linkCircular(int pos, LinkedList &ll){
  if(pos<0 || ll.head ==NULL) return;
  Node* cur= ll.head;
  int i=0;
  while(cur != NULL && i<pos){
    cur=cur-> next;
    i++;
  }

  if(cur!=NULL){
    ll.tail-> next=cur;
  }
}

bool hasCycle(Node* head){
  if (head == NULL || head->next ==NULL) return false;
  Node* sl= head;
  Node* fa= head;

  while(fa != nullptr && fa->next != nullptr){
    sl= sl->next;
    fa= fa->next->next;
    if ( fa== sl){ // compare address not value
      return true;
    }
  }

  return false;
} 




int main(){

    /**
     LEETCODE 141
    
    @brief Main execution function.
    Reads the cycle insertion index 'pos' followed by a space-separated list of integers
    ending with -1 to construct a singly linked list. Links the tail node to the node at index 'pos'
    to form a potential cycle, then uses Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
    to check whether the linked list contains a cycle.
    Input Sample:
    1
    3 2 0 -4 -1
    Output Sample:
    YES
    Purpose:
    Demonstrates cycle detection in a singly linked list using two pointers (slow and fast pointers)
    with O(N) time complexity and O(1) space complexity.*/

  LinkedList ll;
  ll.head= nullptr; ll.tail= nullptr;
  int pos; cin>>pos;
  int x;
  while(cin>>x){
    if( x==-1) break;
    Node* t= add(x);
    insertTail(t, ll);
  }

  linkCircular(pos, ll);
  bool isCycle= hasCycle(ll.head);
  isCycle ? cout<<"YES" : cout<<"NO";

  return 0;

}