#include <iostream>
#include <vector>
using namespace std;
bool canConstruct(string ransomNote, string magazine) {
    vector<int> s(26,0);
    for(char &c: magazine){
        s[c-'a']++;
    }
    for(char &c: ransomNote){
        if(s[c-'a']==0){
            return false;
        }
        s[c-'a']--;
    }
    return true;
}

int main() 
{
    /**
 * LEETCODE 383: RANSOM NOTE
 *
 * @brief Determines if a ransom note can be constructed from a given magazine's available characters.
 *
 * The algorithm utilizes the Frequency Counter / Hash Table Technique (Fixed-size Array) to count character occurrences.
 *
 * Key Technical Insight:
 * - Employs a frequency array of size 26 (`vector<int> s(26, 0)`) to map lower-case English letters ('a' - 'z').
 * - Maps characters to array indices using ASCII arithmetic: `c - 'a'`.
 * - First Pass (Magazine): Iterates through `magazine` to build a character inventory (increments frequency counts).
 * - Second Pass (Ransom Note): Iterates through `ransomNote` to consume available letters (decrements frequency counts).
 * - Early Termination: Instantly returns `false` if a required character count reaches `0` (insufficient letters).
 * - Ensures each letter in `magazine` is used at most once.
 *
 * Input Sample:
 *
 *   ransomNote = "aa", magazine = "aab"
 *
 * Execution Step-by-Step:
 *
 *   Initialization:
 *   s = [0, 0, ..., 0] (26 zeros)
 *
 *   Phase 1: Populate Inventory (magazine = "aab")
 *   - c = 'a' -> s['a'-'a']++ -> s[0] = 1
 *   - c = 'a' -> s['a'-'a']++ -> s[0] = 2
 *   - c = 'b' -> s['b'-'a']++ -> s[1] = 1
 *   Current state: s['a'] = 2, s['b'] = 1, others = 0
 *
 *   Phase 2: Validate & Consume (ransomNote = "aa")
 *   - Step 1: c = 'a'
 *     - Check: s['a'-'a'] = 2 > 0 (Valid)
 *     - Consume: s['a'-'a']-- -> s[0] = 1
 *   - Step 2: c = 'a'
 *     - Check: s['a'-'a'] = 1 > 0 (Valid)
 *     - Consume: s['a'-'a']-- -> s[0] = 0
 *
 *   Termination & Result:
 *   - Successfully verified all characters in ransomNote.
 *   - Returns: true
 *
 * Output:
 *
 *   true
 *
 * Purpose:
 * Demonstrates how to:
 * - Solve string matching and sub-bag/multiset problems using frequency counting.
 * - Map character sets to fixed-size array buffers for O(1) direct-access memory operations.
 * - Validate resource availability under constraints where elements are consumable resources (used at most once).
 *
 * Time Complexity: O(N + M)
 *   - Iterates through `magazine` of length M and `ransomNote` of length N in two linear passes.
 * Space Complexity: O(1)
 *   - Uses a fixed auxiliary array of size 26 regardless of input string length.
 *
 * where N is the length of `ransomNote` and M is the length of `magazine`.
 */
    string ransome, magazine;
    getline(cin, ransome);
    getline(cin, magazine);
    bool res= canConstruct(ransome, magazine);
    res? cout<<"true":cout<<"false";

    return 0;
}