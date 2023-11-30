#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> best;
int maxP = -1;

void findComb(vector<int>& p, int K, stack<int>& s, int i) {
    if (K == 0) {
        vector<int> curr(s.size());
        int idx = s.size() - 1;
        stack<int> temp = s;
        while (!temp.empty()) {
            curr[idx--] = temp.top();
            temp.pop();
        }

        int currMax = -1;
        for (int v : curr) {
            if (v > currMax) {
                currMax = v;
            }
        }
        
        if (currMax > maxP) {
            best = curr;
            maxP = currMax;
        } else if (currMax == maxP) {
            for (int j = curr.size() - 1; j >= 0; j--) {
                if (curr[j] > best[j]) {
                    best = curr;
                    break;
                } else if (curr[j] < best[j]) {
                    break;
                }
            }
        }
        return;
    }
    if (i == p.size() || K < 0) return;

    s.push(p[i]);
    findComb(p, K - p[i], s, i + 1);

    s.pop();
    findComb(p, K, s, i + 1);
}

void sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    stack<int> s;
    findComb(p, K, s, 0);

    sort(best);

    if (best.size() == 0) {
        cout << 0 << endl;
    } else {
        for (int price : best) {
            cout << price << endl;
        }
    }

    return 0;
}
