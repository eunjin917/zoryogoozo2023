#include <iostream>
#include <vector>

using namespace std;

class Stair {
private:
    vector<int> LineComb;
    int StairCount = 0;
    int height = 0;
public:
    Stair() {}
    ~Stair() {}
    void make_stair(int line) {
        LineComb.push_back(line);
        StairCount++;
        if(StairCount%2 == 0) height += line;
    }
    string point_place(int xpoint, int ypoint) {
        int xplace = 0;
        int yplace = height;
        if(ypoint > yplace)
            return "out";
        for(int i = 0; i < StairCount/2; i++) {
            xplace += LineComb[i*2];
            if(xpoint > xplace){
                yplace -= LineComb[i*2 + 1];
            }
            else {
                if(xpoint == xplace) {
                    if(ypoint <= yplace && ypoint >= yplace - LineComb[i*2 + 1])
                        return "on";
                    else {
                        if(ypoint > yplace)
                            return "out";
                        else
                            return "in";
                    }
                }
                else {
                    if(ypoint == yplace)
                        return "on";
                    else {
                        if(ypoint > yplace)
                            return "out";
                        else
                            return "in";
                    }
                }
            }
        }
        return "out";
    }
};

int main(void) {
    int stairline;
    int xpoint, ypoint;
    Stair stair;

    while(cin >> stairline) {
        if(stairline == 0)
            break;
        stair.make_stair(stairline);
    }

    while(cin >> xpoint >> ypoint) {
        cout << stair.point_place(xpoint, ypoint) << endl;
    }
}
