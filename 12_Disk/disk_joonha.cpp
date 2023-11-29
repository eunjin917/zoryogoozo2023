//score: 73... (T_T)

#include<bits//stdc++.h>

#define error cout<<"error"<<endl; return

using namespace std;

int V, disk_sz=0;
list<string> disk;
string oper_in;       //for input
deque<string> oper_v; //for input
deque< deque<string> > operation;
list< pair<string,int> > file_table;

void searchSpace(int &n1, int &n2){ //free space search
  auto it1=disk.begin(),it2=disk.begin();
  n1 = n2;
  advance(it1,n1);
  while(*it1 != ""){
    it1++;
    n1++;
  }
  n2 = n1;
  advance(it2,n2);
  while(*it2 == "" && it2 != disk.end()){
    it2++;
    n2++;
  }
}
void Write(string fa, int sa){
  if(V - disk_sz < sa){
    cout<<"diskfull"<<endl;
    return;
  }
  auto myfunc = [fa](pair<string,int>const &v) {return v.first == fa;};
  auto it = find_if(file_table.begin(), file_table.end(), myfunc);
  if(it != file_table.end())   error;

  auto it1=disk.begin(),it2=disk.begin();
  int n1=0,n2=0;
  while(n2 < V){
    searchSpace(n1, n2);
    if(n2-n1 >= sa) break;
  }
  if(n2-n1 >= sa){  //chunk is 1
    advance(it1,n1);
    advance(it2,n1+sa);
    disk.erase(it1,it2);
    disk.insert(it2, sa, fa);
    file_table.push_back(make_pair(fa,n1));
  }
  else{ //slice file
    while(sa){
      int n1=0,n2=0;
      it1=disk.begin();
      it2=disk.begin();
      searchSpace(n1, n2);
      advance(it1,n1);
      if(sa > n2-n1){
        advance(it2,n2);
        disk.erase(it1,it2);
        disk.insert(it2, n2-n1, fa);
        sa -= n2-n1;
      }
      else{
        advance(it2,n1+sa);
        disk.erase(it1,it2);
        disk.insert(it2, sa, fa);
        sa = 0;
      }
      file_table.push_back(make_pair(fa,n1));
    }
  }
  disk_sz += sa;
}
void Show(string fa){
  auto myfunc = [fa](pair<string,int>const &v) {return v.first == fa;};
  auto it = find_if(file_table.begin(), file_table.end(), myfunc);
  if(it == file_table.end())  error;

  while(it != file_table.end()){
    cout << it->second <<" ";
    auto it1 = it;
    it1++;
    it = find_if(it1, file_table.end(), myfunc);
  }
  cout<<endl;
}
void Delete(string fa){
  auto myfunc = [fa](pair<string,int>const &v){return v.first == fa;};
  auto it = find_if(file_table.begin(), file_table.end(), myfunc);
  if(it == file_table.end())  error;

  int sa = 0;
  while(it != file_table.end()){
    int n1 = it->second;
    auto it1=disk.begin(),it2=disk.begin();
    advance(it1,n1);
    file_table.erase(it);
    while(*it1 == fa){
      disk.insert(it1,"");
      disk.erase(it1);
      sa++;
      it1=disk.begin();
      it2=disk.begin();
      n1++;
      advance(it1,n1);
    }
    it = find_if(file_table.begin(), file_table.end(), myfunc);
  }
  disk_sz -= sa;
}
void Compact(){
  int n1=0,n2=0;
  while(n2!=V){ //compact
    searchSpace(n1, n2);
    auto it1=disk.begin(),it2=disk.begin();
    advance(it1,n1);
    advance(it2,n2);
    disk.splice(disk.end(),disk,it1,it2);
  }
  //table redefinition
  file_table.clear();
  n1=0,n2=0;
  auto it1=disk.begin(),it2=disk.begin();
  while(it2 != disk.end()){
    while(*it1 == *it2 && n2<V){
      it2++;
      n2++;
    }
    file_table.push_back(make_pair(*it1,n1));
    it1 = it2;
    n1=n2;
  }
}
int main(void){
  //input
  cin >> V;
  while(oper_in != "end"){
    cin >> oper_in;
    switch(oper_in[0])
    {
    case 'w':
      oper_v.push_back(oper_in); cin>>oper_in;
    case 's':
    case 'd':
      oper_v.push_back(oper_in); cin>>oper_in;
      break;
    }
    oper_v.push_back(oper_in);
    operation.push_back(oper_v);
    oper_v.clear();
  }//input end
  disk.resize(V);  //make free space

  auto sentence = *operation.begin();
  while(sentence[0] != "end"){
    switch(sentence[0][0])
    {
    case 'w':{ //write
      Write(sentence[1], stoi(sentence[2]));
      break;
      }
    case 's':{ //show
      Show(sentence[1]);
      break;
      }
    case 'd':{ //delete
      Delete(sentence[1]);
      break;
      }
    case 'c': //compact
      Compact();
    }
    operation.pop_front();
    sentence = *operation.begin();
  }
}
