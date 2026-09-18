#include <iostream>
#include <unordered_set>
using namespace std;
char repeatedCharacter(string s) {
    unordered_set<char> m;
    for(int i =0; i< s.length(); i++){
        if(m.find(s[i])!= m.end()){
            return s[i];
        }else{
            m.insert(s[i]);
        }
    }
    return '\0';
}
char repeatedCharacter(string s){
    vector<int> counts(26,0);
    for(const char &c: s){
        counts[c-'a']++;
        if(counts[c-'a']==2) return c;
    }
    return ' ';
}
int main() 
{
    /**
 * LEETCODE 2351: FIRST LETTER TO APPEAR TWICE
 *
 * @brief Finds the first character in a string that appears twice.
 *
 * The algorithm scans the string left-to-right and tracks seen characters using a Hash Set or Frequency Array
 * to achieve immediate lookup upon detecting the first duplicate.
 *
 * Key Technical Insight:
 * - Traverses the string linearly from the first character (left-to-right).
 * - Approach 1 (Hash Set): Uses `std::unordered_set<char>` to store visited characters. Offers $O(1)$ average insertion and search.
 * - Approach 2 (Frequency Array): Uses a fixed-size vector `vector<int>(26, 0)` indexed by ASCII offset `c - 'a'`.
 *   This achieves lower space overhead ($O(1)$ auxiliary space) and eliminates hash map overhead.
 * - Terminates early and returns the character as soon as its occurrence count reaches 2 (or is found in set).
 *
 * Input Sample:
 *
 *   s = "abccbaacz"
 *
 * Execution Step-by-Step (Frequency Array approach):
 *
 *   Initialization:
 *   counts = [0, 0, ..., 0] (size 26)
 *
 *   Step 1:
 *   - c = 'a' -> counts['a' - 'a'] = counts[0] = 1 (Count < 2, continue)
 *
 *   Step 2:
 *   - c = 'b' -> counts['b' - 'a'] = counts[1] = 1 (Count < 2, continue)
 *
 *   Step 3:
 *   - c = 'c' -> counts['c' - 'a'] = counts[2] = 1 (Count < 2, continue)
 *
 *   Step 4:
 *   - c = 'c' -> counts['c' - 'a'] = counts[2] = 2 (Count == 2!)
 *   - Return 'c' immediately.
 *
 * Output:
 *
 *   'c'
 *
 * Purpose:
 * Demonstrates how to:
 * - Utilize hash sets / fixed-size frequency tables for immediate lookup operations.
 * - Perform character-to-index mapping using ASCII arithmetic: `c - 'a'`.
 * - Optimize search problems by short-circuiting execution upon meeting a condition.
 *
 * Time Complexity: $O(N)$
 *   - Single pass over the string up to $N$ characters (where $N$ is the length of $s$).
 *   - In practice for 26 lowercase English letters, loop runs at most 27 iterations $\to O(1)$.
 *
 * Space Complexity: $O(1)$ or $O(U)$
 *   - Approach 1 (Hash Set): $O(U)$ where $U$ is the number of unique characters ($U \le 26$).
 *   - Approach 2 (Frequency Array): $O(1)$ fixed auxiliary memory for 26 alphabetic slots.
 */
    string s;
    getline(cin,s);
    char r= repeatedCharacter(s);
    cout<<r;
    return 0;
}