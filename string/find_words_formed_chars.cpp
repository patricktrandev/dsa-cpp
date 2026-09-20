#include <iostream>
#include <vector>
using namespace std;
int countCharacters(vector<string>& words, string chars) {
    vector<int> s(26,0);
    for(char &c: chars){
        s[c-'a']++;
    }
    int total=0;
    
    for(string &t:words){
        vector<int> temp=s;
        bool valid=true;
        for(char &k:t){
            if(temp[k-'a']==0){
                valid=false;
                break;
            }
            temp[k-'a']--;
        }
        if(valid) total+=t.length();
    }
    return total;
}

int main() 
{
   /**
 * LEETCODE 1160: FIND WORDS THAT CAN BE FORMED BY CHARACTERS
 *
 * @brief Calculates the sum of lengths of all strings in `words` that can be formed using letters from `chars`.
 *
 * The algorithm utilizes a Frequency Counter / Hash Table (Fixed-size Array) combined with State Restoration (Array Copying)
 * to independently validate each word against the available character inventory.
 *
 * Key Technical Insight:
 * - Inventory Pass: Builds a master frequency array of size 26 (`vector<int> s(26, 0)`) for all available characters in `chars`.
 * - State Preservation (Copying): For each candidate string `t` in `words`, creates a lightweight copy (`vector<int> temp = s`)
 *   to track remaining available characters without corrupting the master inventory for subsequent words.
 * - Validation & Consumption: Iterates through each character in word `t`:
 *   - Checks if `temp[k - 'a'] > 0` using ASCII mapping (`k - 'a'`).
 *   - Consumes the character by decrementing `temp[k - 'a']--`.
 *   - Instantly invalidates (`valid = false`) and breaks early if a required character is unavailable or depleted.
 * - Result Accumulation: Adds `t.length()` to `total` only if the entire word `t` is successfully validated.
 *
 * Input Sample:
 *
 *   words = ["cat", "bt", "hat", "tree"], chars = "atach"
 *
 * Execution Step-by-Step:
 *
 *   Initialization:
 *   - Master Inventory `s` from `chars` ("atach"):
 *     s['a'-'a'] = 2, s['c'-'a'] = 1, s['h'-'a'] = 1, s['t'-'a'] = 1, others = 0
 *   - total = 0
 *
 *   Processing Word 1: "cat"
 *   - Copy master state: temp = s (s['a']=2, s['c']=1, s['h']=1, s['t']=1)
 *   - Check 'c': temp['c'] = 1 > 0 -> temp['c'] = 0
 *   - Check 'a': temp['a'] = 2 > 0 -> temp['a'] = 1
 *   - Check 't': temp['t'] = 1 > 0 -> temp['t'] = 0
 *   - Valid! total += length("cat") -> total = 3
 *
 *   Processing Word 2: "bt"
 *   - Copy master state: temp = s (s['a']=2, s['c']=1, s['h']=1, s['t']=1)
 *   - Check 'b': temp['b'] = 0 -> Invalid! Break loop.
 *   - total remains 3
 *
 *   Processing Word 3: "hat"
 *   - Copy master state: temp = s
 *   - Check 'h', 'a', 't' -> All valid!
 *   - Valid! total += length("hat") -> total = 3 + 3 = 6
 *
 *   Processing Word 4: "tree"
 *   - Copy master state: temp = s
 *   - Check 't' (valid), Check 'r' (temp['r'] = 0 -> Invalid!)
 *   - total remains 6
 *
 * Termination & Output:
 *   - Returns total: 6
 *
 * Purpose:
 * Demonstrates how to:
 * - Reuse a fixed-size frequency map across multiple independent validation passes using deep copies ($O(1)$ copy cost for size 26).
 * - Avoid state pollution when checking multiple sub-problems against a shared resource constraint.
 * - Perform $O(1)$ fast lookup and character index mapping via character arithmetic (`c - 'a'`).
 *
 * Time Complexity: O(K + \sum L_i)
 *   - Building master map takes O(K) where K is the length of `chars`.
 *   - Iterating through each word takes O(L_i) where L_i is the length of word i.
 *   - Array copy cost is O(26) = O(1) per word.
 * Space Complexity: O(1)
 *   - Uses fixed-size arrays/vectors of size 26 regardless of input bounds.
 *
 * where K is the length of `chars` and L_i is the length of the i-th string in `words`.
 */
    string chars;
    getline(cin, chars);
    int k; cin>>k;
    cin.ignore();
    vector<string> words;
    while(k>0){
        string m;
        getline(cin, m);
        words.push_back(m);
        k--;
    }
    int res= countCharacters(words, chars);
    cout<<res;

    return 0;
}