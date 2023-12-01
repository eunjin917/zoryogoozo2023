#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

typedef struct {
    long child, parent;
    int depth;
} Fraction;

ostream& operator<<(ostream& os, Fraction f) {
    return os << f.child << " " << f.parent << endl;
}

Fraction make_frac(long c, long p) {
    Fraction f;
    f.child = c;
    f.parent = p;
    return f;
}

void yakbun(Fraction& f) {
    int g = __gcd(f.child, f.parent);
    f.child /= g;
    f.parent /= g;
}

Fraction func(Fraction a, Fraction b, Fraction c) {
    Fraction f;
    f.parent = b.parent * c.child;
    f.child = b.child * c.parent;
    
    f.child = f.child*a.parent + a.child*f.parent;
    f.parent *= a.parent;
    yakbun(f);

    f.depth = a.depth-1;

    return f;
}

bool myComp(Fraction a, Fraction b) {
    return a.depth < b.depth;
}

int main() {
    int N;
    char str[101];
    list<Fraction> frac_list;
    
    cin >> N;
    
    int d = 0;
    for (int i=0; i<N; ++i) {
        char ch;
        cin >> ch;
        str[i] = ch;
        switch(ch) {
            case '(':
                d += 1;
                break;
            case ')':
                d -= 1;
                break;
            default:
                auto f = make_frac(ch-'0', 1);
                f.depth = d;
                frac_list.push_back(f);
                break;
        }
    }

    if (d) {
        cout << -1 << endl;
        return 0;
    }

    int max_depth = max_element(frac_list.begin(), frac_list.end(), myComp)->depth;
    while(max_depth) {
        for (auto it=frac_list.begin(); it!=frac_list.end(); ++it) {
            if(it->depth == max_depth) {
                auto temp_it = it;
				auto f1 = *temp_it;
                auto f2 = *(++temp_it);
                auto f3 = *(++temp_it);
                it = frac_list.insert(it, func(f1, f2, f3));
                frac_list.erase(++it, ++temp_it);
                break;
            }
        }

        max_depth = max_element(frac_list.begin(), frac_list.end(), myComp)->depth;
    }
    auto f = frac_list.front();

    // Fraction f = func(make_frac(1,1), make_frac(2,1), make_frac(3,1));
    cout << f.child << " " <<  f.parent << endl;
    
    return 0;
}
