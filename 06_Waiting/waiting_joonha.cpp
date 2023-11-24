#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i = int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define pb push_back
#define vbetoend  v.end() - v.begin()

using namespace std;

int N, k, transaction, space;
char s;
vector<char> sign;
vector<int> trans, init;
vector< vector<int> > v;

void input(){
  cin >> N >> k;
  REP(i,N){
    cin >> s >> transaction;
    sign.pb(s);
    trans.pb(transaction);
  }
  init.pb(trans[0]);
  v.pb(init);
}
void output(){
  REP(i, v.end() - v.begin() )    cout << v[i][0] << endl;
}
int select(int index){
  if(v.size() != 0){
    for(int i = vbetoend-1; i >= 0; i-- ){
      if( v[i][0] < trans[index] )  return i;
    }
  }
  return 0;
}
void waiting(){
  FOR(i,1,N){

    if( sign[i] == '+'){  // case : transaction > 0
      //select space
      space = select(i);
      //insert
      if(v.size() != 0)   v[space].pb(trans[i]);
      else{
        init.clear();
        init.pb(trans[i]);
        v.pb(init);
      }
      //sort
      sort( v[space].begin(), v[space].end() );
      //if size is 2k division
      if( v[space].size() == 2 * k ){
        init.clear();
        init.assign(v[space].begin() + k, v[space].end());
        v.insert( v.begin() + space + 1, init );
        v[space].erase( v[space].begin() + k, v[space].end() );
      }
    }
    else{   // case : transaction < 0
      REP(j,vbetoend){
        //find num
        if( count( v[j].begin(), v[j].end(), trans[i] ) == 1 ){
          auto it2 = find( v[j].begin(), v[j].end(), trans[i] );
          //erase num
          v[j].erase( it2 );
          break;
        }
      }
      //if size is 0 delete
      REP(j,vbetoend){
        if( v[j].size() == 0 )
          v.erase( v.begin() + j );
      }
    }
  }
}


int main(void){

  input();
  waiting();
  output();

  return 0;
}
