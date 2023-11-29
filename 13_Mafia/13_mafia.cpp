#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
using ll = long long;
using pll = pair<ll, ll>;
struct people{
    ll pl, depth; string name;
    people(): pl(0), depth(0), name("") {}
    people(ll pl, string name, ll depth): pl(pl), depth(depth), name(name) {}
    bool operator>(people b){
        if (pl == b.pl){
            if (depth == b.depth)   return name < b.name;
            return depth < b.depth;
        }
        return pl > b.pl;
    }
};
ll n;
string name, boss;
vector<people> vec;
map<string, vector<string>> mp;
set<string> st;
ll dfs(string boss, ll depth){
    ll sum = 0;
    for (string serve: mp[boss]){
        sum += dfs(serve, depth + 1);
    }
    vec.emplace_back(sum, boss, depth);
    return 1 + sum;
}
int main() {
    fastio
    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> name >> boss; mp[boss].emplace_back(name); st.insert(name);
    }
    for (auto it = begin(mp); it != end(mp); it++){
        if (st.find(it->f) == st.end()) {
            dfs(it->f, 0);
        }
    }
    sort(begin(vec), end(vec), [](people a, people b){
        return a > b;
    });
    for (auto x: vec){
        cout << x.name << "\n";
    }
}