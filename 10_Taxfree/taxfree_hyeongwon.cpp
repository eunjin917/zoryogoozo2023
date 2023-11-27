#include <iostream>
#include <stack>

using namespace std;

stack<int> sortedPrice, tempPrice;
stack<int> boughtGoods, usedGoods;

int main(void) {
    bool Found = false;
    int numOfGoods, couponPrice, goodPrice;

    cin >> numOfGoods >> couponPrice;
    while(numOfGoods-- > 0) {
        cin >> goodPrice;
        while(!sortedPrice.empty()) {
            if(sortedPrice.top() > goodPrice) {
                tempPrice.push(sortedPrice.top());
                sortedPrice.pop();
            }
            else {
                break;
            }
        }
        sortedPrice.push(goodPrice);
        while(!tempPrice.empty()) {
            sortedPrice.push(tempPrice.top()); //use top, same reason
            tempPrice.pop();
        }
    }
    while(!sortedPrice.empty()) {
        if(sortedPrice.top() > couponPrice) { //use top, same reason
            sortedPrice.pop();
        }
        else break;
    }

    int boughtPrice = 0;

    while(!sortedPrice.empty()) {
        if(sortedPrice.top() <= couponPrice - boughtPrice) { //use top, same reason
            boughtGoods.push(sortedPrice.top()); //use top, same reason
            boughtPrice += sortedPrice.top();
        }
        usedGoods.push(sortedPrice.top()); //use top, same reason
        sortedPrice.pop();

        if(boughtPrice == couponPrice) {
            Found = true;
            break;
        }

        if(sortedPrice.empty()) {
            while(!boughtGoods.empty()) {
                if(boughtGoods.top() == usedGoods.top()) {
                    boughtPrice -= boughtGoods.top();
                    boughtGoods.pop();
                }
                else break;
            }

            if(!boughtGoods.empty()) {
                while(boughtGoods.top() != usedGoods.top()) {
                    sortedPrice.push(usedGoods.top());
                    usedGoods.pop();
                }
                boughtPrice -= boughtGoods.top();
                boughtGoods.pop();
            }
        }
    }

    if(!Found) {
        cout << 0 << endl;
    }
    else {
        while(!boughtGoods.empty()) {
            cout << boughtGoods.top() << endl;
            boughtGoods.pop();
        }
    }

}
