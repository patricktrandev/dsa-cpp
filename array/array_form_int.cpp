#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> addToArrayForm(vector<int>& n, int k) {
    vector<int> res;
    int i =n.size()-1; 
    while(i>=0 || k>0){
        if(i>=0){
            k+=n[i];
            
        }
        res.push_back(k%10);
        k/=10;
        i--;
    }
    
    reverse(res.begin(), res.end());
    return res;
}

int main() 
{
    /**
 * LEETCODE 989: ADD TO ARRAY-FORM OF INTEGER
 *
 * @brief Computes the array-form addition of an integer array `num` and an integer `k`.
 *
 * The algorithm utilizes a Schoolbook Manual Addition Strategy using `k` as a Dynamic Carry Buffer.
 *
 * Key Technical Insight:
 * - Backwards Traversal: Starts from the least significant digit (rightmost index `i = n.size() - 1`).
 * - Integrated Carry Mechanism: Uses `k` itself to accumulate digit sums, eliminating the need for a separate carry variable.
 * - Positional Addition: Adds digit `num[i]` directly to `k` if index `i >= 0`.
 * - Digit Extraction & Reduction:
 *   - Extract least significant result digit via modulo: `k % 10`.
 *   - Pass remaining carry over to the next position via integer division: `k /= 10`.
 * - Dynamic Loop Bounds: Continues processing as long as digits remain in `num` (`i >= 0`) OR carry exists in `k` (`k > 0`).
 * - Reversal Step: Reverses `res` at the end to align digits from most significant to least significant.
 *
 * Input Sample:
 *
 *   num = [1, 2, 0, 0], k = 34
 *
 * Execution Step-by-Step:
 *
 *   Initialization:
 *   - i = 3 (num[3] = 0), k = 34, res = []
 *
 *   Step 1 (i = 3):
 *   - k += num[3] -> k = 34 + 0 = 34
 *   - Push digit: k % 10 = 4 -> res = [4]
 *   - Carry update: k = 34 / 10 = 3
 *   - Decrement pointer: i = 2
 *
 *   Step 2 (i = 2):
 *   - k += num[2] -> k = 3 + 0 = 3
 *   - Push digit: k % 10 = 3 -> res = [4, 3]
 *   - Carry update: k = 3 / 10 = 0
 *   - Decrement pointer: i = 1
 *
 *   Step 3 (i = 1):
 *   - k += num[1] -> k = 0 + 2 = 2
 *   - Push digit: k % 10 = 2 -> res = [4, 3, 2]
 *   - Carry update: k = 2 / 10 = 0
 *   - Decrement pointer: i = 0
 *
 *   Step 4 (i = 0):
 *   - k += num[0] -> k = 0 + 1 = 1
 *   - Push digit: k % 10 = 1 -> res = [4, 3, 2, 1]
 *   - Carry update: k = 1 / 10 = 0
 *   - Decrement pointer: i = -1
 *
 *   Termination & Reversal:
 *   - Loop terminates (i = -1, k = 0).
 *   - Reverse res: [4, 3, 2, 1] -> [1, 2, 3, 4]
 *
 * Output:
 *
 *   [1, 2, 3, 4]
 *
 * Purpose:
 * Demonstrates how to:
 * - Handle arbitrarily large number additions exceeding standard primitive data type limits (`long long`).
 * - Reuse an input integer parameter as an active carry state machine.
 * - Perform right-to-left digit accumulation with end-stage string/vector reversal.
 *
 * Time Complexity: O(max(N, log10(K)))
 *   - Loops up to the number of digits in `num` (N) or the number of digits in `k` (log10(K)), whichever is larger.
 *   - Vector reversal takes O(max(N, log10(K))) time.
 * Space Complexity: O(max(N, log10(K)))
 *   - Allocates memory to store the resulting digit vector of size max(N, log10(K)) + 1.
 *
 * where N is the length of `num` and K is the integer value to add.
 */
    int n,k; cin>>n>>k;
    vector<int> a;
    while(n>0){
        int x; cin>>x;
        a.push_back(x);
        n--;
    }
    vector<int> res=addToArrayForm(a,k);
    for(int i=0; i< res.size(); i++){
        cout<<res[i]<<"\t";
    }
    return 0;
}