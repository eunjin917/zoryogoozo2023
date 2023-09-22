#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define rep(i, N) for (int i = 0; i < (int)(N); i++)

int N, t;
vector<int> x, y;
int px, py;
vector<int> rx, ry;
int c1, c2;

void input() {
    cin >> N;
    x.resize(N);
    y.resize(N);
    rep(i, N) {
        cin >> x[i] >> y[i];
    }
    cin >> t;
}

void pushBack() {
    rx.push_back(px);
    ry.push_back(py);
}

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void moveToNext(int a, int b) {
    // 두 점 사이의 거리를 계산
    double dist = distance(x[a], y[a], x[b], y[b]);
    // dx, dy는 이동 방향 벡터
    int dx = (x[b] - x[a]) / dist;
    int dy = (y[b] - y[a]) / dist;
    
    while (px != x[b] || py != y[b]) {
        px += dx;
        py += dy;
        pushBack();
    }
}

void boundary() {
    rep(i, N + 1) {
        // c2
        if (px == x[N / 2 - 1] && py == y[N / 2 - 1]) {
            c1 = 0;
            c2 = rx.size() - 1;
        }
        if (i == 0) {
            px = x[i];
            py = y[i];
            pushBack();
        } else if (i == N) {
            moveToNext(N - 1, 0);
            break;
        }
        moveToNext(i - 1, i);
    }
}

void move() {
    int moving = 1;
    int lap = rx.size() - 1; // 전체 경로 수 (주기 계산)
    
    rep(i, t) {
        c1 += moving;
        c2 -= moving;
        // 주기에 다다르면 시작점으로 초기화
        if (c1 == lap) c1 = 0;
        if (c2 == lap) c2 = 0;
        if (c1 == -1) c1 = lap - 1;
        if (c2 == -1) c2 = lap - 1;
        // 충돌 후
        if (c1 == c2 || abs(c1 - c2) == 1) {
            moving = -moving;
            // 1칸 간격으로 마주할 때
            if (abs(c1 - c2) == 1) i++;
        }
    }
}

void output() {
    cout << rx[c1] << " " << ry[c1] << endl;
    cout << rx[c2] << " " << ry[c2] << endl;
}

int main() {
    input();
    boundary();
    move();
    output();
    return 0;
}

