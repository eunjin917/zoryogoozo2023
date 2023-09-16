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
        line[(i + n - 1) % n].s = {px, py};//i번째 직선의 시작점과 끝점을 저장
    }
    lt.emplace_back(0);
    for (ll i = 0; i < n; i++) {//line's length, prefix_sum
        ll l = abs(line[i].s.f - line[i].f.f) + abs(line[i].s.s - line[i].f.s); lgt += l;//line의 끝점마다 이때까지 line의 길이의 총합을 저장.
        lt.emplace_back(lt.back() + l);
    }
    for (ll i = 0; i < 5; i++) {
        ll t; cin >> t; t %= lgt;//시간이 t일 때 도달하는 위치와 동일.
        ll l, r; l = 0; r = n;
        while (l < r) {//이분 탐색을 이용해서 어떤 라인에 있는지 탐색.
            ll m = (l + r) >> 1;
            if (t >= lt[m]) l = m + 1;
            else r = m;
        }
        l--;
        t -= lt[l]; ll v1, v2; v1 = line[l].f.s - line[l].s.s; v2 = line[l].f.f - line[l].s.f; //직선에서 얼마나 이동할 수 있는 지 구함.
        //직선이 y축에 평행한 지, x축에 평행한 지 확인.
        if (v1) cout << line[l].f.f << " " << line[l].f.s - t * abs(v1) / v1;
        else    cout << line[l].f.f - t * abs(v2) / v2 << " " << line[l].f.s;
        cout << "\n";
    }
    return 0;
}
