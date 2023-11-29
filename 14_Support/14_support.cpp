#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll tmk = 30;
struct Guest{
    ll avtime, id, time;
    Guest(): avtime(0), id(0), time(0) {}
    Guest(ll a, ll b, ll c): avtime(a), id(b), time(c) {}
    bool operator<(const Guest other) const{
        if (time == other.time){
            return avtime > other.avtime;
        }
        return time < other.time;
    }
};
priority_queue<Guest> Room;
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    vector<Guest> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i].avtime >> p[i].id >> p[i].time;
    }
    ll idx = 0, cnt = 0, back = 1;//0 -> prior이 저장, 1 -> 나감
    Guest prior;
    while (cnt < n || !Room.empty()){
        while (idx < n && p[idx].avtime <= tmk){
            Room.emplace(p[idx++]);
        }
        if (Room.empty()){
            if (!back) {
                Room.emplace(prior); back = 1;
            }
            else {
                Room.emplace(p[idx++]);
                tmk = Room.top().avtime;
            }
        }
        Guest pl = Room.top(); Room.pop();
        if (!back){
            Room.emplace(prior);
        }
        if (pl.time <= 10){
            tmk += pl.time; back = 1;
            cout << pl.id << "\n"; cnt++;
        }
        else{
            tmk += pl.time / 2; pl.time -= pl.time / 2; back = 0;
            pl.avtime = tmk;
            prior = pl;
        }
    }
    return 0;
}
