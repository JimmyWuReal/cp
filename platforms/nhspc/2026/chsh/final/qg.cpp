#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n, m; 
    cin >> a >> b >> n >> m; 

    vector<int> res(n + m + 1, 0); 

    int fd, sd; 
    fd = (a * b) / 10; 
    sd = (a * b) % 10; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i + j] += sd; 
            res[i + j + 1] += fd; 
        }
    }

    for (int i = 0; i < n + m + 1; i++) {
        if (res[i] >= 10) {
            res[i + 1] += res[i] / 10;  
            res[i] = res[i] % 10; 
        }
    }

    bool started = false; 

    for (int i = n + m; i >= 0; i--) {
        if (res[i] != 0 && !started) started = true; 

        if (started) cout << res[i]; 
    }

    cout << endl; 

    return 0;
}