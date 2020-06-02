#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;

using namespace std;

ll power(ll a, ll n) {
    if (n == 0) {
        return 1LL;
    }
    ll half = power(a, n / 2) % MOD;
    ll p = (half * half) % MOD;
    if (n % 2 != 0) {
        return (p * a) % MOD;
    } else {
        return p;
    }
}

ll comb(ll n, ll r) {
    ll ans = 1;
    for (int i = 0; i < r; i++) {
        ans = ans * power(i + 1, MOD - 2) % MOD;
        ans = ans * (n - i) % MOD;
    }
    return ans;
}


int main() {
    ll n, k, ans;
    ans = 0LL;
    cin >> n >> k;
    if (n - 1 <= k) {
        ans = comb(2 * n - 1, n - 1);
    } else {
        // n C m
        vector<ll> values(k + 1);
        for (ll m = 0; m <= k; m++) {
            if (m == 0LL) {
                values[m] = 1LL;
            } else {
                values[m] = (n - m + 1) * power(m, MOD - 2) % MOD;
                values[m] = values[m] * values[m - 1] % MOD;
            }
        }
        // for (int m = 0; m <= k; m++) {
        //     auto v = values[m];
        //     cout << v << endl;
        //     cout << v * ((n - m) * power(n, MOD - 2)) % MOD << endl;
        // }
        for (ll m = 0LL; m <= k; m++) {
            // cout << comb(n, m) << ", " << comb(n - 1, m) << endl;
            // ans += comb(n, m) * comb(n - 1, m);
            // ans += values[m] * comb(n - 1, m);
            ll v = values[m] * (n - m) % MOD;
            v = v * power(n, MOD - 2) % MOD;
            ans += values[m] * v;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}