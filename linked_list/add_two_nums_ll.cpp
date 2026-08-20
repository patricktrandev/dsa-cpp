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
  Node* p=new Node;
  p->data=x;
  p->next= nullptr;
  return p;
}

void insertTail(Node* p, Linkedlist &ll){
  if(ll.head==nullptr){
    ll.head=p;
    ll.tail=p;
    return;
  }
  ll.tail->next=p;
  ll.tail=p;
}

void print(Node* head){
  Node* cur=head;
  while(cur != nullptr){
    cout<<cur->data<<"\t";

    cur=cur->next;
  }
}
Node* addTwoNumbers(Node* h1, Node* h2){
  Linkedlist l;
  l.head=nullptr, l.tail=nullptr;
  Node* c1=h1;
  Node* c2=h2;
  int ca=0;
  while(c1 != nullptr || c2!= nullptr ||ca !=0){
    int s=0;
    if(c1 != nullptr){
        s+=c1->data;
        c1= c1->next;
    }

    if(c2 != nullptr){
        s+=c2->data;
        c2=c2->next;
    }

    s+=ca;
    int d=s%10;
    ca=s/10;
    Node* t=add(d);
    insertTail(t,l);
  }

  return l.head;
}


int main(){

 /** LEETCODE 2
 * ADD TWO NUMBERS USING LINKED LIST
 *
 * @brief Adds two numbers represented by singly linked lists.
 *
 * Each linked list stores one digit per node in reverse order.
 * For example:
 *
 *   9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9
 *
 * represents the number:
 *
 *   9,999,999
 *
 * The function traverses both linked lists simultaneously and performs
 * digit-by-digit addition, similar to manual arithmetic. A carry value
 * is maintained when the sum of two digits is greater than or equal to 10.
 *
 * Input Sample:
 *
 *   9 9 9 9 9 9 9 -1
 *   9 9 9 9 -1
 *
 * These linked lists represent:
 *
 *   9,999,999
 * +  99,999
 * ----------
 *  10,099,998
 *
 * Because the digits are stored in reverse order, the result is:
 *
 *   8 -> 9 -> 9 -> 9 -> 9 -> 0 -> 0 -> 1
 *
 * Purpose:
 * Demonstrates how to:
 * - Traverse two linked lists simultaneously.
 * - Perform digit-by-digit addition.
 * - Handle carry values between digits.
 * - Create a new linked list to store the result.
 *
 * Time Complexity: O(max(N, M))
 * Space Complexity: O(max(N, M))
 *
 * where N and M are the lengths of the two linked lists.
 */
  Linkedlist a;
  a.head=nullptr, a.tail=nullptr;
  Linkedlist b;
  b.head=nullptr, b.tail=nullptr;
  int x;
  while(cin>>x){
    if(x==-1) break;
    Node* t=add(x);
    insertTail(t, a);
  }
  int z;
  while(cin>>z){
    if(z==-1) break;
    Node* t=add(z);
    insertTail(t, b);
  }

  Node* r=addTwoNumbers(a.head, b.head);
  print(r);
  return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 /*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dum(0);
        ListNode* tail=&dum;
        ListNode* c1= l1;
        ListNode* c2=l2;

        int ca=0;
        while(c1 != nullptr || c2 != nullptr || ca!=0){
            int s=0;
            if(c1 != nullptr){
                s+=c1->val;
                c1=c1->next;
            }
            if(c2 != nullptr){
                s+=c2->val;
                c2=c2->next;
            }
            s+=ca;
            int d=s%10;
            ca=s/10;
            tail->next= new ListNode(d);
            //move tail
            tail=tail-> next;

        }
        return dum.next;
    }
};

*/