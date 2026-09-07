#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int maxProfit(vector<int>& p){
   int min_sf=p[0];
   int mx_p=p[0]-min_sf;
   for(int i=0; i< p.size(); i++){
    min_sf=min(min_sf, p[i]);
    mx_p= max(mx_p,p[i]-min_sf);
   }

   return mx_p;
}

int main(){
   /** LeetCode 121
 * @brief Finds the maximum profit from buying and selling a stock once.
 * 
 * Takes an array of stock prices where prices[i] is the price on the i-th day.
 * Leverages the Dynamic Programming / Single Pass technique by maintaining a running
 * minimum price (`min_price`) seen so far. At each step, calculates the potential profit
 * if selling on the current day and updates the maximum profit (`max_profit`),
 * achieving an optimal O(N) time and O(1) auxiliary space complexity.
 * 
 * Input Sample:
 * 6
 * 7 1 5 3 6 4
 * Output Sample:
 * 5
 * 
 * Input Sample:
 * 5
 * 7 6 4 3 1
 * Output Sample:
 * 0
 * 
 * Purpose:
 * Demonstrates 1-variable State Compression in Dynamic Programming (Greedy Single Pass)
 * to solve array tracking problems with optimal O(N) time and O(1) space complexity
 * without nested loops.
 */
    int k; cin>>k;
    vector<int> a;

    while(k>0){
        int t; cin>>t;
        a.push_back(t);
        k--;
    }

    int r=maxProfit(a);
    cout<<r;

    
    
  return 0;
}