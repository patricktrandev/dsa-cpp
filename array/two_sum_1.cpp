#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<int> twoSum(vector<int> &n, int t) {
   int i=0; int j=n.size()-1;
   while(i<=j){
    int k=n[i]+n[j];
    if(k==t){
        return {i+1 ,j+1};
    }else if(k>t){
        j--;
    }else{
        i++;
    }
   }
}

int main(){
   /** LeetCode 167
 * @brief Finds two numbers in a 1-indexed, sorted array that add up to a specific target.
 * 
 * Takes a sorted 1-indexed vector of integers and a target sum. Leverages the Two Pointers 
 * technique by placing one pointer at the beginning and another at the end of the array. 
 * Moves the pointers inward based on the current sum relative to the target, achieving an 
 * optimal search in O(N) time and O(1) auxiliary space complexity.
 * 
 * Input Sample:
 * 4 9
 * 2 7 11 15
 * Output Sample:
 * 1    2
 * 
 * Input Sample:
 * 3 6
 * 2 3 4
 * Output Sample:
 * 1    3
 * 
 * Input Sample:
 * 2 -1
 * -1 0
 * Output Sample:
 * 1    2
 * 
 * Purpose:
 * Demonstrates the Two Pointers pattern on sorted arrays to achieve optimal O(N) time 
 * complexity and O(1) space complexity without extra data structures like Hash Maps.
 */
    int k,t; cin>>k>>t;
    vector<int> a;

    while(k>0){
        int t; cin>>t;
        a.push_back(t);
        k--;
    }

    vector<int> x;
    x= twoSum(a,t);
    for(int i =0; i< x.size(); i++){
        cout<<x[i]<<"\t";
    }
    
  return 0;
}