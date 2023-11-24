#include <bits/stdc++.h>
using namespace std;

struct Pos{
  int x,y;
};

int main(void){
  int num=1;
  int Mx,My=0;
  int dx,dy,Dx=0;
  int xpos,ypos;
  int vsz;
  vector<int> v;
  int j=0;
  Pos pos[15];

  for(int i=0;num;i++){
    cin>>num;
    v.push_back(num);
    if(i%2==0){
      Mx+=num;
    }
    if(i%2==1){
      My+=num;
    }
  }
  vsz=v.size()-2;

  while(cin>>xpos){
    cin>>ypos;
    pos[j].x=xpos;
    pos[j].y=ypos;
    j++;
  }
  for (int k=0;k<j;k++){
    dx=0;
    dy=My;
    Dx=0;
    if(pos[k].x>Mx){
        cout<<"out"<<endl;
        continue;
    }
    for(int i=0;i<vsz;i=i+2){
      Dx+=v[0+i];
      if(pos[k].x<Dx&&pos[k].x>dx){
        if(pos[k].y<dy){
          cout<<"in"<<endl;
        }
        else if(pos[k].y==dy){
          cout<<"on"<<endl;
        }
        else{
          cout<<"out"<<endl;
        }
      }
      else if(pos[k].x==Dx){
        if(pos[k].y<=dy && pos[k].y>=dy-(v[i+1])){
          cout<<"on"<<endl;
        }
        else if(pos[k].y<dy-(v[i+1])){
          cout<<"in"<<endl;
        }
        else{
          cout<<"out"<<endl;
        }
      }
      dx+=v[i];
      dy-=v[i+1];
    }
  }

  return 0;
}
