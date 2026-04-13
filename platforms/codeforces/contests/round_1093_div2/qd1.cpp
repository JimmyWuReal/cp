#include <bits/stdc++.h>
using namespace std;

static int m;
static vector<int> ans;

// this is really hard, hope do well. 
// pls. 

int ask(const vector<int>& v) {
    cout << "? " << v.size();
    for (int x : v) cout << ' ' << x;
    cout << endl;
    cout.flush();

    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

int ask_seg(int l, int r) {
    vector<int> v;
    v.reserve(r - l + 1);
    for (int i = l; i <= r; ++i) v.push_back(i);
    return ask(v);
}

int ask_out(int l, int r) {
    vector<int> v;
    v.reserve(m - (r - l + 1));
    for (int i = 1; i < l; ++i) v.push_back(i);
    for (int i = r + 1; i <= m; ++i) v.push_back(i);
    return ask(v);
}

int cnt(int l, int r) {
    int len = r - l + 1;
    int a = ask_seg(l, r);

    if (((len - a) & 1) != 0) return 3;

    int b = ask_out(l, r);
    int d = a - b;

    if (d == 1) return 1;
    if (d == -1) return 2;
    return 0;
}

void solve(int l, int r, int need) {
    if (need == 0) return;
    if (l == r) {
        ans.push_back(l);
        return;
    }

    int md = (l + r) >> 1;
    int lc = cnt(l, md);
    int rc = need - lc;

    solve(l, md, lc);
    solve(md + 1, r, rc);
}

// main func 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // test cases 
    while (t--) {
        int n;
        cin >> n;
        m = 2 * n + 1;

        ans.clear();
        solve(1, m, 3);

        cout << "! ";
        for (int i = 0; i < 3; ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}
