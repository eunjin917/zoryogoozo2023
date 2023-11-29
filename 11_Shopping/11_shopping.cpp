#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
using ll = long long;
using pll = pair<ll, ll>;
ll n, k;
struct custom{
    ll num, time, idx;
    custom(ll num, ll time, ll idx): num(num), time(time), idx(idx) {}
    bool operator>(custom b){
        return (time == b.time) ? (idx < b.idx) : (time > b.time);
    }
};
priority_queue<custom, vector<custom>, greater<>> pq;
int main() {
    fastio
    cin >> n >> k;
    vector<pll> vecq;
    for (ll i = 1; i <= n; i++){
        ll rn, w; cin >> rn >> w; vecq.emplace_back(rn, w);
    }
    ll x = min(n, k);
    for (ll i = 0; i < x; i++){
        if (i >= n) break;
        pq.push({vecq[i].f, vecq[i].s, i + 1});
    }
    ll idx = x, cnt = 1;
    while (cnt <= n){
        custom x = pq.top(); pq.pop(); vector<custom> vec = {x};
        while (!pq.empty() && x.time == pq.top().time){
            vec.emplace_back(pq.top()); pq.pop();
        }
        for (auto [id, time, pos]: vec){
            cout << id << "\n"; cnt++;
        }
        for (auto it = rbegin(vec); it != rend(vec); it++){
            if (idx == n)   break;
            auto [id, time, pos] = *it;
            pq.push({vecq[idx].f, time + vecq[idx].s, pos}); idx++;
        }
    }
    return 0;
}
