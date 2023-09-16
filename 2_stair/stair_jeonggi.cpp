#include <iostream>

using namespace std;

#define X1 0
#define X2 1
#define HEIGHT 2

class stair {
public:
    int size, total_height, accumulated_x, accumulated_y, h_arr[20], v_arr[20];
    int (* my_ds)[3];   // [][0] for x1, [][1] for x2, [][3] for y 

    stair() : size(0), total_height(0), accumulated_x(0){}
    bool input(int i) {
        int value;

        cin >> value;

        if(value == 0) {
            size = i/2;
            my_ds = new int[size][3];   // [][0] for x1, [][1] for x2, [][3] for y 
            accumulated_y = total_height;
            return true;
        }

        if(i%2) {
            v_arr[i/2] = value;
            total_height += value;
        }
        else
            h_arr[i/2] = value;

        return false;
    }
    void calc() {
        for(int i=0; i<size; ++i) {
            my_ds[size-1-i][X1] = accumulated_x;
            accumulated_x += h_arr[i];

            my_ds[size-1-i][X2] = accumulated_x;

            my_ds[size-1-i][HEIGHT] = accumulated_y;
            accumulated_y -= v_arr[i];
        }
        // for(int i=0; i<size; ++i)
        //     cout << i << "th stair...  " << my_ds[i][X1] << " " << my_ds[i][X2] << " " << my_ds[i][HEIGHT] << endl;
    }
    void print_position_of_coord(int x, int y) {
        int idx=0;   // idx of stair
        for(; idx<size; ++idx)
            if(y <= my_ds[idx][HEIGHT])
                break;
        
        if(idx == size) 
            cout << "out" << endl;
        else if(x == my_ds[idx][X2] || y == my_ds[idx][HEIGHT] && my_ds[idx][X1] <= x && x < my_ds[idx][X2])
            cout << "on" << endl;
        else if(x > my_ds[idx][X2])
            cout << "out" << endl;
        else
            cout << "in" << endl;
    }
};

int main() {
    stair my_stair; 

    for(int i=0; i<41; ++i)
        if(my_stair.input(i))
            break;

    my_stair.calc();

    int x, y;
    while(cin >> x >> y)
        my_stair.print_position_of_coord(x, y);

    return 0;
}