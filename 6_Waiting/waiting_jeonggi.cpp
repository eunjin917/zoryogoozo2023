#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void sit(vector< vector<int> >& room, int num, int k) {
    auto iter = room.begin();
    
    if(room.size() == 2) {
        room.insert(iter+1, vector<int>({num}));
        return;
    }

    while(true) {
        if((*iter)[0] < num && num < (*(iter+1))[0]) {
            if(iter == room.begin())
                ++iter;
            
            (*iter).push_back(num);
            sort((*iter).begin(), (*iter).end());
            break;
        }
        ++iter;
    }
    
    if((*iter).size() == 2*k) {
        auto inner_it = (*iter).begin();
        vector <int> copy(inner_it+k, inner_it+2*k);

        (*iter).erase(inner_it+ k, inner_it+ 2*k);
        room.insert(iter+1, copy);
    }
}

void out(vector< vector<int> >& room, int num) {
    auto iter = room.begin();
    for(; iter<room.end(); ++iter) {
        auto inner_iter = find((*iter).begin(), (*iter).end(), num);
        if (inner_iter != (*iter).end()) {
            (*iter).erase(inner_iter);
            if ((*iter).empty())
                room.erase(iter);

            return;
        } 
    }
}

void print_answer(vector< vector<int> >& room) {
    auto iter = room.begin()+1;
    for(; iter<room.end()-1; ++iter)
        cout << (*iter)[0] << endl;
}

int main() {
    int n, k;
    vector< vector<int> > waiting_room({{0}, {1001}});

    cin >> n >> k;

    char sign;
    int number;

    for(int i=0; i<n; ++i) {
        cin >> sign >> number;

        if (sign == '+')
            sit(waiting_room, number, k);
        else
            out(waiting_room, number);
    }

    print_answer(waiting_room);
    // cout << "...PRINTING NOW..." << endl;
    // for(auto w: waiting_room) {
    //     for(auto ww: w) {
    //         cout << ww << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}