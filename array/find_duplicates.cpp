#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findDuplicate(vector<int> &a){
    int sl=0; int f=0;
    do{
        sl=a[sl];
        f=a[a[f]];
    }while(sl!=f);
    //found intercept reset slow 
    sl=0;
    while(f!=sl){
        sl=a[sl];
        f=a[f];
    }
    return sl;
}

int main(){
    /** leetcode 287
     * @brief Finds the duplicate number in an array of n + 1 integers where each integer is in the range [1, n].
     * 
     * Reads the size of the array `k` followed by `k` integers into a vector. Treats the array as a linked list 
     * where each value points to the next index, transforming the duplicate detection problem into finding 
     * the entry point of a cycle using Floyd's Tortoise and Hare (Fast and Slow Pointers) algorithm.
     * 
     * Input Sample:
     * 5
     * 1 3 4 2 2
     * 
     * Output Sample:
     * 2
     * 
     * Input Sample:
     * 5
     * 3 1 3 4 2
     * 
     * Output Sample:
     * 3
     * 
     * Purpose:
     * Demonstrates cycle detection in a functional graph using Floyd's algorithm with O(N) time 
     * complexity and O(1) auxiliary space complexity without modifying the original array.
     */
    int k; cin>>k;
    vector<int> a;

    while(k>0){
        int t; cin>>t;
        a.push_back(t);
        k--;
    }
    int i= findDuplicate(a);
    cout<<i;
    
  return 0;
}