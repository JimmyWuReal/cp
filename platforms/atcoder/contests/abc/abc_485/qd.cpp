#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin>>N; 
    string s; cin>>s; 

    int k=-1; 
    int mask=0; 
    
    for (int i=0; i<N; i++) {
        mask|=(1<<(s[i]-'A'));

        if (mask==7) {
            k=i+1;
            break;
        }
    }

    if (k==-1) {
        cout<<0<<'\n';
        return 0;
    }

    vector<bool> suffix(N+1, false);

    mask=0;

    for (int i=N-1; i>=0; i--) {
        mask|=(1<<(s[i]-'A'));
        suffix[i]=(mask==7);
    }

    vector<int> last(3, -1);
    long long res=0;

    for (int j=1; j<N; j++) {
        last[s[j-1]-'A']=j-1;

        if (!suffix[j]) continue;

        int limit=min({last[0], last[1], last[2]});

        if (limit>=k) res+=limit-k+1;
    }

    cout<<res<<'\n';
    return 0;
}
