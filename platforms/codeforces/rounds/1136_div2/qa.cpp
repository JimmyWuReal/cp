#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T; 

    while (T--) {
        int N; cin>>N; 

        int res=INT_MAX; 

        for (int end=1; end<=200; end++) {
            for (int start=0; start<end; start++) {
                if ((end+start+1)*(end-start)>=N*2) {
                    res=min(res, end-1+(end-start)); 
                }
            }
        }

        cout<<res<<'\n'; 
    }

    return 0;
}
