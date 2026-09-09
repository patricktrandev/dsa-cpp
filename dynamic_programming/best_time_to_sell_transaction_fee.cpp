#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int maxProfit(vector<int>& p, int fee){
   int h=0-p[0]; int f=0;
   for(int i =0; i< p.size(); i++){
      h=max(h, f-p[i]);
      f=max(f, h+p[i]-fee);
   }
   return f;
}

int main(){
  /** LeetCode 714
 * @brief Calculates the maximum profit achievable from stock trading with a transaction fee.
 * 
 * Computes the maximum profit using Dynamic Programming with O(1) space complexity. 
 * Maintains two states at each step:
 * - `h` (hold): Maximum profit when holding a stock.
 * - `f` (free): Maximum profit when holding no stock (cash on hand).
 * 
 * Dynamic Programming Transitions:
 * - `h = max(h, f - p[i])`: 
 *   Either keep the stock from the previous day, or buy a new stock today at price `p[i]`
 *   using cash from the previous `free` state.
 * - `f = max(f, h + p[i] - fee)`: 
 *   Either remain without stock, or sell the currently held stock today at price `p[i]`
 *   and pay the transaction `fee`.
 * 
 * Input Sample:
 * 6 2
 * 1 3 2 8 4 9
 * Output Sample:
 * 8
 * 
 * Input Sample:
 * 6 3
 * 1 3 7 5 10 3
 * Output Sample:
 * 6
 * 
 * Purpose:
 * Demonstrates State-Machine Dynamic Programming to optimize stock trading decisions
 * with transaction fees in O(N) time and O(1) auxiliary space complexity.
 */
    int k,t; cin>>k>>t;
    vector<int> a;

    while(k>0){
        int t; cin>>t;
        a.push_back(t);
        k--;
    }

   int i=maxProfit(a,t);
   cout<< i;
    

    
    
  return 0;
}