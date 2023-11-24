//문제의 특징
//같은 가격이 존재하는 경우 선정 대상에서 애초에 배제됨
//같은 가격이 존재한다 -> p 배열에서 갯수 카운트 후 확인!
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;
using pls = pair<ll, string>;
ll p[10001];//p의 값 <= 10000, 입찰 가격이 p인 입찰의 갯수를 구함.
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); //fastio
    ll n; cin >> n;
    vector<pls> vec;//vector에는 pair을 이용해 다른 원소를 같이 넣을 수 있음.
    while (n--){//입력 받기
        string name; ll price;
        cin >> name >> price;
        p[price]++; vec.emplace_back(price, name);
    }
    sort(vec.begin(), vec.end(), [](pls a, pls b){//내림차순으로 정렬
        return a.first > b.first;
    });//람다 함수
    for (auto [price, name]: vec){
        if (p[price] == 1){//price가 유일해야 함.
            cout << name; return 0;//이름 출력 후 바로 탈출
        }
    }
    cout << "NONE";
    return 0;
}
