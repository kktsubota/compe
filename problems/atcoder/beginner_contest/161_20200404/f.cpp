#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

ll count_ak(ll n) {
    // for k == n
    ll cnt = 1LL;

    ll i = 2LL;
    while (i * i <= n) {
        if (n % i == 0LL) {
            // i, n / i
            cnt += 2LL;
        }
        i++;
    }
    return cnt;
}

int main(int argc, char const *argv[]) {
    ll n;
    cin >> n;
    ll ans = 0LL;
    // k == n
    ans += 1LL;
    ans += count_ak(n - 1LL);
    // cout << ans << endl;

    for (ll k = 2LL; k < 1000000LL; k++) {
        ll m = n;
        for (ll k_d = 1; k_d < 20LL; k_d++) {
            if (m % k != 0LL) {
                break;
            }
            m = m / k;
            if (m <= 1LL) {
                break;
            }
            // a * K + 1?
            if (((m - 1LL) % k) == 0LL) {
                ans += 1LL;
            }
        }
        
    }
    cout << ans << endl;
    return 0;    
}