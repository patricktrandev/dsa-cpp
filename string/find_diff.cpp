#include <iostream>
using namespace std;
char findTheDifference(string s, string t){
    int t1=0;int t2=0;
    for(int i=0; i< s.length(); i++){
        t1+=int(s[i]);
    }
    for(int i=0; i< t.length(); i++){
        t2+=t[i];
    }
    return char(t2-t1);
}

int main() 
{
    /*
        LC 389
    */
    string s, t;
    getline(cin,s);
    getline(cin,t);
    char r=findTheDifference(s,t);
    cout<<r;
    return 0;
}