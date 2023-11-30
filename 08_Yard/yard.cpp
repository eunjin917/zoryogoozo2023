#include <bits/stdc++.h>
using namespace std;

vector<deque<int>> yard;
int N;

void input() {
    cin >> N;
    yard.resize(N);
    
    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        deque<int> containers;
        
        for (int j = 0; j < s; j++) {
            int tons;
            cin >> tons;
            containers.push_back(tons);
        }
        yard[i] = containers;
    }
}

void rearrange() {
    while (true) {
        int highestIdx = 0;
        int lowestIdx = 0;
        int maxHeight = 0;
        int minHeight = INT_MAX;

        for (int i = 0; i < N; i++) {
            if (yard[i].size() > maxHeight ||
                (yard[i].size() == maxHeight && !yard[i].empty() && yard[i].back() > yard[highestIdx].back())) {
                maxHeight = yard[i].size();
                highestIdx = i;
            }
            if (yard[i].size() < minHeight) {
                minHeight = yard[i].size();
                lowestIdx = i;
            }
        }

        if ((maxHeight - minHeight) <= 1) {
            break;
        }

        if (highestIdx != -1 && !yard[highestIdx].empty()) {
            yard[lowestIdx].push_back(yard[highestIdx].back());
            yard[highestIdx].pop_back();
        }
    }
}

void output() {
    for (int i = 0; i < N; i++) {
        if (yard[i].empty()) {
            cout << "0" << endl;
        } else {
            for (const int& container : yard[i]) {
                cout << container << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    input();
    rearrange();
    output();
    return 0;
}
