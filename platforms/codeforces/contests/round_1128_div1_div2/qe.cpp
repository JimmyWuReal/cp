#include <bits/stdc++.h>
using namespace std;

using ll=long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;

    while (T--) {
        int N; ll K;
        cin>>N>>K;

        string mooRBS; cin>>mooRBS;

        int M=N/2;
        int LOG=1;

        while ((1<<LOG)<=M) LOG++;

        vector<vector<int>> up(LOG,vector<int>(M+1));
        vector<int> dep(M+1);
        vector<ll> dis(M+1),used(M+1);

        vector<int> st;
        st.push_back(0);

        int cnt=0;
        ll pre=0,ans=0;

        for (char c:mooRBS) {
            if (c=='(') {
                int u=++cnt;
                int p=st.back();

                dep[u]=dep[p]+1;
                dis[u]=dis[p]+used[p];

                up[0][u]=p;

                for (int j=1; j<LOG; j++) {
                    up[j][u]=up[j-1][up[j-1][u]];
                }

                if (dis[u]<=K) {
                    pre=max(pre,(ll)dep[u]);
                }

                ll need=dis[u]-K;
                int v=u;

                for (int j=LOG-1; j>=0; j--) {
                    int x=up[j][v];

                    if (x!=0 && dis[x]>=need) {
                        v=x;
                    }
                }

                ans=max(ans,(ll)dep[u]-dep[v]+1);

                st.push_back(u);
            }
            else {
                int u=st.back();
                st.pop_back();

                int p=st.back();

                used[p]+=cnt-u+1;
            }
        }

        ans=max(ans,min((ll)M,K+pre));

        cout<<ans<<'\n';
    }

    return 0;
}