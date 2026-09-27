#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin>>N>>Q; 
    
    vector<bool> ts(N, true);  
    vector<int> type(Q), xx(Q, -1); 
    vector<char> cc(Q); 

    for (int i=0; i<Q; i++) {
        int t; cin>>t; 
        type[i]=t; 
        
        if (t==1) {
            int x; cin>>x; 
            x--; 
            
            xx[i]=x; 
            ts[x]=(ts[x]==false ? true : false); 
        } else {
            char c; cin>>c; 
            cc[i]=c; 
        }
    }

    set<int> active; 
    vector<bool> changed(N, false); 
    string ans(N, 'a'); 

    for (int i=0; i<N; i++) {
        if (ts[i]==true) active.insert(i); 
    }

    for (int i=Q-1; i>=0; i--) {
        if (type[i]==2) {
            for (auto x : active) {
                ans[x]=cc[i]; 
                changed[x]=true; 
            }
            active.clear(); 
        } else {
            int x=xx[i]; 

            if (changed[x]) continue; 

            if (active.count(x)) {
                active.erase(x); 
            } else {
                active.insert(x); 
            }
        }
    }

    cout<<ans<<'\n';

    return 0;
}