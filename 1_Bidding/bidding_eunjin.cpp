#include <bits/stdc++.h>
#include <string>
using namespace std;

#define fastio  \
    iostream::sync_with_stdio(false);   \
    cin.tie(nullptr);   \
    cout.tie(nullptr);

vector<string> names;
vector<int> prices;
int answer_idx = 0;

void input() {
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        string name;
        int price;
        cin >> name >> price;
        names.push_back(name);
        prices.push_back(price);
    }
}

int find_max_price_idx() {
    while(true) {   // 1round
        int first_idx = 0;
        bool is_first = true, single = true;

        int max_price = *max_element(prices.begin(), prices.end());

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] == max_price) {
                if (is_first) {
                    first_idx = i;
                    is_first = false;
                    continue;
                }
                prices[i] = 0;
                single = false; // repeated
            }
        }

        if (single) {
            return first_idx;
        }
        else if (all_of(prices.begin(), prices.end(), [](int i) { return i==0; } )) {
            return -1;
        }
        prices[first_idx] = 0;
    }
}

void output() {
    if (answer_idx != -1) {
        cout << names[answer_idx];
    }
    else {
        cout << "NONE";
    }
}

int main() {
    input();
    answer_idx = find_max_price_idx();
    output();
}
