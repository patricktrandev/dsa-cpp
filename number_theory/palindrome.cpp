#include <iostream>

using namespace std;

int reverse(int x){
    int res=0;
    while(x>0){
        int d=x%10;
        res=res*10 +d;
        x/=10;
    }
    return res;
}

bool isPalindrome(int x){
    int res= reverse(x);
    if(res==x){
        return true;
    }else{
        return false;
    }
}

int main(){
    /**
 * LEETCODE 9: PALINDROME NUMBER
 *
 * @brief Checks whether an integer is a palindrome (reads the same backward as forward).
 *
 * The algorithm reverses the digits of the input number and compares the reversed result 
 * with the original value.
 *
 * Conditions & Edge Cases:
 * 1. Negative numbers (e.g., -121) are NOT palindromes due to the negative sign.
 * 2. Single-digit numbers (0-9) are always palindromes.
 * 3. Multi-digit numbers are palindromes if reversing their digits yields the exact same value.
 *
 * Execution Step-by-Step (Evaluation for x = 121):
 *
 *   Step 1: Read input x = 121.
 *   Step 2: Call reverse(121):
 *           - Iteration 1: d = 121 % 10 = 1 | res = 0 * 10 + 1 = 1   | x = 12
 *           - Iteration 2: d = 12 % 10 = 2  | res = 1 * 10 + 2 = 12  | x = 1
 *           - Iteration 3: d = 1 % 10 = 1   | res = 12 * 10 + 1 = 121| x = 0
 *           - Returns res = 121.
 *   Step 3: Compare res (121) == x (121) -> Returns true.
 *   Step 4: Output "YES".
 *
 * Purpose:
 * Demonstrates how to:
 * - Extract and reverse digits using modulo (%) and integer division (/).
 * - Validate symmetrical properties of numbers.
 *
 * Time Complexity: O(log10(N)) - The number of iterations corresponds to the number of digits in N.
 * Space Complexity: O(1) - Uses a constant amount of extra space.
 */
    int x;
    cin>>x;
    bool res= isPalindrome(x);
    res ? cout<<"YES":cout<<"NO";

  return 0;
}