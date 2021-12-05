#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll k_bound, n;
    cin >> n;
    ll ans = 0LL;

    k_bound = 1000000LL;
    // [N // 1] + ..., [N / m]
    // where [N / m] > k_bound
    for (ll i = 1LL; i <= n; ++i) {
        if (n / i <= k_bound) {
            break;
        }
        // [1, n]
        ans += (n / i);
    }
    // count where [N // i] == k, 1 <= k <= k_bound
    for (ll k = 1LL; k <= k_bound; ++k) {
        // n / (k+1) < i <= n / k
        ll cnt = (n / k) - (n / (k+1));
        ans += k * cnt;
    }
    cout << ans << endl;

    return 0;
}