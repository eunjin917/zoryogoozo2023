#include <bits/stdc++.h>
using namespace std;

int N, k[2];
map<string, vector<string>> funcs;
vector<string> answer;

void input() {
    cin >> N >> k[0] >> k[1];
    for (int i = 1; i <= N; i++) {
        string func_name, stmt;
        cin >> func_name;
        while (cin >> stmt && stmt != "$")
            funcs[func_name].push_back(stmt);
    }
}

bool exists_in_vector(const vector<string>& vec, const string& val) {
    return find(vec.begin(), vec.end(), val) != vec.end();
}

bool func_call() {
    stack<pair<string, int>> s;
    vector<string> func_log, visited;

    s.push({"M", 0});
    while (!s.empty()) {
        auto [cur_func, idx] = s.top(); s.pop();
        if (idx == 0) {
            if (exists_in_vector(visited, cur_func) && exists_in_vector(func_log, cur_func)) return true;
            visited.push_back(cur_func);
            func_log.push_back(cur_func);
        }
        if (idx < funcs[cur_func].size()) {
            string now = funcs[cur_func][idx];
            s.push({cur_func, idx + 1});
            if ("A" <= now && now <= "Z") s.push({now, 0});
            else answer.push_back(cur_func + "-" + now);
        } else {
            func_log.erase(remove(func_log.begin(), func_log.end(), cur_func), func_log.end());
        }
    }
    return false;
}

int main() {
    input();
    if (func_call()) {
        cout << "DEADLOCK";
        return 0;
    }

    for (int i = 0; i < 2; i++) {
        if (k[i] > 0) {
            if (k[i] > answer.size()) cout << "NONE\n";
            else cout << answer[k[i] - 1] << "\n";
        } else {
            if (abs(k[i]) > answer.size()) cout << "NONE\n";
            else cout << answer[answer.size() + k[i]] << "\n";
        }
    }
}
