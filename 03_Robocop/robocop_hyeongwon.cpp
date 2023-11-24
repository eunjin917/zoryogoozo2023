#include <iostream>
#include <vector>

using namespace std;

class Robocop {
private:
    vector<pair<int,int>> pointComb;
    vector<int> distComb;
    int maxPoint;
    int numOfPoint = 0;
    int oneCycleDist = 0;
public:
    Robocop(int maxPoint) : maxPoint(maxPoint) {}

    void set_robocop(int xpoint, int ypoint) {
        auto point = make_pair(xpoint, ypoint);
        pointComb.push_back(point);
        numOfPoint++;
        if(numOfPoint == maxPoint) {
            for(int i = 0; i < maxPoint; i++){
                oneCycleDist += abs(pointComb[(i+1)%maxPoint].first - pointComb[i].first + pointComb[(i+1)%maxPoint].second - pointComb[i].second);
                distComb.push_back(oneCycleDist);
            }
        }
    }

    void second_after_where(int second) {
        int xstart, ystart, index;
        int realSec = second % oneCycleDist;
        for(int i = 0; i < maxPoint; i++) {
            if(realSec < distComb[i]) {
                index = i;
                break;
            }
        }
        realSec -= distComb[index++];
        xstart = pointComb[index%maxPoint].first;
        ystart = pointComb[(index--)%maxPoint].second;
        if(xstart == pointComb[index].first) {
            if(ystart > pointComb[index].second) ystart += realSec;
            else ystart -= realSec;
        }
        else {
            if(xstart > pointComb[index].first) xstart += realSec;
            else xstart -= realSec;
        }
        cout << xstart <<" " << ystart << endl;
    }
};


int main(void) {
    int numOfPoint, xpoint, ypoint, second;

    cin >> numOfPoint;
    Robocop Robo(numOfPoint);

    for(int i = 0; i < numOfPoint; i++) {
        cin >> xpoint >> ypoint;
        Robo.set_robocop(xpoint, ypoint);
    }

    for(int j = 0; j < 5; j++) {
        cin >> second;
        Robo.second_after_where(second);
    }
}
