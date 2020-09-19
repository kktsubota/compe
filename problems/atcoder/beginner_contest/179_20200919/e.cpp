#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    ll r, ans = 0LL;

    for (ll i = 1LL; i <= n; i++) {
        if (i == 1LL) {
            r = x % m;
        } else {
            r = (r * r) % m;
        }
        // 0 only
        if (r == 0LL) {
            break;
        }
        // should be smaller period than m
        if (i != 1 && r == x) {
            ll period = i - 1;
            ll count = n / period;
            ans *= count;

            n = n - count * period;
            i = 1;
        }
        ans += r;
    }
    cout << ans << endl;
    return 0;
}