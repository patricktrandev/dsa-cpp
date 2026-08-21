#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int romanToInt(string s){
    unordered_map<char, int> p = {
    {'I', 1}, {'V', 5}, {'X', 10}, 
    {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int i =0;
    int res=0; 
    while(i< s.size()){
        if(p[s[i]]>= p[s[i+1]]){
            res+=p[s[i]];
        }else{
            res-=p[s[i]];
        }
        i++;
    }
    return res;
}

int main(){
    /** LEETCODE 13
     * ROMAN TO INTEGER
     *
     * @brief Converts a Roman numeral string to an integer.
     *
     * The algorithm traverses the string backwards from right to left (right-to-left scan).
     * It maintains a running maximum value (`max_val`) encountered so far.
     *
     * - If the current numeral's value is greater than or equal to `max_val`, 
     *   it is added to the total result, and `max_val` is updated.
     * - If the current numeral's value is strictly less than `max_val`, 
     *   it represents a subtractive combination (e.g., IV, IX, XL, XC, CD, CM) 
     *   and is subtracted from the total result.
     *
     * Input Sample:
     *
     *   s = "MCMXCIV"
     *
     * Execution Step-by-Step (Right-to-Left Traversal):
     *
     *   Step 1: Char 'V' (5)   >= max_val (0)  -> res += 5,   max_val = 5   (res = 5)
     *   Step 2: Char 'I' (1)   <  max_val (5)  -> res -= 1                 (res = 4)
     *   Step 3: Char 'C' (100) >= max_val (5)  -> res += 100, max_val = 100 (res = 104)
     *   Step 4: Char 'X' (10)  <  max_val (100)-> res -= 10                (res = 94)
     *   Step 5: Char 'M' (1000)>= max_val (100)-> res += 1000,max_val = 1000(res = 1094)
     *   Step 6: Char 'C' (100) <  max_val (1000)->res -= 100               (res = 994)
     *   Step 7: Char 'M' (1000)>= max_val (1000)->res += 1000,max_val = 1000(res = 1994)
     *
     * Output:
     *
     *   1994
     *
     * Purpose:
     * Demonstrates how to:
     * - Traverse a string backwards to handle subtractive notation naturally.
     * - Map characters to integer values using `std::unordered_map`.
     * - Propagate state (`max_val`) to evaluate Roman numerals in O(N) time without forward lookup.
     *
     * Time Complexity: O(N)
     * Space Complexity: O(1) (Hash map size is constant with 7 Roman symbols).
     *
     * where N is the length of the string `s`.
     */
    string s;
    getline(cin, s);
    int i=romanToInt(s);
    cout<<i;

  return 0;
}