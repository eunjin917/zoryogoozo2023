#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// printing stack from bottom to top.
ostream& operator<< (ostream& os, stack<int> s) {
    stack <int> reversed;
    
    while (!s.empty()) {
        reversed.push(s.top());
        s.pop();
    }
    
    if (!reversed.empty()) {
        os << reversed.top();
        reversed.pop();
    } else {
        os << '0';
    }

    while (!reversed.empty()) {
        os << ' ' << reversed.top();
        reversed.pop();
    }

    return os;
}

bool comp(stack<int> a, stack<int> b) {
    int a_size = a.size();
    int b_size = b.size();

    if (a_size < b_size) return true;
    if (a_size > b_size) return false;
    if (!a.empty())      return a.top() < b.top();
    
    return true;
}

bool stable(const vector< stack<int> > yard) {
    auto first = yard.begin();
    auto last  = yard.end();

    return (max_element(first, last, comp)->size() - min_element(first, last, comp)->size()) < 2;
}

void move_container(vector< stack<int> >& yard) {
    auto first = yard.begin();
    auto last  = yard.end();

    auto highest_priority_cont = max_element(first, last, comp);
    int lowest_height = min_element(first, last, comp)->size();
    
    for (auto& w: yard) {
        if (w.size() == lowest_height) {
            w.push(highest_priority_cont->top());
            return highest_priority_cont->pop();
        }
    }
}

int main() {
    int N, num_of_containers;
    cin >> N;

    vector< stack<int> > yard;

    // INPUT PART
    for (int i=0; i<N; ++i) {
        stack<int> load;
        
        cin >> num_of_containers;
        
        for (int j=0; j<num_of_containers; ++j) {
            int id;

            cin >> id;
            load.push(id);
        }

        yard.push_back(load);
    }

    while (!stable(yard))
        move_container(yard);

    // cout << "PRINTING NOW.." << endl;
    for (auto w: yard)
        cout << w << endl;

    return 0;
}