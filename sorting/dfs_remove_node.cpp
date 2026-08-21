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
    p->next=nullptr;
    return p;
}
void init(Linkedlist &ll){
    Node* p=add(0);
    ll.head=p;
    ll.tail=p;
}

void insert(Node* p, Linkedlist &ll){
    ll.tail->next=p;
    ll.tail=p;
}
void print(Node* head){
    Node* cur=head;
    while(cur != nullptr){
        cout<<cur->data<<'\t';
        cur=cur->next;
    }
}
int dfs(Node* h, int k){
    if(h==nullptr) return 0;
    int index= 1+dfs(h->next,k);
    if(index==k) {
        Node* toDelete = h->next;
        h->next= h->next->next;
        delete toDelete;
    }
    return index;
}

Node* removeNthFromEnd(Node* h, int n){
    dfs(h, n+1);
    return h->next;
}

int main(){
   /** LEETCODE 19
 * REMOVE NTH NODE FROM END OF LIST
 *
 * @brief Removes the n-th node from the end of a singly linked list and returns its head.
 *
 * The algorithm uses Depth-First Search (DFS) / Post-order Traversal (Recursion).
 * It traverses to the end of the list first, and then counts back from the tail 
 * as the call stack unwinds (backtracking). When reaching index (n + 1) from the end,
 * the current node removes its next neighbor (which is the n-th node from the end).
 *
 * Input Sample:
 *
 *   n = 2
 *   head = 1 -> 2 -> 3 -> 4 -> 5
 *
 * Execution Step-by-Step (Post-order unwinding):
 *
 *   dfs(nullptr) returns index 0
 *   Node 5: index = 1 + 0 = 1
 *   Node 4: index = 1 + 1 = 2
 *   Node 3: index = 1 + 2 = 3  <-- (index == n + 1, so remove Node 3's next: Node 4)
 *           Node 3 -> next becomes Node 5
 *   Node 2: index = 1 + 3 = 4
 *   Node 1: index = 1 + 4 = 5
 *
 * Output:
 *
 *   1 -> 2 -> 3 -> 5
 *
 * Purpose:
 * Demonstrates how to:
 * - Use recursion/DFS to traverse to the end of a singly linked list.
 * - Calculate positions from the tail during the call stack unwinding phase.
 * - Bypass and delete the target node when standing at the (n + 1)-th node from the end.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N) due to the implicit recursion call stack.
 *
 * where N is the total number of nodes in the linked list.
 */
    int k; cin>>k;
    Linkedlist ll;
    init(ll);
    int x;
    while(cin>>x){
        if(x==-1) break;
        Node* t=add(x);
        insert(t, ll);
    }

    Node* h= removeNthFromEnd(ll.head, k);
    print(h);

  return 0;
}