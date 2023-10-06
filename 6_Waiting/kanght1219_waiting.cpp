#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    map<int, set<int>> mp;
    for (int i = 0; i < n; i++){
        string name; int p; cin >> name >> p;
        if (name == "+"){
            if (mp.empty()){
                mp[p].insert(p);
            }
            else{
                auto x = mp.lower_bound(p);
                if (x != mp.begin())  x--;
                int pos = x->first;
                if (pos > p){
                    mp[p] = x->second; mp[p].insert(p);
                    mp.erase(pos); pos = p;
                }
                else{
                    mp[pos].insert(p);
                }
                if (mp[pos].size() == 2 * k){
                    int idx = 0; int lmt = 0;
                    for (auto it = mp[pos].begin(); it != mp[pos].end(); it++){
                        if (idx == k){
                            mp[*it].insert(*it); lmt = *it;
                        }
                        else if (idx > k){
                            mp[lmt].insert(*it);
                        }
                        idx++;
                    }
                    for (auto it : mp[lmt]){
                        mp[pos].erase(it);
                    }
                }
            }
        }
        else{
            auto x = mp.lower_bound(p);
            if (x->first != p && x != mp.begin())  x--;
            mp[x->first].erase(p);
            if (!mp[x->first].size())   mp.erase(x->first);
            if (x->first == p) {
                int v = *mp[x->first].begin();
                for (auto it: mp[x->first]){
                    mp[v].insert(it);
                }
                mp.erase(x->first);
            }
        }
    }
    for (auto [a, b]: mp){
        cout << a << "\n";
    }
    return 0;
}
