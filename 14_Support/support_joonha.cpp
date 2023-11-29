#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct compare{
  bool operator()(tuple<int,int,int> u, tuple<int,int,int> v){
    return make_tuple( get<2>(u), -get<0>(u) ) < make_tuple( get<2>(v), -get<0>(v) );
  }
};
           //arrive time, ID. counseling time
priority_queue< tuple<int,int,int>, deque< tuple<int,int,int> >,compare > Room;

int main(){
  int N = 5;
  int t = 30;
  int enter, customId, counseling;
  vector<int> input;
  deque<vector<int> > data;

  cin>>N;
  for(int i=0; i<N; i++){
    cin>>enter >> customId >> counseling;
    input = {enter, customId, counseling};
    data.push_back(input);
  }

  for(t; !Room.empty()||!data.empty(); t++){
    for(auto w:data){
      if(t > w[0]){
        Room.push(make_tuple(w[0],w[1],w[2]));
        data.pop_front();
      }
    }
    if(Room.empty())  continue;
    int time = get<2>(Room.top());
    if( time <= 10 ){ //remaining time is 10 minutes -> complete
      cout<<get<1>(Room.top())<<endl;
      Room.pop();
      t += time-1;
      continue;
    }
    auto c = Room.top();
    Room.pop();
    Room.push( make_tuple(t+time/2, get<1>(c), time-time/2) );
    t += time-time/2 -1;

  }

}

