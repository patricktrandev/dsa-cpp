#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int missingNumber(vector<int>& n){
    //gaus
    int k=n.size();
    int s= k*(k+1)/2;
    int t=0;
    for(int i=0; i<k; i++) t+=n[i];
    return s-t;
}
int missingNumber2(vector<int>& n){
    //xor
    int res=n.size();
    for(int i=0; i<n.size(); i++){
        res^=i;
        res^=n[i];
    }
    return res;
}
int main(){
    /** LEETCODE 268
 * MISSING NUMBER
 *
 * @brief Finds the only number in the range [0, n] that is missing from the array.
 *
 * Given an array `n` containing `k` distinct numbers in the range [0, k], 
 * return the only number in the range that is missing from the array.
 *
 * ============================================================================
 * APPROACH 1: Gauss' Summation Formula (`missingNumber`)
 * ============================================================================
 * Key insight: The sum of the first `k` natural numbers [0...k] is given by 
 * `k * (k + 1) / 2`. The missing number is simply the expected total sum minus 
 * the actual sum of elements present in the array.
 *
 * Input Sample:
 *   nums (n) = [3, 0, 1]  (k = 3)
 *
 * Execution Step-by-Step:
 *   Step 1: k = 3
 *           Expected sum s = 3 * (3 + 1) / 2 = 6.
 *
 *   Step 2: Calculate actual sum `t`:
 *           i = 0 -> t = 0 + 3 = 3
 *           i = 1 -> t = 3 + 0 = 3
 *           i = 2 -> t = 3 + 1 = 4
 *
 *   Step 3: Missing number = s - t = 6 - 4 = 2.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * ============================================================================
 * APPROACH 2: Bit Manipulation - XOR (`missingNumber2`)
 * ============================================================================
 * Key insight: XOR operation has properties `x ^ x = 0` and `x ^ 0 = x`.
 * If we XOR all indices from `0` to `k` with all values in the array `n`, 
 * every number present in the array will appear twice and cancel out (yielding 0). 
 * The only number that appears once will be the missing number.
 *
 * Input Sample:
 *   nums (n) = [3, 0, 1]  (k = 3)
 *
 * Execution Step-by-Step:
 *   Initialize res = k = 3
 *
 *   Step 1: i = 0, n[0] = 3
 *           res = 3 ^ 0 ^ 3 = 0
 *
 *   Step 2: i = 1, n[1] = 0
 *           res = 0 ^ 1 ^ 0 = 1
 *
 *   Step 3: i = 2, n[2] = 1
 *           res = 1 ^ 2 ^ 1 = 2
 *
 * Output:
 *   2
 *
 * Purpose:
 * Demonstrates how to:
 * - Utilize mathematical formulas (Gauss Sum) for O(1) auxiliary space solutions.
 * - Avoid potential integer overflow in sum calculation by using XOR operations.
 * - Apply bitwise XOR properties to isolate single/missing elements efficiently.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * where N (or k) is the length of the array `n`.
 */
    int k; cin>>k;
    vector<int> a;

    while(k>0){
        int t; cin>>t;
        a.push_back(t);
        k--;
    }
    int i= missingNumber2(a);
    cout<<i;
    
  return 0;
}