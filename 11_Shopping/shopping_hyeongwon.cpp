#include <bits/stdc++.h>

using namespace std;

vector<queue<pair<int, int>>> calcComb;
bool AllEmpty = false;

void check_all_empty() {
    AllEmpty = true;
    for(auto calc : calcComb) {
        if(!calc.empty()) {
            AllEmpty = false;
            break;
        }
    }
}

int main(){
    int N, k, custNum, countGoods;
    queue<pair<int, int>> calcOne;
    vector<int> timeComb, frontTimeComb;

    cin >> N >> k;

    while (k-- > 0) {
        calcComb.push_back(calcOne);
        timeComb.push_back(0);
    }
    while (N-- > 0) {
        cin >> custNum >> countGoods;
        int minindex = min_element(timeComb.begin(), timeComb.end()) - timeComb.begin();
        calcComb[minindex].push(make_pair(custNum, countGoods));
        timeComb[minindex] += countGoods;
    }
    for (auto w : calcComb) {
        if (!w.empty()) {
            frontTimeComb.push_back(w.front().second);
        }
        else {
            frontTimeComb.push_back(100);
        }
    }
    check_all_empty();


    while (!AllEmpty) {
        int findIndex = abs(min_element(frontTimeComb.rbegin(), frontTimeComb.rend()) - frontTimeComb.rend()) - 1;

        cout << calcComb[findIndex].front().first << endl;

        int completeGood = calcComb[findIndex].front().second;
        for (auto& w : calcComb) {
            if (!w.empty())
                w.front().second -= completeGood;
        }

        calcComb[findIndex].pop();

        for (int i = 0; i < frontTimeComb.size(); i++) {
            if (!calcComb[i].empty())
                frontTimeComb[i] = calcComb[i].front().second;
            else {
                frontTimeComb[i] = 100;
            }
        }
        check_all_empty();
    }
}
