#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin>>Q; 

    string S, T; cin>>S>>T; 
    
    int sz=S.size(); 
    int tz=T.size(); 

    vector<int> occ(sz, 0); 
    for (int i=0; i<sz-tz+1; i++) {
        if (S.substr(i, tz)==T) occ[i]=1; 
    } 

    vector<int> prefix(sz); 
    prefix[0]=occ[0]; 
    for (int i=1; i<sz; i++) {
        prefix[i]=prefix[i-1]+occ[i]; 
    }

    while (Q--) {
        int l, r; 
        cin>>l>>r; 
        
        if (r-l+1<tz) {
            cout<<"No\n";
            continue;
        }

        int left=l-1;
        int right=r-tz;

        int cnt=prefix[right]-(left ? prefix[left-1] : 0);

        if (cnt>0) {
            cout<<"Yes\n"; 
        } else {
            cout<<"No\n"; 
        }
    }
    
    return 0;
}