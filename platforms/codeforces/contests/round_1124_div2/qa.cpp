#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int n, k; cin>>n>>k; 
        int res=0; 
        while (k>1) {
            k--; 
            n--; 
            res+=2; 
        }

        int a=1; 
        while (n>0) {
            n--; 
            a*=2; 
        }

        res+=a; 
        cout<<res<<'\n'; 
    }

    return 0;
}