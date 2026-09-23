#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string T, P; cin>>T>>P; 

    string s=P+'#'+T; 
    vector<int> pi(s.size());

    for (int i=1; i<(int)s.size(); i++) {
        int j=pi[i-1];

        while (j>0 && s[i]!=s[j]) {
            j=pi[j-1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i]=j;
    }

    int ans=0;
    int m=P.size();

    for (int i=m+1; i<(int)s.size(); i++) {
        if (pi[i]==m) {
            ans++;
        }
    }

    cout<<ans<<'\n';
}