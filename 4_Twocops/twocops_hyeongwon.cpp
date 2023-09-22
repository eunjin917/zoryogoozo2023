#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Twocops {
private:
    int maxPoint;
    int numOfPoint = 0, oneCycleDist = 0, twoPointsDist = 0;
    vector<pair<int,int>> pointComb;
    vector<int> distComb;
public:
    Twocops(int n) : maxPoint(n) {}

    void set_cops(int x, int y) {
        auto point = make_pair(x, y);
        pointComb.push_back(point);
        numOfPoint++;
        if(numOfPoint == maxPoint) {
            for(int i = 0; i < maxPoint; i++){
                oneCycleDist += abs(pointComb[(i+1)%maxPoint].first - pointComb[i].first + pointComb[(i+1)%maxPoint].second - pointComb[i].second);
                distComb.push_back(oneCycleDist);
            }
            twoPointsDist = distComb[maxPoint/2 - 2];
        }
    }

    void robot_move(int& x, int& y, int realSec) {
        int index;

        for(int i = 0; i < maxPoint; i++) {
            if(realSec <= distComb[i]) {
                index = i;
                break;
            }
        }

        realSec -= distComb[index++];

        x = pointComb[index%maxPoint].first;
        y = pointComb[(index--)%maxPoint].second;

        if(x == pointComb[index].first) {
            if(y > pointComb[index].second) y += realSec;
            else y -= realSec;
        }
        else {
            if(x > pointComb[index].first) x += realSec;
            else x -= realSec;
        }
    }

    void after_second(int second) {
        bool cross = false;
        int findex, sindex;
        int firstX, firstY, secondX, secondY;
        int realSec = second % oneCycleDist;

        if(realSec > twoPointsDist/2 && realSec <= (twoPointsDist + oneCycleDist)/2) {
            cross = true;
        }

        robot_move(firstX, firstY, realSec);
        robot_move(secondX, secondY, (twoPointsDist + oneCycleDist - realSec) % oneCycleDist);

        if(cross) {
            swap(firstX, secondX);
            swap(firstY, secondY);
        }
        cout << firstX << " " << firstY << endl << secondX << " " << secondY << endl;
    }
};

int main(void) {
    int numOfPoint, x, y, second;

    cin >> numOfPoint;

    Twocops twocops(numOfPoint);

    while(numOfPoint--) {
        cin >> x >> y;
        twocops.set_cops(x, y);
    }
    cin >> second;

    twocops.after_second(second);
}
