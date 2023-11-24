#include <bits/stdc++.h>
using namespace std;

#define fastio  \
    iostream::sync_with_stdio(false);   \
    cin.tie(nullptr);   \
    cout.tie(nullptr);

struct point{
    int x;
    int y;
    char direction;   // up down right left
    int time;
};

vector<point> Points;
int N, Cycle_time=0;

void calc(int last_x, int last_y, int this_x, int this_y) {
    int diff;
    char direction;

    if (this_x == last_x) {
        diff = this_y - last_y;
        direction = (diff > 0) ? 'u' : 'd';
    }
    else if (this_y == last_y) {
        diff = this_x - last_x;
        direction = (diff > 0) ? 'r': 'l';
    }

    Points.push_back({last_x, last_y, direction, Cycle_time});

    Cycle_time += (diff > 0) ? diff : -diff;
}



void set_points() {
    int last_x, last_y;
    cin >> N >> last_x >> last_y;

    // 0 ~ N-2
    for (int i=0; i<N-1; i++) {
        int this_x, this_y;
        cin >> this_x >> this_y;

        calc(last_x, last_y, this_x, this_y);

        last_x = this_x;
        last_y = this_y;
    }

    // N-1
    calc(last_x, last_y, Points[0].x, Points[0].y);

    // view

    /*
    for (int i=0; i<N; i++) {
        cout << Points[i].x << " " << Points[i].y << " " << Points[i].direction <<" " << Points[i].time << "\n";
    }
    */
}


void output(int time, int i) {

                int diff = time - Points[i].time;

                switch (Points[i].direction) {
                case 'u':
                    cout << Points[i].x << " " << Points[i].y +diff << "\n";
                    break;
                case 'd':
                    cout << Points[i].x << " " << Points[i].y -diff << "\n";
                    break;
                case 'r':
                    cout << Points[i].x +diff << " " << Points[i].y << "\n";
                    break;
                case 'l':
                    cout << Points[i].x -diff << " " << Points[i].y << "\n";
                    break;
                }
}


void testcase() {
    int seconds;
    while (cin >> seconds) {
        int time = seconds % Cycle_time;

        int index;
        for (index=1; index<N; index++) {   // 1~ N-1
            if (time < Points[index].time) {  // range! 1400 -> last
                output(time, index-1);
                break;
            }

        }
        if (index==N && time < Cycle_time) {
            output(time, index-1);
        }
    }
}



int main() {
    set_points();
    testcase();
}
