#include <iostream>
typedef long long int ll;


using namespace std;

ll MOD = 1000000000LL + 7LL;


ll pow_mod(ll a, ll n) {
    if (n == 0LL) {
        return 1LL;
    }
    ll p = pow_mod(a, n / 2);
    ll temp = (p * p) % MOD;
    if (n % 2 == 0LL) {
        return temp;
    } else {
        return (a * temp) % MOD;
    }
}

int main(int argc, char const *argv[]) {
    ll x, y;
    cin >> x >> y;
    if ((x + y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll n = (x + y) / 3;
    x -= n;
    y -= n;

    if (x < 0LL or y < 0LL) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1LL;
    for (ll i = x + 1; i < x + y + 1; i++) {
        ans = (ans * i) % MOD;
    }
    for (ll i = 1LL; i < y + 1; i++) {
        ans = (ans * pow_mod(i, MOD - 2)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
