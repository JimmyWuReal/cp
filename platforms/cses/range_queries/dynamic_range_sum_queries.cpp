#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

vector<ll> a, tree; 

void build(int node, int l, int r) {
    if (l==r) {
        tree[node]=a[l];
        return; 
    }

    int mid=(l+r)/2; 

    build(node*2, l, mid); 
    build(node*2+1, mid+1, r); 

    tree[node]=tree[node*2]+tree[node*2+1]; 
}

void update(int node, int l, int r, int idx, ll val) {
    if (l==r) {
        tree[node]=val; 
        return; 
    }

    int mid=(l+r)/2; 

    if (mid>=idx) {
        update(node*2, l, mid, idx, val); 
    } else {
        update(node*2+1, mid+1, r, idx, val); 
    }

    tree[node]=tree[node*2]+tree[node*2+1]; 
}

ll query(int node, int l, int r, int ql, int qr) {
    if (r<ql || l>qr) return 0; 
    if (l>=ql && r<=qr) return tree[node]; 

    int mid=(l+r)/2; 

    ll ls=query(node*2, l, mid, ql, qr); 
    ll rs=query(node*2+1, mid+1, r, ql, qr); 

    return ls+rs; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin>>N>>Q; 

    a.resize(N+1); 
    tree.resize(4*N+5); 

    for (int i=0; i<N; i++) cin>>a[i+1]; 

    build(1, 1, N); 

    while (Q--) {
        int type; cin>>type; 

        if (type==1) {
            int k;
            ll u; 
            cin>>k>>u; 

            update(1, 1, N, k, u); 
        } else {
            int l, r; 
            cin>>l>>r; 

            cout<<query(1, 1, N, l, r)<<'\n'; 
        }
    }

    return 0; 
}