#include <bits/stdc++.h>
using namespace std;

class MInfo {
public:
    string name;   // 구성원 이름
    string boss;   // 상사 이름
    list<MInfo>::iterator bossPtr; // 상사 포인터
    int depth;     // 깊이
    int children;  // 자식 수

    MInfo() : depth(0), children(0) {}
};

int N;
list<MInfo> mList;

// 구성원 입력
void Input() {
    cin >> N;
    MInfo tmp;
    for (int i = 1; i < N; i++) {
        cin >> tmp.name >> tmp.boss;
        mList.push_back(tmp);
    }
}

// 조직 트리 생성
void BuildTree() {
    for (auto &m : mList) {
        if (m.boss == "NULL") continue;

        m.bossPtr = mList.begin();
        for (const auto &b : mList) {
            if (b.name == m.boss) break;
            m.bossPtr++;
        }

        if (m.bossPtr == mList.end()) {
            MInfo root;
            root.boss = "NULL";
            root.name = m.boss;
            mList.push_back(root);
            m.bossPtr--;
        }
    }
}

// 정렬 함수
bool Compare(MInfo m1, MInfo m2) {
    if (m1.children == m2.children) {
        if (m1.depth == m2.depth) return m1.name < m2.name;
        return m1.depth < m2.depth;
    }
    return m1.children > m2.children;
}

// 깊이 설정
void SetDepth() {
    for (auto &m : mList) {
        int d = 0;
        auto p = m;
        while (p.boss != "NULL") {
            p = *p.bossPtr;
            d++;
        }
        m.depth = d;
    }
}

// 자식 수 설정
void SetChildren() {
    for (const auto &m : mList) {
        auto p = m;
        while (p.boss != "NULL") {
            auto &b = *p.bossPtr;
            b.children++;
            p = b;
        }
    }
}

// 결과 출력
void Output() {
    for (const auto &m : mList)
        cout << m.name << endl;
}

int main() {
    Input();
    BuildTree();
    SetDepth();
    SetChildren();
    mList.sort(Compare);
    Output();
    return 0;
}
