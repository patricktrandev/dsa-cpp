#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    string res;
    int i =a.length()-1, j=b.length()-1;
    int ca=0;
    while(i>=0 || j >=0 || ca !=0 ){
        int s=0;
        if(i<a.size()){
            s+= a[i]-'0';
            i--;
        }
        if(j<b.size()){
            s+= b[j]-'0';
            j--;
        }
        s+=ca;

        res+= to_string(s%2);
        ca=s/2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){

/** LEETCODE 67
 * ADD BINARY
 *
 * @brief Adds two binary strings and returns their sum as a binary string.
 *
 * The function iterates through both binary strings from right to left (least
 * significant bit to most significant bit), performing bit-by-bit addition
 * in base 2. A carry value is maintained whenever the sum of bits and carry
 * is greater than or equal to 2.
 *
 * Input Sample:
 *
 *   a = "1010"
 *   b = "1011"
 *
 * Binary Addition:
 *
 *     1 0 1 0   (10 in decimal)
 *   + 1 0 1 1   (11 in decimal)
 *   ---------
 *   1 0 1 0 1   (21 in decimal)
 *
 * Output:
 *
 *   "10101"
 *
 * Purpose:
 * Demonstrates how to:
 * - Traverse two strings backwards simultaneously using two pointers.
 * - Convert character digits ('0', '1') to numerical values using ASCII subtraction.
 * - Perform base-2 arithmetic with carry propagation (sum % 2 and sum / 2).
 * - Dynamically construct and reverse the result string.
 *
 * Time Complexity: O(max(N, M))
 * Space Complexity: O(max(N, M))
 *
 * where N and M are the lengths of strings a and b.
 */
  string a,b;
  getline(cin,a);
  getline(cin,b);
  string t=addBinary(a,b);
  cout<<t;


  return 0;
}