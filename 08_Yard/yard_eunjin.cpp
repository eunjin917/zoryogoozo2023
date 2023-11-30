#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR_LOOP_TO(end) for (int i = 0; i < (end); i++)
#define vi vector<int>

vector<pair<int, vi>> Yard;
int N, Line_count, Weight;

void input() {
    cin >> N;
    FOR_LOOP_TO(N) {
        cin >> Line_count;

        vi containers;
        FOR_LOOP_TO(Line_count) {
            cin >> Weight;
            containers.push_back(Weight);
        }
        Yard.emplace_back(Line_count, containers);
    }
}

int find_max_height() {
    int max_height=0;
    vi max_indexs, max_top_weights;

    FOR_LOOP_TO(N) {
        int this_height =Yard[i].first;
        if (this_height==0) continue;

        int this_top = Yard[i].second.back();

        if (this_height > max_height) {
            max_indexs.clear();
            max_top_weights.clear();
            max_indexs.push_back(i);
            max_top_weights.push_back(this_top);
            max_height = this_height;
        }
        else if (this_height == max_height) {
            max_indexs.push_back(i);
            max_top_weights.push_back(this_top);
        }
    }

    return max_indexs[max_element(max_top_weights.begin(), max_top_weights.end()) - max_top_weights.begin()]; // find heavy weight index
}

int find_min_height() {
    int min_height=0x3f3f3f3f;
    vi min_indexs;

    FOR_LOOP_TO(N) {
        int this_height = Yard[i].first;

        if (this_height < min_height) {
            min_indexs.clear();
            min_indexs.push_back(i);
            min_height = this_height;

        }
        else if (this_height == min_height) min_indexs.push_back(i);
    }

    return *min_element(min_indexs.begin(), min_indexs.end());  // find low number index
}

void move_container(int max_index, int min_index) {
    int temp = Yard[max_index].second.back();

    Yard[max_index].second.pop_back();
    Yard[max_index].first--;

    Yard[min_index].second.push_back(temp);
    Yard[min_index].first++;
}

void steps() {
    while(true) {
        int max_index = find_max_height(), min_index = find_min_height();

        if (Yard[max_index].first - Yard[min_index].first < 2) break;

        move_container(max_index, min_index);
    }
}

void output() {
    FOR_LOOP_TO(N) {
        vi containers = Yard[i].second;

        if (containers.empty()) cout << "0";

        for (int weight : containers) cout << weight << " ";
        cout << "\n";
    }
}


int main() {
    input();
    steps();
    output();
}
