#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
    int arrival_time, id, support_time;
} Guest;

typedef struct {
    bool operator() (Guest a, Guest b) {
        if (a.support_time < b.support_time)
            return true;

        if (a.support_time > b.support_time)
            return false;

        return a.arrival_time > b.arrival_time;
    }
} MyComp;

int main() {
    int N, time_passed=30;
    priority_queue<Guest, vector<Guest>, MyComp> pq;

    cin >> N;
    for (int i=0; i<N; ++i) {
        Guest g;

        cin >> g.arrival_time >> g.id >> g.support_time;

        if (g.arrival_time > 30) {
            while (time_passed < g.arrival_time && !pq.empty()) {
                auto g_got_consult = pq.top();
                pq.pop();
                if (g_got_consult.support_time > 10) {
                    time_passed += g_got_consult.support_time/2;
                    g_got_consult.arrival_time = time_passed;
                    g_got_consult.support_time -= g_got_consult.support_time/2;
                    pq.push(g_got_consult);
                } else {
                    time_passed += g_got_consult.support_time;
                    cout << g_got_consult.id << endl;
                }
            }
        }
        pq.push(g);
    }
    
    while (!pq.empty()) {
        auto g_got_consult = pq.top();
        pq.pop();
        if (g_got_consult.support_time > 10) {
            time_passed += g_got_consult.support_time/2;
            g_got_consult.arrival_time = time_passed;
            g_got_consult.support_time -= g_got_consult.support_time/2;
            pq.push(g_got_consult);
        } else {
            time_passed += g_got_consult.support_time;
            cout << g_got_consult.id << endl;
        }
    }

    return 0;
}