#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int findShortestSubArray(vector<int>& n){
  unordered_map<int, int> f;
  unordered_map<int, int> l;
  unordered_map<int, int> c;
  for(int i =0 ; i< n.size(); i++){
    int x=n[i];
    if(f.find(x) != f.end()){
      l[x]=i;
    }else{
      f[x]=i;
      l[x]=i;
    }
    c[x]++;
  }
  int mx=c[0]; int mi=9999;
  for(auto t:c){
    if(t.second> mx) mx=t.second;

  }
  
  for(auto t:c){
    if(t.second==mx){
      int k= l[t.first]-f[t.first]+1;
      if(mi>k){
        mi=k;
      }
    }
  }
  return mi;
}

int main(){
    /**
 * LEETCODE 697
 * DEGREE OF AN ARRAY
 *
 * @brief Finds the length of the smallest contiguous subarray that has the same degree as the array.
 *
 * The degree of an array is defined as the maximum frequency of any element in the array.
 * To find the shortest contiguous subarray containing all occurrences of a frequent element,
 * we need to track three values for each element:
 * 1. The first occurrence index.
 * 2. The last occurrence index.
 * 3. The total frequency (count).
 *
 * The shortest length of a subarray containing all occurrences of an element `x` is:
 *   
 *   length = last_index[x] - first_index[x] + 1
 *
 * Input Sample:
 *
 *   nums = [1, 2, 2, 3, 1, 4, 2]
 *
 * Process:
 * - Frequencies:
 *     1 -> 2 times  (first: 0, last: 6) -> length = 4 - 0 + 1 = 5
 *     2 -> 3 times  (first: 1, last: 6) -> length = 6 - 1 + 1 = 6
 *     3 -> 1 time   (first: 3, last: 3) -> length = 3 - 3 + 1 = 1
 *     4 -> 1 time   (first: 5, last: 5) -> length = 5 - 5 + 1 = 1
 * - Degree of array = 3 (due to element 2 appearing 3 times).
 * - Shortest subarray length for elements with frequency = 3 is 6 (for element 2).
 *
 * Output:
 *
 *   6
 *
 * Purpose:
 * Demonstrates how to:
 * - Track element positions and frequencies using Hash Maps / Structs.
 * - Calculate sub-segment bounds using first and last indices.
 * - Solve subsegment problems efficiently in a single pass.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 *
 * where N is the number of elements in the input array.
 */
  vector<int> a;
  int k;
  while(cin>>k){
    if(k==-1) break;
    a.push_back(k);
  } 
  
  int i=findShortestSubArray(a);
  cout<<i;
  return 0;
}