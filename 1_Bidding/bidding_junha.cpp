#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool compare(pair<string,int>a,pair<string,int>b){

  return a.second>b.second;
}
int main(void){
  vector<pair<string,int>> v;
  int num;
  string PeopleName;
  int bid;
  cin>>num;
  for(int i=0;i<num;i++){
    cin>>PeopleName;
    cin>>bid;
    v.push_back(pair<string,int>(PeopleName,bid));
  }
  sort(begin(v),end(v),compare); //벡터 오름차순 정렬
  int n;
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v.size();j++){
      if(v[j].second!=v[j+1].second){
        n=j;
        break;
      }
    }
    if(n!=0){
      for(int j=0;j<n+1;j++){
        v.erase(v.begin());
      }
    }

  }
  #ifndef DEBUG
    cout<<v[0].first<<endl;
  #endif // DEBUG
  if(v[0].second == v[1].second) cout<<"None";
  else cout<<v[0].first;
  return 0;
}
