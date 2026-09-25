#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n; 
    vector<int> a(n); for (auto &x : a) cin>>x; 

    int m1=0; 
    int m2=0; 
    int m3=0; 

    for (int i=0; i<n; i++) {
        if (a[i]>m1) {
            m3=m2; 
            m2=m1; 
            m1=a[i]; 
        } else if (a[i]>m2) {
            m3=m2; 
            m2=a[i]; 
        } else if (a[i]>m3) m3=a[i]; 
        
        if (i>=2) cout<<m3<<'\n'; 
    }

    return 0;
}