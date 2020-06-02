#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll MOD = 1000000007LL;

vector<ll> merge_gcd(vector<ll> a, vector<ll> b) {
    ll k = a.size();
    vector<ll> ret(k, 0LL);
    for (ll i = 1LL; i < k; i++) {
        for (ll j = i; j < k; j += (i + 1)) {
            ret[i] += (a[i] * b[j] % MOD);
            ret[i] %= MOD;
        }
    }
    for (ll j = 1LL; j < k; j++) {
        for (ll i = j; i < k; i += (j + 1)) {
            if (i == j) {
                continue;
            }
            ret[j] += (a[i] * b[j] % MOD);
            ret[j] %= MOD;
        }
    }
    return ret;
}

vector<ll> count_gcd(ll n, ll k) {
    if (n == 1LL) {
        vector<ll> ones(k, 1LL);
        return ones;
    }
    vector<ll> half = count_gcd(n / 2, k);
    if (n % 2LL == 0LL) {
        return merge_gcd(half, half);
    } else {
        return merge_gcd(merge_gcd(count_gcd(1, k), half), half); 
    }
}

int main(int argc, char const *argv[]) {
    ll n, k;
    cin >> n >> k;
    vector<ll> count = count_gcd(n, k);
    for (int i = 0; i < count.size(); i++) {cout << count[i] << ", ";} cout << endl;
    ll ans = 0LL;
    for (ll i = 0LL; i < k; i++) {
        ans += (i + 1) * count[i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;    
}