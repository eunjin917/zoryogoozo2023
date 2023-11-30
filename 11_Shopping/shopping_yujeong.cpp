#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Customer {
    int id;
    int items;
};

struct finish {
    int id;
    int time;
    int cart;

    bool operator < (const finish& other) const {
        if (time == other.time) {
            return cart < other.cart; // 낮은 계산대 번호가 먼저
        }
        return time > other.time; // 낮은 시간이 먼저
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    queue<Customer> wating;
    vector<list<Customer>> counters(M);
    vector<finish> finishedCustomers;

    for(int i = 0; i < N; i++) {
        Customer c;
        cin >> c.id >> c.items;
        wating.push(c);
    }

    int currentTime = 0;
    for(int i = 0; i < M && !wating.empty(); i++) {
        counters[i].push_back(wating.front());
        wating.pop();
    }

    while(N > 0) {
        currentTime++;
        priority_queue<finish> processedQueue;

        for(int i = 0; i < M; i++) {
            if(!counters[i].empty()) {
                counters[i].front().items--;
                if(counters[i].front().items == 0) {
                    processedQueue.push({counters[i].front().id, currentTime, i});
                    counters[i].pop_front();
                    N--;

                    if(!wating.empty()) {
                        counters[i].push_back(wating.front());
                        wating.pop();
                    }
                }
            }
        }

        while (!processedQueue.empty()) {
            finishedCustomers.push_back(processedQueue.top());
            processedQueue.pop();
        }
    }

    // 출력
    for(const auto& c : finishedCustomers) {
        cout << c.id << endl;
    }

    return 0;
}
