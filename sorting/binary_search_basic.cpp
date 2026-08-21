#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &a, int t, int l, int r){
    int m= l+(r-l)/2;
    if(a[m]==t){
        return m;
    }else if (t< a[m]){
        return binarySearch(a, t,l, m-1);
    }else{
        return binarySearch(a, t, m+1, r);
    }

}

int main(){

    /*
        input:
        9
        1 4 5 6 8 9 15 17
        output: 5

        Time complexity: O(logn)
    */
    vector<int> a;
    int k; cin>>k;
    int x;
    while(cin>>x){
        if(x==-1) break;
        a.push_back(x);
    }

    int i= binarySearch(a,k,0,a.size());
    cout<<i;

  return 0;
}