#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;

    while (T--) {
        int N, Q; cin>>N>>Q;
        string S; cin>>S;

        long long A=0;

        for (int i=0; i+1<N; i++) {
            if (S[i]!=S[i+1]) {
                long long pos=i+1;
                A+=pos*(N-pos);
            }
        }

        long long cnt[2]={0, 0};

        for (int i=0; i<N; i++) {
            cnt[S[i]-'0']++;
        }

        auto answer=[&]() -> long long {
            long long B=cnt[0]*cnt[1];
            return (A+B)/2;
        };

        cout<<answer();

        while (Q--) {
            int x; cin>>x;
            --x;

            int d=S[x]-'0';
            cnt[d]--;
            cnt[d^1]++;

            if (x>0) {
                long long pos=x;
                long long w=pos*(N-pos);

                if (S[x-1]!=S[x])
                    A-=w;
                else
                    A+=w;
            }

            if (x+1<N) {
                long long pos=x+1;
                long long w=pos*(N-pos);

                if (S[x]!=S[x+1])
                    A-=w;
                else
                    A+=w;
            }

            S[x]=(S[x]=='0'?'1':'0');

            cout<<' '<<answer();
        }
        cout<<'\n';
    }

    return 0;
}