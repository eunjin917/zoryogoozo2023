#include <bits/stdc++.h>
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define f first
#define s second
using namespace std;
int main(){
    fastio
    stack<int> st[21];
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int j = 0; j < x; j++){
            int value; cin >> value; st[i].push(value);
        }
    }
    while (true){
        //f: height, s: weight
        int mx, mn; mx = 0; mn = 0;
        for (int i = 1; i < n; i++){
            if (st[i].size() < st[mn].size())   mn = i;
            if (st[i].size() > st[mx].size())   mx = i;
        }
        if (st[mx].size() - st[mn].size() <= 1)   break;
        int mxnum, mnnum; mxnum = 0; mnnum = 0;
        for (int i = 1; i < n; i++){
            if (st[mxnum].empty()) mxnum = i;
            else if (st[i].empty())  continue;
            else if (st[mxnum].size() < st[i].size() || (st[mxnum].size() == st[i].size() && st[mxnum].top() < st[i].top())){
                mxnum = i;
            }
        }
        for (int i = 0; i < n; i++){
            if (st[mnnum].size() > st[i].size()){
                mnnum = i;
            }
        }
        int v = st[mxnum].top(); st[mnnum].push(v); st[mxnum].pop();
    }
    for (int i = 0; i < n; i++){
        vector<int> ans;
        while (!st[i].empty()){
            ans.emplace_back(st[i].top()); st[i].pop();
        }
        if (ans.empty()){
            cout << "0" << endl;
        }
        for (auto i = ans.rbegin(); i != ans.rend(); i++){
            cout << *i << " ";
        }
        cout << "\n";
    }
    return 0;
}
