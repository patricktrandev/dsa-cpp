#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int maxChunksToSorted(vector<int> &a){
    //gaus
    int k =a.size();
    int s= k*(k+1)/2;
    int chunk=0; int t=0;
    for(int i=0; i<k; i++){
        t+=a[i];
        int s= i*(i+1)/2;
        if (s-t==0 || i==a[i]){
            chunk++;
            t=0;
        }
    }
    return chunk;
    
}
int maxChunksToSorted2(vector<int> &a){
    //max val
    int max_val=0;
    int chunk=0;
    for(int i=0; i<a.size(); i++){
        max_val= max(max_val, a[i]);
        if(max_val==i){
            chunk++;
        }
    }
    return chunk;
}
int main(){
    /** leetcode 769
     * @brief Calculates the maximum number of chunks an array can be split into such that 
     * sorting each chunk individually results in a fully sorted array.
     * 
     * Reads the size of the array `k` followed by `k` integers representing a permutation 
     * of numbers from 0 to n - 1. It offers two approaches: prefix sum tracking and maximum 
     * value tracking. The `maxChunksToSorted2` method determines chunk boundaries by checking 
     * if the maximum element encountered so far equals the current index.
     * 
     * Input Sample:
     * 5
     * 4 3 2 1 0
     * 
     * Output Sample:
     * 1
     * 
     * Input Sample:
     * 5
     * 1 0 2 3 4
     * 
     * Output Sample:
     * 4
     * 
     * Purpose:
     * Demonstrates array partitioning and greedy optimal sub-structure tracking with O(N) time 
     * complexity and O(1) auxiliary space complexity.
     */
    int k; cin>>k;
    vector<int> a;

    while(k>0){
        int t; cin>>t;
        a.push_back(t);
        k--;
    }
    int i= maxChunksToSorted2(a);
    cout<<i;
    
  return 0;
}