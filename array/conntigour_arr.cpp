#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int findMaxLength(vector<int> &n) {
    int j=-1; int s=0; int mx=0;
    unordered_map<int, int> m;
    for(int i =0; i<n.size(); i++){
        if(n[i]==0){
            s-=1;
            
        }else{
            s+=1;
        }

        if(m.find(s)!= m.end()){
            mx=max(mx,i-m[s]);
        }else{
            m[s]=i;
        }
    }
    return mx;
}

int main(){
    /** LeetCode 525
     * @brief Finds the maximum length of a contiguous subarray with an equal number of 0 and 1.
     * 
     * Reads a binary vector of integers containing only 0s and 1s. Transforms the problem into finding 
     * the longest subarray with a sum of 0 by treating 0 as -1. Uses a Prefix Sum technique combined 
     * with a Hash Map to record the first occurrence index of each prefix sum in O(N) time.
     * 
     * Input Sample:
     * [0, 1]
     * Output Sample:
     * 2
     * 
     * Input Sample:
     * [0, 1, 0]
     * Output Sample:
     * 2
     * 
     * Input Sample:
     * [0, 1, 1, 1, 1, 1, 0, 0, 0]
     * Output Sample:
     * 6
     * 
     * Purpose:
     * Demonstrates the Prefix Sum + Hash Map pattern for contiguous subarray problems, 
     * achieving O(N) time complexity and O(N) auxiliary space complexity.
     */
    int k; cin>>k;
    vector<int> a;

    while(k>0){
        int t; cin>>t;
        a.push_back(t);
        k--;
    }
    int i= findMaxLength(a);
    cout<<i;
    
  return 0;
}