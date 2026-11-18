#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin>>N>>M; 
    vector<int> a(N, -1);

    vector<vector<int>> f(N); 
    
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        a--; b--; 

        f[a].push_back(b); 
        f[b].push_back(a); 
    }

    for (int i=0; i<N; i++) {
        if (a[i]==-1) {
            queue<int> q; 
            int cur=0; 

            q.push(i); 
            a[i]=cur; 

            while (!q.empty()) { 
                queue<int> temp; 
                cur=(cur+1)%2; 

                while (!q.empty()) { 
                    int c=q.front(); 
                    q.pop(); 

                    for (int x : f[c]) {
                        if (a[x]==(cur+1)%2) {
                            cout<<"IMPOSSIBLE\n"; 
                            return 0; 
                        }

                        if (a[x]==-1) {
                            a[x]=cur; 
                            temp.push(x); 
                        }
                    }
                }

                q=temp; 
            }
        } 
    }

    for (int x : a) {
        cout<<x+1<<' '; 
    }

    return 0;
}