#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
void moveZeroes(vector<int>& n){
   int s=0; 
   for(int f=0; f<n.size(); f++){
      if(n[f]!=0){
         n[s++]=n[f];
      }
   }
   for(int i =s; i< n.size(); i++){
      n[i]=0;
   }
}

int main(){
   /** LeetCode 283
 * @brief Moves all 0's to the end of an array while maintaining the relative order of non-zero elements.
 * 
 * Takes an array of integers and modifies it in-place using a Two-Pointer technique.
 * The slow pointer (`s`) tracks the position for the next non-zero element, while the fast
 * pointer (`f`) scans the array. Non-zero elements are moved to the front, and the remaining
 * tail elements are filled with zeros, achieving optimal O(N) time and O(1) auxiliary space complexity.
 * 
 * Input Sample:
 * 5
 * 0 1 0 3 12
 * Output Sample:
 * 1    3    12    0    0    
 * 
 * Input Sample:
 * 1
 * 0
 * Output Sample:
 * 0    
 * 
 * Purpose:
 * Demonstrates In-place Array Partitioning and the Two-Pointer approach
 * to reorder elements efficiently in O(N) time and O(1) space complexity
 * without using extra memory allocations.
 */
    int k; cin>>k;
    vector<int> a;

    while(k>0){
        int t; cin>>t;
        a.push_back(t);
        k--;
    }

    moveZeroes(a);
    for(int i =0; i< a.size(); i++){
      cout<<a[i]<<"\t";
   }

    
    
  return 0;
}