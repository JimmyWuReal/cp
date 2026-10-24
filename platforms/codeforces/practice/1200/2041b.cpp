#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        long long a, b; cin>>a>>b; 
        long long total=a+b;

        long long l=0, r=1e5; 
        long long mid; 

        while (l!=r-1) {
            mid=(l+r)/2; 
            
            long long c=mid*(mid+1)/2; 
            if (c>total) {
                r=mid; 
            } else {
                l=mid;                 
            }
        }

        cout<<l<<'\n'; 
    } 

    return 0;
}