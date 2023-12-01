#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dist[3][26], st[3];
vector<ll> edge[26];
ll n, m, k;
void bfs(ll v, ll pos){
    dist[v][pos] = 0;
    queue<ll> q; q.push(pos);
    while (!q.empty()){
        ll px = q.front(); q.pop();
        for (ll nxt: edge[px]){
            if (dist[v][nxt] == -1){
                dist[v][nxt] = dist[v][px] + 3;
                q.push(nxt);
            }
        }
        if (dist[v][px]) dist[v][px] -= 2;
    }
}
int main() {
    memset(dist, -1, sizeof(dist));
    cin >> n;
    for (ll i = 0; i < 3; i++)  {
        char c; cin >> c; st[i] = c - 97;
    }
    for (ll i = 0; i < n; i++){
        char s; cin >> s; ll p = s - 97;
        while (cin >> s && s != '$'){
            edge[s - 97].emplace_back(p);
            edge[p].emplace_back(s - 97);
        }
    }
    for (ll i = 0; i < 3; i++)  bfs(i, st[i]);
    ll ans = 1e9;
    ll pos = -1;
    for (ll i = 0; i < 26; i++){
        ll cand = 0;
        for (ll j = 0; j < 3; j++){
            if (dist[j][i] == -1)   {
                cand = 1e11; break;
            }
            cand = max(cand, dist[j][i]);
        }
        if (ans > cand){
            pos = i; ans = cand;
        }
    }
    if (pos == -1){
        cout << "@\n-1";
    }
    else{
        cout << (char)('a' + pos) << "\n" << ans;
    }

}
