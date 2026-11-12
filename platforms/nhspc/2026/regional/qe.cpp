#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, R; cin>>N>>R;
    vector<int> a(N); 
    for (int &x : a) cin>>x; 

    long long l=0, r=1e8; 

    while (r!=l+1) {
        long long mid=(r+l)/2; 

        long long cur=mid; 

        bool pos=false; 

        for (int i=0; i<N; i++) {
            cur=cur+(cur+R-1)/R; 
            cur-=a[i]; 

            if (cur<=0) {
                pos=true; 
                break; 
            } 

            if (cur>1e8) break; // 避免因為 R 過小而大幅度的增加
        }

        if (pos) {
            l=mid; 
        } else {
            r=mid; 
        }
    }

    cout<<l<<'\n'; 

    return 0;
}