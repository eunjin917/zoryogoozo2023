#include <iostream>
#include <cmath>

#define MAX         50
#define QUERY_NUM   5

#define XNY 2
#define X   0
#define Y   1

#define FOR(i,n)        for(int i=0; i<n; ++i)
#define Input(a)        cin >> a
#define InputC(i,coord) cin >> coord[i][X] >> coord[i][Y]
#define Print(a)        cout << a << endl
#define PrintC(coord)   cout << coord[X] << " " << coord[Y] << endl
#define SIGNOF(n) ((n>0)-(n<0))


using namespace std;

void compute_move_recur_(int* coord, int(*move) [2], int sec, int is_for_y) {
    int moved = move[0][is_for_y];

    if(sec < abs(moved)) {
            coord[is_for_y] += sec * SIGNOF(moved);
            return;
    }
    else {
        coord[is_for_y] += moved;
        return compute_move_recur_(coord, move+1, sec-abs(moved), !move[1][X]);
    }
}

int main() {
    int num;
    
    int routing_point[MAX+1][XNY], move[MAX][XNY], total_moves=0;
    
    int time_per_loop;

    Input(num);
    
    FOR(i, num)
        InputC(i, routing_point);

    routing_point[num][X] = routing_point[0][X];
    routing_point[num][Y] = routing_point[0][Y];

    FOR(i, num) {
        move[i][X] = routing_point[i+1][X] - routing_point[i][X];
        move[i][Y] = routing_point[i+1][Y] - routing_point[i][Y];
        total_moves += abs(move[i][X] + move[i][Y]);
    }

    // FOR(i, num) {
    //     cout << i << "th..." << endl;
    //     cout << x_move[i] << " " << y_move[i] << endl;
    //     cout << time_per_move[i] << endl << endl;
    // }

    int time_point;
    int coord[XNY];

    FOR(i, QUERY_NUM) {
        Input(time_point);
       
        time_point %= total_moves;

        coord[X] = routing_point[0][X];
        coord[Y] = routing_point[0][Y];   
        compute_move_recur_(coord, move, time_point, !move[0][X]);     

        PrintC(coord);
    }

    // Print("PRINT NOW...");

    // FOR(i, num)
    //     cout << routing_point[i][X] << " " << routing_point[i][Y] << endl;

    return 0;
}