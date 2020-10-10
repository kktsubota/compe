#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll MOD = 1000000007LL;


ll pow_ll(ll a, ll n) {
    if (n == 0LL) {
        return 1LL;
    } else {
        ll half = n / 2;
        ll a_half = pow_ll(a, half);
        ll ret = a_half * a_half % MOD;
        if (n % 2 == 1LL) {
            ret = ret * a % MOD;
        }
        return ret;
    }
}
int main() {
    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (ll i = 0LL; i < h; i++) {
        cin >> s[i];
    }
    vector<vector<int>> cnt_w(h, vector<int>(w, 0LL));
    for (ll i = 0LL; i < h; i++) {
        ll cnt = 0LL;
        ll index = 0LL;
        for (ll j = 0LL; j <= w; j++) {
            if (j < w && s[i][j] == '.') {
                cnt++;
            } else {
                for (ll k = index; k < j; k++) {
                    cnt_w[i][k] = cnt;
                }
                cnt = 0LL;
                index = j + 1LL;
            }
        }
    }
    // for (auto v: cnt_w) {
    //     for (auto e: v) {
    //         cout << e << ",";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> cnt_h(h, vector<int>(w, 0LL));
    for (ll j = 0LL; j < w; j++) {
        ll cnt = 0LL;
        ll index = 0LL;
        for (ll i = 0LL; i <= h; i++) {
            if (i < h && s[i][j] == '.') {
                cnt++;
            } else {
                for (ll k = index; k < i; k++) {
                    cnt_h[k][j] = cnt;
                }
                cnt = 0LL;
                index = i + 1LL;
            }
        }
    }

    // for (auto v: cnt_h) {
    //     for (auto e: v) {
    //         cout << e << ",";
    //     }
    //     cout << endl;
    // }

    ll total_empty = 0LL;
    for (ll i = 0LL; i < h; i++) {
        for (ll j = 0LL; j < w; j++) {
            if (s[i][j] == '.') {
                total_empty++;
            }
        }
    }

    ll ans = 0LL;
    ll total_pow = pow_ll(2LL, total_empty);
    vector<ll> precomputed(total_empty + 1);
    for (int i = 0LL; i < precomputed.size(); i++) {
        if (i == 0LL) {
            precomputed[i] = 1LL;
        } else {
            precomputed[i] = (precomputed[i - 1] * 2 % MOD);
        }
    }
    for (ll i = 0LL; i < h; i++) {
        for (ll j = 0LL; j < w; j++) {
            if (s[i][j] == '.') {
                ll cnt = cnt_w[i][j] + cnt_h[i][j] - 1LL;
                // ans += (pow_ll(2LL, cnt) - 1) * pow_ll(2LL, total_empty - cnt);
                // ll diff = total_pow - pow_ll(2LL, total_empty - cnt);
                ll diff = precomputed[total_empty] - precomputed[total_empty - cnt];
                if (diff < 0LL) {
                    diff += MOD;
                }
                ans += diff;
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}