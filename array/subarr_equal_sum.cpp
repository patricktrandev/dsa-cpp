#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool findSubarrays(vector<int>& n) {
    unordered_set<int> s;
    for(int i=0; i<n.size()-1; i++){
        int sum=n[i]+n[i+1];
        if(s.find(sum)!= s.end()){
            return true;
        }else{
            s.insert(sum);
        }
    }
    return false;
}
int main() 
{  

    /**
 * LEETCODE 2395: FIND SUBARRAYS WITH EQUAL SUM
 *
 * @brief Determines whether there exist two subarrays of length 2 with equal sum.
 *
 * The algorithm utilizes the Hash Set Lookup Technique (Single-Pass Traversal) to detect duplicate pairwise sums.
 *
 * Key Technical Insight:
 * - Iterates through the array and computes the sum of every contiguous pair of elements: `n[i] + n[i + 1]`.
 * - Employs a Hash Set (`std::unordered_set<int>`) to store and look up previously calculated pair sums in O(1) average time.
 * - Early Exit Condition: If the current pairwise sum is already present in the set, a duplicate is found (`return true`).
 * - Otherwise, inserts the sum into the set to maintain history for subsequent comparisons.
 *
 * Input Sample:
 *
 *   n = [4, 2, 4]
 *
 * Execution Step-by-Step:
 *
 *   Initialization:
 *   s = {} (empty unordered_set)
 *
 *   Step 1 (i = 0):
 *   - Subarray considered: [n[0], n[1]] -> [4, 2]
 *   - sum = 4 + 2 = 6
 *   - Lookup: 6 in s? -> False
 *   - Insert: s = {6}
 *
 *   Step 2 (i = 1):
 *   - Subarray considered: [n[1], n[2]] -> [2, 4]
 *   - sum = 2 + 4 = 6
 *   - Lookup: 6 in s? -> True (Duplicate found!)
 *   - Early Exit: return true
 *
 * Output:
 *
 *   true ("YES")
 *
 * Purpose:
 * Demonstrates how to:
 * - Perform contiguous sub-array window calculations (fixed size = 2).
 * - Utilize fast lookup data structures (`std::unordered_set`) to achieve linear time complexity.
 * - Optimize duplicate detection without requiring nested loops O(N^2).
 *
 * Time Complexity: O(N)
 *   - Single pass through the array of length N with average O(1) hash set insertion and lookup operations.
 * Space Complexity: O(N)
 *   - Allocates memory for the hash set, storing up to (N - 1) unique pairwise sums in the worst case.
 *
 * where N is the number of elements in the array `n`.
 */
    int k; cin>>k;
    vector<int> a;
    while(k>0){
        int x; cin>>x;
        a.push_back(x);
        k--;
    }
    bool check= findSubarrays(a);
    check? cout<<"YES":cout<<"NO";
    return 0;
}