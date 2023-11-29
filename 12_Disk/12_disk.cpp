#include <bits/stdc++.h>
#define f first
#define ff f.f
#define s second
#define fs f.s
using namespace std;
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
using ll = long long;
using pll = pair<ll, ll>;
using plls = pair<pll, string>;
ll sz, siz, prior, cap;
string cmd, name;
map<pll, string> szmp;
int main() {
    fastio
    szmp.insert({{0, 0}, ""});
    cin >> sz;
    szmp.insert({{sz, sz}, ""});
    while (true){
        cin >> cmd;
        if (cmd == "compact"){
            vector<plls> vec(szmp.begin(), szmp.end()); szmp.clear();
            ll prior = 0; string pname = "qqq";
            szmp.insert({{0, 0}, ""});
            for (auto [a, b]: vec){
                if (a.s != a.f){
                    if (pname == b){
                        ll x = szmp.rbegin()->f.f;
                        szmp.erase(rbegin(szmp)->f);
                        szmp.insert({{x, prior + a.s - a.f}, b});
                    }
                    else    szmp.insert({{prior, prior + a.s - a.f}, b});
                }
                pname = b;
                prior += a.s - a.f;
            }
            szmp.insert({{sz, sz}, ""});
            continue;
        }
        else if (cmd == "end")   return 0;
        cin >> name;
        if (cmd == "show"){
            bool nud = true;
            for (auto x: szmp){
                if (x.s == name) {
                    nud = false;
                    cout << x.ff << " ";
                }
            }
            if (nud)    cout << "error";
            cout << "\n";
            continue;
        }
        else if (cmd == "delete"){
            vector<pll> vec;
            for (auto x: szmp){
                if (x.s == name){
                    vec.emplace_back(x.f);
                }
            }
            if (vec.empty())    cout << "error\n";
            else for (auto x: vec) {
                szmp.erase(x);
            }

            continue;
        }
        cin >> siz;
        prior = 0, cap = 0;
        for (auto x: szmp){
            if (x.ff - prior >= siz){
                 cap = -1; break;
            }
            cap += x.ff - prior; prior = x.fs;
        }
        if (cap == -1) {
            szmp.insert({{prior, prior + siz}, name});
        }
        else if (cap < siz)  cout << "diskfull\n";
        else{
            prior = 0;
            vector<plls> vec;
            for (auto x: szmp){
                if (!siz)   break;
                if (x.ff > prior){
                    ll p = min(x.ff - prior, siz);
                    siz -= p;
                    vec.push_back({{prior, prior + p}, name});
                }
                prior = x.fs;
            }
            for (plls x: vec)   szmp.insert({x.f, x.s});
        }
    }
}