#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, k; 
    cin >> h >> w >> k; 

    vector<string> s(h); 

    for (auto &str : s) cin >> str; 

    // swap if h > w
    if (h > w) {
        vector<string> t(w, string(h, '0')); 
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                t[j][i] = s[i][j]; 
            }
        }

        swap(h, w); 
        s = t;
    }

    long long ans= 0 ; 
    vector<int> col(w); 

    for (int top = 0; top < h; top++) {
        fill(col.begin(), col.end(), 0); 

        for (int bottom = top; bottom < h; bottom++) {
            for (int c = 0; c < w; c++) col[c] += s[bottom][c] - '0';

            unordered_map<int, int> cnt; 
            cnt.reserve(w * 2 + 5); 
            cnt[0] = 1; 

            int pre = 0; 
            for (int c = 0; c < w; c++) {
                pre += col[c]; 
                if (cnt.count(pre - k)) ans += cnt[pre - k];
                cnt[pre]++; 
            } 
        }
    }

    cout << ans << endl; 

    return 0;
}