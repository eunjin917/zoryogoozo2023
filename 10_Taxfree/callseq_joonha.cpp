#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i = int(a); i < int(b); i++)
#define REP(i,b) FOR(i,0,b)
#define show_none cout<<"NONE"<<endl

using namespace std;

int N, k1, k2, idx=0, s, isdeadlock=0;
string func, searchvalue;
vector< vector<string> > declare;
vector<string> func_name, fun, vdeadlock;
stack<string> process;
stack<int> space;

void searchFuncSpace(){
  searchvalue = process.top();
  REP(i,N){
    if(func_name[i] == searchvalue)  space.push(i);
  }
  s = space.top();
}
void callseq(){
  searchFuncSpace();
  REP(i, declare[s].size()){
    if( isupper( declare[s][i].at(0) ) ){
      process.push(declare[s][i]);
      vdeadlock.push_back(process.top());
      if( count(vdeadlock.begin(), vdeadlock.end()-1, vdeadlock.back()) ){
        isdeadlock = 1;
        return;
      }
      callseq();
    }
    else{
      idx++;
      fun.push_back( process.top() + "-" + declare[s][i] ); //F-act
    }
    if(isdeadlock)  return;
  }
  space.pop();
  if(!space.empty())  s = space.top();
  process.pop();
  vdeadlock.pop_back();
}
int main(){
  //input
  cin >> N >> k1 >> k2;
  REP(i,N){
    int state = 1;
    cin >> func;
    while(func != "$"){
      if(state){
        func_name.push_back(func);
        state = 0;
      }
      else fun.push_back(func);
      cin >> func;
    }
    declare.push_back(fun);
    fun.clear();
  } //input end

  //init
  process.push("M");
  vdeadlock.push_back("M");

  callseq();
  if(k1>0)  k1--;
  while(k1<0)    k1 += idx;

  if(k2>0) k2--;
  while(k2<0)    k2 += idx;

  //output
  if(isdeadlock)    cout << "DEADLOCK";
  else{
    if(k1 >= idx)  show_none;
    else           cout << fun[k1] << endl;
    if(k2 >= idx)  show_none;
    else           cout << fun[k2];
  }
}
