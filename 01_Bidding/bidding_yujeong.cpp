#include <iostream>
#include <string>
#include <map>

using namespace std;

// 경매 참가자 구조체
struct Bidder {
    string name;
    int price;
};

int main() {
    int N;
    cin >> N;
    cin.ignore();

    const int maxBidders = 100; // 최대 경매 참가자 수
    Bidder bidders[maxBidders]; // 경매 참가자를 저장하는 배열

    // 경매 참가자와 입찰가 입력
    for (int i = 0; i < N; i++) {
        string name;
        int price;
      
        cin >> name >> price;
        bidders[i].name = name;
        bidders[i].price = price;
    }

    // 중복된 입찰가를 가진 사람을 제외하고 가장 높은 입찰가를 찾음
    map<int, string> uniqueBids; // 입찰가를 키로, 이름을 값으로 가지는 맵

    for (int i = 0; i < N; i++) {
        if (uniqueBids.find(bidders[i].price) == uniqueBids.end()) {
            // 해당 입찰가를 가진 사람이 없으면 추가
            uniqueBids[bidders[i].price] = bidders[i].name;
        } else if (uniqueBids[bidders[i].price] != "DUPLICATE") {
            // 이미 해당 입찰가를 가진 사람이 있으면 "DUPLICATE"로 표시
            uniqueBids[bidders[i].price] = "DUPLICATE";
        }
    }

    int maxBid = 0; // 가장 높은 입찰가 초기화
    string winner = "NONE"; // 낙찰자 초기화

    // 가장 높은 입찰가와 낙찰자를 찾음
    for (const auto& entry : uniqueBids) {
        if (entry.second != "DUPLICATE" && entry.first > maxBid) {
            maxBid = entry.first;
            winner = entry.second;
        }
    }

    cout << winner << endl;

    return 0;
}
