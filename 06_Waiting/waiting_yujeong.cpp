#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
vector<vector<int>> chairs;

void split(int idx) {
    vector<int> &chair = chairs[idx];
    vector<int> newChair(chair.begin() + k, chair.end());
    chair.erase(chair.begin() + k, chair.end());
    chairs.insert(chairs.begin() + idx + 1, newChair);
}

void enter(int num) {
    if (chairs.empty()) {
        chairs.push_back({num});
        return;
    }
    
    for (int i = 0; i < chairs.size(); i++) {
        if (chairs[i].size() < 2 * k) {
            auto position = lower_bound(chairs[i].begin(), chairs[i].end(), num);
            
            // 입장하는 숫자가 마지막에 위치하려 할 때, 다음 의자의 첫 번째 원소보다 크거나 같으면 패스
            if (i < chairs.size() - 1 && position == chairs[i].end() && num >= chairs[i+1][0]) {
                continue;
            }

            chairs[i].insert(position, num);
            if (chairs[i].size() == 2 * k) {
                split(i);
            }
            return;
        }
    }
}

void leave(int num) {
    for (int i = 0; i < chairs.size(); i++) {
        auto pos = find(chairs[i].begin(), chairs[i].end(), num);
        if (pos != chairs[i].end()) {
            chairs[i].erase(pos);
            if (chairs[i].empty()) {
                chairs.erase(chairs.begin() + i);
            }
            return;
        }
    }
}

int main() {
    int N;
    cin >> N >> k;

    for (int i = 0; i < N; i++) {
        char sign;
        int operation;
        cin >> sign >> operation;
        if (sign == '+') {
            enter(operation);
        } else {
            leave(operation);
        }
    }

    for (int i = 0; i < chairs.size(); i++) {
        cout << chairs[i][0] << "\n";
    }

    return 0;
}

