#include <iostream>
#include <algorithm>
using namespace std;
string addStrings(string n1, string n2){
    int i=n1.length()-1;
    int j=n2.length()-1;
    string res="";
    int carry=0;
    while(i>=0 || j>=0 || carry>0){
            int d1=(i>=0)? n1[i]-'0':0;
            int d2=(j>=0)? n2[j]-'0':0;
            int s=d1+d2+carry;
            int t=s%10;
            carry=s/10;
            res+=to_string(t);
            
            i--; j--;
        }
        
    reverse(res.begin(), res.end());
    return res;
}
int main() 
{
/**
 * LEETCODE 415: ADD STRINGS
 *
 * @brief Computes the sum of two non-negative integers represented as strings.
 *
 * The algorithm utilizes the Two-Pointer Technique (Right-to-Left Traversal) to simulate elementary manual addition.
 *
 * Key Technical Insight:
 * - Traverses both input strings backwards, starting from the least significant digit (rightmost index).
 * - Safe character-to-integer conversion is performed using ASCII arithmetic: `char - '0'`.
 * - Ternary operators handle strings of unequal lengths by substituting out-of-bounds indices with `0`.
 * - Maintains a `carry` variable across iterations for values exceeding base-10 (sum >= 10).
 * - Avoids numeric overflow (BigInteger limits) by constructing the result digit-by-digit as a string.
 *
 * Input Sample:
 *
 *   n1 = "456", n2 = "77"
 *
 * Execution Step-by-Step:
 *
 *   Initialization:
 *   i = 2 (n1[2] = '6'), j = 1 (n2[1] = '7'), carry = 0, res = ""
 *
 *   Step 1:
 *   - d1 = 6, d2 = 7, carry = 0 -> sum = 6 + 7 + 0 = 13
 *   - Digit kept (t = 13 % 10): 3 -> res = "3"
 *   - New carry (13 / 10): 1
 *   - Decrement pointers: i = 1, j = 0
 *
 *   Step 2:
 *   - d1 = 5, d2 = 7, carry = 1 -> sum = 5 + 7 + 1 = 13
 *   - Digit kept (t = 13 % 10): 3 -> res = "33"
 *   - New carry (13 / 10): 1
 *   - Decrement pointers: i = 0, j = -1
 *
 *   Step 3:
 *   - d1 = 4, d2 = 0 (j < 0), carry = 1 -> sum = 4 + 0 + 1 = 5
 *   - Digit kept (t = 5 % 10): 5 -> res = "335"
 *   - New carry (5 / 10): 0
 *   - Decrement pointers: i = -1, j = -2
 *
 *   Termination & Reversal:
 *   - Loop terminates (i < 0, j < 0, carry == 0).
 *   - Reverse res: "335" -> "533"
 *
 * Output:
 *
 *   "533"
 *
 * Purpose:
 * Demonstrates how to:
 * - Handle arbitrarily large integer addition without using standard integer data types.
 * - Perform positional arithmetic on strings using back-to-front dual index tracking.
 * - Utilize string manipulation (`std::to_string`, `std::reverse`) to formulate the final result.
 *
 * Time Complexity: O(max(N, M))
 *   - Traverses the strings in a single pass up to the length of the longer string (plus optional carry).
 * Space Complexity: O(max(N, M))
 *   - Allocates memory to store the output string of length max(N, M) + 1.
 *
 * where N and M are the lengths of `n1` and `n2` respectively.
 */
    string a,b;
    getline(cin, a);
    getline(cin,b);
    string res= addStrings(a,b);
    cout<<res;
    return 0;
}