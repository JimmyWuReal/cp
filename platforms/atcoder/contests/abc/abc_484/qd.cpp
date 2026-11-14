#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 
    vector<int> a(N); 
    for (int &x : a) cin>>x; 

    long long res=1; 

    map<int, int> t; 

    for (int i=0; i<N; i++) {
        int cnt=max(0, i-t[a[i]]); 
        t[a[i]]++; 

        if (i>0 && a[i]==a[i-1]) cnt=0; 
        
        res+=cnt; 
    }

    cout<<res<<'\n'; 

    return 0;
}