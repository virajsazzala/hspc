#include <bits/stdc++.h>
using namespace std;

class Fraction {
    int _num, _den;

  public:
    Fraction() : _num(0), _den(1) {}
    Fraction(int den) : _num(1), _den(den) {}
    Fraction(int den, int num) : _num(num), _den(den) {}

    Fraction &operator+=(Fraction fa) {
        int num = (fa._num * this->_den) + (this->_num * fa._den);
        int den = fa._den * this->_den;
        int gcd = __gcd(num, den);
        this->_num = num / gcd;
        this->_den = den / gcd;
        return *this;
    }

    friend ostream &operator<<(ostream &, Fraction &f) {
        cout << f._num << "/" << f._den;
        return cout;
    }
};

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        /* take input */
        int fc, tp;
        vector<Fraction> fs;

        cin >> fc;
        for (int i = 0; i < fc; i++) {
            cin >> tp;
            fs.push_back(Fraction(tp));
        }

        /* res of adding all fractions */
        Fraction res;
        for (auto i = fs.begin(); i != fs.end(); i++) res += *i;

        /* display o/p */
        for (auto i = fs.begin(); i + 1 != fs.end(); i++)
            cout << *i << " + ";
        cout << fs.back() << " = " << res << endl;
    }
    return 0;
}