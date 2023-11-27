#include <bits/stdc++.h>

using namespace std;

struct Guest {
    int arrivedTime, id, interviewTime;
};

struct cmp {
    bool operator()(Guest a, Guest b) {
        if(a.interviewTime != b.interviewTime)
            return a.interviewTime < b.interviewTime;
        else
            return a.arrivedTime > b.arrivedTime;
    }
};

int Start = 30;
priority_queue<Guest, vector<Guest>, cmp> Room;

void OneInterviewed() {
    if(Room.top().interviewTime <= 10) {
        Start += Room.top().interviewTime;
        cout << Room.top().id << endl;
    }
    else {
        int didInterview = Room.top().interviewTime / 2;
        Start += didInterview;
        Guest afterInterview = {Start, Room.top().id, Room.top().interviewTime - didInterview};
        Room.push(afterInterview);
    }
    Room.pop();
}

int main() {
    int N, arrived, id, interview;
    cin >> N;

    while(N-- > 0) {
        cin >> arrived >> id >> interview;
        while(arrived > Start) {
            if(Room.empty()) break;
            OneInterviewed();
        }

        if(Room.empty() && arrived > Start)
            Start = arrived;

        Room.push({arrived, id, interview});

    }

    while(!Room.empty()) {
        OneInterviewed();
    }
}
