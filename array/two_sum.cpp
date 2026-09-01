#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &n, int t){
    unordered_map<int, int> m;
    for(int i=0;i<n.size(); i++){
        int r= t-n[i];
        if(m.find(r) != m.end()){
            return {m[r], i};
        }else{
            m[n[i]]=i;
        }
    }
}

int main(){
    /** LEETCODE 1
 * TWO SUM
 *
 * @brief Finds two numbers in an array that add up to a specific target value
 *        and returns their indices.
 *
 * Given an array of integers `n` and an integer `t` (target), return indices 
 * of the two numbers such that they add up to `t`.
 * Assume that each input would have exactly one solution, and you may not use 
 * the same element twice.
 *
 * The algorithm uses Hash Map (One-Pass). Key insight: As we iterate through 
 * the array, for each element `n[i]`, we calculate its complement `r = t - n[i]`.
 * If `r` already exists in the map, we have found the pair. Otherwise, we store 
 * `n[i]` and its index `i` in the map for future lookups.
 *
 * Input Sample:
 *
 *   target (t) = 9
 *   nums (n)   = [2, 7, 11, 15]
 *
 * Execution Step-by-Step:
 *
 *   Step 1: i = 0, n[i] = 2, r = 9 - 2 = 7
 *           7 is NOT in map `m`.
 *           Insert map[2] = 0. Map state: {2: 0}
 *
 *   Step 2: i = 1, n[i] = 7, r = 9 - 7 = 2
 *           2 IS in map `m` (at index 0).
 *           Match found! Return indices {m[2], 1} -> {0, 1}.
 *
 * Output:
 *
 *   0   1
 *
 * Purpose:
 * Demonstrates how to:
 * - Use a Hash Map (`unordered_map`) for O(1) average lookup time.
 * - Reduce time complexity from O(N^2) brute-force to O(N) by trading space for time.
 * - Perform single-pass lookup and insertion simultaneously.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
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
    vector<int> res= twoSum(n,b);
    for(int i=0; i< res.size(); i++){
        cout<< res[i]<<"\t";
    }

  return 0;
}