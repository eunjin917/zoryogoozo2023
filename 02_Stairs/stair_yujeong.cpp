#include <iostream>
#include <vector>
using namespace std;

// 수평, 수직 선분의 구조체
struct Segment {
    int horizontal;
    int vertical;
};

string pointLocation(const vector<Segment>& segments, int pointX, int pointY) {
    int x = 0; // 시작점의 x 좌표
    int y = 0; // 시작점의 y 좌표
    int n = segments.size();

    // 시작점의 y 좌표를 수직 선분 길이의 합으로 설정
    for (const auto& segment : segments) {
        y += segment.vertical;
    }
    
    for (int i = 0; i < 2 * n ; i++) {
        int horizontal = segments[i / 2].horizontal;
        int vertical = segments[i / 2].vertical;
        
        if (i % 2 == 0) {
            // 수평 선분일 경우 (짝수 인덱스)
            if (pointX >= x && pointX <= x + horizontal && pointY == y) return "on";
            else if (pointX >= x && pointX < x + horizontal && pointY < y) return "in";
            else if (pointX > x && pointX <= x + horizontal && pointY > y) return "out";
            
            x += horizontal;
        } else {
            // 수직 선분일 경우 (홀수 인덱스)
            if (pointY >= y - vertical && pointY <= y && pointX == x) return "on";
            else if (pointY >= y - vertical && pointY < y && pointX < x) return "in";
            else if (pointY > y - vertical && pointY <= y && pointX > x) return "out";
            
            y -= vertical;
        }
    }
    return "out";
}

int main() {
    vector<Segment> segments;
    int num;

    // 선분 길이 입력
    while (cin >> num) {
        if (num == 0) break;

        Segment segment;
        segment.horizontal = num;
        cin >> segment.vertical;
        segments.push_back(segment);
    }

    vector<pair<int, int>> points;

    // 질문 점 입력
    while (cin >> num) {
        if (cin.eof()) break;

        int X, Y;
        X = num;
        cin >> Y;
        points.push_back({X, Y});
    }

    for (const auto& point : points) {
        int pointX = point.first;
        int pointY = point.second;

        string location = pointLocation(segments, pointX, pointY);
        cout << location << endl;
    }

    return 0;
}
