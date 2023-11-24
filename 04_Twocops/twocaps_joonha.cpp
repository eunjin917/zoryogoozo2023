#include<bits/stdc++.h>

using namespace std;

#define fs first
#define sc second
#define pb push_back
#define FOR(i,a,b)  for(int i=int(a); i<int(b); i++)
#define REP(i,b) FOR(i,0,b)

vector<pair<float, float>> v;
int ver_number, t, vn,loop_time;
int c1_dir,c2_dir, c1_scope,c2_scope;
pair<float,float>c1,c2;


void input(){     //input start
  cin>>ver_number;
  int v1,v2;
  REP(i,ver_number){
    cin >>v1 >> v2;
    v.pb(make_pair(v1,v2));
  }
  v.pb(make_pair(v[0].fs,v[0].sc));
  cin>>t;     //input end

  vn=(ver_number>>1)-1;
  REP(i,ver_number)    //calculation loop time
    loop_time+= abs( (v[i].fs-v[i+1].fs) + (v[i].sc - v[i+1].sc) );

  t = t % (loop_time);

  c1=v[0];
  c2=v[vn];
  c1_dir=1;
  c2_dir=-1;  // 1 is clockwise -1 is counterclockwise
  c1_scope=0;
  c2_scope=vn;
}

void patrol(float time){
  if(time==t){
    return;
  }

  if( v[c1_scope].sc == v[c1_scope+c1_dir].sc ){
    if(v[c1_scope].fs < v[c1_scope+c1_dir].fs)       c1.fs+=0.5;
    else if(v[c1_scope].fs > v[c1_scope+c1_dir].fs)  c1.fs-=0.5;
  }
  else if(v[c1_scope].fs == v[c1_scope+c1_dir].fs){
    if(v[c1_scope].sc < v[c1_scope+c1_dir].sc)       c1.sc+=0.5;
    else if(v[c1_scope].sc > v[c1_scope+c1_dir].sc)  c1.sc-=0.5;
  }

  if( v[c2_scope].sc == v[c2_scope+c2_dir].sc ){
    if(v[c2_scope].fs < v[c2_scope+c2_dir].fs)       c2.fs+=0.5;
    else if(v[c2_scope].fs > v[c2_scope+c2_dir].fs)  c2.fs-=0.5;
  }
  else if(v[c2_scope].fs == v[c2_scope+c2_dir].fs){
    if(v[c2_scope].sc < v[c2_scope+c2_dir].sc)       c2.sc+=0.5;
    else if(v[c2_scope].sc > v[c2_scope+c2_dir].sc)  c2.sc-=0.5;
  }

  if( c1 == v[c1_scope+c1_dir] )    c1_scope += c1_dir;
  if( c2 == v[c2_scope+c2_dir] )    c2_scope += c2_dir;

  if     (c1_dir== 1 && c1_scope == ver_number)   c1_scope = 0;
  else if(c1_dir==-1 && c1_scope ==0)             c1_scope = ver_number;
  if     (c2_dir== 1 && c2_scope == ver_number)   c2_scope = 0;
  else if(c2_dir==-1 && c2_scope ==0)             c2_scope = ver_number;

  if( c1 == c2 ){     //collision
    swap(c1_dir, c2_dir);
    swap(c1_scope, c2_scope);
  }


  return patrol(time+0.5);
}

int main(void){
  input();
  patrol(0);
  cout << c1.fs << " " << c1.sc << endl << c2.fs << " " << c2.sc << endl;

  return 0;
}
