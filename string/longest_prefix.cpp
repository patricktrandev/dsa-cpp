#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string longestCommonPrefix(vector<string>& st){

    sort(st.begin(), st.end());

    string f=st.front();
    string l=st.back();
    int n = f.size() > l.size()? l.size(): f.size();
   
    string res="";
    for(int i=0; i< n; i++){
        if(f[i]!=l[i]){
            return res;
        }else{
            res+=f[i];
        }
    }

    return res;
}


int main() 
{

    /**
 * LEETCODE 14: LONGEST COMMON PREFIX
 *
 * @brief Finds the longest common prefix (LCP) string amongst an array of strings.
 *
 * The algorithm utilizes a Sorting-based Reduction approach. 
 * By lexicographically sorting the array of strings, the strings with the greatest 
 * differences are forced to the ends of the container (index 0 and index N-1).
 *
 * Key Technical Insight:
 * - Lexicographical order guarantees that if a prefix is shared across all strings 
 *   in the array, it MUST be shared between the first string (`f`) and the last string (`l`).
 * - Thus, the problem reduces from comparing N strings to comparing only TWO strings (`f` and `l`).
 *
 * Input Sample:
 *
 *   st = ["flower", "flow", "flight"]
 *
 * Execution Step-by-Step:
 *
 *   Step 1: Lexicographical Sort
 *           Original: ["flower", "flow", "flight"]
 *           Sorted:   ["flight", "flow", "flower"]
 *
 *   Step 2: Identify Boundary Strings
 *           f = st.front() -> "flight"
 *           l = st.back()  -> "flower"
 *           n = min(length("flight"), length("flower")) = 6
 *
 *   Step 3: Character-by-Character Comparison Loop:
 *           i = 0: 'f' == 'f' -> res += 'f' (res = "f")
 *           i = 1: 'l' == 'l' -> res += 'l' (res = "fl")
 *           i = 2: 'i' != 'o' -> Mismatch detected! Return early with res = "fl"
 *
 * Output:
 *
 *   "fl"
 *
 * Purpose:
 * Demonstrates how to:
 * - Reduce string array comparison complexity using lexicographical sorting (`std::sort`).
 * - Avoid redundant element-by-element comparisons across the entire vector.
 * - Optimize boundary traversal by bound-checking against the minimum string length.
 *
 * Time Complexity: O(N * M * log N)
 *   - Sorting N strings of max length M takes O(N * log N * M).
 *   - The final loop runs in O(M) time.
 * Space Complexity: O(1) auxiliary space (excluding space used by std::sort, which is O(log N)).
 *
 * where N is the number of strings and M is the length of the shortest boundary string.
 */
    vector<string> sts;
    int k; cin>>k;
    cin.ignore();
    while(k>0){
        string t;
        getline(cin,t);
        sts.push_back(t);
        k--;
    }
    string res=longestCommonPrefix(sts);
    cout<<res;
    return 0;
}