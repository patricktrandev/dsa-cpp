#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(): data(0), next(nullptr){}
    Node(int x): data(x), next(nullptr){}
    Node(int x, Node* next): data(x), next(next){}
};

void insertTail(Node* &head, Node* &tail,int x){
    Node* t= new Node(x);
    if(head==nullptr){
        head= tail= t;
        return;
    }
    tail->next=t;
    tail=t;
}
void print(Node* head){
    Node* curr= head;
    while(curr!=nullptr){
        cout<<curr->data<<"\t";
        curr=curr->next;
    }
}

Node* rotateRight(Node* head, int k) {
    if(head== nullptr || head->next==nullptr || k==0) return head;
    Node* curr= head;
    int x=1;
    while(curr->next!= nullptr){
        curr=curr->next;
        x++;
        
    }
    
    curr->next=head;
    k=k%x;
    int z= x-k;
    while(z>0){
        curr=curr->next;
        z--;
    }
    
    Node* newTail= curr;
    Node* newHead= curr->next;
    newTail->next=nullptr;
    return newHead;
}
int main() 
{

    /*
        LC 61
    */
    Node* head=nullptr; Node* tail= nullptr;
    int k,t;cin>>k>>t;
    while(k>0){
        int x; cin>>x;
        insertTail(head, tail, x);
        k--;
    }
    Node* h= rotateRight(head, t);
    print(h);

    return 0;
}