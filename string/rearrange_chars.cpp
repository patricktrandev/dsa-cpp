#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int rearrangeCharacters(string s, string target){
  vector<int> f(26,0);
  for(char &c: s){
    f[c-'a']++;
  }
  vector<int> x(26,0);
  for(char &c: target){
    x[c-'a']++;
  }
  int min_count=INT_MAX;
  for(int i=0; i< 26; i++){
    if(x[i]>0){
      if(f[i]==0) return 0;
      min_count= min(min_count, f[i]/x[i]);
    }
  }
  return  min_count;
}


int main(){
    /**
 * LEETCODE 2287: REARRANGE CHARACTERS TO MAKE TARGET STRING
 *
 * @brief Calculates the maximum number of copies of `target` that can be formed using characters from `s`.
 *
 * The algorithm utilizes the Frequency Map Bottleneck Technique (Dual Frequency Arrays & Integer Division)
 * to find the limiting character constraint (limiting reagent).
 *
 * Key Technical Insight:
 * - Source Frequency Map (`f`): Counts total available occurrences of each letter in input string `s`.
 * - Target Frequency Map (`x`): Counts required occurrences of each letter per single instance of `target`.
 * - Bottleneck Evaluation: For each distinct character present in `target` (`x[i] > 0`):
 *   - Early Exit: Returns `0` immediately if any required character is completely missing in `s` (`f[i] == 0`).
 *   - Ratio Calculation: Computes integer division `f[i] / x[i]` to determine how many times character `i` can support forming `target`.
 *   - Global Minimum (`min_count`): Tracks the smallest ratio across all required characters, which acts as the maximum total copies achievable.
 *
 * Input Sample:
 *
 *   s = "ilovecodingonleetcode", target = "code"
 *
 * Execution Step-by-Step:
 *
 *   Initialization:
 *   - Build `f` from `s`:
 *     f['c'-'a'] = 2, f['o'-'a'] = 4, f['d'-'a'] = 2, f['e'-'a'] = 3, ... (other counts)
 *   - Build `x` from `target` ("code"):
 *     x['c'-'a'] = 1, x['o'-'a'] = 1, x['d'-'a'] = 1, x['e'-'a'] = 1
 *   - min_count = INT_MAX
 *
 *   Evaluating Ratios for Required Characters (x[i] > 0):
 *   - Char 'c': f['c'] / x['c'] = 2 / 1 = 2 -> min_count = min(INT_MAX, 2) = 2
 *   - Char 'd': f['d'] / x['d'] = 2 / 1 = 2 -> min_count = min(2, 2) = 2
 *   - Char 'e': f['e'] / x['e'] = 3 / 1 = 3 -> min_count = min(2, 3) = 2
 *   - Char 'o': f['o'] / x['o'] = 4 / 1 = 4 -> min_count = min(2, 4) = 2
 *
 * Termination & Output:
 *   - Returns min_count: 2
 *
 * Purpose:
 * Demonstrates how to:
 * - Solve resource allocation and assembly-style bottleneck problems using ratio division.
 * - Map characters to fixed-size array frequencies ($O(1)$ memory access) via ASCII indexing (`c - 'a'`).
 * - Apply the concept of "limiting factor" (similar to limiting reactants in chemistry) to string composition problems.
 *
 * Time Complexity: O(N + M)
 *   - Single pass over string `s` of length N and string `target` of length M.
 *   - Checking ratios takes fixed time O(26) = O(1).
 * Space Complexity: O(1)
 *   - Uses two fixed-size arrays of size 26 regardless of input string lengths.
 *
 * where N is the length of `s` and M is the length of `target`.
 */
  string s; getline(cin,s);
  cin.ignore();
  string target; getline(cin,target);

  int res= rearrangeCharacters(s,target);
  cout<<res;


  return 0;
}