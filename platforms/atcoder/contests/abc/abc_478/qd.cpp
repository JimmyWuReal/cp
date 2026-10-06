#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r;
    long long x;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin>>N>>Q; 
    vector<Query> q(Q); 

    for (auto &a : q) {
        cin>>a.l>>a.r>>a.x; 
    }

    sort(q.begin(), q.end(), [](Query a, Query b) {
        if (a.x!=b.x) return a.x<b.x; 
        if (a.l!=b.l) return a.l<b.l; 
        return a.r<b.r; 
    });

    vector<int> diff(N+2, 0); 

    int i=0; 

    while (i<Q) {
        int j=i; 

        while (j<Q && q[j].x==q[i].x) {
            j++; 
        }

        int l=q[i].l; 
        int r=q[i].r; 

        for (int k=i+1; k<j; k++) {
            if (q[k].l<=r+1) {
                r=max(r, q[k].r); 
            } else {
                diff[l]++; 
                diff[r+1]--; 

                l=q[k].l; 
                r=q[k].r; 
            }
        }

        diff[l]++; 
        diff[r+1]--; 

        i=j; 
    }

    int cnt=0; 

    for (int i=1; i<=N; i++) {
        cnt+=diff[i]; 
        cout<<cnt<<"\n"; 
    }

    return 0;
}