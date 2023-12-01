#include <bits/stdc++.h>

using namespace std;

struct Fraction {
    int numerator, denominator;
};

vector<Fraction> expStack;
stack<int> Stack;

Fraction calc(Fraction& a, Fraction& b, Fraction& c) {
    Fraction firstFrac = {b.numerator*c.denominator, b.denominator*c.numerator};

    int numerator = (a.numerator * firstFrac.denominator) + (a.denominator * firstFrac.numerator);
    int denominator = a.denominator * firstFrac.denominator;

    return {numerator, denominator};
}

int main() {
    int N;
    char oneExp;

    cin >> N;

    while(N-- > 0) {
        cin >> oneExp;
        if(oneExp == '(') {
            Stack.push(0);
        }
        else if(oneExp == ')') {
            if(!Stack.empty() && Stack.top() == 3) {
                int lastIndex = expStack.size() - 1;
                Fraction newFrac = calc(expStack[lastIndex - 2], expStack[lastIndex - 1], expStack[lastIndex]);
                expStack.erase(expStack.end() - 3, expStack.end());
                expStack.push_back(newFrac);
                Stack.pop();
                if(!Stack.empty()) {
                    Stack.top()++;
                }
            }
            else {
                cout << -1 << endl;
                break;
            }
        }
        else {
            Stack.top()++;
            expStack.push_back({oneExp - '0', 1});
        }
    }

    if(!Stack.empty()) {
        cout << -1 << endl;
    }
    else {
        int numerator = expStack[0].numerator, denominator = expStack[0].denominator;
        int GCD = __gcd(numerator, denominator);
        cout << numerator/GCD << " " << denominator/GCD << endl;
    }
}
