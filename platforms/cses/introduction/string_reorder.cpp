#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin>>S; 

    int N=S.size(); 

    vector<int> cnt(26, 0); 

    for (char c : S) cnt[c-'A']++; 

    if (*max_element(cnt.begin(), cnt.end())>(N+1)/2) {
        cout<<-1<<'\n';
        return 0; 
    }

    string ans; 
    int prev=-1; 

    for (int pos=0; pos<N; pos++) {
        int mx1=0, mx2=0, idx=-1; 

        for (int i=0; i<26; i++) {
            if (cnt[i]>mx1) {
                mx2=mx1; 
                mx1=cnt[i]; 
                idx=i; 
            } else {
                mx2=max(mx2, cnt[i]); 
            }
        }

        int m=N-pos-1; 
        bool found=false; 

        for (int c=0; c<26; c++) {
            if (cnt[c]==0 || c==prev) continue; 

            int otherMax=(c==idx ? mx2 : mx1); 

            if (cnt[c]-1<=m/2 && otherMax<=(m+1)/2) {
                ans+=char('A'+c); 
                cnt[c]--; 
                prev=c; 
                found=true; 
                break; 
            }
        }

        if (!found) {
            cout<<-1<<'\n';
            return 0; 
        }
    }

    cout<<ans<<'\n'; 

    return 0;
}