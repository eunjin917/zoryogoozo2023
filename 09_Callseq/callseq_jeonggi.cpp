#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <cctype>
#include <map>
#include <stack>
#include <vector>

using namespace std;

vector<string> run(map<char,vector<string> > funcs) {
    vector<string> printed;
    set<char> call_set;
    stack<pair<char, vector<string>::iterator> > sequence;

    char ch, state='M';
    auto it = funcs[state].begin();

    while(true) {
        ch = (*it)[0];
        if(ch == '$') {
            if(sequence.empty())
                break;
            
            state = sequence.top().first;
            call_set.erase(sequence.top().first);
            it = sequence.top().second;
            sequence.pop();
            continue;
        }

        if(isupper(ch)) {
            if (!call_set.insert(state).second) {
                printed.clear();
                return printed;
            }
            sequence.push(make_pair(state,it+1));
            it = funcs[ch].begin();
            state = ch;
            continue;
        }

        printed.push_back(string(1, state)+"-"+*it);
        ++it;
    }
    
    return printed;
}

int main() {
    int N, k1, k2;
    map<char, vector<string> > funcs;

    char func;

    cin >> N >> k1 >> k2;

    string str;
    for (int i=0; i<N; ++i) {
        cin >> func;
        funcs[func] = vector<string>();

        str = "";
        while (str != "$") {
            cin >> str;
            funcs[func].push_back(str);
        }
    }

    auto printed = run(funcs);

    int len = printed.size();
    if (len) {
        k1 = k1 < 0 ? len+k1 : k1-1;
        k2 = k2 < 0 ? len+k2 : k2-1;
        
        if (k1 > len-1) cout << "NONE" << endl;
        else            cout << printed[k1] << endl;

        if (k2 > len-1) cout << "NONE" << endl;
        else            cout << printed[k2] << endl;

    } else
        cout << "DEADLOCK" << endl;

    // for (auto w: funcs) {
    //     cout << w.first << endl;
    //     cout << "{";
    //     for (auto ww: w.second) {
    //         cout << ww << " ";
    //     }
    //     cout << "}" << endl;
    // }

    return 0;
}