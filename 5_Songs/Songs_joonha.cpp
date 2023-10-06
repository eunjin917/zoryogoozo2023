#include<bits//stdc++.h>

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define mt make_tuple

using namespace std;

int N,k;
string title;
char genre;
int broadcast;
double file_size;
int download;
int index;
array<tuple<string,char,int,double,int>,100> arr, com_arr;

bool mybool(const tuple<string,char,int,double,int> &u, const tuple<string,char,int,double,int> &w){
  return mt(-get<2>(u), -get<4>(u), get<3>(u)) < mt(-get<2>(w), -get<4>(w), get<3>(w));
}

void input(){
  cin>>N>>k;

  REP(i,N){
    cin >> title >> genre >> broadcast >> file_size >> download;
    arr[i] = (mt(title,genre,broadcast,file_size,download));
  }
}
void sorting(){
  sort(arr.begin(),arr.end(),mybool);

  REP(j,N-1){
    REP(i,N-1){
      if(get<1>(arr.at(i)) == get<1>(arr.at(i+1))){
        swap(arr.at(i+1),arr.at(i+2));
      }
      else{
        index=i+2;
      }
    }
    if(com_arr == arr)  break;
    sort(arr.begin()+index,arr.end(),mybool);
    com_arr=arr;
  }

}

int main(void){
  input();
  sorting();
  cout << get<0>(arr[k-1]);
  return 0;
}
