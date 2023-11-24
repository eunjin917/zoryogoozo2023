#include<bits/stdc++.h>

#define FOR(i,a,b) for(int i = int(a); i<int(b); i++)
#define REP(i,b) FOR(i,0,b)
#define pb push_back
#define mt make_tuple

using namespace std;

int N,info;
int ci,ei;
vector < tuple<int,int> > c, fx;


bool mybool(const tuple<int,int> &u, const tuple<int,int> &w ){
    return -get<1>(u) < -get<1>(w);
}

void input(){
    cin >> N;
    REP(i,N){
        cin >> info;
        REP(j,info){
            cin >> ci >> ei;
            c.pb( mt(ci, ei) );
        }
    }
    sort(c.begin(), c.end(), mybool);
}
void output(){
    if(fx.size() != 0){
        cout << fx.size() << endl;
        REP(i,fx.size()){
            cout << get<0>(fx[i]) << " " << get<1>(fx[i]) << endl;
        }
    }
    else{
        cout<<"0 0";
    }
}
void calculation(){
    REP(i,c.size()-1){
        if( get<1>(c[i]) == get<1>(c[i+1]) ){
            get<0>(c[i]) = get<0>(c[i]) + get<0>(c[i+1]) ;
            c.erase(c.begin()+i+1);
            if(get<0>(c[i]) == 0){
                c.erase(c.begin()+i);
            }
            i--;
        }
    }
    if(c.size() == 2){
        if( (get<1>(c[0]) == get<1>(c[1])) && get<0>(c[0]) == -1 * get<0>(c[1]) ){
            fx.pb( mt(0, 0) );
        }
    }
       fx.assign( c.begin(), c.end() );
}

int main(void){
    input();
    calculation();
    output();
    return 0;
}
