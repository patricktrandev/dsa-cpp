#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &n){
    int res=0;
    for(int i=0; i<n.size(); i++){
        res^=n[i];
    }
    return res;
}

int main(){
   /**
 * LEETCODE 136: SINGLE NUMBER
 *
 * @brief Finds the single element in an array where every other element appears twice.
 *
 * The algorithm leverages the Bitwise XOR (`^`) operator properties to achieve linear runtime
 * complexity without using additional memory.
 *
 * Key Bitwise XOR Properties:
 * 1. Self-inverse: x ^ x = 0 (Any number XORed with itself results in 0).
 * 2. Identity:     x ^ 0 = x (Any number XORed with 0 remains unchanged).
 * 3. Commutative & Associative: The order of XOR operations does not affect the result.
 *
 * Execution Logic:
 * 1. Initialization: Start with `res = 0`.
 * 2. Traversal: Iterate through each element in the input vector `n`.
 * 3. Bitwise Accumulation: Accumulate the XOR sum of `res` and `n[i]` (`res ^= n[i]`).
 * 4. Cancellation: Elements appearing twice cancel each other out to 0 (e.g., a ^ b ^ a = b ^ (a ^ a) = b ^ 0 = b).
 * 5. Return: The final value of `res` is the unique single element.
 *
 * Step-by-Step Execution Example (n = [4, 1, 2, 1, 2]):
 * - Initial state: res = 0
 * - i = 0: res = 0 ^ 4 = 4
 * - i = 1: res = 4 ^ 1
 * - i = 2: res = 4 ^ 1 ^ 2
 * - i = 3: res = 4 ^ 1 ^ 2 ^ 1 = 4 ^ (1 ^ 1) ^ 2 = 4 ^ 0 ^ 2 = 4 ^ 2
 * - i = 4: res = 4 ^ 2 ^ 2 = 4 ^ (2 ^ 2) = 4 ^ 0 = 4
 * - Final Result: 4
 *
 * Time Complexity:  O(N) - Single pass through the array of size N.
 * Space Complexity: O(1) - Constant auxiliary space, using only a single variable (`res`).
 */
    int x;
    vector<int> a;
    while(cin>>x){
        if(x==-1) break;
        a.push_back(x);
    }
    int i= singleNumber(a);
    cout<<i;

  return 0;
}