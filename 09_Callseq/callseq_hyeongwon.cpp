#include <bits/stdc++.h>

using namespace std;

int funcSize = 0;
vector<string> funcExec;
vector<string> funcExecName;
map<string,vector<string>> funcComb;
bool Deadlock = false;

void full_function(string funcName) {
    for(auto& w : funcComb[funcName]) {
        if(isupper(w[0])) {
            if(find(funcExecName.begin(), funcExecName.end(), w) != funcExecName.end()) {
                Deadlock = true;
                break;
            }
            funcExecName.push_back(w);
            full_function(w);
            funcExecName.pop_back();
        }
        else {
            funcExec.push_back(funcName + "-" + w);
            funcSize++;
        }
        if(Deadlock) break;
    }
}

string what_execute(int time) {
    if(abs(time) > funcSize) return "NONE";
    else if(time > 0) return funcExec[time - 1];
    else return funcExec[funcSize + time];
}

int main(void) {
    int N, k1, k2;
    string func, funcContent;
    //stack<string> funcExec;

    cin >> N >> k1 >> k2;
    while(N-- > 0) {
        cin >> func;
        vector<string> funcContents;
        while(cin >> funcContent) {
            if(funcContent == "$") break;
            funcContents.push_back(funcContent);
        }
        funcComb[func] = funcContents;
    }

    full_function("M");

    if(Deadlock) cout << "DEADLOCK" << endl;
    else {
        cout << what_execute(k1) << endl << what_execute(k2) << endl;
    }
}
