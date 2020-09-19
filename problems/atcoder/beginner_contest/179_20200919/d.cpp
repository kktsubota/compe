#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    ll MOD = 998244353LL;
    cin >> n >> k;
    vector<ll> left(k), right(k);
    for (int i = 0; i < k; i++) {
        cin >> left[i] >> right[i];
    }

    vector<ll> ans(n, 0LL);
    vector<ll> sum_region(k, 0LL);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ans[i] = 1LL;
        } else {
            for (int j = 0; j < k; j++) {
                ans[i] = (ans[i] + sum_region[j]) % MOD;
            }
        }

        // update sum
        for (int j = 0; j < k; j++) {
            if (i + 1 - left[j] >= 0) {
                sum_region[j] = (sum_region[j] + ans[i + 1 - left[j]]) % MOD;
            }
            if (i + 1 - right[j] - 1 >= 0) {
                sum_region[j] = (sum_region[j] - ans[i - right[j]]) % MOD;
                if (sum_region[j] < 0LL) {
                    sum_region[j] += MOD;
                }
            }
        }
    }
    cout << ans[n - 1] << endl;
    return 0;
}