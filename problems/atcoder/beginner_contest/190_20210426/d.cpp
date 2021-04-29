#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    // [m, m + 1, ..., m + k]
    // (2m + k) * (k + 1) // 2
    // = (k + 1) m + (k + 1) k // 2
    // maximum k is 2 * 10 ** 6 when m >= 0
    // when m < 0, tail is same with m >= 0

    ll ans = 0;
    ll cum = 0;
    for (int k = 1; k < 2000000; k++) {
        cum += k;
        if (cum % k == n % k && cum <= n) {
            // cout << k << endl;
            ans++;
        }
    }
    // include non-positive value
    ans *= 2;
    cout << ans << endl;
    return 0;
}