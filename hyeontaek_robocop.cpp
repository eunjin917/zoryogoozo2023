#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
ll lgt;
int main(){
    ll n; cin >> n;
    vector<pair<pll, pll>> line(n, {{0, 0}, {0, 0}});//save line
    vector<ll> lt;
    for (ll i = 0; i < n; i++){//input line
        ll px, py; cin >> px >> py;
        line[i].f = {px, py};
        line[(i + n - 1) % n].s = {px, py};
    }
    lt.emplace_back(0);
    for (ll i = 0; i < n; i++) {//line's length, prefix_sum
        ll l = abs(line[i].s.f - line[i].f.f) + abs(line[i].s.s - line[i].f.s); lgt += l;
        lt.emplace_back(lt.back() + l);
    }
    for (ll i = 0; i < 5; i++) {
        ll t; cin >> t; t %= lgt;
        ll l, r; l = 0; r = n;
        while (l < r) {//binary_search and find t's line
            ll m = (l + r) >> 1;
            if (t >= lt[m]) l = m + 1;
            else r = m;
        }
        l--;
        t -= lt[l]; ll v1, v2; v1 = line[l].f.s - line[l].s.s; v2 = line[l].f.f - line[l].s.f;
        if (v1) cout << line[l].f.f << " " << line[l].f.s - t * abs(v1) / v1;
        else    cout << line[l].f.f - t * abs(v2) / v2 << " " << line[l].f.s;
        cout << "\n";
    }
    return 0;
}
