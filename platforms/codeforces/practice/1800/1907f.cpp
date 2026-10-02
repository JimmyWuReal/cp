#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N; cin>>N; 

        vector<int> a(N);
        for (int &x : a) cin>>x;

        int s=0, b=0;
        int sp=-1, bp=-1;

        for (int i=0; i<N-1; i++) {
            if (a[i]>a[i+1]) {
                b++;
                bp=i;
            } 

            if (a[i]<a[i+1]) {
                s++;
                sp=i;
            }
        }

        int ans=INT_MAX;

        if (b==0) ans=0;

        if (s==0) ans=min(ans, 1);

        if (b==1 && a[N-1]<=a[0]) {
            ans=min(ans, N-bp-1);
            ans=min(ans, bp+3);
        }

        if (s==1 && a[N-1]>=a[0]) {
            ans=min(ans, N-sp);
            ans=min(ans, sp+2);
        }

        if (ans==INT_MAX)
            cout<<-1<<'\n';
        else
            cout<<ans<<'\n';
    }

    return 0;
}