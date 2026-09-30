#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 
    int a=0, b=0; 
    for (int i=0; i<N; i++) {
        int x; cin>>x; 
        a+=x; 
    }

    for (int i=0; i<N; i++) {
        int x; cin>>x; 
        b+=x; 
    }

    if (a>=b) {
        cout<<"YES\n"; 
    } else {
        cout<<"NO\n"; 
    }

    return 0; 
}