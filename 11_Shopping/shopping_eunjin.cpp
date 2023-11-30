#include <bits/stdc++.h>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> Counters;

void input() {
    cin >> N >> K;
    Counters.resize(K, make_pair(0, 0));
}

void output() {
    int min_t = min_element(Counters.begin(), Counters.end(), [](const auto &counter1, const auto &counter2) {
        return counter1.second < counter2.second;
    })->second;
    for (auto it = Counters.rbegin(); it != Counters.rend(); ++it) {
        auto &counter = *it;
        if (counter.second == min_t) {
            cout << counter.first << "\n";
            counter = make_pair(0, 0);
        } else counter.second -= min_t;
    }
}

void calculate() {
    for (int i = 0; i < N; i++) {
        int id, time;
        cin >> id >> time;
        for (auto &counter: Counters) {
            if (counter.first == 0) {
                counter = make_pair(id, time);
                break;
            }
        }
        if (all_of(Counters.begin(), Counters.end(), [](const auto &counter) {
            return counter.first != 0;
        })) {
            output();
        }
    }

    while (!Counters.empty()) {
        Counters.erase(remove_if(Counters.begin(), Counters.end(), [](const auto &counter) {
            return counter.first == 0;
        }), Counters.end());

        output();
    }
}


int main() {
    input();
    calculate();
    return 0;
}