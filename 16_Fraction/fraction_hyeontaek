#include <bits/stdc++.h>
#define popd = st.top(); st.pop();
using namespace std;
using ll = long long;
ll gcd(ll x, ll y){ if(y == 0){return x;} else {return gcd(y, x%y);}}
struct frac{
    ll a, b;
    frac(): a(0), b(1) {}
    frac(ll a, ll b): a(a / gcd(a, b)), b(b / gcd(a, b)) {}
    frac operator+(frac x){
        ll tmp_a = a * x.b + b * x.a, tmp_b = b * x.b;
        return frac(tmp_a, tmp_b);
    }
    frac operator/(frac x){
        ll tmp_b = b * x.a, tmp_a = a * x.b;
        return frac(tmp_a, tmp_b);
    }
    bool operator==(frac x) {
        return (x.a == a && x.b == b);
    }
    void print(){
        cout << a << " " << b;
    }
};
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    ll n; cin >> n; stack<frac> st;
    for (ll i = 0; i < n; i++){
        char t; cin >> t;
        if (t == '(')   st.push(frac(0, 1));
        else if (t == ')'){
                frac c popd
                frac b popd
                frac a popd
                if (st.empty() || !(st.top() == frac(0, 1))){
                    cout << -1; return 0;
                }
                else{
                    st.pop();
                    st.push(a + b / c);
                }

        }
        else{
            st.push(frac((ll)t - 48, 1));
        }

    }
    if (st.size() != 1) cout << -1;
    else    st.top().print();
}
