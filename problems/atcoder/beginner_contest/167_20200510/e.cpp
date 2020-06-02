#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353LL;


ll pow_mod(ll a, ll n) {
    if (n == 1LL) {
        return a;
    } else if (n == 0LL) {
        return 1LL;
    }else {
        ll half = pow_mod(a, n / 2);
        if (n % 2 == 0) {
            return half * half % MOD;
        } else {
            half = half * half % MOD;
            return half * a % MOD;
        }
    }
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll ans = 0LL;
    ll comb;
    for (ll i = 0LL; i <= k; i++) {
        // comb(n - 1, i)
        if (i == 0LL) {
            comb = 1LL;
        } else {
            comb = comb * (n - 1 - i + 1) % MOD;
            comb = comb * pow_mod(i, MOD - 2) % MOD;
        }
        // cout << "comb(" << n - 1 << ", " << i << "): ";
        // cout << comb << endl;

        // comb (n, i) * (m - 1) ** (n - i - 1)
        ll temp = comb * pow_mod(m - 1, n - i - 1);
        // cout << (temp % MOD) << endl;
        ans += (temp % MOD);
        ans %= MOD;
    }
    ans = ans * m % MOD;
    cout << ans << endl;
    return 0;
}