#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)

using namespace std;

int N, vsz;
int min_sz, min_idx;
int max_sz;
int ton,ton_num;
stack<int> yard;
vector <int> ysz; //yard size
vector <int> max_idx;
vector< stack<int> > v;

void input(){
  cin >> N;
  REP(i,N){
    cin >> ton_num;
    REP(j,ton_num){
      cin >> ton;
      yard.push(ton);
    }
    v.push_back(yard);
    yard = stack<int> ();  //clear y
  }
  //input end
}
void output(){
  //v's all element show
  REP(i,N){
    vsz = v[i].size();
    if(vsz == 0 ) cout<<'0';
    REP( j, vsz ){
      yard.push( v[i].top() );
      v[i].pop();
    }
    REP( j, vsz ){
      cout << yard.top() <<" ";
      yard.pop();
    }
    cout<<endl;
  }
}
void searchSpace(){
  //search move space
  ysz.clear();
  REP(i,N){
    ysz.push_back( v[i].size() );
  }
  min_sz = *min_element(ysz.begin(), ysz.end());
  REP(i,N){
    if(ysz[i] == min_sz){
      min_idx = i;
      break;
    }
  }
  max_sz = *max_element(ysz.begin(), ysz.end());
  max_idx.clear();
  REP(i,N){
    if(ysz[i] == max_sz)  max_idx.push_back(i);
  }
  REP(i,max_idx.size()){
    if( v[max_idx[0]].top() < v[max_idx[i]].top() ) swap(max_idx[0],max_idx[i]);
  }
}
void shippingYard(){
  //big to small
  searchSpace();
  while( max_sz - min_sz > 1){
    v[min_idx].push( v[max_idx[0]].top() );
    v[max_idx[0]].pop();
    searchSpace();
  }
}
int main(void){

  input();
  shippingYard();
  output();

  return 0;
}
