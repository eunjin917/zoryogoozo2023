#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, K, price;
    vector<int> products;
    set<vector<int> > perm_set;
    stack<int> stk;

    cin >> N >> K;

    products.reserve(N);
    
    for (int i=0; i<N; ++i) {
        cin >> price;

        auto it = products.begin();
        for (; it < products.end(); ++it) {
            if (*it > price) {
                products.insert(it, price);
                break;
            }
        }
        if (it == products.end())
            products.push_back(price);
    }

    for (int i=0; i<N; ++i)
        stk.push(0);

    int last;
    while (!stk.empty()) {
        if (stk.size() == N) {
            stack<int> tempStk = stk;
            vector<int> perm;
            int sum = 0;

            while (!tempStk.empty()) {
                sum += tempStk.top();
                if (tempStk.top())
                    perm.push_back(tempStk.top());

                tempStk.pop();
            }
            
            if (sum == K)
                perm_set.insert(perm);

            last = !!stk.top();
            stk.pop();
        }

        if (last == 1) {
            last = !!stk.top();
            stk.pop();
        }
        if (last == 0) {
            stk.push(products[stk.size()]);
            last = -1;
        } else if (last == -1)
            stk.push(0);
    }

    for (auto w: perm_set) {
        for (auto ww: w) {
            cout << ww << " ";
        }
        cout << endl;
    }

    if (perm_set.empty())
        cout << 0 << endl;
    else
        for (auto it=(*perm_set.rbegin()).rbegin(); it!=(*perm_set.rbegin()).rend(); ++it)
            cout << *it << endl;

    return 0;
}