#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Waiting {
private:
    int chairSize;
    vector<int> numberComb;
    vector<vector<int>> waitComb;
public:
    Waiting(int num) : chairSize(num) {}

    void customer_in (int number) {

        int index = 0;

        numberComb.push_back(number);

        if(waitComb.size() == 0) {
            vector<int> oneChair;
            oneChair.push_back(number);
            waitComb.push_back(oneChair);
            return;
        }

        if(waitComb.size() > 1) {
            for(index = 0; index < waitComb.size() - 1; index++) {
                if(number < waitComb[index + 1][0]) break;
            }
        }

        waitComb[index].push_back(number);

        sort(waitComb[index].begin(), waitComb[index].end());

        if(waitComb[index].size() == chairSize * 2) {

            vector<int> newChair;

            for(int i = 0; i < chairSize; i++) {
                newChair.push_back(waitComb[index][chairSize]);
                waitComb[index].erase(waitComb[index].begin() + chairSize);
            }

            waitComb.emplace(waitComb.begin() + index + 1, newChair);
        }
        /*
        for(auto w : waitComb) {
            sort(w.begin(), w.end());
            for(auto x : w) {
                cout << x << " ";
            }
            cout << endl << endl;
        }
        */

    }

    void customer_out(int number) {
        auto isInNumComb = find(numberComb.begin(), numberComb.end(), number);
        if(isInNumComb != numberComb.end()) {
            int index;
            numberComb.erase(isInNumComb);
            for(index = 0; index < waitComb.size(); index++) {
                auto findIt = find(waitComb[index].begin(), waitComb[index].end(), number);
                if(findIt != waitComb[index].end()) {
                    waitComb[index].erase(findIt);
                    break;
                }
            }

            if(waitComb[index].size() == 0) {
                waitComb.erase(waitComb.begin() + index);
            }
        }
        /*
        for(auto w : waitComb) {
            for(auto x : w) {
                cout << x << " ";
            }
            cout << endl << endl;
        }
        */

    }

    void customer(string inout, int number){
        if(inout == "+") {
            customer_in (number);
        }
        else {
            customer_out(number);
        }
    }

    void print_low(){
        for(auto w : waitComb){
            cout << w[0] << endl;
        }
    }
};

int main(){
    int N, k, number;
    string inout;

    cin >> N >> k;

    Waiting wait(k);

    while(N-- > 0) {
        cin >> inout >> number;
        wait.customer(inout, number);
    }

    wait.print_low();
}
