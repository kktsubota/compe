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

int main(int argc, char const *argv[]) {
    ll n, a, b;
    cin >> n >> a >> b;
    // cout << power(2LL, n) << endl;
    // cout << comb(n, a) << endl;
    ll ans = power(2LL, n) - 1 - comb(n, a) - comb(n, b);

    while (ans < 0) {
        ans += MOD;
    }
    cout << ans << endl;
    return 0;
}
