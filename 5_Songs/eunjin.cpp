#include <bits/stdc++.h>
using namespace std;

#define fastio  \
    iostream::sync_with_stdio(false);   \
    cin.tie(nullptr);   \
    cout.tie(nullptr);

struct song{
    string Title;
    char Genre;
    int Broadcast;
    double Size;
    int Download;

    // overloading
    bool operator==(const song& other) const {
        return this->Genre == other.Genre;
    }
};

vector<song> Songs;
int N, K;

void input() {
    cin >> N >> K;
    Songs.resize(N);
    for (int i=0; i<N; i++) {
        cin >> Songs[i].Title >> Songs[i].Genre >> Songs[i].Broadcast >> Songs[i].Size >> Songs[i].Download;
    }
}

bool compare(const song& s1, const song& s2) {
    if (s1.Broadcast == s2.Broadcast) {
        if (s1.Download == s2.Download)
            return s1.Size < s2.Size;
        else
            return s1.Download > s2.Download;
    }
    else
        return s1.Broadcast > s2.Broadcast;
}

void ranking() {
    sort(Songs.begin(), Songs.end(), compare);

    for (int i=0; i<N-2; i++) {
        if (Songs[i].Genre == Songs[i+1].Genre) {

            bool allGenresEqual = true;
            for (int j = i + 1; j < N; ++j) {
                if (Songs[j].Genre != Songs[i].Genre) {
                    allGenresEqual = false;
                    break;
                }
            }

            if (!allGenresEqual)
                swap(Songs[i+1], Songs[i+2]);
        }
    }
}

void output() {

    // view

    /*
    for (int i=0; i<N; i++) {
        cout << Songs[i].Title << " " << Songs[i].Genre << " " << Songs[i].Broadcast << " " << Songs[i].Size << " " << Songs[i].Download << "\n";
    }
    */

    cout << Songs[K-1].Title;
}

int main() {
    input();
    ranking();
    output();
}
