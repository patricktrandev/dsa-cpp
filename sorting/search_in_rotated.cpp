#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target){
    int l=0; int r=nums.size()-1;
    while(l<=r){
        int m= l+(r-l)/2;
        if(nums[m]==target) return m;
        if(nums[l]<= nums[m]){
            if(nums[l]<= target && target< nums[m]){
                r=m-1;
            }else{
                l=m+1;
            }
        }else{
            if(nums[m]< target && target <= nums[r]){
                l= m+1;
            }else{
                r=m-1;
            }
        }

    }

    return -1;
}

int main(){
        /** LEETCODE 33
     * SEARCH IN ROTATED SORTED ARRAY
     *
     * @brief Searches for a target value in an integer array sorted in ascending order 
     *        that has been rotated at an unknown pivot index.
     *
     * An array sorted in ascending order (with distinct values) is rotated at a pivot point.
     * For example, [0, 1, 2, 4, 5, 6, 7] might become [4, 5, 6, 7, 0, 1, 2].
     *
     * The algorithm uses Modified Binary Search. Key insight: When diving the array at midpoint 'm', 
     * at least one half (left [l...m] or right [m...r]) MUST be strictly sorted.
     *
     * Input Sample:
     *
     *   target = 0
     *   nums   = [4, 5, 6, 7, 0, 1, 2]
     *
     * Execution Step-by-Step:
     *
     *   Step 1: l = 0, r = 6, m = 3 (nums[m] = 7)
     *           Left half [4, 5, 6, 7] is sorted (nums[l] <= nums[m]).
     *           Target (0) is NOT in range [4, 7], so search in right half -> l = m + 1 = 4.
     *
     *   Step 2: l = 4, r = 6, m = 5 (nums[m] = 1)
     *           Left half [0, 1] is sorted (nums[l] <= nums[m]).
     *           Target (0) IS in range [0, 1], so search in left half -> r = m - 1 = 4.
     *
     *   Step 3: l = 4, r = 4, m = 4 (nums[m] = 0)
     *           nums[m] == target -> Return index 4.
     *
     * Output:
     *
     *   4
     *
     * Purpose:
     * Demonstrates how to:
     * - Implement Binary Search with modified boundary checks.
     * - Identify which half of a rotated sorted array is strictly increasing.
     * - Determine if the target lies within the sorted half to eliminate half the search space.
     *
     * Time Complexity: O(log N)
     * Space Complexity: O(1)
     *
     * where N is the length of the array `nums`.
     */
    vector<int> a;
    int k; cin>>k;
    int x;
    while(cin>>x){
        if(x==-1) break;
        a.push_back(x);
    }

    int i= search(a,k);
    cout<<i;

  return 0;
}