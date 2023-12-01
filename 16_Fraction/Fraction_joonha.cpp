#include <iostream>
#include <algorithm>
#include <vector>

#define mp make_pair
#define fs first
#define sc second

using namespace std;

int N;
vector<char> input;
int n=1;
int check1=0, check2=0; //check number of parenthesis

pair<int,int> fraction(){

  pair<int,int> a,b,c;
  if(input[n] == '('){
    n++;
    a = fraction();
  }
  if(n<N && input[n] != ')') a = mp(input[n++]-'0', 1);
  else n++;

  if(input[n] == '('){
    n++;
    b = fraction();
  }
  if(n<N && input[n] != ')') b = mp(input[n++]-'0', 1);
  else n++;

  if(input[n] == '('){
    n++;
    c = fraction();
  }
  if(n<N && input[n] != ')') c = mp(input[n++]-'0', 1);
  else n++;
  return mp(a.fs * c.fs*b.sc + b.fs*c.sc*a.sc, c.fs*b.sc*a.sc);
}


int main(){
  pair<int,int> answer;
  char c;

  cin>> N;
  for(int i=0; i<N; i++){
    cin>>c;
    input.push_back(c);
    if(c == '(')  check1++;
    if(c == ')')  check2++;
  }
  if(check1 != check2){
    cout<<-1;
    return 0;
  }
  answer = fraction();
  int gcd = __gcd(answer.fs, answer.sc);
  cout<<answer.first/gcd<<" "<<answer.second/gcd;
}
