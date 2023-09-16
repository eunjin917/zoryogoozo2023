#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000

#define fastio  \
    iostream::sync_with_stdio(false);   \
    cin.tie(nullptr);   \
    cout.tie(nullptr);

vector<vector<int>> points(SIZE, vector<int>(SIZE, 0));
int last_x_point = 0, last_y_point = 0;

void set_points() {
    bool is_horizontal = true;
    int this_line;

    while (cin >> this_line) {
        // exit
        if (this_line == 0) {
            for (int j=last_x_point+1; j<SIZE; j++) {
                points[last_y_point][j] = -1;
            }
            return;
        }
        // horizontal
        if (is_horizontal) {
            for (int i = last_y_point + 1; i < SIZE; i++) {
                for (int j = last_x_point; j < last_x_point + this_line; j++) {
                    points[i][j] = 1;
                }
            }
            last_x_point += this_line;
            is_horizontal = false;
        }
        // vertical
        else {
            for (int i = last_y_point; i < last_y_point + this_line; i++) {
                for (int j = last_x_point + 1; j < SIZE; j++) {
                    points[i][j] = -1;
                }
            }
            last_y_point += this_line;
            is_horizontal = true;
        }
    }
}

void testcase() {

    // after SIZE 20
    /*
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            cout << setw(3) << points[i][j];
        }
        cout << "\n";
    }
    */

    int x, y;
    while (cin >> x >> y) {
        int new_y = last_y_point - y;
        if (new_y < 0) cout << "out\n";
        else {
            int point_value = points[new_y][x];
            if (point_value == 0) cout << "on\n";
            else if (point_value == 1) cout << "in\n";
            else if (point_value == -1) cout << "out\n";
        }
    }
}

int main() {
    set_points();
    testcase();
}
