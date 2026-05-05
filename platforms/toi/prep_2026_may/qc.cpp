#include <bits/stdc++.h>
using namespace std;

struct mxNdKp {
    int sz, blkSz, nBlks;
    vector<long long> dta;
    vector<vector<long long>> grps;

    mxNdKp() {}

    mxNdKp(const vector<long long>& w) {
        setup(w);
    }

    void setup(const vector<long long>& w) {
        dta = w;
        sz = (int)w.size();
        blkSz = max(1, (int)sqrt(sz) + 1);
        nBlks = (sz + blkSz - 1) / blkSz;
        grps.assign(nBlks, {});
        for (int j = 0; j < sz; j++) grps[j / blkSz].push_back(dta[j]);
        for (auto& v : grps) sort(v.begin(), v.end());
    }

    void modify(int p, long long d) {
        int bg = p / blkSz;

        auto& vv = grps[bg];
        auto kt = lower_bound(vv.begin(), vv.end(), dta[p]);
        vv.erase(kt);

        dta[p] += d;

        vv.insert(lower_bound(vv.begin(), vv.end(), dta[p]), dta[p]);
    }

    long long sumRng(int l, int r) {
        long long tot = 0;
        for (int i = l; i <= r; i++) tot += dta[i];
        return tot;
    }

    int cntGrtr(int l, int r, long long x) {
        int cnt = 0;
        int sblk = l / blkSz;
        int eblk = r / blkSz;

        if (sblk == eblk) {
            for (int i = l; i <= r; i++) if (dta[i] > x) cnt++;
            return cnt;
        }

        int endL = min(sz - 1, (sblk + 1) * blkSz - 1);
        for (int i = l; i <= endL; i++) if (dta[i] > x) cnt++;

        for (int bg = sblk + 1; bg <= eblk - 1; bg++) {
            auto& vv = grps[bg];
            auto kt = upper_bound(vv.begin(), vv.end(), x);
            cnt += (int)(vv.end() - kt);
        }

        int strtR = eblk * blkSz;
        for (int i = strtR; i <= r; i++) if (dta[i] > x) cnt++;

        return cnt;
    }
};


struct qzFtwk {
    int sz;
    vector<long long> t;

    qzFtwk() {}

    qzFtwk(const vector<long long>& a) {
        setup(a);
    }

    void setup(const vector<long long>& a) {
        sz = (int)a.size();
        t.assign(sz + 1, 0);
        for (int i = 0; i < sz; i++) incr(i, a[i]);
    }

    void incr(int p, long long v) {
        p++;
        while (p <= sz) {
            t[p] += v;
            p += p & -p;
        }
    }

    long long prxSum(int p) {
        p++;
        long long res = 0;
        while (p > 0) {
            res += t[p];
            p -= p & -p;
        }
        return res;
    }

    long long sumRng(int l, int r) {
        if (l > r) return 0;
        return prxSum(r) - (l == 0 ? 0 : prxSum(l - 1));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        y[i] = 500 - x[i];
    }

    mxNdKp sx(x), sy(y);
    qzFtwk fx(x), fy(y);

    while (q--) {
        int typ;
        cin >> typ;

        if (typ == 1) {
            int k;
            long long p;
            char c;
            cin >> k >> p >> c;
            k--;

            if (c == 'A') {
                sx.modify(k, p);
                fx.incr(k, p);
            } else {
                sy.modify(k, p);
                fy.incr(k, p);
            }
        } else {
            int l, r;
            char c;
            cin >> l >> r >> c;
            l--, r--;

            long long sm;
            int ln = r - l + 1;

            if (c == 'A') {
                sm = fx.sumRng(l, r);
                long long av = sm / ln;
                cout << sx.cntGrtr(l, r, av) << '\n';
            } else {
                sm = fy.sumRng(l, r);
                long long av = sm / ln;
                cout << sy.cntGrtr(l, r, av) << '\n';
            }
        }
    }

    return 0;
}