#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum;
    Node* left;
    Node* right;

    Node(long long sum = 0, Node* left = nullptr, Node* right = nullptr)
        : sum(sum), left(left), right(right) {}
};

Node* update(Node* node, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        return new Node(val, nullptr, nullptr);
    }

    int tm = (tl + tr) >> 1;
    Node* left = node ? node->left : nullptr;
    Node* right = node ? node->right : nullptr;

    if (pos <= tm) {
        left = update(left, tl, tm, pos, val);
    } else {
        right = update(right, tm + 1, tr, pos, val);
    }

    long long sum = (left ? left->sum : 0LL) + (right ? right->sum : 0LL);
    return new Node(sum, left, right);
}

long long query(Node* node, int tl, int tr, int l, int r) {
    if (!node || r < tl || tr < l) {
        return 0;
    }
    if (l <= tl && tr <= r) {
        return node->sum;
    }

    int tm = (tl + tr) >> 1;
    return query(node->left, tl, tm, l, r) +
           query(node->right, tm + 1, tr, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<Node*> roots(n, nullptr);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y;
            cin >> x >> y;
            roots[x - 1] = roots[y - 1];
        } else if (type == 2) {
            int x, y, z;
            cin >> x >> y >> z;
            roots[x - 1] = update(roots[x - 1], 1, m, y, z);
        } else {
            int x, l, r;
            cin >> x >> l >> r;
            cout << query(roots[x - 1], 1, m, l, r) << '\n';
        }
    }

    return 0;
}
