#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin>>N>>K; 
    vector<int> a(N); 
    for (int &x : a) cin>>x; 

    vector<int> sorted=a; 
    sort(sorted.begin(), sorted.end()); 

    int cnt=0; 

    for (int i=0; i<N; i++) {
        if (a[i]!=sorted[i]) break; 
        cnt++; 
    }
    for (int i=N-1; i>=0; i--) {
        if (a[i]!=sorted[i]) break; 
        cnt++; 
    }

    if (N-cnt>K) {
        cout<<"No\n"; 
    } else {
        cout<<"Yes\n"; 
    }

    return 0;
}