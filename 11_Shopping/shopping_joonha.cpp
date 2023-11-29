#include<bits//stdc++.h>

#define pb push_back
#define fs first
#define sc second
#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define show(x) for(auto w:x) cout << w << endl;

using namespace std;

int N, k;
int id ,n;
list< pair<int,int> > customer, checkout;
list< pair<int,int> >::iterator it[10];
vector<int> succes;

void input(){
  cin >> N >> k;
  if(k>N) k=N;
  REP(i,N){
    cin >> id >> n;
    customer.pb(make_pair(id,n));
  }
  REP(i,k){ //init
    it[i] = customer.begin();
    customer.splice(checkout.begin(),customer,it[i]);
  }
}
void counter(){
  while(succes.size() != N){
    REP(i,k)    it[i] -> sc --;
    for(int i=k-1;i>=0; i--){ //customer close to the exit leave first
      if(!it[i]->sc)    succes.pb(it[i]->fs);
    }
    REP(i,k){   // first come customer enter close to number 1
      if(!it[i]->sc){   //pay complete
        if(!customer.begin()->sc){    //no waiting customer
          for(int j=i;j<k-1;j++)    it[j] = it[j+1];
          k--;
        }
        else{
          it[i] = customer.begin();
          customer.splice(checkout.begin(),customer,it[i]);
        }
      }
    }
  }
}

int main(void){
  input();
  counter();
  show(succes);
}
