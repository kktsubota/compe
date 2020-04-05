#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

ll count_ak(ll n) {
    if (n == 1LL) {
        return 0LL;
    }
    // for k == n
    ll cnt = 1LL;

    ll i = 2LL;
    while (i * i < n) {
        if (n % i == 0LL) {
            // i, n / i
            cnt += 2LL;
        }
        i++;
    }
    if (i * i == n) {
        cnt++;
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

    vector<ll> divs;
    ll i = 1LL;
    while (i * i <= n) {
        if (n % i == 0LL) {
            divs.push_back(i);
            if (i * i != n) {
                divs.push_back(n / i);
            }
        }
        i++;
    }
    sort(divs.begin(), divs.end());
    for (auto k: divs) {
        if (k == 1) {
            continue;
        }
        if (k == n) {
            break;
        }
        ll m = n;
        while (m % k == 0) {
            m = m / k;
        }
        // a * K + 1?
        if (m % k == 1LL) {
            ans += 1LL;
        }
    }
    cout << ans << endl;
    return 0;    
}