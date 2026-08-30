#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& n) {
  int cur=n[0]; int mx=n[0];
  for(int i=1; i< n.size(); i++){
    cur= max(n[i], cur+n[i]);
    mx= max(mx, cur);
  }
  return mx;
}

int main(){
    /** LEETCODE 53
 * MAXIMUM SUBARRAY USING KADANE'S ALGORITHM
 *
 * @brief Finds the contiguous subarray within a 1D integer array which has the largest sum.
 *
 * The algorithm efficiently solves the problem by making a local optimal choice 
 * at each position. At each element, it decides whether to add the current element 
 * to the existing subarray or start a completely new subarray from that element.
 * For example:
 *
 *   [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 *
 * The maximum contiguous subarray is [4, -1, 2, 1].
 *
 * Input Sample:
 *
 *   9 (number of elements - variable 't' in main)
 *   -2 1 -3 4 -1 2 1 -5 4 -1
 *
 * This input represents the array:
 *
 *   [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 *
 * The algorithm tracks the running sum and updates the global maximum.
 * The final output is the largest sum found:
 *
 *   6
 *
 * Purpose:
 * Demonstrates how to:
 * - Apply Kadane's Algorithm for dynamic programming problems.
 * - Maintain running local maximums vs. global maximums.
 * - Optimize a problem from O(N^2) brute-force to linear time.
 * - Handle arrays with both positive and negative integers.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * where N is the length of the input array.
 */
  int t; cin>>t;
  vector<int> a;
  int k;
  while(t>0){
    cin>>k;
    a.push_back(k);
    t--;
  } 
  
  int i=maxSubArray(a);
  cout<<i;
  return 0;
}