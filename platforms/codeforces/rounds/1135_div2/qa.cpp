#include <bits/stdc++.h>
using namespace std;

bool prime(int x) {
    if (x==1) return true; 

    for (int i=2; i<x; i++) {
        if (x%i==0) {
            return false; 
        }
    }

    return true; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N; cin>>N; 

        if (N<=3) {
            cout<<-1<<'\n'; 
            continue;; 
        }

        for (int i=1; i<=N; i++) {
            if (i==1) cout<<4<<' '; 
            else if (i==4) cout<<1<<' ';
            else cout<<i<<' '; 
        }

        cout<<'\n'; 
    }

    return 0;
}
