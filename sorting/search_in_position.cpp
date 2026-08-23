#include <iostream>
#include <vector>
using namespace std;

 int searchInsert(vector<int> &nums, int target) {
        int r= nums.size()-1;
        int l=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target < nums[mid]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
}

int main(){
    /** LEETCODE 35
 * SEARCH INSERT POSITION
 *
 * @brief Finds the index of a target value in a sorted array, or the index where 
 * it would be if it were inserted in order.
 *
 * The algorithm uses Binary Search (Divide and Conquer).
 * It continuously halves the search space by comparing the target with the middle element.
 * If the target is found, its index is returned. If the target is not present, 
 * the left pointer 'l' will naturally converge to the exact insertion position 
 * once the search space is exhausted (when l > r).
 *
 * Input Sample:
 *
 *   target = 2
 *   nums = [1, 3, 5, 6]
 *
 * Execution Step-by-Step (Binary Search Iteration):
 *
 *   Initial state: l = 0, r = 3
 *   Step 1: mid = 0 + (3 - 0) / 2 = 1 -> nums[1] = 3
 *           target (2) < nums[1] (3) -> update r = mid - 1 = 0
 *   Step 2: mid = 0 + (0 - 0) / 2 = 0 -> nums[0] = 1
 *           target (2) > nums[0] (1) -> update l = mid + 1 = 1
 *   Termination: l (1) > r (0) -> Loop ends.
 *
 * Output:
 *
 *   1 (Index where target 2 should be inserted)
 *
 * Purpose:
 * Demonstrates how to:
 * - Implement logarithmic binary search on a sorted array.
 * - Calculate mid safely avoiding integer overflow: mid = l + (r - l) / 2.
 * - Utilize pointer convergence to find insertion boundaries without additional checks.
 *
 * Time Complexity: O(log N)
 * Space Complexity: O(1)
 *
 * where N is the total number of elements in the array.
 */
    vector<int> a;
    int k; cin>>k;
    int x;
    while(cin>>x){
        if(x==-1) break;
        a.push_back(x);
    }
    int i=searchInsert(a,k);
    cout<<i;
    return 0;
}