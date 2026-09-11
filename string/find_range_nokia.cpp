#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int, int>> parseInterval(string s){
    vector<pair<int, int>> mp;
    int st=-1;
    int cur=0;
    bool hasNum=false;
    for(char c:s){
        if(isdigit(c)){
            cur=cur*10+ (c-'0');
            hasNum=true;
        }else if (c=='-'){
            st=cur;
            cur=0;
            hasNum=false;
            
        }else if (c==',' || c==' '){
            if(hasNum && st!=-1){
                mp.push_back({st,cur});
                st=-1;cur=0;
                hasNum=false;
            }
        }
    }
    if(hasNum && st!=-1){
        mp.push_back({st,cur});
    }
    
    return mp;

}


void find_range(string s) {
    //split char
    vector<pair<int, int>> mp;
    vector<pair<int, int>> m;
    mp=parseInterval(s);
    int mx=mp[0].second;
    int min= mp[0].first;
    
    for(int i=0; i< mp.size(); i++){
        if(mp[i].first <= mx && mp[i].second>min){
            mx= mp[i].second;
        }else{
            m.push_back({min, mx});
            min=mp[i].first;
            mx=mp[i].second;
            
        }
    }
    m.push_back({min, mx});
    for(auto t: m){
        cout<<t.first<<" - "<<t.second<<"\n"; 
    }
    
}
int main() 
{
    /**
    nokia dev
 */
    string s;
    getline(cin, s);
    cin.ignore();
    find_range(s);
    
    return 0;
}