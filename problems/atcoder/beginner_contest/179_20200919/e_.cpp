#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    ll r, ans = 0LL;

    set<ll> prev;
    unordered_set<ll> prev_set;
    vector<ll> prev_list;

    vector<ll> ans_hist;    

    for (ll i = 0LL; i < n; i++) {
        if (i == 0LL) {
            r = x;
        } else {
            r = (r * r) % m;
        }
        // 0 only
        if (r == 0LL) {
            break;
        }
        // auto it = prev.find(r);
        // if (it != prev.end()) {
        if (prev_set.find(r) != prev_set.end()) {
            // ll index = distance(prev.begin(), it);
            ll index = distance(prev_list.begin(), find(prev_list.begin(), prev_list.end(), r));
            ll period = i - index;
            ll count = (n - index) / period;
            ll rest = (n - index) % period;
            if (index == 0) {
                ans += ans * (count - 1);
                if (rest != 0) {
                    ans += ans_hist[rest - 1];                
                }
            } else {
                ans += (ans - ans_hist[index - 1]) * (count - 1);
                // cout << (ans_hist[index + rest - 1] - ans_hist[index - 1]) << endl;
                ans += (ans_hist[index + rest - 1] - ans_hist[index - 1]);
            }
            break;
        } else {
            ans += r;
            prev.insert(r);
            ans_hist.push_back(ans);
            prev_set.insert(r);
            prev_list.push_back(r);
        }
    }
    cout << ans << endl;
    return 0;
}