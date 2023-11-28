#include<bits//stdc++.h>

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

using namespace std;

bool mybool(int i,int j){return i>j;}
void myprint(int i){
  if(i)  cout<< i << endl;
}

int N, K, p;
stack<int> cost,rcost;
stack<int> num, rnum;
vector<int> v;
vector< vector<int> > maxvalue;

void input(){
  cin >> N >> K;
  REP(i,N){
    cin >> p;
    cost.push(p);
    num.push(0);
  }//input end
}
void output(){
  int sz = maxvalue.size();
  if(!sz){
    cout << "0" ;
    return ;
  }
  REP(i,sz)  sort(maxvalue[i].begin(),maxvalue[i].end(),mybool);
  sort(maxvalue.begin(),maxvalue.end());

  for_each(maxvalue[sz-1].rbegin(),maxvalue[sz-1].rend(),myprint);
}
void searchValue(){
  int sum = 0;
  while(!num.empty()){
    rcost.push(cost.top());
    rnum.push(num.top());
    sum += num.top() * cost.top();
    cost.pop();
    num.pop();
  }
  while(!rnum.empty()){
    num.push(rnum.top());
    cost.push(rcost.top());
    if(sum == K)  v.push_back(num.top() * cost.top());
    rcost.pop();
    rnum.pop();
  }
  if(sum == K){
    maxvalue.push_back(v);
    v.clear();
  }
}
void findNum(){
  while(true){//increase 1
    num.top()++;
    if(num.top() == 2){
      num.pop();
      if(num.empty())   return;
      findNum();
      num.push(0);
    }
    if(num.size() < N)  return;
    searchValue();
  }

}
int main(void){
  input();
  findNum();
  output();
  return 0;
}
