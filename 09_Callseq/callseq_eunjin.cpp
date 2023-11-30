#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MAX_DEPTH 3000

vector<pair<char, string>> Sequences;
map<char, vector<string>> Functions;
vector<int> K;
int RecursionCount = 0;
bool IsDeadlock = false;

void input() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    K.push_back(k1);
    K.push_back(k2);

    for (int i=0; i<n; i++) {
        char func_name;
        cin >> func_name;

        vector<string> statements;
        string statement;
        while (cin >> statement) {
            if (statement.compare("$") == 0) break;
            statements.push_back(statement);
        }

        Functions[func_name] = statements;
    }
}

void func_call(char func_name) {

    if (IsDeadlock) return;

    if (RecursionCount++ > MAX_DEPTH) {
        IsDeadlock = true;
        cout << "DEADLOCK";
        return;
    }

    for (auto& statement : Functions[func_name]) {
        if (isupper(statement[0])) func_call(statement[0]);
        else Sequences.emplace_back(func_name,statement);
    }
}


void output() {
    int all_size = Sequences.size();

    if (IsDeadlock == false) {
        for (auto const& k : K) {
            if (k > all_size) cout << "NONE\n";
            else if (k > 0) cout << Sequences[k-1].first << "-" << Sequences[k-1].second << "\n";
            else if (k < 0) cout << Sequences[all_size+k].first << "-" << Sequences[all_size+k].second << "\n";
        }
    }
}

int main() {
    input();
    func_call('M');
    output();
}
