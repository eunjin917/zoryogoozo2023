#include<bits//stdc++.h>

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

using namespace std;

struct mafia{
    int depth=0, num_of_member=0;
    string name;
    list<string> member;
};
int N,idx;
vector<int> ranking;
string Person, Boss;
vector<string> pb,people;
vector<vector<string>> data, organ;

void setNumofMember(mafia *gang,string str, int n){
  REP(i,N){
    if(str == organ[i][0]){
      FOR(j,1,organ[i].size())        setNumofMember(gang, organ[i][j], n);
      gang[n].num_of_member++;
      return;
    }
  }
}
void setdepth(mafia *gang, string str, int n){
  REP(i,N){
    if(str == gang[i].name){
      gang[i].depth = n+1;
      n++;
      for(auto it=gang[i].member.begin();it!=gang[i].member.end();it++) setdepth(gang,*it,n);
      return;
    }
  }
}
void determineRanking(mafia *gang){
  REP(i,N){
    gang[i].name = organ[i][0];
    FOR(j,1,organ[i].size())      setNumofMember(gang, organ[i][j], i);

    if(gang[i].num_of_member == N-1){      gang[i].depth++; idx = i;}

  }
  REP(i,N){
    if(gang[i].depth){
      for(auto it=gang[i].member.begin();it!=gang[i].member.end();it++)
        setdepth(gang,*it,1);
      break;
    }
  }

  REP(i,N) ranking.push_back(i);
  REP(i,N){
    FOR(j,i,N){
      int r = ranking[j];
      if(gang[ranking[j]].num_of_member > gang[ranking[i]].num_of_member){
        ranking.erase(ranking.begin()+j);
        ranking.insert(ranking.begin()+i,r);
      }
      else if(gang[ranking[j]].num_of_member == gang[ranking[i]].num_of_member){
        if(gang[ranking[j]].depth < gang[ranking[i]].depth){
          ranking.erase(ranking.begin()+j);
          ranking.insert(ranking.begin()+i,r);
        }
      }
    }
  }
}
int main(void){
  //input
  cin >> N;
  mafia gang[N];
  REP(i,N-1){
    cin>>Person >> Boss;
    pb.push_back(Person);
    people.push_back(Person);
    organ.push_back(pb);
    pb.push_back(Boss);
    data.push_back(pb);
    pb.clear();
  }//input end

  //init
  REP(i,data.size()){
    auto it = find(people.begin(),people.end(),data[i][1]);
    if(it == people.end()){
      people.push_back(data[i][1]);
      pb.push_back(data[i][1]);
      break;
    }
  }
  organ.push_back(pb);
  sort(organ.begin(),organ.end());
  REP(i,organ.size()){
    REP(j,data.size()){
      if(organ[i][0] == data[j][1]){
        organ[i].push_back(data[j][0]);
        gang[i].member.push_back(data[j][0]);
      }
    }
  }

  determineRanking(gang);

  //output
  REP(i,N)    cout<<gang[ranking[i]].name<<endl;

}
