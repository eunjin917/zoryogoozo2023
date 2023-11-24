#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int, greater<int>> poly;
    int N;
    cin >> N;

    while (N--) {
        int t;
        cin >> t;
        while (t--) {
            int c, e;
            cin >> c >> e;
            if (poly.find(e) != poly.end()) {
                poly[e] += c;
            } else {
                poly[e] = c;
            }
            if (poly[e] == 0) {
                poly.erase(e);
            }
        }
    }

    if (poly.empty()) {
        cout << "0 0" << endl;
    } else {
        cout << poly.size() << endl;
        for (const auto& term : poly) {
            cout << term.second << " " << term.first << endl;
        }
    }

    return 0;
}
