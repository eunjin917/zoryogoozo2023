#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pll = pair<int, int>;
int lgt, n, length, t, t2, lmt1, lmt2, l, r, m, v1, v2, i;
vector<pair<pll, pll>> line;
vector<int> lt(1, 0);
pll find_pos(int t){
    l = 0; r = n;
    while (l < r) {//binary_search and find t's line
        m = (l + r) >> 1;
        if (t >= lt[m]) l = m + 1;
        else r = m;
    }
    l--; t -= lt[l]; v1 = line[l].f.s - line[l].s.s; v2 = line[l].f.f - line[l].s.f;
    if (v1) return {line[l].f.f, line[l].f.s - t * abs(v1) / v1};
    else    return {line[l].f.f - t * abs(v2) / v2, line[l].f.s};
}
int main(){
    cin >> n; line.resize(n);
    for (i = 0; i < n; i++){//input line
        cin >> line[i].f.f >> line[i].f.s;
        line[(i + n - 1) % n].s = line[i].f;
    }
    for (i = 0; i < n; i++) {//line's length, prefix_sum
        length = abs(line[i].s.f - line[i].f.f) + abs(line[i].s.s - line[i].f.s); lgt += length;
        lt.emplace_back(lgt);
    }
    cin >> t; t %= lgt; t2 = (lgt - t + lt[n / 2 - 1]) % lgt;
    lmt1 = lt[n / 2 - 1] / 2; lmt2 = (lt[n / 2 - 1] + lgt) / 2;
    pll ans1, ans2; ans1 = find_pos(t); ans2 = find_pos(t2);
    if (lmt1 < t && t <= lmt2)  swap(ans1, ans2);
    cout << ans1.f << " " << ans1.s << "\n";
    cout << ans2.f << " " << ans2.s;
    return 0;
}
