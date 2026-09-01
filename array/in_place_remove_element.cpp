#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int removeElement(vector<int> &n, int t){
    int s=0; 
    for(int f=0; f<n.size(); f++){
        if(n[f]!=t){
            n[s++]=n[f];

        }
    }
    return s;
}

int main(){
    /** LEETCODE 27
 * REMOVE ELEMENT
 *
 * @brief Removes all instances of a value in-place from an integer array 
 *        and returns the number of remaining elements.
 *
 * Given an integer array `n` and an integer `t` (target value to remove), 
 * modify the array in-place such that all elements not equal to `t` are placed 
 * at the beginning. The relative order of elements may be changed.
 *
 * The algorithm uses the Two-Pointer Technique (Slow & Fast Pointers). 
 * Key insight: Pointer `f` (fast) scans every element in the array, while pointer `s` (slow) 
 * maintains the boundary of valid elements. Whenever `n[f]` is not equal to `t`, 
 * we copy `n[f]` to `n[s]` and increment `s`.
 *
 * Input Sample:
 *
 *   val (t)  = 3
 *   nums (n) = [3, 2, 2, 3]
 *
 * Execution Step-by-Step:
 *
 *   Step 1: f = 0, n[f] = 3 (matches target t)
 *           Skip incrementing s -> s = 0, array remains [3, 2, 2, 3].
 *
 *   Step 2: f = 1, n[f] = 2 (does NOT match t)
 *           Assign n[s] = n[1] -> n[0] = 2, then s++ -> s = 1. Array: [2, 2, 2, 3].
 *
 *   Step 3: f = 2, n[f] = 2 (does NOT match t)
 *           Assign n[s] = n[2] -> n[1] = 2, then s++ -> s = 2. Array: [2, 2, 2, 3].
 *
 *   Step 4: f = 3, n[f] = 3 (matches target t)
 *           Skip incrementing s -> s = 2, array remains [2, 2, 2, 3].
 *
 * Output:
 *
 *   2  (The modified prefix is [2, 2], new length is 2)
 *
 * Purpose:
 * Demonstrates how to:
 * - Modify an array in-place without allocating extra memory for another array.
 * - Utilize Fast/Slow pointers to overwrite undesirable elements.
 * - Maintain an effective length tracker for filtered results.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * where N is the length of the array `n`.
 */
    int a,b;cin>>a>>b;
    vector<int> n;
    while(a>0){
        int k;cin>>k;
        n.push_back(k);
        a--;
    }
    int i = removeElement(n,b);
    cout<<i;

  return 0;
}