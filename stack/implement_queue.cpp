#include <iostream>
#include <vector>
#include <stack>
#include <random>
using namespace std;

class MyQueue {
  private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {

    }

    int getLen(){
      return s1.size()+s2.size();
    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if(s2.empty()){
          int len= s1.size();
          while(len>0){
            s2.push(s1.top());
            s1.pop();
            len--;
          }
        }
      int val=s2.top();
      s2.pop();
      return val;
    }

    int peek() {
        if(s2.empty() && !s1.empty()){
          int len= s1.size();
          while(len>0){
            s2.push(s1.top());
            s1.pop();
            len--;
          }
        }
      return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};


int main(){

    /** LEETCODE 232
 * IMPLEMENT QUEUE USING STACKS
 *
 * @brief Implements a First-In-First-Out (FIFO) queue using two std::stack instances (LIFO).
 *
 * The queue operational mechanics are split between two stacks: `s1` (input stack) and `s2` (output stack).
 *
 * - `push(x)`: Elements are always pushed directly onto `s1` in O(1) time.
 * - `pop()` / `peek()`: Reads or removes the front element from `s2`:
 *   - If `s2` is non-empty, the top element of `s2` represents the front of the queue.
 *   - If `s2` is empty, all elements from `s1` are popped and pushed into `s2`. This transfer
 *     reverses their order, bringing the oldest pushed element to the top of `s2`.
 * - `empty()`: The queue is empty only when both `s1` and `s2` are empty.
 *
 * Input Operations Sequence Sample:
 *
 *   Operations: ["push(1)", "push(2)", "peek()", "pop()", "empty()"]
 *
 * Execution Step-by-Step:
 *
 *   Step 1: push(1) -> s1.push(1)                                (s1: [1],      s2: [])
 *   Step 2: push(2) -> s1.push(2)                                (s1: [1, 2],   s2: [])
 *   Step 3: peek()  -> s2 is empty -> Transfer s1 to s2          (s1: [],       s2: [2, 1])
 *                   -> Returns s2.top() = 1                      (s1: [],       s2: [2, 1])
 *   Step 4: pop()   -> Reads s2.top() = 1 -> s2.pop()            (s1: [],       s2: [2])
 *   Step 5: empty() -> Checks (s1.empty() && s2.empty())        -> Returns false
 *
 * Purpose:
 * Demonstrates how to:
 * - Replicate FIFO queue behavior by chaining two LIFO stack operations.
 * - Perform lazy / amortized transfer of elements to preserve average efficiency.
 * - Safely manage internal container states across multiple dynamic method invocations.
 *
 * Time Complexity: 
 * - push(x): O(1)
 * - pop(): Amortized O(1), Worst-case O(N) when s2 is empty and needs transferring elements from s1.
 * - peek(): Amortized O(1), Worst-case O(N) during s1-to-s2 transfer.
 * - empty(): O(1)
 *
 * Space Complexity: O(N) to store up to N elements across both stacks `s1` and `s2`.
 *
 * where N is the total number of elements currently stored in the queue.
 */

  vector<string> a;
  int t; cin>>t;
  cin.ignore();

  while(t>0){
    string k; cin>>k;
    a.push_back(k);
    t--;
  }
  MyQueue q;
  for( auto x: a){
    if(x=="MyQueue"){
      q= MyQueue();
      cout<<"init queue..."<<endl;
    }else if( x=="push"){
      int r= rand()%10 +1;
      cout<<"generate r="<<r<<endl;
      q.push(r);
      cout<<"Length queue is "<<q.getLen()<<endl;
    }else if (x=="peek"){
      int k=q.peek();
      cout<<"peek value is "<<k<<endl;
    }else if (x=="pop"){
      int k=q.pop();
      cout<<"pop value is "<<k<<endl;
    }else if(x=="empty"){
      bool check= q.empty();
      check ? cout<<"true" : cout<<"false";
    }
  }

  return 0;
}