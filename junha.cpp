#include<iostream>
#include<vector>
#include<cstdlib>   //for int abs

using namespace std;

#define fs  first
#define sc  second
#define FOR(i, a, b) for (int i=int(a); i<int(b); i++)
#define dot 5
vector <pair<int,int>> v;
int ver_number;
int t[dot];
int loop_time=0;

struct Spatium{
  int x;
  int y;
};
Spatium spatium[dot];

void input(){
  int v1,v2;
  cin>>ver_number;
   FOR(i,0,ver_number){
    cin >>v1 >> v2;
    v.push_back(pair<int,int> (v1,v2));
  }
  v.push_back(pair<int,int>(v[0].fs,v[0].sc));
  FOR(i,0,dot){
    cin>>t[i];
  }

  FOR(i,0,ver_number){    //loop time ?
    if(v[i].fs==v[i+1].fs){
      loop_time+=abs(v[i].sc - v[i+1].sc);
    }
    else if(v[i].sc == v[i+1].sc ){
      loop_time+=abs(v[i].fs - v[i+1].fs);
    }
  }
}
void output(){
  FOR(i,0,dot)
  cout<<spatium[i].x<<" "<<spatium[i].y<<endl;
}
void currentLocation(){
  FOR(j,0,dot){
    int scope=0;
    spatium[j].x=v[0].fs;
    spatium[j].y=v[0].sc;

    FOR(i,0,t[j]%loop_time){
      if(spatium[j].x==v[scope+1].fs && spatium[j].y==v[scope+1].sc){
          scope++;
      }
      if(scope == (ver_number) ){
            scope=0;
      }

      if(v[scope].fs == v[scope+1].fs ){         // x same
        if(v[scope].sc < v[scope+1].sc)       spatium[j].y++;  //y small
        else if(v[scope].sc > v[scope+1].sc)  spatium[j].y--;  //y big
      }
      else if(v[scope].sc == v[scope+1].sc){   // y same
        if(v[scope].fs < v[scope+1].fs)       spatium[j].x++;  //x small
        else if(v[scope].fs > v[scope+1].fs)  spatium[j].x--;  //x big
      }
    }

  }
}

int main(void){

  input();
  currentLocation();
  output();

  return 0;
}
