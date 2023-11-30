#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct guest{
    int arrive, id, c_time;
};

struct cmp{
    bool operator()(const guest& g1, const guest& g2){
        if(g1.c_time == g2.c_time) return g1.arrive > g2.arrive;
        return g1.c_time < g2.c_time;
    }
};

queue<guest> member;
priority_queue<guest, vector<guest>, cmp> Room;

int counseling(int time){
    guest client = Room.top();
    Room.pop();
    if(client.c_time <= 10){
        cout << client.id << endl;
        return time + client.c_time;
    }
    else {
        time += client.c_time/2;
        Room.push({time, client.id, client.c_time - client.c_time/2});
        return time;
    }
}

int main(){
    int N, ti, id, ci, t = 30;
    
    cin >> N;
    while(cin >> ti >> id >> ci) member.push({ti, id, ci});

    while(!member.empty() || !Room.empty()){
        while(!member.empty() && member.front().arrive <= t) {
            Room.push(member.front());
            member.pop();
        }
        if(Room.empty()){
            t = member.front().arrive;
            Room.push(member.front());
            member.pop();
        }

        t = counseling(t);
    }

    return 0;
}
