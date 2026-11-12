#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, double> g; 

    g["Mercury"]=0.39; 
    g["Venus"]=0.90; 
    g["Earth"]=1.00; 
    g["Mars"]=0.39; 
    g["Jupiter"]=2.53; 
    g["Saturn"]=1.07; 
    g["Uranus"]=0.89; 
    g["Neptune"]=1.14; 

    vector<pair<double, pair<string, string>>> a; 

    double m=0; 

    for (int i=0; i<8; i++) {
        string name, planet;
        double weight; 
        
        cin>>name>>weight>>planet; 

        double mass=weight/g[planet]; 
        mass=round(mass*100)/100; // 取小數點後兩位

        m=max(m, mass); 

        a.push_back({mass, {name, planet}}); 
    }

    cout << fixed << setprecision(2); // 確定輸出會有兩位

    for (int i=0; i<8; i++) {
        if (a[i].first==m) {
            cout<<a[i].second.first<<' '<<a[i].second.second<<' '<<a[i].first<<'\n'; 
        }
    }

    return 0;
}