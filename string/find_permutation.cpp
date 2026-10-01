#include <iostream>
#include <unordered_map>

using namespace std;

int findPermutationDifference(string s, string t){
    unordered_map<char,int> m;
    for(int i =0; i< s.length(); i++){
        m[s[i]]=i;
    }
    int total=0;
    for(int i =0; i< t.length(); i++){
       total+=abs(m[t[i]]-i);
    }

    return total;
}

int main() 
{
    /*
        LC 3146
    */
    string s,t;
    getline(cin,s);
    getline(cin, t);
    int res=findPermutationDifference(s,t);
    cout<<res;

    return 0;
}