#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define EXP_SIZE 1000

vector<int> Canonical(EXP_SIZE, 0);
int N, T, C, E;

int input() {
    for (int i=0; i<N; i++) {
        cin >> T;
        for (int j=0; j<T; j++) {
            cin >> C >> E;
            Canonical[E] += C;
        }
    }
}

void output() {
    int cnt = count_if(Canonical.begin(), Canonical.end(), [](int elem) {
             return elem != 0;
    });

    if (cnt == 0) {
        cout << "0 0\n";
        return;
    }

    cout << cnt << "\n";
    for (int i=EXP_SIZE-1; i>=0; i--) {
        if (Canonical[i] != 0) {
            cout << Canonical[i] << " " << i << "\n";
        }
    }
}

int main() {
    input();
    output();
}
