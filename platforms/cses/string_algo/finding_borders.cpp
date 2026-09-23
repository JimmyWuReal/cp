#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int N = S.size();

    vector<int> pi(N);

    for (int i = 1; i < N; i++) {
        int j = pi[i - 1];

        while (j > 0 && S[i] != S[j])
            j = pi[j - 1];

        if (S[i] == S[j])
            j++;

        pi[i] = j;
    }

    vector<int> ans;

    int k = pi[N - 1];

    while (k > 0) {
        ans.push_back(k);
        k = pi[k - 1];
    }

    reverse(ans.begin(), ans.end());

    for (int x : ans)
        cout << x << ' ';

    return 0;
}