#include <bits/stdc++.h>
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define f first
#define s second
using namespace std;
unordered_map<string, vector<string>> func;
set<string> check;
bool deadlock = false;
vector<pair<string, string>> ans;
void function_X(string name){
    if (deadlock)   return;
    if (check.find(name) != check.end()){
        deadlock = true;
        return;
    }
    check.insert(name);
    for (auto i: func[name]){
        if (func.find(i) != func.end()) function_X(i);
        else    ans.emplace_back(name, i);
    }
    check.erase(name);
}
int main(){
    fastio
    int n, a, b; cin >> n >> a >> b;
    for (int i = 0; i < n; i++){
        string name_func, cmd; cin >> name_func;
        while (true){
            cin >> cmd;
            if (cmd == "$") break;
            func[name_func].emplace_back(cmd);
        }
    }
    function_X("M");
    if (deadlock){
        cout << "DEADLOCK";
        return 0;
    }
    if (a < 0)  a += ans.size() + 1;
    if (b < 0)  b += ans.size() + 1;
    if (a > ans.size() || a < 0)   cout << "NONE\n";
    else    cout << ans[a - 1].f << "-" << ans[a - 1].s << "\n";
    if (b > ans.size() || b < 0)   cout << "NONE";
    else    cout << ans[b - 1].f << "-" << ans[b - 1].s;
    return 0;
}
