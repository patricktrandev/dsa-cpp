#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& a, int k){
    int n =a.size();
    k=k%n;
    reverse(a.begin(), a.end());

    reverse(a.begin(),a.begin()+k);
    reverse(a.begin()+k, a.end());
}


int main() 
{
    /** LeetCode 189
 * @brief Rotates an array to the right by k steps.
 * 
 * Computes the array rotation using the "Three Reverses" algorithm in O(1) extra space complexity. 
 * Executes three sequential reverse operations based on modulo arithmetic (k = k % n):
 * - `reverse(a.begin(), a.end())`: 
 *   Reverses the entire array to move the last k elements to the front, though inverted.
 * - `reverse(a.begin(), a.begin() + k)`: 
 *   Reverses the first k elements to restore their original relative order.
 * - `reverse(a.begin() + k, a.end())`: 
 *   Reverses the remaining n - k elements to restore their original relative order.
 * 
 * Input Sample:
 * 7 3
 * 1 2 3 4 5 6 7
 * Output Sample:
 * 5	6	7	1	2	3	4	
 * 
 * Input Sample:
 * 4 2
 * -1 -100 3 99
 * Output Sample:
 * 3	99	-1	-100	
 * 
 * Purpose:
 * Demonstrates the "Three Reverses" technique to perform cyclic right rotation
 * on a sequence in O(N) time and O(1) auxiliary space complexity.
 */
    int k,t; cin>>k>>t;
    vector<int> a;
    int x;
    while(k>0){
        cin>>x;
        a.push_back(x);
        k--;
    }
    rotate(a,t);
    for(int i=0; i< a.size(); i++){
        cout<<a[i]<<"\t";
    }
    return 0;
}