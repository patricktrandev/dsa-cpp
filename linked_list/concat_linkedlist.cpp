#include <iostream>
#include <vector>
#include <unordered_map>
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
    Node* p=new Node;
    p->data=x;
    p->next=nullptr;
    return p;
}

void insert(int x, LinkedList &ll){
    Node* p=new Node;
    p->data=x;
    p->next=nullptr;
    if(ll.head==nullptr){
        ll.head=p;
        ll.tail=p;
        return;
    }
    ll.tail->next=p;
    ll.tail=p;
}

Node* concat(Node* h1, Node* h2){
    Node* curr= h1;
    while(curr-> next != NULL){
        curr= curr->next;
    }
    curr-> next= h2;
    h2=nullptr;
    return h1;
}

void print(Node* h){
    Node* curr= h;
    while(curr != nullptr){
        cout<< curr-> data<<"\t";
        curr= curr->next;
    }
}

int main(){
    LinkedList l1; l1.head=nullptr, l1.tail=nullptr;
    LinkedList l2; l2.head=nullptr, l2.tail=nullptr;
    insert(2,l1);
    insert(4,l1);
    insert(6,l1);
    insert(10,l1);
    insert(5,l2);
    insert(8,l2);
    insert(9,l2);
    insert(26,l2);
    insert(12,l2);

    print(l1.head);
    cout<<endl;
    print(l2.head);
    cout<<endl;

    Node* st= concat(l1.head, l2.head);
    print(st);
    
  return 0;
}