#include <iostream>
#include <cmath>
#include <vector>

#define XNY 2
#define X   0
#define Y   1

#define FOR(i,n)        for(int i=0; i<n; ++i)
#define Input1(a)       cin >> a
#define Input2(x, y)    cin >> x >> y
#define PrintC(coord)   cout << coord[X] << " " << coord[Y] << endl
#define SIGNOF(n)       ((n>0)-(n<0))

using namespace std;

void compute_move_recur_(int* coord, vector <int>::iterator iter, int sec, int is_for_y) {
    int one_move = *iter;

    if(sec < abs(one_move)) {
        coord[is_for_y] += sec * SIGNOF(one_move);
        return;
    }
    coord[is_for_y] += one_move;
    return compute_move_recur_(coord, iter+1, sec-abs(one_move), !is_for_y);
}

int compute_count_of_bounce(float first_bounce_time, int one_cycle_time, int given_time) {
    if (given_time < first_bounce_time)
        return 0;
    else
        return 1+(given_time-first_bounce_time)/one_cycle_time;
}

int main() {
    int num, given_time, x, y, is_vertical;

    int time_c1_to_c2, total_time=0;

    vector <int> corners[XNY], c1_move;

    Input1(num);

    FOR(i, num) {
        Input2(x, y);
        corners[X].push_back(x);
        corners[Y].push_back(y);
    }
    
    FOR(i,2)
        corners[i].push_back(corners[i][0]);

    x = corners[X][0];
    y = corners[Y][0];

    is_vertical = !(corners[X][1] - x);

    FOR(i, num) {
        c1_move.push_back(corners[is_vertical][i+1] - corners[is_vertical][i]);
        total_time += abs(c1_move[i]);

        if (i+1 == num/2-1)
            time_c1_to_c2 = total_time;
        is_vertical ^= 1;
    }

    int coord[2][XNY] = {x, y, x, y};

    Input1(given_time);

    int valid_time = given_time % total_time;
    compute_move_recur_(coord[0], c1_move.begin(), valid_time, is_vertical);

    valid_time = (time_c1_to_c2+total_time-valid_time)%total_time;
    compute_move_recur_(coord[1], c1_move.begin(), valid_time, is_vertical);

    int idx = compute_count_of_bounce((float)time_c1_to_c2/2, total_time/2, given_time) % 2;
    
    PrintC(coord[idx]);
    PrintC(coord[!idx]);
    
    return 0;
}
