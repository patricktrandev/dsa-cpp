#include <iostream>
#include <algorithm>
using namespace std;
struct LNode{
    int data;
    LNode* next;
    LNode(): data(0), next(nullptr) {}
    LNode(int x): data(x), next(nullptr){}
    LNode(int x, LNode* next): data(x), next(next){}
};
void insertHead(LNode* &head, int x) {
    LNode* newNode = new LNode(x);
    newNode->next = head;
    head = newNode;
}
void insertTail(LNode* &head, LNode* &tail, int x){
    LNode* newNode= new LNode(x);
    if(head==nullptr){
        head=tail=newNode;
        return;
    }
    tail-> next=newNode;
    tail=newNode;
}
void print(LNode* head){
    LNode* curr=head;
    while(curr != nullptr){
        cout<<curr-> data<<"\t";
        curr= curr->next;
    }
}

LNode* swapNodes(LNode* head, int k){
    LNode* s=head; LNode* f=head;
    LNode* first= head; LNode* second=head;
    for(int i=0; i< k-1; i++){
        f= f->next;
    }
    first=f;
    while(f->next!= NULL){
        s= s-> next;
        f=f->next;
    }
    second= s;
    swap(first->data, second->data);
    return head;
}

int main() 
{   
    /**
 * LEETCODE 1721: SWAPPING NODES IN A LINKED LIST
 *
 * @brief Swaps the values of the k-th node from the beginning and the k-th node from the end in a singly linked list.
 *
 * The algorithm utilizes a Two-Pointer Technique (Fast and Slow Pointers) to locate target nodes in a single pass.
 *
 * Key Technical Insight:
 * - The k-th node from the beginning (`first`) is located by advancing a fast pointer `f` by `k - 1` steps.
 * - By advancing both a slow pointer `s` (starting at `head`) and `f` until `f` reaches the last node (`f->next == nullptr`),
 *   the distance maintained between them ensures `s` lands precisely at the k-th node from the end (`second`).
 * - Thus, both target nodes are identified without calculating the total length of the linked list beforehand.
 *
 * Input Sample:
 *
 *   List: 1 -> 2 -> 3 -> 4 -> 5, k = 2
 *
 * Execution Step-by-Step:
 *
 *   Step 1: Locate k-th Node from Beginning
 *           Advance `f` by k - 1 = 1 step:
 *           f = node(2) -> first = node(2) [Data: 2]
 *
 *   Step 2: Locate k-th Node from End (Simultaneous Traversal)
 *           s starts at head (node(1)), f is at node(2).
 *           Advance both until f->next == nullptr:
 *           - Move 1: s = node(2), f = node(3)
 *           - Move 2: s = node(3), f = node(4)
 *           - Move 3: s = node(4), f = node(5) (f->next is nullptr -> Stop)
 *           second = s -> node(4) [Data: 4]
 *
 *   Step 3: Swap Values
 *           swap(first->data, second->data)
 *           Data changes from [1, 2, 3, 4, 5] to [1, 4, 3, 2, 5]
 *
 * Output:
 *
 *   1   4   3   2   5
 *
 * Purpose:
 * Demonstrates how to:
 * - Locate relative elements from the end of a singly linked list using the Two-Pointer strategy.
 * - Avoid multiple passes or computing list size prior to node retrieval.
 * - Perform value-swapping in O(1) auxiliary space without altering node pointers.
 *
 * Time Complexity: O(N)
 *   - Traverses the linked list in a single pass of N nodes.
 * Space Complexity: O(1)
 *   - Operates entirely in-place using auxiliary pointers.
 *
 * where N is the total number of nodes in the linked list.
 */
    LNode* head= nullptr;
    LNode* tail= nullptr;

    int k,t; cin>>k>>t;
    while(k>0){
        int x; cin>>x;
        insertTail(head,tail, x);

        k--;
    }
    LNode* h=swapNodes(head, t);
    print(head);
    return 0;
}