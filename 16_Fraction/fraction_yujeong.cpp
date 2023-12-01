#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}

pair<ll, ll> cal(vector<pair<ll, ll>> arr) {
    pair<ll, ll> res1 = arr[0];
    pair<ll, ll> res2 = {
        arr[1].first * arr[2].second,
        arr[1].second * arr[2].first
    };

    pair<ll, ll> ret = {
        res1.first * res2.second + res1.second * res2.first,
        res1.second * res2.second
    };

    ll g = gcd(ret.first, ret.second);
    ret.first /= g;
    ret.second /= g;

    return ret;
}

int main() {
    int n;
    cin >> n;

    vector<vector<pair<ll, ll>>> fraction(1);
    
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        
        if ('1' <= c && c <= '9') {
            fraction.back().push_back({ c - '0', 1 });
        } else if (c == '(') {
            vector<pair<ll, ll>> du;
            fraction.push_back(du);
        } else if (c == ')') {
            if ((int)(fraction.back()).size() == 3) {
                pair<ll, ll> val = cal(fraction.back());
                fraction.pop_back();
                fraction.back().push_back(val);
            } else {
                cout << -1;
                return 0;
            }
        }
    }
    
    if ((int)(fraction).size() == 1 && (int)(fraction.back()).size() == 1)
        cout << fraction.back()[0].first << ' ' << fraction.back()[0].second;
    else cout << -1;
}
