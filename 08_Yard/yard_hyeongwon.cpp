//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, numOfCarry, weight;
    vector<int> countComb;
    vector<stack<int>> carryComb;

    cin >> N;
    while(N-- > 0) {
        stack<int> oneLine;
        cin >> numOfCarry;
        countComb.push_back(numOfCarry);
        while(numOfCarry-- > 0) {
            cin >> weight;
            oneLine.push(weight);
        }
        carryComb.push_back(oneLine);
    }

    while(*max_element(countComb.begin(), countComb.end()) - *min_element(countComb.begin(), countComb.end()) > 1) {
        int maxindex;
        int maxvalue = *max_element(countComb.begin(), countComb.end());
        int maxweight = 0;
        int minindex = min_element(countComb.begin(), countComb.end()) - countComb.begin();

        for(int i = 0; i < carryComb.size(); i++) {
            if(carryComb[i].size() == maxvalue) {
                if(maxweight < carryComb[i].top()) {
                    maxweight = carryComb[i].top();
                    maxindex = i;
                }
            }
        }

        carryComb[minindex].push(carryComb[maxindex].top());
        carryComb[maxindex].pop();
        countComb[maxindex]--;
        countComb[minindex]++;
    }

    //not stack, if vector... countComb[countComb.size()-1] = countComb.top()

    for(auto& w : carryComb) {
        stack<int> reverseStack;
        while(w.size() > 0) {
            reverseStack.push(w.top());
            w.pop();
        }
        if(reverseStack.size() == 0) {
            cout << 0 << endl;
        }
        else {
            while(reverseStack.size() > 0) {
                cout << reverseStack.top() << " ";
                reverseStack.pop();
            }
            cout << endl;
        }
    }
}
