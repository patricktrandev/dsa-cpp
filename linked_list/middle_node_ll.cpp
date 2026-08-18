#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
struct LinkedList {
    Node* head;
    Node* tail;
};
Node* add(int x){
    Node* p= new Node;
    p->data=x;
    p->next=nullptr;
    return p;
}
void insertTail(Node* p, LinkedList &ll){
    if(ll.head==nullptr){
        ll.head=p;
        ll.tail=p; 
        return;
    }
    ll.tail->next=p;
    ll.tail=p;
}
Node* middleNode(Node* head){
    Node* f= head;
    Node* sl=head;
    while(f !=nullptr && f->next !=nullptr){
        sl= sl->next;
        f=f->next->next;
    }
    return sl;

}

int main(){

    /**
     * LEETCODE 876
    * @brief Main execution function.
    *
    * Reads a space-separated list of integers ending with -1
    * to construct a singly linked list.
    * Then finds and prints the middle node of the linked list
    * using the fast and slow pointer technique.
    *
    * Input Sample:
    * 1 2 3 4 5 -1
    *
    * Output Sample:
    * 3
    *
    * Algorithm:
    * - The slow pointer moves one node at a time.
    * - The fast pointer moves two nodes at a time.
    * - When the fast pointer reaches the end, the slow pointer
    *   will be pointing to the middle node.
    *
    * Time Complexity: O(N)
    * Space Complexity: O(1)
    */

  LinkedList ll;
  ll.head= nullptr; ll.tail= nullptr;
  int x;
  while(cin>>x){
    if( x==-1) break;
    Node* t= add(x);
    insertTail(t, ll);
  }

    Node* m= middleNode(ll.head);
    cout<<m->data;

  return 0;

}