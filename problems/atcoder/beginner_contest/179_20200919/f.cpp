#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    set<ll> prev = {1, 3, 4, 5};
    vector<ll> ans_hist = {1, 4, 8, 13};
    ll r = 4;
    ll n = 11;
    ll i = 4;
    ll ans = 13;
    auto it = prev.find(r);
    ll index = distance(prev.begin(), it);
    // 2
    cout << index << endl;
    ll period = i - index;
    ll count = (n - index) / period;
    ll rest = (n - index) % period;
    // 2, 4, 1
    cout << period << count << rest << endl;
    // 13 - 4 = 9
    cout << ans - ans_hist[index - 1] << endl;
    ans += (ans - ans_hist[index - 1]) * (count - 1);
    ans += (ans_hist[index + rest - 1] - ans_hist[index - 1]);
    cout << ans << endl;

    return 0;
}