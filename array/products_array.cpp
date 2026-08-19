#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &n){
    // left
    vector<int> ans(n.size(),1); int l=1; 
    for(int i=0; i< n.size();i++){
        ans[i]=l;
        l*=n[i];
    }

    //right
    int r=1;
    for(int i=n.size()-1; i>=0; i--){
        ans[i]*=r;
        r*=n[i];

    }
    return ans;
} 

int main() 
{
        /** PREFIX SUM LEETCODE 238
     * @brief Computes the product of all elements in an array except the element at the current index.
     * 
     * Reads a sequence of space-separated integers ending with -999 into a vector, then uses
     * a two-pass algorithm (Prefix and Suffix products) to compute the result for each index
     * without using the division operator.
     * 
     * Input Sample:
     * 1 2 3 4 -999
     * 
     * Output Sample:
     * 24	12	8	6	
     * 
     * Input Sample:
     * -1 1 0 -3 3 -999
     * 
     * Output Sample:
     * 0	0	9	0	0	
     * 
     * Purpose:
     * Demonstrates element-wise product calculation excluding self using Prefix and Suffix
     * accumulation with O(N) time complexity and O(1) auxiliary space complexity.
     */

    vector<int> a;
    int x;
    while(cin>>x){
        if (x==-999) break;
        a.push_back(x);
    }
    vector<int> ans= productExceptSelf(a);
    for(auto i:ans){
        cout<<i<<"\t";
    }
   


    return 0;
}