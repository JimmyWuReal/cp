#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 
    vector<vector<int>> r(N); 
    
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        a--; b--; 
        r[a].push_back(b); 
        r[b].push_back(a); 
    }

    int cnt=0; 
    vector<bool> seen(N, false); 
    vector<int> last(N, -1); 
    queue<int> q; 

    q.push(0); 
    
    while (!q.empty()) {
        queue<int> temp; 
        cnt++; 

        while (!q.empty()) {
            int cur=q.front(); 
            q.pop(); 
    
            if (cur==N-1) {
                vector<int> res; 
                while (cur!=0) {
                    res.push_back(cur+1); 
                    cur=last[cur]; 
                }
                res.push_back(1); 

                reverse(res.begin(), res.end()); 

                cout<<cnt<<'\n'; 
                for (int x : res) cout<<x<<' '; 
                cout<<'\n'; 

                return 0; 
            }
    
            for (int x : r[cur]) {
                if (!seen[x]) {
                    seen[x]=true; 
                    last[x]=cur; 
                    temp.push(x); 
                }
            }
        }

        q=temp; 
    }

    cout<<"IMPOSSIBLE\n"; 

    return 0;
}