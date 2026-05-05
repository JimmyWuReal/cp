#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    bool multiple = false;

    while (!q.empty()) {
        if (q.size() >= 2) {
            multiple = true;
            break;
        }

        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            indegree[nxt]--;

            if (indegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    cout << (multiple ? 1 : 0) << '\n';

    return 0;
}