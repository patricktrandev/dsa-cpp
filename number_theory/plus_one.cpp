#include <iostream>
#include <vector>
using namespace std;


vector<int> plusOne(vector<int>& d){
    
    for(int i=d.size()-1; i>=0; i--){
        if(d[i]<9){
            d[i]++;
            return d;
        }
        d[i]=0;
        
    }

    d.insert(d.begin(),1);
    return d;
}

int main(){
    /**
 * LEETCODE 66: PLUS ONE
 *
 * @brief Increments a large integer represented as an array of digits by one.
 *
 * The algorithm iterates through the digits from right to left (least significant to 
 * most significant digit) to simulate manual addition with carry propagation.
 *
 * Execution Logic:
 * 1. Traversal: Start from the rightmost digit (`d.size() - 1`).
 * 2. If digit < 9: Increment the current digit by 1 and return the vector immediately 
 *    (no further carry to propagate).
 * 3. If digit == 9: Set the current digit to 0 and continue the loop to propagate the carry (1).
 * 4. Overflow Case: If the loop finishes without returning, all digits were 9 (e.g., [9, 9, 9] -> [0, 0, 0]).
 *    Insert `1` at the front of the array to produce the final result (e.g., [1, 0, 0, 0]).
 *
 * Step-by-Step Execution Example (d = [9, 9]):
 * - Loop i = 1: d[1] is 9 -> Set d[1] = 0 (d = [9, 0])
 * - Loop i = 0: d[0] is 9 -> Set d[0] = 0 (d = [0, 0])
 * - Loop ends -> Insert 1 at the beginning -> Result: [1, 0, 0, 0]
 *
 * Time Complexity: 
 * - Best Case: O(1) when the last digit is less than 9.
 * - Worst Case: O(N) when all digits are 9 (where N is the number of digits).
 *
 * Space Complexity: O(1) in-place modification (O(N) auxiliary space only when reallocating for insert).
 */
    int x;
    vector<int> a;
    while(cin>>x){
        if(x==-1) break;
        a.push_back(x);
    }
    vector<int> r= plusOne(a);
    for(int i=0; i<r.size(); i++){
        cout<<r[i]<<"\t";
    }

  return 0;
}