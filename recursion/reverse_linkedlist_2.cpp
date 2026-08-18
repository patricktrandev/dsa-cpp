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
    p->data=x;
    p->next=nullptr;
    return p;
}

void insertTail(Node* p, LinkedList &ll){
    if(ll.head== nullptr){
        ll.head= p;
        ll.tail=p;
        return;
    }
    ll.tail->next=p;
    ll.tail=p;
}
void print(Node* head){
    Node* cur=head;
    while(cur!= nullptr){
        cout<<cur->data<<"\t";
        cur= cur->next;
    }
}

Node* reverseList(Node* head){
    if(head ==nullptr || head->next ==nullptr) return head;
    Node* nh= reverseList(head->next);

    head->next->next= head; //rotate next in next node
    head->next = nullptr; //clear old pointers
    return nh;
}


int main(){

    /**
     * @brief Main execution function.
     * Reads a space-separated list of integers ending with -1 to construct 
     * a singly linked list, reverses the list recursively, and prints the 
     * reversed sequence separated by tabs.
     * 
     * Input Sample:
     * 1 2 3 4 5 -1
     * 
     * Output Sample:
     * 5	4	3	2	1	
     * 
     * Purpose:
     * Demonstrates the reversal of a singly linked list using recursion 
     * with O(N) time complexity and O(N) auxiliary space complexity (due to call stack).
     * 
     * recursion tree
     */

  LinkedList ll;
  ll.head= nullptr; ll.tail= nullptr;
  int x;
  while(cin>>x){
    if( x==-1) break;
    Node* t= add(x);
    insertTail(t, ll);
  }

    Node* rh=reverseList(ll.head);
    print(rh);

  return 0;

}