#include <bits/stdc++.h>
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define tlk tuple<int, int, double, string>
#define pq priority_queue<tlk, vector<tlk>>
#define REP(i, a, b) for (int i = a; i < b; i++)
using namespace std;
map<string, pq> mp;
int main(){
    fastio
    int n, k, b, d; string name, genre, str, prior; double fsz;
    cin >> n >> k;
    REP(i, 0, n) {
        cin >> name >> genre >> b >> fsz >> d; fsz = 100000.0 - fsz;
        mp[genre].push({b, d, fsz, name});
    }
    prior = "";
    tlk value;
    REP(i, 0, k){
        str = "";
        value = {-1, -1, -1, ""};
        for (auto p: mp){
            if (!p.second.size() || p.first == prior)   continue;
            if (p.second.top() > value){
                value = p.second.top(); str = p.first;
            }
        }
        if (str == ""){
            mp[prior].pop();
        }
        else {
            mp[str].pop(); prior = str;
        }
    }
    auto [a, bk, c, dk] = value;
    cout << dk;
    return 0;
}
