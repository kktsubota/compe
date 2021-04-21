#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll n;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    map<ll, ll> value_map;
    for (ll i = -200LL; i <= 200; i++) {
        value_map[i] = 0LL;
    }
    for (auto a: A) {
        value_map[a] += 1LL;
    }
    ll ans = 0LL;
    for (auto v1: value_map) {
        for (auto v2: value_map) {
            ll diff = (v1.first - v2.first);
            ans += diff * diff * v1.second * v2.second;
        }
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}