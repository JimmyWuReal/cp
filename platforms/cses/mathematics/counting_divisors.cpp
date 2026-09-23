#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N;

    while (N--) {
        int x; cin>>x; 

        int ans=1; 
        for (int p=2; 1LL*p*p<=x; p++) {
            if (x%p==0) {
                int exp=0; 
                while (x%p==0){
                    x/=p; 
                    exp++; 
                }

                ans*=(exp+1); 
            }
        }
        if (x>1) ans*=2; 

        cout<<ans<<'\n'; 
    }
}