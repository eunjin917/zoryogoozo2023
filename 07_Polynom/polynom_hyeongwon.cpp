#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sort_poly(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main(){
    int N, k, number, upper;

    cin >> N;

    vector<pair<int,int>> polyComb;

    while(N-- > 0) {
        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> number >> upper;
            polyComb.push_back(make_pair(number, upper));
        }
        sort(polyComb.begin(), polyComb.end(), sort_poly);
    }

    for(int j = 0; j < polyComb.size(); j++) {
        for(int k = j + 1; k < polyComb.size(); k++) {
            if(polyComb[j].second == polyComb[k].second) {
                polyComb[j].first += polyComb[k].first;
                polyComb.erase(polyComb.begin()+ k);
                k--;
            }
        }
        if(polyComb[j].first == 0) {
            polyComb.erase(polyComb.begin()+j);
            j--;
        }
    }

    if(polyComb.size() == 0) {
        cout << "0 0"<< endl;
    }
    else {
        cout << polyComb.size() << endl;
        for(auto x : polyComb) {
            if(x.first !=0 ) cout << x.first <<" " <<x.second << endl;
        }
    }
}
