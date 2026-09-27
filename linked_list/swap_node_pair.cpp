#include <iostream>
using namespace std;

struct LNode{
    int data;
    LNode *next;
    LNode(): data(0), next(nullptr){}
    LNode(int x): data(x), next(nullptr){}
    LNode(int x, LNode *next): data(x), next(next){}
};
void insertTail(LNode* &head, LNode* & tail, int x){
    LNode* newNode= new LNode(x);
    if(head==nullptr){
        head=tail= newNode;
        return;
    }
    tail-> next= newNode;
    tail= newNode;
}
void print(LNode* &head){
    LNode* curr= head;
    while(curr != nullptr){
        cout<< curr-> data<<"\t";
        curr= curr->next;
    }
}
LNode* swapPairs(LNode* head) {
    LNode* dummy= new LNode(0);
    dummy-> next=head;
    LNode* curr= dummy;
    while(curr->next != nullptr && curr-> next -> next != nullptr){
        LNode* first= curr-> next;
        LNode* second= curr-> next-> next;
        first-> next= second->next;
        second-> next= first;
        curr->next= second;
        curr= first;
    }
    LNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

int main() 
{
    /*
        LC 24
    */

    LNode* head= nullptr;
    LNode* tail= nullptr;
    int k;cin>>k;
    while(k>0){
        int t; cin>>t;
        insertTail(head, tail, t);
        k--;
    }
    LNode* h= swapPairs(head);
    print(h);

    return 0;
}