#include <iostream>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct {
    int customer;
    int num_of_item;
    int time_passed;
} COUNTER;

int calc_time(COUNTER a) {
    return a.num_of_item + a.time_passed;
}

bool comp_wait(COUNTER a, COUNTER b) {
    return calc_time(a) < calc_time(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, k;
    int ids[100000], num_of_items[100000];
    list<COUNTER> counters;

    cin >> N >> k;

    for (int i=0; i<N; ++i) {
        cin >> ids[i] >> num_of_items[i];
    }

    int i;
    for (i=0; i<k && i<N; ++i) {
        COUNTER c;
        c.customer = ids[i];
        c.num_of_item = num_of_items[i];
        c.time_passed = 0;
        counters.push_back(c);
    }

    unsigned long long sum = 0;
    int cnt = 1;
    stack<reverse_iterator<list<COUNTER>::iterator> > stk;

    while (!counters.empty()) {
        auto it = min_element(counters.rbegin(), counters.rend(), comp_wait);
        
        int min_time = calc_time(*it);
        while (it != counters.rend()) {
            stk.push(it);
            
            sum += (unsigned long long)(cnt++) * it->customer;
            it->time_passed += it->num_of_item;
            it->customer = 0;
            it->num_of_item = 0;

            for (++it; it != counters.rend(); ++it)
                if (calc_time(*it) == min_time)
                    break;
        }
        
        while (!stk.empty()) {
            it = stk.top();
            if (i<N) {
                it->customer = ids[i];
                it->num_of_item = num_of_items[i];
                i++;
            } else {
                ++it;
                counters.erase(it.base());
            }

            stk.pop();
        }
    }

    cout << sum << endl;

    return 0;
}
