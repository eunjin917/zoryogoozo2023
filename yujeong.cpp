#include <iostream>
#include <vector>
#include <array>

using namespace std;

#define rep(i, N) for (int i = 0; i < (int)(N); i++)

int num;
vector<int> segmentX, segmentY;
array<int, 5> seconds;
int robotX, robotY;
vector<int> routeX, routeY;

void input();
void calculateRoute();
void output();
void recordRoutePoint();
void moveNextPoint(int startPointIndex, int endPointIndex);

int main() {
    input();
    calculateRoute();
    output();
    return 0;
}

void input() {
    cin >> num;

    int a, b;
    rep(i, num) {
        cin >> a >> b;
        segmentX.push_back(a);
        segmentY.push_back(b);
    }

    rep(i, 5) {
        cin >> seconds[i];
    }
}

void calculateRoute() {
    rep(i, num + 1) {
        if (i == 0) {
            robotX = segmentX[i];
            robotY = segmentY[i];
            recordRoutePoint();
            continue;
        }
        if (i == num) {
            moveNextPoint(num - 1, 0);
            break;
        }
        moveNextPoint(i - 1, i);
    }
}

void recordRoutePoint() {
    routeX.push_back(robotX);
    routeY.push_back(robotY);
}

void moveNextPoint(int startPointIndex, int endPointIndex) {
    while (robotX != segmentX[endPointIndex] || robotY != segmentY[endPointIndex]) {
        if (segmentX[endPointIndex] - segmentX[startPointIndex] > 0) {
            robotX++;
            recordRoutePoint();
            continue;
        }
        if (segmentX[endPointIndex] - segmentX[startPointIndex] < 0) {
            robotX--;
            recordRoutePoint();
            continue;
        }
        if (segmentY[endPointIndex] - segmentY[startPointIndex] > 0) {
            robotY++;
            recordRoutePoint();
            continue;
        }
        if (segmentY[endPointIndex] - segmentY[startPointIndex] < 0) {
            robotY--;
            recordRoutePoint();
            continue;
        }
    }
}

void output() {
    size_t lapCount = routeX.size() - 1;
    rep(i, 5) {
        cout << routeX[seconds[i] % lapCount] << " " << routeY[seconds[i] % lapCount] << endl;
    }
}

