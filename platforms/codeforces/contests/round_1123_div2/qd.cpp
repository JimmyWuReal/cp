#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N; cin>>N; 
        vector<int> pos(N); 
        for (int i=1; i<=N; i++) {
            int x; cin>>x; 
            pos[x-1]=i%2; 
        }

        pair<int, int> end; // first is odd, second is even 
        if (N%2==0) {
            end={1, 1}; 
        } else {
            end={2, 0}; 
        }

        bool res=true; 

        for (int s : pos) {
            if (s==1) {
                if (end.first==0) {
                    cout<<"NO\n"; 
                    res=false; 
                    break; 
                } 
                end.first--; 
                end.second++; 
            } else {
                if (end.second==0) {
                    cout<<"NO\n"; 
                    res=false; 
                    break; 
                } 
                end.second--; 
                end.first++; 
            }
        }

        if (res) cout<<"YES\n"; 
    }

    return 0;
}