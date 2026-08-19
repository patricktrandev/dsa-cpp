#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> &n){
    unordered_set<int> s;
    for(int i=0; i<n.size(); i++){
        if(s.find(n[i])!= s.end()){
            return true;
        }else{
            s.insert(n[i]);
        }
    }
    return false;
} 

int main() 
{

    /** leetcode 217
     * @brief Checks if an integer array contains any duplicate values using a Hash Set.
     * 
     * Reads a sequence of space-separated integers ending with -1 into a vector, then uses
     * an `unordered_set` (hash table) to track encountered elements. If a duplicate element is found
     * during iteration, the function returns true immediately; otherwise, it returns false.
     * 
     * Input Sample:
     * 3 2 0 -4 -1
     * 
     * Output Sample:
     * NO
     * 
     * Input Sample:
     * 1 2 3 1 -1
     * 
     * Output Sample:
     * YES
     * 
     * Purpose:
     * Demonstrates duplicate detection in an array using an unordered_set (hash table)
     * with O(N) average time complexity and O(N) space complexity.
     */

    vector<int> a;
    int x;
    while(cin>>x){
        if (x==-1) break;
        a.push_back(x);
    }

    bool isDuplicate= containsDuplicate(a);
    isDuplicate ? cout<<"YES": cout<<"NO";


    return 0;
}