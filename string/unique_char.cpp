#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int firstUniqChar(string s){
    vector<int> x(26,0);
    for(int i=0; i< s.length(); i++){
        int index= s[i]-'a';
        if(x[index]!=0){
            x[index]++;
        }else{
            x[index]=1;
        }
    }
    for(int i=0; i< s.length(); i++){
        int k = s[i]-'a';
        if(x[k]==1){
            return i;
        }
    }
    return -1;
}
int main() 
{
    /**
 * LEETCODE 387: FIRST UNIQUE CHARACTER IN A STRING
 *
 * @brief Finds the index of the first non-repeating character in a given string.
 *
 * The algorithm uses a Two-Pass Frequency Array (Direct Addressing / Hash Array) approach.
 *
 * Key Technical Insight:
 * - Employs a fixed-size frequency array of length 26 to achieve O(1) auxiliary space complexity for lowercase English letters.
 * - Map characters to array indices using zero-based ASCII arithmetic: `index = s[i] - 'a'`.
 * - Pass 1 (Frequency Population): Iterates through the string to count occurrences of each character.
 * - Pass 2 (Early Exit Lookup): Re-iterates through the string sequentially to identify the first character with a frequency of 1.
 * - Retains original character order without requiring additional queue structures.
 *
 * Input Sample:
 *
 *   s = "loveleetcode"
 *
 * Execution Step-by-Step:
 *
 *   Step 1: Frequency Counting (Pass 1)
 *   - Iterates through "loveleetcode":
 *     'l': 2, 'o': 2, 'v': 1, 'e': 4, 't': 1, 'c': 1, 'd': 1
 *   - Resulting frequency table:
 *     x['l'-'a'] = 2, x['o'-'a'] = 2, x['v'-'a'] = 1, x['e'-'a'] = 4, ...
 *
 *   Step 2: Sequential Lookup (Pass 2)
 *   - i = 0, s[0] = 'l': x['l'-'a'] = 2 != 1 -> Continue
 *   - i = 1, s[1] = 'o': x['o'-'a'] = 2 != 1 -> Continue
 *   - i = 2, s[2] = 'v': x['v'-'a'] = 1 == 1 -> Target found! Return index 2
 *
 * Output:
 *
 *   2
 *
 * Purpose:
 * Demonstrates how to:
 * - Replace dynamic hash maps with fixed-size arrays for lower overhead when the alphabet set is bounded.
 * - Perform positional lookup while maintaining input order via a two-pass strategy.
 * - Map character data into numeric index offsets using relative ASCII computation.
 *
 * Time Complexity: O(N)
 *   - Scans the string twice: once to count frequencies and once to find the first unique character.
 * Space Complexity: O(1)
 *   - Allocates a constant-size frequency vector of size 26 regardless of input length.
 *
 * where N is the length of string `s`.
 */

    string a;
    getline(cin, a);
    
    int res= firstUniqChar(a);
    cout<<res;
    return 0;
}