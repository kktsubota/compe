#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll pow_ll(ll a, ll n) {
    if (n == 0LL) {
        return 1LL;
    } else {
        ll half = pow_ll(a, (n / 2));
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * a;
        }
    }
}
int main() {
    ll x;
    cin >> x;
    bool flag_find = false;
    for (ll a = -1000LL; a <= 1000LL; a++) {
        for (ll b = -1000LL; b <= 1000LL; b++) {
            if (pow_ll(a, 5) - pow_ll(b, 5) == x) {
                cout << a << " " << b << endl;
                flag_find = true;
                break;
            }
        }
        if (flag_find) {
            break;
        }
    }
    return 0;
}