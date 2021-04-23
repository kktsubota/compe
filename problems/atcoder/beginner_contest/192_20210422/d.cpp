#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> pows(ll x, ll a) {
    vector<ll> vec(a + 1);
    for (ll i = 0LL; i < a; i++) {
        if (i == 0LL) {
            vec[a - i] = 1LL;
        } else {
            if ((LONG_LONG_MAX / x) < vec[i - 1]) {
                vec[a - i] = 0LL;
            } else {
                vec[a - i] = x * vec[i-1];
            }
        }
    }
    return vec;
}

bool func(string x, ll n, ll m) {
    vector<ll> base = pows(n, x.length() - 1);
    // overflow (over m)
    if (*(base.end() - 1) == 0LL) {
        return false;
    }
    ll x_base = 0LL; 
    for (int i = 0; i < x.length(); i++) {
        ll y = (ll) (x[i] - '0');
        if (m / y < base[i]) {
            return false;
        }
        if (m - x_base< y * base[i]) {
            return false;
        }
        x_base += y * base[i]
    }
    if (m < x_base) {
        return false;
    }
    return true;
}
int main() {
    string x;
    ll m;
    cin >> x;
    cin >> m;

    // d >= 1
    ll d = -1;
    for (auto c: x) {
        d = max(d, (ll) (c - '0'));
    }
    ll ans = 0LL;
    if (x.length() >= 3) {
        // base is n
        for (ll n = d + 1LL; n <= 1000000LL; n++) {
            if (func(x, n, m)) {
                ans += 1LL;
            } else {
                break;
            }
        }
    } else if (x.length() == 1) {
        // unique value
        ans = 1LL;
    } else if (x.length() == 2) {
        
    }
    return 0;
}