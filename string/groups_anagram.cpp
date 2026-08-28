#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &st){
    unordered_map<string, vector<string>> m;
    vector<string> a;
    for(int i =0; i<st.size(); i++){
      string key = st[i];
      sort(key.begin(), key.end());
      m[key].push_back(st[i]);
    }
    vector<vector<string>> res;
    for(auto &p:m){
      res.push_back(p.second);
    }

    return res;
}

int main(){
   /** LEETCODE 49
 * GROUP ANAGRAMS
 *
 * @brief Groups an array of strings into sub-lists of anagrams.
 *
 * The algorithm uses a Hash Map (`std::unordered_map`) to categorize words based on 
 * their canonical form (sorted character sequence).
 *
 * - For each word in the input array, a copy is made and its characters are sorted 
 *   alphabetically to generate a unique key (e.g., "eat", "tea", "ate" all become "aet").
 * - The sorted key serves as the hash map key, where the value is a dynamic list (`vector<string>`) 
 *   holding all original words that match this sorted character signature.
 * - Finally, all grouped lists from the map values are collected into the final result matrix.
 *
 * Input Sample:
 *
 *   strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 *
 * Execution Step-by-Step (Categorization via Sorted Key):
 *
 *   Step 1: Word "eat" -> Sorted key "aet" -> map["aet"] = ["eat"]
 *   Step 2: Word "tea" -> Sorted key "aet" -> map["aet"] = ["eat", "tea"]
 *   Step 3: Word "tan" -> Sorted key "ant" -> map["ant"] = ["tan"]
 *   Step 4: Word "ate" -> Sorted key "aet" -> map["aet"] = ["eat", "tea", "ate"]
 *   Step 5: Word "nat" -> Sorted key "ant" -> map["ant"] = ["tan", "nat"]
 *   Step 6: Word "bat" -> Sorted key "abt" -> map["abt"] = ["bat"]
 *
 * Output:
 *
 *   [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]
 *
 * Purpose:
 * Demonstrates how to:
 * - Utilize string sorting to establish a invariant hash key for string equivalency.
 * - Leverage `std::unordered_map` for efficient bucket insertion and grouping.
 * - Aggregate grouped values from a hash map into a 2D matrix structure.
 *
 * Time Complexity: O(N * K log K)
 * Space Complexity: O(N * K)
 *
 * where N is the number of strings in `strs`, and K is the maximum length of a string.
 */
    int k; cin>>k;
    cin.ignore();
    vector<string> a;
    string s;
    for (int i = 0; i < k; i++) {
        cin >> s;
        a.push_back(s);
    }
   vector<vector<string>> r = groupAnagrams(a);
    for (int i = 0; i < r.size(); i++) {
        for (auto t : r[i]) {
            cout << t << "\t";
        }
        cout << endl;
    }


  return 0;
}