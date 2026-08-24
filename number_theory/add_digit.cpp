#include <iostream>

using namespace std;

int addDigits(int num){
    if(num==0){
        return 0;
    }else if(num%9==0){
        return 9;
    }else{
        return num%9;
    }
}

int main(){
  /** LEETCODE 258
 * ADD DIGITS
 *
 * @brief Repeatedly adds all digits of a non-negative integer until the result has only one digit.
 *
 * The algorithm uses the mathematical property of Digital Root (Congruence Modulo 9) to solve the
 * problem in O(1) time without using any loops or recursion.
 *
 * Mathematical Logic:
 * - Any number N in base 10 can be expressed as: N = a_k*10^k + a_(k-1)*10^(k-1) + ... + a_1*10 + a_0
 * - Since 10^n ≡ 1 (mod 9), it follows that: N ≡ a_k + a_(k-1) + ... + a_1 + a_0 (mod 9)
 * - Thus, a number's digital root is congruent to its value modulo 9.
 *
 * Conditions:
 * 1. If num == 0: The result is 0.
 * 2. If num % 9 == 0: The digital root is 9 (since a non-zero number's repeated digit sum cannot be 0).
 * 3. Otherwise: The result is num % 9.
 *
 * Input Sample:
 *
 *   num = 38
 *   Standard Sample: num = 0
 *
 * Execution Step-by-Step (Digital Root Evaluation for num = 38):
 *
 *   Step 1: Check if num == 0                     -> false (38 != 0)
 *   Step 2: Check if num % 9 == 0 (38 % 9 = 2)     -> false
 *   Step 3: Evaluate num % 9                       -> 38 % 9 = 2
 *   Step 4: Returns 2                              -> (Verification: 3 + 8 = 11 -> 1 + 1 = 2)
 *
 * Execution Step-by-Step (Digital Root Evaluation for num = 18):
 *
 *   Step 1: Check if num == 0                     -> false (18 != 0)
 *   Step 2: Check if num % 9 == 0 (18 % 9 = 0)     -> true
 *   Step 3: Returns 9                              -> (Verification: 1 + 8 = 9)
 *
 * Purpose:
 * Demonstrates how to:
 * - Apply mathematical properties (Modulo 9 / Digital Root) to eliminate iterative processing.
 * - Achieve constant time O(1) and constant space O(1) complexity.
 * - Handle edge cases like zero and multiples of 9 effectively.
 *
 * Time Complexity: O(1) since it uses basic arithmetic operations.
 * Space Complexity: O(1) as no extra memory allocation is required.
 */
    int x;
    cin>>x;
    int res= addDigits(x);
    cout<<res;

  return 0;
}