#include <iostream>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

list<set<int>> chairs;
int N, K;

void input() {
    cin >> N >> K;
}

void check_split(auto itr) {
    if (itr->size() == 2*K) {
        set<int> chair;
        for (int i=0; i<K; i++) {
            int last = *(itr->rbegin());
            chair.insert(last);
            itr->erase(last);
        }
        chairs.insert(next(itr), chair);
    }
}

void check_empty(auto itr) {
    if (itr->size() == 0) {
        chairs.erase(itr);
    }
}


void enter(int num) {
    if (chairs.size() == 0) {
        set<int> chair;
        chair.insert(num);
        chairs.push_front(chair);
        return;
    }

    auto last_itr =  chairs.begin();
    for (auto itr = chairs.begin(); itr != chairs.end(); ++itr) {
        if (num < *(itr->begin())) {
            last_itr->insert(num);
            check_split(last_itr);
            return;
        }
        last_itr = itr;
    }

    last_itr->insert(num);
    check_split(last_itr);
}

void leave(int num) {
    if (chairs.empty()) return;

    auto last_itr =  chairs.begin();
    for (auto itr = chairs.begin(); itr != chairs.end(); ++itr) {
        if (num <= *(itr->rbegin())) {
            itr->erase(num);
            check_empty(itr);
            return;
        }
        last_itr = itr;
    }

    last_itr->erase(num);
    check_empty(last_itr);
}

void transactions() {
    for (int i=0; i<N; i++) {
        char sign;
        int num;
        cin >> sign >> num;
        switch(sign) {
            case '+': enter(num); break;
            case '-': leave(num); break;
        }
    }
}

void output() {
    for (auto const& chair :chairs) {
        cout << *(chair.begin()) << "\n";
    }
}

int main() {
    input();
    transactions();
    output();
}
