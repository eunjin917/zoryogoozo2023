#include <bits/stdc++.h>
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define f first
#define s second
using namespace std;
using pll = pair<int, int>;
vector<pll> price;
stack<pll> st;
int n, k;
bool ans = false;
int sum = 0;
void point(int idx){
    if (sum > k)    return;
    else if (sum == k){
        ans = true; return;
    }
    if (idx == n) return;
    st.push(price[idx]); sum += price[idx].second;
    point(idx + 1);
    if (ans)    return;
    st.pop();
    sum -= price[idx].second;
    point(idx + 1);
    if (ans)    return;
}
int main(){
    fastio
    cin >> n >> k; price.resize(n);
    for (int i = 0; i < n; i++){
        cin >> price[i].s; price[i].f = i;
    }
    sort(begin(price), end(price), [](pll a, pll b){
        return a.s > b.s;
    });
    point(0);
    if (ans){
        while (!st.empty()){
            cout << st.top().s << "\n"; st.pop();
        }
    }
    else{
        cout << 0;
    }
    return 0;
}
