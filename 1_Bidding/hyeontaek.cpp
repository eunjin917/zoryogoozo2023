#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;
using pls = pair<ll, string>;
ll p[10001];//p의 값 <= 10000
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); //fastio
    ll n; cin >> n;
    vector<pls> vec;
    while (n--){
        string name; ll price;
        cin >> name >> price;
        p[price]++; vec.emplace_back(price, name);
    }
    sort(vec.begin(), vec.end(), [](pls a, pls b){
        return a.first > b.first;
    });//lambda function, sorted by price, decreased
    for (auto [price, name]: vec){
        if (p[price] == 1){//if price is unique, output answer end exit
            cout << name; return 0;
        }
    }
    cout << "NONE";
    return 0;
}
