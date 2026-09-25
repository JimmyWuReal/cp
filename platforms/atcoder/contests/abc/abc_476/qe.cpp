#include <bits/stdc++.h>
using namespace std;

struct Node {
    int mn, mnIdx;
    int mx, mxIdx;
};

class SegTree {
    int n;
    vector<Node> tree;

    Node mergeNode(const Node& a, const Node& b) {
        Node res;

        if (a.mn<=b.mn) {
            res.mn=a.mn;
            res.mnIdx=a.mnIdx;
        } else {
            res.mn=b.mn;
            res.mnIdx=b.mnIdx;
        }

        if (a.mx>=b.mx) {
            res.mx=a.mx;
            res.mxIdx=a.mxIdx;
        } else {
            res.mx=b.mx;
            res.mxIdx=b.mxIdx;
        }

        return res;
    }

    void build(int node, int l, int r, const vector<int>& p) {
        if (l==r) {
            tree[node]={p[l], l, p[l], l};
            return;
        }

        int mid=(l+r)/2;

        build(node*2, l, mid, p);
        build(node*2+1, mid+1, r, p);

        tree[node]=mergeNode(tree[node*2],
                               tree[node*2+1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l==r) {
            tree[node]={val, idx, val, idx};
            return;
        }

        int mid=(l+r)/2;

        if (idx<=mid)
            update(node*2, l, mid, idx, val);
        else
            update(node*2+1, mid+1, r, idx, val);

        tree[node]=mergeNode(tree[node*2], tree[node*2+1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql<=l && r<=qr) return tree[node];

        int mid=(l+r)/2;

        if (qr<=mid) return query(node*2, l, mid, ql, qr);

        if (ql>mid) return query(node*2+1, mid+1, r, ql, qr);

        Node left=query(node*2, l, mid, ql, qr);
        Node right=query(node*2+1, mid+1, r, ql, qr);

        return mergeNode(left, right);
    }

public:
    SegTree(const vector<int>& p) {
        n=p.size();
        tree.resize(4*n);
        build(1, 0, n-1, p);
    }

    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin>>N>>M;

    vector<int> p(N);

    for (int& x : p) cin>>x;

    SegTree seg(p);

    while (M--) {
        int l, r;
        cin>>l>>r;

        l++; r++;

        Node cur=seg.query(l, r);

        int minp=cur.mnIdx;
        int maxp=cur.mxIdx;

        swap(p[minp], p[maxp]);

        seg.update(minp, p[minp]);

        if (minp!=maxp) seg.update(maxp, p[maxp]);
    }

    for (int x : p) cout<<x<<' ';

    cout<<'\n';

    return 0;
}