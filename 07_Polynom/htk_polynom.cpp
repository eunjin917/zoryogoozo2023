#include <bits/stdc++.h>
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define REI(i, x) for (auto i: x)
#define REP(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
map<int, int, greater<>> mp;
int main(){
    fastio
    int f; cin >> f;
    while (f--){
        int n; cin >> n;
        while (n--){
            int a, b; cin >> a >> b;
            if (mp.find(b) != mp.end()) mp[b] += a;
            else mp[b] = a;
        }
    }
    vector<pair<int, int>> vec;
    for (auto [a, b]: mp){
        if (b)  vec.emplace_back(b, a);
    }
    if (vec.empty())    cout << "0 0";
    else{
        cout << vec.size() << "\n";
        for (auto [a, b]: vec){
            cout << a << " " << b << "\n";
        }
    }
}